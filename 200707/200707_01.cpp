#include <wiringPi.h>
#include <softTone.h>
#include <stdio.h>
#include <stdlib.h>

#define SPKR 6
#define TOTAL 16

int notes[] = {
	391, 391, 440, 440, 391, 391, 330, 330,
	391, 391, 291, 229, 229, 294, 294, 294
};

void musicPlay()
{
	softToneCreate(SPKR);
	
	for(int i = 0; i < TOTAL; ++i)
	{
		softToneWrite(SPKR, notes[i]);
		delay(285);
		softToneWrite(SPKR, 0);
		delay(50);
	}
}

int main()
{
	wiringPiSetup();
	musicPlay();
	return 0;
}

