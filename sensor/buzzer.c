#include "buzzer.h"
void beep_init()
{
	 if ( wiringPiSetup() == -1 )
		exit( 1 );	
		pinMode(BEEP, OUTPUT);
}

void beep_demo()
{
	unsigned char i;
	for(i=0;i<100;i++)
	{
		digitalWrite(BEEP,HIGH);
		delay(1);
		digitalWrite(BEEP, LOW);
		delay(1);
	}
	for(i=0;i<200;i++)
	{
		digitalWrite(BEEP,HIGH);
		delay(2);
		digitalWrite(BEEP, LOW);
		delay(2);
	}
	}