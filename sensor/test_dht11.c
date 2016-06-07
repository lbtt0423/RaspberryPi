#include "dht11.h"

void setup()
{
 if ( wiringPiSetup() == -1 )
		exit( 1 );
}

int main(void)
{
	setup();

	while ( 1 )
	{
		read_dht11_dat();
		delay( 1000 ); /* wait 1sec to refresh */
	}

	return(0);
}
