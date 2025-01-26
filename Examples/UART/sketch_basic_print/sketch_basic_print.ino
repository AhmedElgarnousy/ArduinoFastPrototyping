void setup(){
  Serial1.begin(9600); //initialize serial communication at a 9600 baud rate
}

void loop(){
  Serial1.println("USBTLL");
  delay(1000);
}
