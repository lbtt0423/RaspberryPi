#ifndef __DS18B20_H
#define __DS18B20_H
#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
    
#define DSBPIN 		0  //DS18B20�����ݿ�λGPIO0

short DS18B20_Get_Temp(void);

#endif
