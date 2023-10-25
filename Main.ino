*
 * Andre Deveau
 *
 * Created October 24 2023
 *
 * Untilizes a HC-SR04 to control Servo through an Arduino
*/

#include <Servo.h>

Servo servoNumber1;

const int trigPin = 3;
const int echoPin = 2;

float duration, distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  servoNumber1.attach(7);
  servoNumber1.write(0);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(100);
  
  if (distance > 50) {
    servoNumber1.write(90);
  } else {
    servoNumber1.write(0);
  }
}