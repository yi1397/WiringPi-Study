
#include <wiringPi.h>
#include <softPwm.h>
#include <stdio.h>
#include <stdlib.h>

unsigned char br[4] = {0,64,128,255};

void ledPwmControl()
{
        

        for(int j = 0; j < 4; j++)
        {
		softPwmWrite(21+j, br[j]);
		delay(150);
                softPwmWrite(20+j, 0);
                delay(150);
        }

	
	for(int j = 0; j < 4; j++)
	{
		softPwmWrite(24-j, br[j]);
		delay(150);
                softPwmWrite(25-j, 0);
                delay(150);
	}
        
        softPwmWrite(21, 0);
        softPwmWrite(22, 0);
        softPwmWrite(23, 0);
        softPwmWrite(24, 0);
}

int main()
{
        wiringPiSetup();
        
        pinMode(21, OUTPUT);
        pinMode(22, OUTPUT);
        pinMode(23, OUTPUT);
        pinMode(24, OUTPUT);

        softPwmCreate(21, 0, 255);
	softPwmCreate(22, 0, 255);
	softPwmCreate(23, 0, 255);
	softPwmCreate(24, 0, 255);
        
        while(1)
        {
                ledPwmControl();
        }

        return 0;
}

