#include <wiringPi.h>
#include <stdio.h>

#define CDS 0
#define LED 5

int main()
{
	
	wiringPiSetup();
	pinMode(CDS, INPUT);
	pinMode(LED, OUTPUT);
	
	while(1)
	{
		digitalWrite(LED, digitalRead(CDS));
	}
}
