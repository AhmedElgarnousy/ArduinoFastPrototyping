#include <SPI.h>

volatile char receivedData;

void setup() {
  Serial.begin(9600);
  Serial.println("Uno Slave Started!");
//  pinMode(SS, INPUT_PULLUP);       // Pin 10 MUST be INPUT for slave mode!
  pinMode(MISO, OUTPUT);    // Set MISO as output (Slave)
  SPCR |= (1 << SPE);       // Enable SPI (Slave mode)
  SPCR |= (1 << SPIE);      // Enable SPI Interrupt
}

ISR(SPI_STC_vect) {        // SPI Interrupt Service Routine
  receivedData = SPDR;      // Store received byte
  Serial.print("Received: ");
  if (receivedData < 0x10) 
    Serial.print("0"); // Pad single digit hex
  Serial.println(receivedData);

  // Serial.println(receivedData, DEC); // Print in HEX
}

void loop() {
  // Do nothing (SPI runs via interrupt)
}
