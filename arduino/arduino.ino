#define TRIGGER  8
#define ECHO 7
#include <Servo.h>
Servo myServo;

void setup() {
  Serial.begin(9600);
  myServo.attach(3);  
  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO, INPUT);
  myServo.write(0); 
}

void loop() {
  long duration, distance;
  digitalWrite(TRIGGER, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER, LOW);
  duration = pulseIn(ECHO, HIGH);
  distance = duration * 0.034 / 2;
  Serial.println(distance);

  if (Serial.available() > 0) {
    char command = Serial.read();
    if (command == 'O') {           
      myServo.write(90);            
      delay(5000);                  
      myServo.write(0);             
    }
  }
  delay(500);
}
