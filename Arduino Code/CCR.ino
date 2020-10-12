#include <Servo.h>
Servo servo1;

const int stepPin1 = 3; 
const int dirPin1 = 4; 
const int stepPin2 = 5; 
const int dirPin2 = 6;
const int limitPin1 = 2;
const int limitPin2 = 7; 
int Steppe_Speed = 1500;

// in cm

int a1 = 10;
int b1 = 10;

int a2 = 4;
int b2 = 2;

int a3 = 4;
int b3 = 2;

int a4 = 2;
int b4 = 4;


void setup() {
servo1.attach(A0);
pinMode(stepPin1,OUTPUT); 
pinMode(dirPin1,OUTPUT);
pinMode(stepPin2,OUTPUT); 
pinMode(dirPin2,OUTPUT);
pinMode(limitPin2,INPUT);
pinMode(limitPin1,INPUT);
}

void loop() {
stepper2_caliberation();
delay(1000);
stepper1_caliberation();
delay(3000);
stepper1_2_forward();
delay(1000);
stepper1_forward_2_reverse();
delay(1000);
stepper1_2_reverse();
delay(1000);
stepper1_reverse_2_forward();
delay(1000);
Up();
//delay(1000);
Down();
//delay(1000);
delay(10000);
}

//33.615013mm peri of pulley, 0.168075065mm step length, 59.49722524278066 steps=1cm

void Up(){
  for (int i=15; i<=65; i++){
  servo1.write(i);
  delay(20);
  
  }
}
void Down(){
  for (int i=65; i>=15 ; i--){
    servo1.write(i);
    delay(20);
    }
}

void stepper2_caliberation(){
   digitalWrite(dirPin2,HIGH); 
   for(int c = 0; digitalRead(limitPin2) == HIGH; c++){
      digitalWrite(stepPin2,HIGH);
      delayMicroseconds(3000);
      digitalWrite(stepPin2,LOW);
      delayMicroseconds(3000); 
}
delay(500);
   digitalWrite(dirPin2,LOW); 
   for(int c = 0; c < 50 ; c++){
      digitalWrite(stepPin2,HIGH);
      delayMicroseconds(1500);
      digitalWrite(stepPin2,LOW);
      delayMicroseconds(1500); 
}
}

void stepper1_caliberation(){
   digitalWrite(dirPin1,LOW); 
   for(int c = 0; digitalRead(limitPin1) == HIGH; c++){
      digitalWrite(stepPin1,HIGH);
      delayMicroseconds(1500);
      digitalWrite(stepPin1,LOW);
      delayMicroseconds(1500);
}
delay(500);
   digitalWrite(dirPin1,HIGH); 
   for(int c = 0; c < 50 ; c++){
      digitalWrite(stepPin1,HIGH);
      delayMicroseconds(1500);
      digitalWrite(stepPin1,LOW);
      delayMicroseconds(1500);
}
}



void stepper1_2_forward(){

  int a = 59.49722524278066*a1;
 int b = 59.49722524278066*b1;

  if(a >= b) {
    digitalWrite(dirPin1,HIGH); 
    digitalWrite(dirPin2,LOW);
    for(int y = 0; y < b; y++) {
      digitalWrite(stepPin1,HIGH); 
      digitalWrite(stepPin2,HIGH); 
      delayMicroseconds(Steppe_Speed); 
      digitalWrite(stepPin1,LOW);
      digitalWrite(stepPin2,LOW);  
      delayMicroseconds(Steppe_Speed);
      }
  digitalWrite(dirPin1,HIGH);
  for(int y = 0; y < a-b; y++){
    digitalWrite(stepPin1,HIGH); 
    delayMicroseconds(Steppe_Speed); 
    digitalWrite(stepPin1,LOW);  
    delayMicroseconds(Steppe_Speed);
    }
  } else if (b > a){ 
    {
      digitalWrite(dirPin1,HIGH); 
      digitalWrite(dirPin2,LOW);
      for(int y = 0; y < a; y++) {
        digitalWrite(stepPin1,HIGH); 
        digitalWrite(stepPin2,HIGH); 
        delayMicroseconds(Steppe_Speed); 
        digitalWrite(stepPin1,LOW);
        digitalWrite(stepPin2,LOW);  
        delayMicroseconds(Steppe_Speed);
        }
    }
    {
      digitalWrite(dirPin2,LOW);
      for(int y = 0; y < b-a; y++){
        digitalWrite(stepPin2,HIGH); 
        delayMicroseconds(Steppe_Speed); 
        digitalWrite(stepPin2,LOW);  
        delayMicroseconds(Steppe_Speed);
        }
     }
   }
}


