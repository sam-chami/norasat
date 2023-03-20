//
// Cansat
// GNU GPL license - Samuel M - IES Rio Nora
//

#include <SPI.h>
#include <Adafruit_BMP280.h>
#include <RH_RF69.h>
#include <RHReliableDatagram.h>

// RDM69 declarations (for arduino uno)
#define RFM69_INT     3
#define RFM69_CS      4
#define RFM69_RST     2

#define RF69_FREQ 434.0

#define DEST_ADDRESS   1
#define MY_ADDRESS     0

Adafruit_BMP280 bmp;

RH_RF69 rf69(RFM69_CS, RFM69_INT);
RHReliableDatagram rf69_manager(rf69, MY_ADDRESS);

int16_t packetnum = 0;
uint8_t buf[RH_RF69_MAX_MESSAGE_LEN];
uint8_t data[] = "  OK";

void sendPacket (char* radiopacket) {
  itoa(packetnum++, radiopacket+13, 10);
  Serial.print("Sending "); Serial.println(radiopacket);
  
  // Send a message to the DESTINATION!
  if (rf69_manager.sendtoWait((uint8_t *)radiopacket, strlen(radiopacket), DEST_ADDRESS)) {
    // Now wait for a reply from the server
    uint8_t len = sizeof(buf);
    uint8_t from;   
    if (rf69_manager.recvfromAckTimeout(buf, &len, 2000, &from)) {
      buf[len] = 0; // zero out remaining string
      
      Serial.print("Got reply from #"); Serial.print(from);
      Serial.print(" [RSSI :");
      Serial.print(rf69.lastRssi());
      Serial.print("] : ");
      Serial.println((char*)buf);     
    } else {
      Serial.println("No reply, is anyone listening?");
    }
  } else {
    Serial.println("Sending failed (no ack)");
  }
}

void setup() {
  Serial.begin(9600);

  pinMode(RFM69_RST, OUTPUT);
  digitalWrite(RFM69_RST, LOW);
  
  unsigned bmp_status;
  bmp_status = bmp.begin();
  if (!bmp_status) {
    Serial.println("BMP280 Error");
  }
  if (!rf69_manager.init()) {
    Serial.println("RFM69 Error");
    while (1); 
  }

  /* Default settings from datasheet. */
  bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,     /* Operating Mode. */
                  Adafruit_BMP280::SAMPLING_X2,     /* Temp. oversampling */
                  Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling */
                  Adafruit_BMP280::FILTER_X16,      /* Filtering. */
                  Adafruit_BMP280::STANDBY_MS_500); /* Standby time. */
  
  rf69.setTxPower(20, true);

  uint8_t key[] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
  rf69.setEncryptionKey(key);

  Serial.print("RFM69 radio @");  Serial.print((int)RF69_FREQ);  Serial.println(" MHz");
}

void loop() {
  char temp[5];
  char pressure[8];

  // Convert numbers to characters, while keeping decimals
  dtostrf(bmp.readTemperature(), 3, 2, temp); 
  dtostrf(bmp.readPressure(), 6, 2, pressure);

  // Concatenate the values into one packet
  char* packet;
  //packet = malloc(strlen(temp)+1+strlen(pressure));
  
  strcpy(packet, temp);
  strcat(packet, ";"); // separator
  strcat(packet, pressure);

  // Debug purposes
    Serial.println(packet);
    Serial.println();

  // Finally, send the packet
  sendPacket(packet);

  // We dont need these values, so to avoid memory leaks:
  free(temp);
  free(pressure);
  free(packet);
  // we free them
  
  delay(250);
}
