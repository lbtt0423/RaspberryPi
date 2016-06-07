#include "buzzer.h"
void setup()
{
	beep_init();
}

int main()
{
	setup();
	
	while(1)
	{
		beep_demo();
	}
}
	