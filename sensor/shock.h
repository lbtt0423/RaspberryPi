#ifndef __SHOCK_H
#define __SHOCK_H
#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define LED	4
#define Shock 0
void shock_init();
void shock_demo();
#endif