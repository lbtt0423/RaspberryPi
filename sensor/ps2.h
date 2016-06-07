#ifndef __PS2_H
#define __PS2_H
#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define DATI	2
#define SWD   3
#define CS    7
#define CLK   0
#define LED   1
#define DATO  4

void ps2_init();
uint8_t GetValue0832(uint8_t Channel);

#endif
