#include "UltraSoundSensor.h"
#include "Arduino.h"

UltraSoundSensor::UltraSoundSensor(byte trigPin, byte echoPin) {
  _trigPin = trigPin;
  _echoPin = echoPin;
}

void UltraSoundSensor::Task(float delta = 0) {
  long duration = 0;
  
  digitalWrite(_trigPin, LOW);
  delayMicroseconds(2);
  
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(_trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(_trigPin, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(_echoPin, HIGH);
  
  // Calculating the distance
  currentDistance = duration * distanceFactor;
}
