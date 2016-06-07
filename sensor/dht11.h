#ifndef __DHT11_H
#define __DHT11_H
#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MAXTIMINGS	85
#define DHTPIN		0

void read_dht11_dat();
#endif
