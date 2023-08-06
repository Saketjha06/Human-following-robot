//Arduino Human following Robot
//Created by Unomle Robotics
// You have to Install the Adafruit Motor Shield and NewPing library Before Uploading the sketch//
// To install the libraries : Go to Labraries then go to Manage libraries and install the libraries   


#include<NewPing.h>
#include<Servo.h>
#define MR1 2
#define MR2 3
#define ML1 4
#define ML2 5
#define RIGHT A2
#define LEFT A3
#define TRIGGER_PIN A1
#define ECHO_PIN A0
#define MAX_DISTANCE 100
  

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
 


Servo myservo;
 
int pos =0;

void setup() {
  // put your setup code here, to run once:

  delay(15);
}

pinMode(RIGHT, INPUT);
pinMode(LEFT, INPUT);
pinMode(MR1, OUTPUT);
pinMode(MR2, OUTPUT);
pinMode(ML1, OUTPUT);
pinMode(ML2, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  delay(50);
 unsigned int distance = sonar.ping_cm();
Serial.print("distance");
Serial.println(distance);


int Right_Value = digitalRead(RIGHT);
int Left_Value = digitalRead(LEFT);

Serial.print("RIGHT");
Serial.println(Right_Value);
Serial.print("LEFT");
Serial.println(Left_Value);

if((Right_Value==1) && (distance>=10 && distance<=30)&&(Left_Value==1)){
digitalWrite(MR1,HIGH);
digitalWrite(MR2,LOW);
digitalWrite(ML1,HIGH);
digitalWrite(ML2,LOW);

}else if((Right_Value==1)&&(distance>=00) && (Left_Value==0)) {
  digitalWrite(MR1,HIGH);
  digitalWrite(MR2,LOW);
  digitalWrite(ML1,LOW);
  digitalWrite(ML2,LOW);
}else if((Right_Value==0)&&(distance>=00)&& (Left_Value==1)) {
 digitalWrite(MR1,LOW);
digitalWrite(MR2,LOW);
digitalWrite(ML1,HIGH);
digitalWrite(ML2,LOW);
}
else if((Right_Value==1)&&(distance>=50) && (Left_Value==1)) {
 digitalWrite(MR1,LOW);
  digitalWrite(MR2,LOW);
  digitalWrite(ML1,LOW);
  digitalWrite(ML2,LOW);
  
}else if((Right_Value==1)&&(distance==0) && (Left_Value==1)) {
 digitalWrite(MR1,LOW);
  digitalWrite(MR2,LOW);
  digitalWrite(ML1,LOW);
  digitalWrite(ML2,LOW);
  
}
     else if(distance >= 1 && distance <= 10) {
digitalWrite(MR1,LOW);
digitalWrite(MR2,LOW);
digitalWrite(ML1,LOW);
digitalWrite(ML2,LOW );
  }
 }
