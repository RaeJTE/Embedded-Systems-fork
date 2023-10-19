#include "mbed.h"
#define WAIT_TIME_MS 1000 


// DigitalOut redLED(PC_2,1);
// DigitalOut yellowLED(PC_3,1);
// DigitalOut greenLED(PC_6,1);

BusOut lights(PC_2, PC_3, PC_6, PB_0, PB_7, PB_14);
//BusOut lights(PC_2, PC_3, PC_6, PB_0, PB_7, PB_14);
//So highest decimal number applicable is 63

int main()
{
    //All OFF
    printf("all on\n");
    lights = 0b111111;

    wait_us(1000000);
    printf("all off\n");
    lights = 0b000000;

    while (true)
    {
        int count = 63;
        while (count >= 0) 
        {
            printf("count = %d\n", count);
            lights = count;
            wait_us(500000);

            count = count - 1;
        }
    }
}