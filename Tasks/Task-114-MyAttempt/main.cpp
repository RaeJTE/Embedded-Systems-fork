#include "mbed.h"

//TRAF_RED1 : PC2/ADC1IN12/PWM1_3N
//TRAF_YEL1 : PC3/A2/ADC1IN13/SPI2_MOSI
//TRAF_GRN1 : PC6/UART6_TX/PWM3_1

//Creates variables for the digital outputs
DigitalOut redLED(PC_2, 1);
DigitalOut yelLED (PC_3, 1);
DigitalOut grnLED (PC_6, 1);


// main() runs in its own thread in the OS
int main()
{
    //Wait 1 second to verify LEDs are working.
    wait_us(1000000);

    //Reset
    redLED = 0;
    yelLED = 0;
    grnLED = 0;
    wait_us(2000000);

    while (true) {
        //Red light
        redLED = 1;
        wait_us(2000000);

        //Red-amber light
        yelLED = 1;
        wait_us(2000000);


        //Green light
        redLED = 0;
        yelLED = 0;
        grnLED = 1;
        wait_us(2000000);

        //Flashing amber light
        grnLED = 0;
        int n = 0;
        while (n<10) {
            yelLED = 1;
            wait_us(200000);
            yelLED = 0;
            wait_us(200000);
            n = n+1;
        }

    }
}

