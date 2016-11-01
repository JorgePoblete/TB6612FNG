/*
  TB6612FNG.h - Library for controling dc motor using the TB6612FNG Breakout board.
  Created by Jorge Enrique Poblete Riquelme, October 26, 2016.
  Released into the public domain.
*/

#ifndef TB6612FNG_h
#define TB6612FNG_h

#include "Arduino.h"

class TB6612FNG
{
  private:
    struct Motor {
      int pwm;
      int in1;
      int in2;
	  boolean is_set;
    };
    struct Direction {
      boolean in1;
      boolean in2; 
    };

	int _stand_by_pin;
    
  public:
    TB6612FNG();
	void setStandByPin(int stand_by_pin);
	void setMotor(Motor motor, int pwm, int in1, int in2);
    void enableMotors();
    void disableMotors();
    void spinMotor(Motor motor, int speed, Direction direction);
    void stopMotor(Motor motor);

    Motor motor_a;
    Motor motor_b;
    Direction direction_cw;
    Direction direction_ccw;
};

#endif
