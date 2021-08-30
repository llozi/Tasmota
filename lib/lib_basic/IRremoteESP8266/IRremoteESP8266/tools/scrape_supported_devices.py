#!/usr/bin/env python3
"""Generate SupportedProtocols.md by scraping source code files"""
import pathlib
import argparse
import subprocess
from io import StringIO
import sys
import re
import time

CODE_URL = "https://github.com/crankyoldgit/IRremoteESP8266/blob/master/src/ir_"

BRAND_MODEL = re.compile(r"Brand: *(?P<brand>.+), *Model: *(?P<model>.+)")
ENUMS = re.compile(r"enum (\w+) {(.+?)};", re.DOTALL)
ENUM_ENTRY = re.compile(r"^\s+(\w+)", re.MULTILINE)
DECODED_PROTOCOLS = re.compile(r".*(?:results->decode_type *=.*?|"
                               r"typeguess\s*=\s*decode_type_t::)(\w+);")
AC_FN = re.compile(r"ir_(.+)\.h")
AC_MODEL_ENUM_RE = re.compile(r"(.+)_ac_remote_model_t")
IRSEND_FN_RE = re.compile(r"IRsend\.h")
ALL_FN = re.compile(r"ir_(.+)\.(h|cpp)")

EXCLUDED_PROTOCOLS = ["UNKNOWN", "UNUSED", "kLastDecodeType", "typeguess"]
EXCLUDED_ACS = ["Magiquest", "NEC"]

def getgitcommittime():
  """Call git to get time of last commit
  """
  try:
    label = subprocess.check_output(\
      ["git", "show", "-s", "--format=%ct", "HEAD"]).strip()
    return int(label)
  except FileNotFoundError as err:
    print("Git failed, which is ok, no git binary found?:", err)
    return None
  except subprocess.SubprocessError as err:
    print("Git failed, which is ok, see output, maybe no git checkout?:", err)
    return None

def getmarkdownheader():
  """Get the generated header
  """
  srctime = getgitcommittime()
  return """<!--- WARNING: Do NOT edit this file directly.
      It is generated by './tools/scrape_supported_devices.py'.
      Last generated: {} --->""".format(
          time.strftime("%a %d %b %Y %H:%M:%S +0000", time.gmtime(srctime)))


def getallprotocols():
  """Return all protocls configured in IRremoteESP8266.h
  """
  irremote = ARGS.directory / "IRremoteESP8266.h"
  enums = getenums(irremote)["decode_type_t"]
  if not enums:
    errorexit("Error getting ENUMS from IRremoteESP8266.h")
  return enums


def getdecodedprotocols():
  """All protocols that include decoding support"""
  ret = set()
  for path in ARGS.directory.iterdir():
    if path.suffix != ".cpp":
      continue
    matches = DECODED_PROTOCOLS.finditer(path.open(encoding="utf-8").read())
    for match in matches:
      protocol = match.group(1)
      if protocol not in EXCLUDED_PROTOCOLS:
        ret.add(protocol)
  return ret


def getallacs():
  """All supported A/C codes"""
  ret = {}
  for path in ARGS.directory.iterdir():
    match = AC_FN.match(path.name)
    if match:
      acprotocol = match.group(1)
      rawmodels = getenums(path)
      models = set()
      for model in rawmodels:
        model = model.upper()
        model = model.replace("K{}".format(acprotocol.upper()), "")
        if model and model not in EXCLUDED_PROTOCOLS:
          models.add(model)
      if acprotocol in ret:
        ret[acprotocol].update(models)
      else:
        ret[acprotocol] = models
    # Parse IRsend.h's enums
    match = IRSEND_FN_RE.match(path.name)
    if match:
      rawmodels = getenums(path)
      for acprotocol, acmodels in rawmodels.items():
        models = set()
        for model in acmodels:
          model = model.upper()
          model = model.replace("K{}".format(acprotocol.upper()), "")
          if model and model not in EXCLUDED_PROTOCOLS:
            models.add(model)
        if acprotocol in ret:
          ret[acprotocol].update(models)
        else:
          ret[acprotocol] = models
  return ret

