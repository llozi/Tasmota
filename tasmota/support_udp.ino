/*
  support_udp.ino - Udp support for Tasmota

  Copyright (C) 2020  Heiko Krupp and Theo Arends

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifdef USE_EMULATION

#ifndef UDP_BUFFER_SIZE
#define UDP_BUFFER_SIZE         120      // Max UDP buffer size needed for M-SEARCH message
#endif
#ifndef UDP_MAX_PACKETS
#define UDP_MAX_PACKETS   3             // we support x more packets than the current one
#endif
#define UDP_MSEARCH_SEND_DELAY  1500     // Delay in ms before M-Search response is send

#include <Ticker.h>
#include "UdpListener.h"
Ticker TickerMSearch;

IPAddress udp_remote_ip;                 // M-Search remote IP address
uint16_t udp_remote_port;                // M-Search remote port

bool udp_connected = false;
bool udp_response_mutex = false;         // M-Search response mutex to control re-entry

UdpListener<UDP_BUFFER_SIZE> UdpCtx(UDP_MAX_PACKETS);

/*********************************************************************************************\
 * UPNP/SSDP search targets
\*********************************************************************************************/

const char URN_BELKIN_DEVICE[] PROGMEM = "urn:belkin:device:**";
const char URN_BELKIN_DEVICE_CAP[] PROGMEM = "urn:Belkin:device:**";
const char UPNP_ROOTDEVICE[] PROGMEM = "upnp:rootdevice";
const char SSDPSEARCH_ALL[] PROGMEM = "ssdpsearch:all";
const char SSDP_ALL[] PROGMEM = "ssdp:all";

/*********************************************************************************************\
 * UDP support routines
\*********************************************************************************************/

bool UdpDisconnect(void)
{
  if (udp_connected) {
    // flush any outgoing packet
    PortUdp.flush();
    UdpCtx.disconnect();
#ifdef USE_DEVICE_GROUPS
    // stop
    PortUdp.stop();
#else // USE_DEVICE_GROUPS
    // stop all
    WiFiUDP::stopAll();
#endif  // !USE_DEVICE_GROUPS
    AddLog_P(LOG_LEVEL_DEBUG, PSTR(D_LOG_UPNP D_MULTICAST_DISABLED));
    udp_connected = false;
  }
  return udp_connected;
}

bool UdpConnect(void)
{
  if (!udp_connected && !restart_flag) {
    // Simple Service Discovery Protocol (SSDP)

    UdpCtx.reset();
    if (igmp_joingroup(WiFi.localIP(), IPAddress(239,255,255,250)) == ERR_OK) { // addr 239.255.255.250
      ip_addr_t addr = IPADDR4_INIT(INADDR_ANY);
      if (UdpCtx.listen(&addr, 1900)) {         // port 1900
        // OK
        AddLog_P(LOG_LEVEL_INFO, PSTR(D_LOG_UPNP D_MULTICAST_REJOINED));
        udp_response_mutex = false;
        udp_connected = true;
      }
    }
    if (!udp_connected) {     // if connection failed
      AddLog_P(LOG_LEVEL_INFO, PSTR(D_LOG_UPNP D_MULTICAST_JOIN_FAILED));
    }
  }
  return udp_connected;
}

void PollUdp(void)
{
  if (udp_connected) {
    // parsePacket
    while (UdpCtx.next()) {
    // while (PortUdp.parsePacket()) {
      UdpPacket<UDP_BUFFER_SIZE> *packet;

      packet = UdpCtx.read();
      if (packet->len >= UDP_BUFFER_SIZE) {
        packet->len--;    // leave space for NULL terminator
      }
      packet->buf[packet->len] = 0;   // add NULL at the end of the packer
      char * packet_buffer = (char*) &packet->buf;

      AddLog_P2(LOG_LEVEL_DEBUG_MORE, PSTR("UDP: Packet (%d)"), packet->len);
      // AddLog_P2(LOG_LEVEL_DEBUG_MORE, PSTR("\n%s"), packet_buffer);

      // Simple Service Discovery Protocol (SSDP)
      if (Settings.flag2.emulation) {
#if defined(USE_SCRIPT_HUE) || defined(USE_ZIGBEE)
        if (!udp_response_mutex && (strstr_P(packet_buffer, PSTR("M-SEARCH")) != nullptr)) {
#else
        if (devices_present && !udp_response_mutex && (strstr_P(packet_buffer, PSTR("M-SEARCH")) != nullptr)) {
#endif
          udp_response_mutex = true;

          udp_remote_ip = packet->srcaddr;
          udp_remote_port = packet->srcport;

          // AddLog_P2(LOG_LEVEL_DEBUG_MORE, PSTR("UDP: M-SEARCH Packet from %s:%d\n%s"),
          //   udp_remote_ip.toString().c_str(), udp_remote_port, packet_buffer);

          uint32_t response_delay = UDP_MSEARCH_SEND_DELAY + ((millis() &0x7) * 100);  // 1500 - 2200 msec

          LowerCase(packet_buffer, packet_buffer);
          RemoveSpace(packet_buffer);

#ifdef USE_EMULATION_WEMO
          if (EMUL_WEMO == Settings.flag2.emulation) {
            if (strstr_P(packet_buffer, URN_BELKIN_DEVICE) != nullptr) {     // type1 echo dot 2g, echo 1g's
              TickerMSearch.attach_ms(response_delay, WemoRespondToMSearch, 1);
              return;
            }
            else if ((strstr_P(packet_buffer, UPNP_ROOTDEVICE) != nullptr) ||  // type2 Echo 2g (echo & echo plus)
                    (strstr_P(packet_buffer, SSDPSEARCH_ALL) != nullptr) ||
                    (strstr_P(packet_buffer, SSDP_ALL) != nullptr)) {
              TickerMSearch.attach_ms(response_delay, WemoRespondToMSearch, 2);
              return;
            }
          }
#endif  // USE_EMULATION_WEMO

#ifdef USE_EMULATION_HUE
          if (EMUL_HUE == Settings.flag2.emulation) {
            if ((strstr_P(packet_buffer, PSTR(":device:basic:1")) != nullptr) ||
                (strstr_P(packet_buffer, UPNP_ROOTDEVICE) != nullptr) ||
                (strstr_P(packet_buffer, SSDPSEARCH_ALL) != nullptr) ||
                (strstr_P(packet_buffer, SSDP_ALL) != nullptr)) {
              TickerMSearch.attach_ms(response_delay, HueRespondToMSearch);
              return;
            }
          }
#endif  // USE_EMULATION_HUE

          udp_response_mutex = false;
          continue;
        }
      }
    }
    optimistic_yield(100);
  }
}

#endif  // USE_EMULATION
