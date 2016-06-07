#include "shock.h"
void shock_init()
{
	 if ( wiringPiSetup() == -1 )
		exit( 1 );	
		pinMode(LED, OUTPUT);
		pinMode(Shock,INPUT);
}

void shock_demo()
{
	uint8_t val=0;
	while(1)
	{
		val=digitalRead(Shock);
		if(val==HIGH){
			digitalWrite(LED,LOW);
			printf("LOW\n");
		}
			else
				digitalWrite(LED,HIGH);
				printf("HIGH\n");
	}
}