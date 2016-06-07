#include "ps2.h"

void setup()
{
 if ( wiringPiSetup() == -1 )
		exit( 1 );
		ps2_init();
}

int main(void)
{
	uint8_t VR_x,VR_y;
	setup();
	

	while ( 1 )
	{
		 if((digitalRead( SWD )))
		 	printf("the LED is ON\n");
		 	else
		printf("the LED is off\n"); 
		VR_x=GetValue0832(0);
		delay(1000);
		printf("The VR_X=%d\n",VR_x);
		VR_y=GetValue0832(1);
		printf("The VR_y=%d\n",VR_y);
		delay( 1000 ); /* wait 1sec to refresh */
	
	}

	return(0);
}
