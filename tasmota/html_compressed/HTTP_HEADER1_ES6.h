/////////////////////////////////////////////////////////////////////
// compressed by tools/unishox/compress-html-uncompressed.py
/////////////////////////////////////////////////////////////////////

const size_t HTTP_HEADER1_SIZE = 505;
const char HTTP_HEADER1_COMPRESSED[] PROGMEM = "\x3D\x0F\xE1\x10\x98\x1D\x19\x0C\x64\x85\x50\xD0\x8F\xC3\xD0\x55\x0D\x09\x05\x7C"
                             "\x3C\x7C\x3D\x87\xD7\x8F\x62\x0C\x2B\xF7\x8F\x87\xB0\xF6\x1F\x87\xA0\xA7\x62\x1F"
                             "\x87\xA0\xD7\x56\x83\x15\x7F\xF3\xA3\xE1\xF6\x2E\x8C\x1D\x67\x3E\x7D\x90\x21\x52"
                             "\xEB\x1A\xCF\x87\xB0\xCF\x58\xF8\xCC\xFD\x1E\xC4\x1E\x75\x3E\xA3\xE1\xEC\x1F\xD1"
                             "\x28\x51\xF0\x46\x67\xA1\xB3\xAC\x7F\x44\xA1\x47\x56\xF6\xD6\xD8\x47\x5F\x83\xB0"
                             "\x99\xF0\xE4\x3A\x88\x5F\x9F\xCE\xBF\x07\x61\x58\xE0\x99\xF3\xB0\xF6\x1D\x87\xE1"
                             "\xE8\x16\xF1\xA2\xFB\x08\xF8\x7D\xE8\x79\xC7\xDA\x15\xF6\x60\xF8\x7D\x89\x75\x67"
                             "\x9E\x8D\xB1\xE6\x76\x1B\x0E\xBD\x0F\x38\xF0\x3A\xFC\xCE\x76\x1D\x44\x45\x77\x63"
                             "\xAE\xDD\xB1\xD7\x77\x6E\xC7\x5D\x96\x15\x91\xA8\xAC\xAC\x8C\x0F\x15\x95\x95\x90"
                             "\x63\xC4\x57\x77\x66\xAB\xBB\xBD\xB2\x37\xA0\x11\x3B\x1D\x64\x6F\x44\x22\x64\x08"
                             "\x91\x8D\xE9\x44\x21\xD8\x91\xE9\x5B\x41\x33\xF0\xFA\xF2\x3A\xD1\xF5\xE3\xD0\xEC"
                             "\x04\x19\x67\xA7\x83\xFE\x8C\xA3\xF0\xCE\xFE\x8D\x87\xCE\x16\x10\x47\x50\x54\x75"
                             "\x56\x1D\x54\x30\xEA\x18\x19\xF0\xFB\x3E\xCF\x0C\x71\xF3\xC7\xC3\xF0\x4C\x0C\x58"
                             "\xD7\xD4\x74\x1E\x74\x4C\x26\x35\xF5\x10\xE3\x22\xD1\x0E\xEF\x8E\xF1\xE0\xD5\xE0"
                             "\x48\xBA\x6A\x16\xFE\x64\x5E\x61\x30\xEB\x3E\x77\x7C\x77\x8F\x1E\x18\x7C\xD3\xE1"
                             "\xF8\xC7\x1D\xDD\x3B\xC7\x4A\x32\x18\xCF\x87\x74\x11\xA4\x1F\x0F\x87\xDD\x33\x65"
                             "\x1F\x67\x68\xFB\x19\x7E\xF0\xFE\x7C\x43\xEC\xF3\x04\x19\xC7\x78\xF0\x3E\x11\xF0"
                             "\xC1\xF0\xFC\x1F\xDE\x13\x07\xCE\x96\x20\x84\xCC\xDF\x51\x05\xBE\xA7\xCF\xE7\x74"
                             "\xFB\x0B\x2C\x43\xEC\xEA\x30\x77\x8F\x06";

#define  HTTP_HEADER1       Decompress(HTTP_HEADER1_COMPRESSED,HTTP_HEADER1_SIZE).c_str()