#ifndef __buzzer_H
#define __buzzer_H
#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BEEP	0
void beep_init();
void beep_demo();
#endif