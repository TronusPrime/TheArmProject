
//#include <SoftwareSerial.h>;
#include <Servo.h>

Servo elbow, fingers, wrist;
//int sun = analogRead(A1);
//const int timeInterval = 7000;
//const int timeInterval2 = 2000;
//const int timeInterval3 = 3000;
//int threshold = 80;
int pos = 130;
int linearValue = 1000;
int basic = 0;
int fulcrum = 3;
int x=0;
int servoDegrees=2;
int servoInterval = 80;
int val; // Data received from the serial port
int bluePin = 6;
int yellowPin2 = 7;
 int redPin = 11; // Set the pin to digital I/O 4
 int yellowPin = 12;
 int greenPin = 13;
unsigned long currentMillis = 0;    // stores the value of millis() in each iteration of loop()
unsigned long previousServoMillis = 0; // the time when the servo was last moved
unsigned long currentMillis2 = 0;
unsigned long previousServoMillis2 = 0;
int servoInterval2 = 30;
int servoDegrees2 = 3;
 //SoftwareSerial soft(10,11);
 void setup() {
  
 pinMode(redPin, OUTPUT); // Set pin as OUTPUT
 pinMode(yellowPin2, OUTPUT);
  pinMode(yellowPin, OUTPUT);
   pinMode(greenPin, OUTPUT);
 //soft.begin(57600);
 elbow.attach(9);
fingers.attach(8, 1050, 2000);
wrist.attach(2);
  wrist.write(35);
  elbow.write(100);
  fingers.writeMicroseconds(linearValue);
 Serial.begin(9600); // Start serial communication at 9600 bps
 }
 void(* resetFunc) (void) = 0; //declare reset function @ address 0
 void loop() {
// currentMillis = millis();
 // sun = analogRead(A1);
 if(Serial.available()){
  //Serial.println(sun);//
   val = Serial.read(); // read it and store it in val
   //Serial.write(val);
  //Serial.println(val); 
   if(val>=0 && val < 45){ // if EEG attention signal is less than 60, dont move arm. 
    digitalWrite(greenPin, LOW);
    digitalWrite(yellowPin,LOW);
   digitalWrite(redPin,HIGH);
  //soft.println(val);
   }else if( val>=45 && val<60){ // if EEG is less than 60, do not move arm
        digitalWrite(greenPin, LOW);
       digitalWrite(redPin,LOW);
   digitalWrite(yellowPin,HIGH);

   }else if(val>=60){ // if EEG attention values are greater than 60, turn on arm 
           digitalWrite(redPin,LOW);
       digitalWrite(yellowPin,LOW);
          digitalWrite(greenPin,HIGH);
          x=1;
   }
     // this is similar to the servo sweep example except that it uses millis() rather than delay()

 
     // nothing happens unless the interval has expired
           if(x==1){
  currentMillis = millis();
int sensorValue = analogRead(A1);
 if (currentMillis - previousServoMillis >= servoInterval) {
       // its time for another move
   previousServoMillis += servoInterval;
   
   pos = pos + servoDegrees; // servoDegrees might be negative


   if ((pos >= 130) || (pos <= 0))  {
         // if the servo is at either extreme change the sign of the degrees to make it move the other way
     servoDegrees = - servoDegrees; // reverse direction
         // and update the position to ensure it is within range
     pos += servoDegrees;        // make the servo move to the next position

   }
   
   if(sensorValue>500){ // Used a muscle sensor with electrodes attached to eye muscles. When a forceful blink is detected, the elbow servo will lock into position.
elbow.detach(); 
  }
 elbow.write(pos);
 }
  // currentMillis = millis();
  /*& // fingers.attach(8,1050,2000);
    int sensor = analogRead(A2);
          for(linearValue= 1000; linearValue<=2100; linearValue +=2){
        fingers.writeMicroseconds(linearValue);
        if(sensor >=500){
          fingers.detach();
        }
      }
    for(linearValue=2100; linearValue >= 1000; linearValue-=2){
      fingers.writeMicroseconds(linearValue);
      if(sensor >=500){
        fingers.detach();
      }

    }
  }
    }
    }
  
  
    */
   currentMillis2 = millis();
int sensorValue2 = analogRead(A2);
 if (currentMillis2 - previousServoMillis2 >= servoInterval2) {
       // its time for another move
   previousServoMillis2 += servoInterval2;
   
   linearValue= linearValue + servoDegrees2; // servoDegrees might be negative


   if ((linearValue >= 2100) || (linearValue <= 1000))  {
         // if the servo is at either extreme change the sign of the degrees to make it move the other way
     servoDegrees2 = - servoDegrees2; // reverse direction
         // and update the position to ensure it is within range
     linearValue += servoDegrees2;
   }
       // make the servo move to the next position
   
//   if(sensorValue2>500){
   // fingers.detach();
 //  x=3;
       // and record the time when the move happened
 //}
    fingers.writeMicroseconds(linearValue);              // tell servo to go to linearValueition in variable 'linearValue'
 }
 }
 }
  }
