
/*

  Puppet Theater NEU
  Art-Net to DMX Converter Unit

  UTAGE / Kazumi Inada @ nandenjin
  https://www.nandenjin.com

*/

#include <UIPEthernet.h>
#include <UIPUdp.h>
#include <SPI.h>

// #include "Artnet.h"
#include "DmxSimpleCustom.h"

#define DMX_OUT_PIN 5

// UDP specific
#define ART_NET_PORT 6454
// Opcodes
#define ART_POLL 0x2000
#define ART_DMX 0x5000
// Buffers
#define MAX_BUFFER_ARTNET 530
// Packet
#define ART_NET_ID "Art-Net\0"
#define ART_DMX_START 18

EthernetUDP Udp;

uint16_t opcode;

void setup() {

  // WARN: You must change this value when you use multiple devices 
  //   with this code on the same network.
  byte mac[] = {0x04, 0xE9, 0xE5, 0x00, 0x69, 0xEC};
  
  Serial.begin( 115200 );
  Serial.println( "SETUP" );
  
  Ethernet.begin( mac );
  Udp.begin(ART_NET_PORT);

  DmxSimple.usePin( DMX_OUT_PIN );
  Serial.println( "DONE" );
  
}

void loop() {
  uint16_t packetSize = Udp.parsePacket();
  uint8_t* dmxBuffer = DmxSimple.getBuffer();

  if (packetSize <= MAX_BUFFER_ARTNET && packetSize > 0)
  {
      Udp.read(dmxBuffer, MAX_BUFFER_ARTNET);

      // Check that packetID is "Art-Net" else ignore
      for (byte i = 0 ; i < 9 ; i++)
      {
        if (dmxBuffer[i] != ART_NET_ID[i])
          return 0;
      }

      opcode = dmxBuffer[8] | dmxBuffer[9] << 8;

      if (opcode == ART_DMX)
      {
//        sequence = dmxBuffer[12];
//        incomingUniverse = dmxBuffer[14] | dmxBuffer[15] << 8;
        uint16_t dmxDataLength = dmxBuffer[17] | dmxBuffer[16] << 8;
//        for (uint16_t i = 0; i < dmxDataLength; i++) {
//          DmxSimple.write( i + 1, artnet.getDmxFrame()[i] );
//        }
      }
      if (opcode == ART_POLL)
      {
        Serial.println( "POLL" );
      }
  }
//  if (r == ART_DMX)
//    for (int i = 0 ; i < artnet.getLength() ; i++)
//        DmxSimple.write( i + 1, artnet.getDmxFrame()[i] );

}