class FnSets():
  """Container for getalldevices"""
  def __init__(self):
    self.allcodes = {}
    self.fnnomatch = set()
    self.allhfileprotos = set()
    self.fnhmatch = set()
    self.fncppmatch = set()

  def add(self, supports, path):
    """add the path to correct set based on supports"""
    if path.suffix == ".h":
      self.allhfileprotos.add(path.stem)
    if supports:
      if path.suffix == ".h":
        self.fnhmatch.add(path.stem)
      elif path.suffix == ".cpp":
        self.fncppmatch.add(path.stem)
    else:
      self.fnnomatch.add(path.stem)

  def printwarnings(self):
    """print warnings"""
    # all protos with support in .cpp file, when there is a .h file
    # meaning that the documentation should probably be moved to .h
    # in the future, with doxygen, that might change
    protosincppwithh = list(self.fncppmatch & self.allhfileprotos)
    if protosincppwithh:
      protosincppwithh.sort()
      print("The following files has supports section in .cpp, expected in .h")
      for path in protosincppwithh:
        print("\t{}".format(path))

    protosincppandh = list(self.fncppmatch & self.fnhmatch)
    if protosincppandh:
      protosincppandh.sort()
      print("The following files has supports section in both .h and .cpp")
      for path in protosincppandh:
        print("\t{}".format(path))

    nosupports = self.getnosupports()
    if nosupports:
      nosupports.sort()
      print("The following files had no supports section:")
      for path in nosupports:
        print("\t{}".format(path))

    return protosincppwithh or protosincppandh or nosupports

  def getnosupports(self):
    """get protos without supports sections"""
    return list(self.fnnomatch - self.fnhmatch - self.fncppmatch)


def getalldevices():
  """All devices and associated branding and model information (if available)
  """
  sets = FnSets()
  for path in ARGS.directory.iterdir():
    match = ALL_FN.match(path.name)
    if not match:
      continue
    supports = extractsupports(path)
    sets.add(supports, path)
    protocol = match.group(1)
    for brand, model in supports:
      protocolbrand = (protocol, brand)
      pbset = sets.allcodes.get(protocolbrand, [])
      if model in pbset:
        print("Model %s is duplicated for %s, %s" % (model, protocol, brand))
      sets.allcodes[protocolbrand] = pbset + [model]

  for fnprotocol in sets.getnosupports():
    sets.allcodes[(fnprotocol[3:], "Unknown")] = []
  return sets


def getenums(path):
  """Returns the keys for the first enum type in path
  """
  ret = {}
  for enums in ENUMS.finditer(path.open(encoding="utf-8").read()):
    if enums:
      enum_name = AC_MODEL_ENUM_RE.search(enums.group(1))
      if enum_name:
        enum_name = enum_name.group(1).capitalize()
      else:
        enum_name = enums.group(1)
      ret[enum_name] = set()
      for enum in ENUM_ENTRY.finditer(enums.group(2)):
        enum = enum.group(1)
        if enum in EXCLUDED_PROTOCOLS:
          continue
        ret[enum_name].add(enum)
  return ret


ARGS = None


def initargs():
  """Init the command line arguments"""
  global ARGS  # pylint: disable=global-statement
  parser = argparse.ArgumentParser()
  parser.add_argument(
      "-n",
      "--noout",
      help="generate no output data, combine with --alert to only check",
      action="store_true",
  )
  parser.add_argument(
      "-s",
      "--stdout",
      help="output to stdout rather than SupportedProtocols.md",
      action="store_true",
  )
  parser.add_argument("-v",
                      "--verbose",
                      help="increase output verbosity",
                      action="store_true")
  parser.add_argument(
      "-a",
      "--alert",
      help="alert if a file does not have a supports section, "
      "non zero exit code if issues where found",
      action="store_true",
  )
  parser.add_argument(
      "directory",
      nargs="?",
      help="directory of the source git checkout",
      default=None,
  )
  ARGS = parser.parse_args()
  if ARGS.directory is None:
    src = pathlib.Path("../src")
    if not src.is_dir():
      src = pathlib.Path("./src")
  else:
    src = pathlib.Path(ARGS.directory) / "src"
  if not src.is_dir():
    errorexit("Directory not valid: {}".format(str(src)))
  ARGS.directory = src
  return ARGS

def getmdfile():
  """Resolves SupportedProtocols.md path"""
  foutpath = ARGS.directory / "../SupportedProtocols.md"
  return foutpath.resolve()

