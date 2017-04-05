

#define relay1 8 // red light
#define relay2 9  // amber light
#define relay3 11   // green light 
const int button1 = 2;     //  bin present sensor at pick face 
const int button2 = 3;  //   bin present at behind pick face
const int button3 = 4;  // bin present at return station (water spider collects)
const int button4 = 5;   //bin error sensor; WRONG bin loaded to S2
                   
// variables will change:
int buttonState1 = 0;         // variable for reading the pushbutton 1
int buttonState2 = 0;         // variable for reading the pushbutton 2
int buttonState3 =0;           // variable for reading the pushbutton 3
int buttonState4 =0;          //variable for reading the pushbutton 4

int prevstate = 0;

void setup()

{    

// Initialise the Arduino data pins for OUTPUT
      
  pinMode(relay1, OUTPUT); // setting all relays as pinouts red
  pinMode(relay2, OUTPUT); // amber
  pinMode(relay3, OUTPUT);  // green

  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3,INPUT);
  pinMode(button4, INPUT);

  Serial.begin(9600);
  
  
}

 

 void loop()

{
   // read the state of the pushbutton value:
 

//message to the receiving device

  
  buttonState1 = digitalRead(button1);
  buttonState2 = digitalRead(button2);
  buttonState3 = digitalRead(button3);
  buttonState4 = digitalRead(button4);
  
  if( (buttonState1 ==HIGH) && (buttonState2 == HIGH) && (buttonState3 == LOW) && (buttonState4 == LOW)) {
    // STATE 1 bins present
    
    Serial.println("Both bins present");
    
    
    //delay(500); 
    
    digitalWrite(relay3, HIGH);           // Turns ON green
    delay(1000);
    digitalWrite(relay3,LOW);
    prevstate=0;
    
  } 
  else if( (buttonState1 == LOW) && (buttonState2 == HIGH) && (buttonState3 == LOW) && (buttonState4 ==LOW)){
    //STATE 2 bin triggered 
    Serial.println("Bin Triggered");
    //delay(500);

    digitalWrite(relay2, HIGH);           // Turns ON amber and red
    digitalWrite(relay1, HIGH);
    delay(1000);
    digitalWrite(relay2,LOW);
    digitalWrite(relay1, LOW);
    prevstate=0;
    
    
 }

  else if( (buttonState1 == HIGH) && (buttonState2 == LOW) && (buttonState3 == HIGH) && (buttonState4 ==LOW)){
    //STATE 3 Karakuri cycle
    
    Serial.println("Karakuri Cycle");
    //delay(500);

    digitalWrite(relay2, HIGH);           // Turns ON amber and red
    digitalWrite(relay1, HIGH);
    delay(1000);
    digitalWrite(relay2,LOW);
    digitalWrite(relay1, LOW);
    prevstate = 1;
  }

  else if ((buttonState1 == HIGH) && (buttonState2 == LOW) && (buttonState3 == LOW) && (buttonState4 ==LOW)){
    // STATE 4 Progress

    Serial.println("Progress");
    //delay(500); 
    
    digitalWrite(relay2, HIGH);           // Turns ON amber
    delay(1000);
    digitalWrite(relay2,LOW);
    prevstate = 1;
    
  }

  else if ((buttonState1 == LOW) && (buttonState2 == LOW) && (buttonState4 ==LOW) && (prevstate == 1)){
    // STATE 5 Stock out 

    Serial.println("Stock out");
    //delay(500); 
    
    digitalWrite(relay1, HIGH);           // Turns ON red
    delay(1000);
    digitalWrite(relay1,LOW);
    prevstate = 1;
    
  } 

  else if ((buttonState1 == HIGH) && (buttonState2 == HIGH) && (buttonState4 ==HIGH )){
    // STATE 6 Wrong bin

    Serial.println("Wrong bin");
    //delay(500); 
    
    digitalWrite(relay1, HIGH);           // Turns ON red
    delay(1000);
    digitalWrite(relay1,LOW);
    
    
  }

  else if ((buttonState1 == LOW) && (buttonState2 == LOW) && (buttonState3 == LOW) && (buttonState4 ==HIGH)){
    // STATE 7 Out; Wrong bin

    Serial.println("Out; Wrong bin");
    //delay(500); 
    
    digitalWrite(relay1, HIGH);           // Turns ON red
    delay(1000);
    digitalWrite(relay1,LOW);
    prevstate = 1;
    
  }

  else{
    digitalWrite(relay1,LOW);
    digitalWrite(relay2,LOW);
    digitalWrite(relay3,LOW);

  }
 }
