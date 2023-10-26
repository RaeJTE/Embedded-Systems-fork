#include "mbed.h"

DigitalIn ButtonA(PG_0); //Button A
DigitalIn ButtonB(PG_1); //Button B 
DigitalIn ButtonC(PG_2, PinMode :: PullDown); //Button C
DigitalIn ButtonD(PG_3, PinMode :: PullDown); //Button D

DigitalOut redLED(PC_2); //Red Traffic 1

// main() runs in its own thread in the OS
int main()
{
    int btnA, btnB, btnC, btnD;
    // Turn OFF the red LED
    redLED = 0;

    while (true) {
    
        // Wait for BOTH button to be pressed
        do {
            btnA = ButtonA; //Read button A
            btnB = ButtonB; //Read button B
            btnC = ButtonC;
            btnD = ButtonD;
        } while ((btnA == 0) || (btnB == 0) || (btnC == 0) || (btnD == 0));

        //Toggle the red LED
        redLED = !redLED;

        printf("-------------\n");

        //Wait for noise to settle
        wait_us(10000);

        printf("Button A is set to %d \n", btnA);
        printf("Button B is set to %d \n", btnB);
        printf("Button C is set to %d \n", btnC);
        printf("Button D is set to %d \n", btnD);
        printf("\n");

        // Wait for EITHER buttons to be released
        do {
            btnA = ButtonA; //Read button A
            btnB = ButtonB; //Read button B
            btnC = ButtonC;
            btnD = ButtonD;
        } while ((btnA + btnB + btnC + btnD) >= 3);

        printf("Button A is set to %d \n", btnA);
        printf("Button B is set to %d \n", btnB);
        printf("Button C is set to %d \n", btnC);
        printf("Button D is set to %d \n", btnD);

        //Wait for noise to settle
        wait_us(10000);

        //Reset the red LED
        redLED = 0;
    }
}


