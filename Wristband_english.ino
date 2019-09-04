#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10, 11); //RX|TX

int button = 3;
int led = 6;

String input = "";
boolean pressed = false;

void setup() {
  
  //BLUETOOTH SETUP CODE
  Serial.begin(9600);
  BTSerial.begin(9600); // default baud rate
  //while (!Serial); //if it is an Arduino Micro
  pinMode(button, INPUT);
  pinMode(led, OUTPUT);

}

void loop() {

    if(digitalRead(button) == HIGH && !pressed) {
      Serial.print("button Pressed");
      BTSerial.write("light");
      pressed = true;
    }

    if(digitalRead(button) == LOW) {
      pressed = false;
    }
    







    //BLUETOOTH REIVICNING CODE
    if(BTSerial.available()) {
       input = BTSerial.readString();

       if(input == "light") {
          digitalWrite(led, HIGH);
          delay(500);
          digitalWrite(led, LOW);
       }


       
       for(int i = 0; i < input.length(); i++) {
          Serial.write(input[i]);
       }
    } 
    
    
    
  


  }










