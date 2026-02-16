#define Ref '_'
char Index[94] = {'0','1','2','3','4','5','6','7','8','9',
                'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
                'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
                '`','~','!','@','#','$','%','^','&','*','(',')','-','_','+','=','[',']','{','}','|',';',':','"','<','>',
                '/','?','.',',','\'','\\'};

int Encrypt[94] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,
                   36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,
                   69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93};

String msg[20];
String data[20];
String dataDecrypt;

int button = 13;
int i = 0;

void setup() {
  pinMode(button,INPUT_PULLUP);
  Serial.begin(9600);
  Serial.setTimeout(3);
}

void AnalyseMsg(String msg) {
  
  int msgLength = 0;      // Total of Message length
  int cnt = 0;            // Count Reference number
  int refLocate[10] = {0};  // Location of the Reference in the message
  int x = 0;              // Variable for helping arrange the msg
  int y = 0;              // Variable for helping arrange the msg
  msgLength = msg.length() - 1;

  for(int i=0;i<msgLength+1;i++) {
    if(Ref == msg[i]) {
      cnt++;
      refLocate[cnt] = i;
    }
  }
  //Serial.println(cnt); 
  refLocate[cnt+1] = msgLength;
  for(int j=0;j<cnt+1;j++) {
    if(refLocate[j+1] == msgLength) {
      y = 1;
    }
    for(int i=refLocate[j]+x;i<refLocate[j+1]+y;i++) {
      data[j] += msg[i];
    }
    Serial.println(data[j]);
    x = 1;
  }
  // Clear data
  for(int i=0;i<cnt+2;i++) {
    data[i] = "";
  }
}

void decryption() {
  for(int j=0;j<i;j++) {
    dataDecrypt += Index[msg[j].toInt()];
  }
  //Serial.println(dataDecrypt);
  AnalyseMsg(dataDecrypt);
  dataDecrypt = "";
  i = 0;
}

void Readmsg() {
  if(Serial.available()) {
    msg[i] = Serial.readString();
    //Serial.println(msg[i]);   
    i++;
  }
}

void loop() {
  Readmsg();
  if(digitalRead(button) == 0) {
    decryption();
    delay(200);
  }
}
