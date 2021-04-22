#ifndef __ULTRASOUNDSENSOR__
#define __ULTRASOUNDSENSOR__

#include "Arduino.h"

class UltraSoundSensor {
  private:
    byte _trigPin;
    byte _echoPin;
    const float distanceFactor = 0.034 / 2;
    int currentDistance = 0;
  public:
    UltraSoundSensor(byte trigPin, byte echoPin);
    void Task(float delta = 0);
    int GetDistance();    
};

#endif
