const int button1 = 4;
int buttonState =0;
const int relay1 = 8;
int currentMode = 0;


void setup() {
  pinMode(button1, INPUT);
  pinMode(relay1,OUTPUT);
  Serial.begin(9600);
  digitalWrite(relay1,HIGH);
 
}

void loop() {
  buttonState = digitalRead(button1);
 

  if ((buttonState ==HIGH) && (currentMode != 1)){
    delay(500);
    lightOn();
    currentMode = 1;
  }
  else if ((buttonState ==HIGH) && (currentMode ==1)) {
    delay(500);
    lightOff();
    currentMode =2;
  }
}

void lightOn(){
  digitalWrite(relay1, LOW);
  Serial.println("Light is on");
  
  
}

void lightOff(){
  digitalWrite(relay1, HIGH);
  Serial.println("Light is off");
  
}

