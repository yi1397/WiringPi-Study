#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>

int cnt = 0;

void led_go(bool stop)
{
	if(!stop)
	{
		digitalWrite(21+cnt, LOW);
		cnt++;
		cnt%=4;
		digitalWrite(21+cnt, HIGH);
	}
}

int main(int argc, char **argv)
{
	wiringPiSetup();
	pinMode(21, OUTPUT);
	pinMode(22, OUTPUT);
	pinMode(23, OUTPUT);
	pinMode(24, OUTPUT);
	pinMode(29, INPUT);
	
	bool stop = false;
	int time_cnt = 0;
	
	while(1)
	{
		if(time_cnt == 4)
		{
			led_go(stop);
			time_cnt = 0;
		}
		if(digitalRead(29) ==HIGH) 
			stop=!stop;
		delay(50);
		time_cnt++;
	}
	
	return 0;
}
