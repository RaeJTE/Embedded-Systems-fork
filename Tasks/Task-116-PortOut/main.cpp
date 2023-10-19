#include "mbed.h"

PortOut lights(PortC, 0b0000000001001100);
//red = 0b0000000000000100
//yellow = 0b0000000000001000
//green = 0b0000000001000000

int main()
{
    //All OFF
    lights = 0;

    while (true)
    {
        lights = 0b0000000000000100+0b0000000000001000;
        wait_us(1000000);
        lights = 0b0000000000001000+0b0000000001000000;
        wait_us(1000000);
        lights = 0b0000000000000100+0b0000000001000000;
        wait_us(1000000);                
    }
}