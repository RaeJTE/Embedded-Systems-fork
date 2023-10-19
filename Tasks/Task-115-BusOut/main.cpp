#include "mbed.h"
#define WAIT_TIME_MS 1000 


// DigitalOut redLED(PC_2,1);
// DigitalOut yellowLED(PC_3,1);
// DigitalOut greenLED(PC_6,1);

BusOut lights(PC_2, PC_3, PC_6, PB_0, PB_7, PB_14);
//BusOut lights(PC_2, PC_3, PC_6, PB_0, PB_7, PB_14);
//So highest decimal number applicable is 61

int main()
{
    //All OFF
    lights = 00000;

    while (true)
    {
        int count = 61;
        while (count >= 0) 
        {
            printf("count = %d\n", count);
            lights = count;
            wait_us(2500000);

            count = count - 1;
        }
    }
}