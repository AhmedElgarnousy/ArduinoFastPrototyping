// Receiver Node: UNO R3

String receivedMessage;

void setup() {
  Serial.begin(9600);    // Initialize the Serial monitor for debugging AND receiving
}

void loop() {
  while (Serial.available() > 0) {
    char receivedChar = Serial.read();
    if (receivedChar == '\n') {
      Serial.print("UNO Receive:");
      Serial.println(receivedMessage);  // Print the received message in the Serial monitor
      receivedMessage = "";  // Reset the received message
    } else {
      receivedMessage += receivedChar;  // Append characters to the received message
    }
  }
}
