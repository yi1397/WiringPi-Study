#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>


int ledControl(int gpio)
{	
	pinMode(gpio, OUTPUT);
	
	for(int i = 0; i < 5; i++)
	{
		printf("high : %d\n", gpio);
		digitalWrite(gpio, HIGH);
		delay(500);
		printf("low : %d\n", gpio);
		digitalWrite(gpio, LOW);
		delay(500);
	}
	
	return 0;
}

int main(int argc, char **argv)
{
	int gno;
	
	if(argc < 2)
	{
		///printf("NO");
		return -1;
	}
	gno = atoi(argv[1]);
	wiringPiSetup();
	ledControl(gno);
	
	return 0;
}