void stepper1_2_reverse(){
int a = 59.49722524278066*a2;
int b = 59.49722524278066*b2;
  if(a >= b) {
    digitalWrite(dirPin1,LOW); 
    digitalWrite(dirPin2,HIGH);
    for(int y = 0; y < b; y++) {
      digitalWrite(stepPin1,HIGH); 
      digitalWrite(stepPin2,HIGH); 
      delayMicroseconds(Steppe_Speed); 
      digitalWrite(stepPin1,LOW);
      digitalWrite(stepPin2,LOW);  
      delayMicroseconds(Steppe_Speed);
      }
  digitalWrite(dirPin1,LOW);
  for(int y = 0; y < a-b; y++){
    digitalWrite(stepPin1,HIGH); 
    delayMicroseconds(Steppe_Speed); 
    digitalWrite(stepPin1,LOW);  
    delayMicroseconds(Steppe_Speed);
    }
  } else if (b > a){ 
    {
      digitalWrite(dirPin1,LOW); 
      digitalWrite(dirPin2,HIGH);
      for(int y = 0; y < a; y++) {
        digitalWrite(stepPin1,HIGH); 
        digitalWrite(stepPin2,HIGH); 
        delayMicroseconds(Steppe_Speed); 
        digitalWrite(stepPin1,LOW);
        digitalWrite(stepPin2,LOW);  
        delayMicroseconds(Steppe_Speed);
        }
    }
    {
      digitalWrite(dirPin2,HIGH);
      for(int y = 0; y < b-a; y++){
        digitalWrite(stepPin2,HIGH); 
        delayMicroseconds(Steppe_Speed); 
        digitalWrite(stepPin2,LOW);  
        delayMicroseconds(Steppe_Speed);
        }
     }
   }
}


void stepper1_forward_2_reverse(){
int a = 59.49722524278066*a3;
int b = 59.49722524278066*b3;  
  if(a >= b) {
    digitalWrite(dirPin1,HIGH); 
    digitalWrite(dirPin2,HIGH);
    for(int y = 0; y < b; y++) {
      digitalWrite(stepPin1,HIGH); 
      digitalWrite(stepPin2,HIGH); 
      delayMicroseconds(Steppe_Speed); 
      digitalWrite(stepPin1,LOW);
      digitalWrite(stepPin2,LOW);  
      delayMicroseconds(Steppe_Speed);
      }
  digitalWrite(dirPin1,HIGH);
  for(int y = 0; y < a-b; y++){
    digitalWrite(stepPin1,HIGH); 
    delayMicroseconds(Steppe_Speed); 
    digitalWrite(stepPin1,LOW);  
    delayMicroseconds(Steppe_Speed);
    }
  } else if (b > a){ 
    {
      digitalWrite(dirPin1,HIGH); 
      digitalWrite(dirPin2,HIGH);
      for(int y = 0; y < a; y++) {
        digitalWrite(stepPin1,HIGH); 
        digitalWrite(stepPin2,HIGH); 
        delayMicroseconds(Steppe_Speed); 
        digitalWrite(stepPin1,LOW);
        digitalWrite(stepPin2,LOW);  
        delayMicroseconds(Steppe_Speed);
        }
    }
    {
      digitalWrite(dirPin2,HIGH);
      for(int y = 0; y < b-a; y++){
        digitalWrite(stepPin2,HIGH); 
        delayMicroseconds(Steppe_Speed); 
        digitalWrite(stepPin2,LOW);  
        delayMicroseconds(Steppe_Speed);
        }
     }
   }
}

  void stepper1_reverse_2_forward(){
int a = 59.49722524278066*a4;
int b = 59.49722524278066*b4;
  if(a >= b) {
    digitalWrite(dirPin1,LOW); 
    digitalWrite(dirPin2,LOW);
    for(int y = 0; y < b; y++) {
      digitalWrite(stepPin1,HIGH); 
      digitalWrite(stepPin2,HIGH); 
      delayMicroseconds(Steppe_Speed); 
      digitalWrite(stepPin1,LOW);
      digitalWrite(stepPin2,LOW);  
      delayMicroseconds(Steppe_Speed);
      }
  digitalWrite(dirPin1,LOW);
  for(int y = 0; y < a-b; y++){
    digitalWrite(stepPin1,HIGH); 
    delayMicroseconds(Steppe_Speed); 
    digitalWrite(stepPin1,LOW);  
    delayMicroseconds(Steppe_Speed);
    }
  } else if (b > a){ 
    {
      digitalWrite(dirPin1,LOW); 
      digitalWrite(dirPin2,LOW);
      for(int y = 0; y < a; y++) {
        digitalWrite(stepPin1,HIGH); 
        digitalWrite(stepPin2,HIGH); 
        delayMicroseconds(Steppe_Speed); 
        digitalWrite(stepPin1,LOW);
        digitalWrite(stepPin2,LOW);  
        delayMicroseconds(Steppe_Speed);
        }
    }
    {
      digitalWrite(dirPin2,LOW);
      for(int y = 0; y < b-a; y++){
        digitalWrite(stepPin2,HIGH); 
        delayMicroseconds(Steppe_Speed); 
        digitalWrite(stepPin2,LOW);  
        delayMicroseconds(Steppe_Speed);
        }
     }
   }
}
