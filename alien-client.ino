
/*

  Puppet Theater NEU
  Art-Net to DMX Converter Unit

  UTAGE / Kazumi Inada @ nandenjin
  https://www.nandenjin.com

*/

#include <UIPEthernet.h>
#include <UIPUdp.h>
#include <SPI.h>

#include "Artnet.h"
#include "DmxSimple.h"

#define DMX_OUT_PIN 5

Artnet artnet;

void setup() {

  // WARN: You must change this value when you use multiple devices 
  //   with this code on the same network.
  byte mac[] = {0x04, 0xE9, 0xE5, 0x00, 0x69, 0xEC};
  
  Serial.begin( 115200 );
  Serial.println( "SETUP" );
  
  Ethernet.begin( mac );
  artnet.begin();

  DmxSimple.usePin( DMX_OUT_PIN );
  Serial.println( "DONE" );
  
}

void loop() {
  
  uint16_t r = artnet.read();
  
  if(r == ART_POLL)
    Serial.println( "POLL" );
  
  if (r == ART_DMX)
    for (int i = 0 ; i < artnet.getLength() ; i++)
        DmxSimple.write( i + 1, artnet.getDmxFrame()[i] );

}

