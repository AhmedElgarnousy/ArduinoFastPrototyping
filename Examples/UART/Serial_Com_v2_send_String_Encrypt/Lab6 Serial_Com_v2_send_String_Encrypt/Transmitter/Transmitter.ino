
char Ref[94] = {'0','1','2','3','4','5','6','7','8','9',
                'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
                'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
                '`','~','!','@','#','$','%','^','&','*','(',')','-','_','+','=','[',']','{','}','|',';',':','"','<','>',
                '/','?','.',',','\'','\\'};

int Encrypt[94] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,
                   36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,
                   69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93};

int button = 13;
String msg = "RUPP_MY002_L1_ON";
String a = "3";

void setup() {
  Serial.begin(9600);
  pinMode(button,INPUT_PULLUP);
}

void encryption(String str) {

  int msgLength = 0;
  int RefLength = 0;
  String dataEncrypt[20];

  //Serial.println(str);
  RefLength = sizeof(Ref);
  msgLength = str.length();

  // Encrypt
  for(int i=0;i<msgLength;i++) {
    for(int j=0;j<RefLength;j++) {
      if(msg[i]==Ref[j]) {
        dataEncrypt[i] = String(Encrypt[j]);
      }
    }
    Serial.print(dataEncrypt[i]);
    delay(30);
  }
}

void loop() {
  if(digitalRead(button)==0) {
    encryption(msg);
  }
}
