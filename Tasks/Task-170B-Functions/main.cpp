#include "uop_msb.h"
#include <cstdint>
#include <stdio.h>
#include <string.h>

// LED Bar Display
BusOut dataBits(LED_D0_PIN, LED_D1_PIN, LED_D2_PIN, LED_D3_PIN, LED_D4_PIN, LED_D5_PIN, LED_D6_PIN, LED_D7_PIN);
DigitalOut LED_BAR_OE(LED_BAR_OE_PIN,1);
DigitalOut LED_RED_LE(LED_RED_LE_PIN);
DigitalOut LED_GRN_LE(LED_GRN_LE_PIN);
DigitalOut LED_BLUE_LE(LED_BLUE_LE_PIN);

void led_init(uint8_t a, bool enabled)
{
    //Disable the LED outputs
    LED_BAR_OE = 1;

    //Set data to a
    dataBits = a;

    //Give a little time
    wait_us(1);

    //Enable all latches
    LED_RED_LE  = 1;
    LED_GRN_LE  = 1;
    LED_BLUE_LE  = 1;

    //Give a little time
    wait_us(1);

    //Enable all latches
    LED_RED_LE  = 0;
    LED_GRN_LE  = 0;
    LED_BLUE_LE  = 0;

    if (enabled) {
        LED_BAR_OE = 0;
    }
}


void setLatch (uint8_t dat,  unsigned char col) {
    //For safety
    LED_RED_LE = 0;
    LED_GRN_LE = 0;
    LED_BLUE_LE = 0;

    wait_us(1);
    dataBits = dat;    //Set the 8-bit data pattern
    wait_us(1);

    switch (col){
        case 'r':
        LED_RED_LE = 1;
        wait_us(1);
        LED_RED_LE = 0;
        break;

        case 'g':
        LED_GRN_LE = 1;
        wait_us(1);
        LED_GRN_LE = 0;
        break;

        case 'b':
        LED_BLUE_LE = 1;
        wait_us(1);
        LED_BLUE_LE = 0;
        break;

        default:
        printf ("Please use 'r' for red, 'g' for green, or 'r' for red. \n");
    }
    
    wait_us(1);

}


int main()
{
    printf("Functions demo\n");

    led_init(0, true);

    while (true) {

        //Update the red
        setLatch(0xFF, 'r');

        //Update the green
        setLatch(0b10101010, 'g');

        //Update the blue
        setLatch(0b11001100, 'b');


        for (unsigned int n=0; n<10; n++) {
            //Enable all the LED BAR Latch Outputs
            LED_BAR_OE = 0;

            //Wait
            wait_us(500000);

            //Disable the latch outputs
            LED_BAR_OE = 1;

            //Wait
            wait_us(500000);            
        }


        //Spin forever
        while(true);

    }

}

