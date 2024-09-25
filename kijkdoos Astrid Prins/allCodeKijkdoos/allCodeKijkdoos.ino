// Include the servo library:
#include "Servo.h"
#define SERVO_NUM 7

//create a new servo object 
Servo servoArray[SERVO_NUM]; //create array of servo object

//connect pin to led
int LED_PIN = 4;

#define laser 2

// Ldr
int LDR_In = 5;
int lichtHoeveelheid[9];
int LDR_ON;
int sum = 0;

bool on;
bool test;

void setup() {
  //start serial monitor
  Serial.begin(115200);

 //servo
  // attach the servo variable to a pin:
  servoArray[1].attach(9);
  servoArray[2].attach(10);
  servoArray[3].attach(11);
  servoArray[4].attach(8);
  servoArray[5].attach(12);
  servoArray[6].attach(13);

  
  //LED
  //set pin output mode
  pinMode(LED_PIN, OUTPUT);

  //laser
  pinMode(laser, OUTPUT);
  digitalWrite(laser, HIGH);

  pinMode(LDR_In, INPUT);
  on = digitalRead(LDR_In);
  // 0=on 1=off
  
}

void loop() {
    bool value = digitalRead(LDR_In);
    Serial.println(value);
    if(on != value){
      delay(50);
      if(value == 0){
      //first position Servo's
      for(int i = 0; i < 6; i++){
        servoArray[i].write(90);
      }
      digitalWrite(LED_PIN, LOW);
      Serial.println("laser connected");
    }
    if(value == 1){
      for(int i = 0; i < 6; i++){
        int random_Number = random(0,14);
        Serial.println(random_Number);
        servoArray[random_Number].write(0);
      } 
      digitalWrite(LED_PIN, HIGH);
      Serial.println("loop end"); 
    }
    on = value;
    }
    

    // digital read ldr (kan je aanpassen wanneer het de lichtsterkte wel als uit ziet?)
    
    
   
 
  
  
/*
  LDR_ON = (lichtHoeveelheid[1] + lichtHoeveelheid[2] + lichtHoeveelheid[3] + lichtHoeveelheid[4] + lichtHoeveelheid[5] + lichtHoeveelheid[6] + lichtHoeveelheid[7] + lichtHoeveelheid[8] + lichtHoeveelheid[9] + lichtHoeveelheid[10]) / 10;
  if(lichtHoeveelheid < 300){
      //Turn off led
      for(int i = 0; i < ledInArray[i]; i++){
        digitalWrite(ledInArray[i], LOW);
      }
    //first position Servo's
      for(int i = 0; i < 6; i++){
        servoArray[i].write(90);
      }
  }
  else{
    for(int i = 0; i < 3; i++){
        //random LED  
         int randomNumber = random(0,4);
         Serial.println("Led lamp " + randomNumber);
         digitalWrite(ledInArray[randomNumber], HIGH);
      }
      //random Servo
      for(int i = 0; i < 6; i++){
        int random_Number = random(0,14);
        Serial.println("Servo :" + random_Number);
        servoArray[random_Number].write(0);
      }     
  }

  for(int i = 0; i < 3; i++){
        //random LED  
         int randomNumber = random(0,4);
         Serial.println("Led lamp " + randomNumber);
         digitalWrite(ledInArray[randomNumber], HIGH);
      }
      //Turn off led
      for(int i = 0; i < ledInArray[i]; i++){
        digitalWrite(ledInArray[i], LOW);
      }
  


  bool value = digitalRead(sensor);

  if(on != value){
    delay(50); // debounce time

    if(value == 0){
      //first position Servo's
      for(int i = 0; i < 6; i++){
        servoArray[i].write(90);
      }
      Serial.println("laser connected");
    }
    if(value == 1){
      for(int i = 0; i < 6; i++){
        int random_Number = random(0,14);
        Serial.println(random_Number);
        servoArray[random_Number].write(0);
      } 
      Serial.println("loop end"); 
    }
    on = value;
  }
  */
}
