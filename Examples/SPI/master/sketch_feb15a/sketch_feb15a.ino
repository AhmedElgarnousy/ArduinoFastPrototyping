#include <SPI.h>

#define SlaveS 9
void setup() {
  SPI.begin();             // Initialize SPI bus
  SPI.setClockDivider(SPI_CLOCK_DIV128);  // Slower clock for testing
//  SPI.beginTransaction(4000000, LSBFIRST, SPI_MODE0);
  Serial.println("Mega2560 Master Started!");
  pinMode(SlaveS, OUTPUT);     // Set SS pin as output
  digitalWrite(SlaveS, HIGH);  // Deselect slave initially
  Serial.begin(9600);      // For debug (optional)
}
char Message[]="hello SPI";
void loop() {
  digitalWrite(SlaveS, LOW);  
  char received; // Select slave
  for(int i= 0; i < sizeof(Message); i++)
  {
      received = SPI.transfer(Message[i]);  // Send 0x80 and read response
      Serial.print("Master Mega Sent: ");
        Serial.println(received);  // Print slave's response
  }
  digitalWrite(SlaveS, HIGH);              // Deselect slave

  Serial.print("Master Mega Sent: message | Received: 0x");
  Serial.println(received, DEC);  // Print slave's response

  delay(2000);  // Wait 1 second
}
