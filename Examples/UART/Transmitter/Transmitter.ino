// Transmitter Node: MEGA 2560 

String sendMessage;
String receivedMessage;

void setup() {
  Serial.begin(9600);    // Initialize the Serial monitor for debugging
  Serial1.begin(9600);   // Initialize Serial1 for sending data
}

void loop() {
  while (Serial.available() > 0) {
   char receivedChar = Serial.read();
//   if(receivedChar == '\n')
//   {
       Serial1.println(receivedChar);  // Send the message through Serial1 with a newline character
//    receivedMessage = "";
//   }
//   else
//   {
//    receivedMessage+=receivedChar;
//    }
  }
}
