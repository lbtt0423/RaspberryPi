#include "colourthree.h"

void Color_Three_Init()
{
	 if ( wiringPiSetup() == -1 )
		exit( 1 );	
		pinMode(COL_RED, OUTPUT);
		pinMode(COL_GREEN, OUTPUT);
		pinMode(COL_BLUE, OUTPUT);
}

void Color_Three_Demo()
{
	digitalWrite(COL_RED, HIGH);
	digitalWrite(COL_GREEN, LOW);
	digitalWrite(COL_BLUE, LOW);
	delay(500);
	digitalWrite(COL_RED, LOW);
	digitalWrite(COL_GREEN,HIGH);
	digitalWrite(COL_BLUE, LOW);
	delay(500);
	digitalWrite(COL_RED,LOW);
	digitalWrite(COL_GREEN, LOW);
	digitalWrite(COL_BLUE, HIGH);
	delay(500);
	
	
	
}