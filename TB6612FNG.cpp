/*
  TB6612FNG.cpp - Library for controling dc motor using the TB6612FNG Breakout board.
  Created by Jorge Enrique Poblete Riquelme, October 26, 2016.
  Released into the public domain.
*/

#include "Arduino.h"
#include "TB6612FNG.h"

TB6612FNG::TB6612FNG() {
	motor_a = {0, 0, 0, false};
	motor_b = {0, 0, 0, false};
}

void TB6612FNG::setStandByPin(int stand_by_pin) {
	_stand_by_pin = stand_by_pin;
	pinMode(_stand_by_pin, OUTPUT);
}

void TB6612FNG::setMotor(Motor motor, int pwm, int in1, int in2) {
	motor = { pwm, in1, in2, true};
	pinMode(motor.pwm, OUTPUT);
	pinMode(motor.in1, OUTPUT);
	pinMode(motor.in2, OUTPUT);
}

void TB6612FNG::enableMotors() {
	digitalWrite(_stand_by_pin, HIGH);
}

void TB6612FNG::disableMotors() {
	digitalWrite(_stand_by_pin, LOW);
}

void TB6612FNG::spinMotor(Motor motor, int speed, Direction direction) {
	if (!motor.is_set) {
		return;
	}
	digitalWrite(motor.in1, direction.in1);
	digitalWrite(motor.in2, direction.in2);
	analogWrite(motor.pwm, speed);
}

void TB6612FNG::stopMotor(Motor motor) {
	if (!motor.is_set) {
		return;
	}
	digitalWrite(motor.in1, LOW);
	digitalWrite(motor.in2, LOW);
	analogWrite(motor.pwm, 0);
}
