char blueToothVal;           //value sent over via bluetooth
char lastValue;              //stores last state of device (on/off)
 
void setup()
{
 Serial.begin(9600); 
 pinMode(11,OUTPUT);
}
 
 
void loop()
{

  Serial.println("Press n for on and f for off");
  if(Serial.availableForWrite()>0)
  {//if there is data being recieved
    blueToothVal=Serial.read(); //read it
  }
  if (blueToothVal=='1')
  {//if value from bluetooth serial is n
    digitalWrite(11,HIGH);            //switch on LED
    if (lastValue!='1')
      Serial.println(F("LED is on")); //print LED is on
    lastValue=blueToothVal;
  }
  else if (blueToothVal=='0')
  {//if value from bluetooth serial is n
    digitalWrite(11,LOW);             //turn off LED
    if (lastValue!='0')
      Serial.println(F("LED is off")); //print LED is on
    lastValue=blueToothVal;
  }
  delay(1000);
}
 
