#ifndef __INIT_H
#define __INIT_H

#include "mbed.h"

#define MOTOR_NUM 8

extern BufferedSerial pc;

extern DigitalOut motor_sign_front[MOTOR_NUM];

extern DigitalOut motor_sign_back[MOTOR_NUM];

extern PwmOut motor_pwm[MOTOR_NUM];





#endif