/* if(x==1){
  currentMillis = millis();
int sensorValue = analogRead(A1);
 if (currentMillis - previousServoMillis >= servoInterval) {
       // its time for another move
   previousServoMillis += servoInterval;
   
   pos = pos + servoDegrees; // servoDegrees might be negative


   if ((pos >= 100) || (pos <= 0))  {
         // if the servo is at either extreme change the sign of the degrees to make it move the other way
     servoDegrees = - servoDegrees; // reverse direction
         // and update the position to ensure it is within range
     pos += servoDegrees;
   }
       // make the servo move to the next position
   
   if(sensorValue>500){
    elbow.detach();
    x=2;
       // and record the time when the move happened
 }
 elbow.write(pos);
 } 
 }
     }
 }
/* case 2:
 if(x==2){
    currentMillis2 = millis();
int sensorValue2 = analogRead(A0);
 if (currentMillis2 - previousServoMillis2 >= servoInterval2) {
       // its time for another move
   previousServoMillis2 += servoInterval2;
   
   linearValue= linearValue + servoDegrees2; // servoDegrees might be negative


   if ((linearValue >= 2100) || (linearValue <= 1000))  {
         // if the servo is at either extreme change the sign of the degrees to make it move the other way
     servoDegrees2 = - servoDegrees2; // reverse direction
         // and update the position to ensure it is within range
     linearValue += servoDegrees2;
   }
       // make the servo move to the next position
   
   if(sensorValue2>500){
    fingers.detach();
   x=3;
       // and record the time when the move happened
 }
    fingers.writeMicroseconds(linearValue);              // tell servo to go to linearValueition in variable 'linearValue'
 }
  x=3;
  
 }
 }
 }
 }/*else if(x==2){
    currentMillis = millis();
sensorValue = analogRead(A1);
   for (linearValue = 1000; linearValue <= 2100; linearValue += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    fingers.writeMicroseconds(linearValue);              // tell servo to go to linearValueition in variable 'linearValue'
    delay(1);                       // waits 15ms for the servo to reach the linearValueition
  }
  for (linearValue = 2100; linearValue >= 0; linearValue -= 1) { // goes from 180 degrees to 0 degrees
    fingers.writeMicroseconds(linearValue);              // tell servo to go to linearValueition in variable 'linearValue'
 delay(1);                       // waits 15ms for the servo to reach the linearValueition
  }
  x=3;
  }                       // waits 15ms for the servo to reach the linearValueition
 
x=3;
 }
 }
 //x=2;
//=====END
//        sensorValue = analogRead(A1); 
//  if(x==1){
//  //digitalWrite(bluePin,HIGH);
//    for(pos = 100; pos >= 0; pos-=1){
//      elbow.write(pos);
//      delay(100);
//     if(sensorValue>500){
//          digitalWrite(7, HIGH);
//          break;
//        elbow.detach();
//        x=2;
//      } 
//    }
// 
//      for(pos = 0; pos <= 100; pos+=1){
//      elbow.write(pos);
//      delay(100);
//     if(sensorValue>500){
//       elbow.detach();
//       x=2;
//      } 
//      }
//       x=2;
//  }
/*  case 2:
        sensorValue = analogRead(A1); 

  if(x==2){


case 3:
      sensorValue = analogRead(A1); 

if(x==3){
  for (pos = 0; pos <= 90; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    wrist.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 90; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    wrist.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
x=4;
}
case 4:
  resetFunc();  //call reset
//digitalWrite(greenPin,LOW);

  }
 }else{
  digitalWrite(redPin,LOW);
  digitalWrite(yellowPin,LOW);
  digitalWrite(greenPin,LOW);
 }
 } */