def errorexit(msg):
  """Print an error and exit on critical error"""
  sys.stderr.write("{}\n".format(msg))
  sys.exit(1)


def extractsupports(path):
  """Extract all of the Supports: sections and associated brands and models
  """
  supports = []
  insupports = False
  for line in path.open(encoding="utf-8"):
    if not line.startswith("//"):
      continue
    line = line[2:].strip()
    if line == "Supports:":
      insupports = True
      continue
    if insupports:
      match = BRAND_MODEL.match(line)
      if match:
        supports.append((match.group("brand"), match.group("model")))
      else:
        insupports = False
        continue
    # search and inform about any legacy formated supports data
    elif any(x in line for x in [ \
             "seems compatible with",
             "be compatible with",
             "it working with here"]):
      print("\t%s Legacy supports format found\n\t\t%s" % (path.name, line))
  return supports


def makeurl(txt, path):
  """Make a Markup URL from given filename"""
  return "[{}]({})".format(txt, CODE_URL + path)


def outputprotocols(fout, protocols):
  """For a given protocol set, sort and output the markdown"""
  protocols = list(protocols)
  protocols.sort()
  for protocol in protocols:
    fout.write("- {}\n".format(protocol))


def generate(fout):
  """Generate data to fout
  return True on any issues (when alert is active)"""
  decodedprotocols = getdecodedprotocols()
  sendonly = getallprotocols() - decodedprotocols
  allacs = getallacs()

  sets = getalldevices()
  allcodes = sets.allcodes
  allbrands = list(allcodes.keys())
  allbrands.sort()

  fout.write("\n# IR Protocols supported by this library\n\n")
  fout.write(
      "| Protocol | Brand | Model | A/C Model | Detailed A/C Support |\n")
  fout.write("| --- | --- | --- | --- | --- |\n")

  for protocolbrand in allbrands:
    protocol, brand = protocolbrand
    codes = allcodes[protocolbrand]
    codes.sort()
    acmodels = []
    acsupport = "-"
    if protocol in allacs:
      acmodels = list(allacs[protocol])
      acmodels.sort()
      brand = makeurl(brand, protocol + ".h")
      if protocol not in EXCLUDED_ACS:
        acsupport = "Yes"

    fout.write("| {} | **{}** | {} | {} | {} |\n".format(
        makeurl(protocol, protocol + ".cpp"),
        brand,
        "<BR>".join(codes).replace("|", "\\|"),
        "<BR>".join(acmodels),
        acsupport,
    ))

  fout.write("\n\n## Send only protocols:\n\n")
  outputprotocols(fout, sendonly)

  fout.write("\n\n## Send & decodable protocols:\n\n")
  outputprotocols(fout, decodedprotocols)

  return ARGS.alert and sets.printwarnings()

def generatenone():
  """No out write
  return True on any issues"""
  return generate(StringIO())

def generatestdout():
  """Standard out write
  return True on any issues"""
  fout = sys.stdout
  fout.write(getmarkdownheader())
  return generate(fout)

def generatefile():
  """File write, extra detection of changes in existing file
  return True on any issues, but only if there is changes"""
  # get file path
  foutpath = getmdfile()
  if ARGS.verbose:
    print("Output path: {}".format(str(foutpath)))
  # write data to temp memorystream
  ftemp = StringIO()
  ret = generate(ftemp)
  # get old filedata, skipping header
  with getmdfile().open("r", encoding="utf-8") as forg:
    olddata = forg.readlines()[3:]
  # get new data, skip first empty line
  ftemp.seek(0)
  newdata = ftemp.readlines()[1:]
  # if new data is same as old we don't need to write anything
  if newdata == olddata:
    print("No changes, exit without write")
    return False
  # write output
  with foutpath.open("w", encoding="utf-8") as fout:
    fout.write(getmarkdownheader())
    fout.write(ftemp.getvalue())

  return ret

def main():
  """Default main function
  return True on any issues"""
  initargs()
  if ARGS.verbose:
    print("Looking for files in: {}".format(str(ARGS.directory.resolve())))
  if ARGS.noout:
    return generatenone()
  if ARGS.stdout:
    return generatestdout()
  # default file
  return generatefile()


if __name__ == "__main__":
  sys.exit(1 if main() else 0)
