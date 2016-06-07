#include "shock.h"
void setup()
{
	shock_init();
}

int main()
{
	setup();
	
	while(1)
	{
		shock_demo();
	}
}
	