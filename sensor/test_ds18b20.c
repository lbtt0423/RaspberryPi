#include "ds18b20.h"

void setup()
{
 if ( wiringPiSetup() == -1 )
		exit( 1 );
		pinMode( DSBPIN, OUTPUT );	
		digitalWrite( DSBPIN, HIGH );
}

int main(void)
{
	int dis_num;
	setup();

	while ( 1 )
	{
	  dis_num =DS18B20_Get_Temp();
		printf("The temperatuer is %d.%d\n",dis_num/10,dis_num%10);
		delay( 1000 ); /* wait 1sec to refresh */
	}

	return(0);
}
