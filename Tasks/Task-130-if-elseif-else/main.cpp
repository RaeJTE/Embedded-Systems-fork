#include "uop_msb.h"
using namespace uop_msb;

/*DigitalIn ButtonA(PG_0); //Button A
DigitalIn ButtonB(PG_1); //Button B
DigitalIn ButtonC(PG_2, PullDown); //Button C
DigitalIn ButtonD(PG_3, PullDown); //Button D
*/
BusIn bus(PG_0, PG_1, PG_2, PG_3);

DigitalOut redLED(TRAF_RED1_PIN);       //Red Traffic 1
DigitalOut yellowLED(TRAF_YEL1_PIN);    //Yellow Traffic 1
DigitalOut greenLED(TRAF_GRN1_PIN);     //Green Traffic 1

//Dual Digit 7-segment Display
LatchedLED disp(LatchedLED::SEVEN_SEG);

int main()
{
    bus[2].mode(PinMode::PullDown);
    bus[3].mode(PinMode::PullDown);
    int count = 0;

    //Turn ON the 7-segment display
    disp.enable(true);

    //Update display
    disp = count;

    while (true) { //Counter can only go up to 99, so confining the while loop to stop counting after 99.
        //Read button without blocking
//        int btnA = bus[0];     //Local to the while-loop  
//        int btnB = bus[1];

        //Test Button A
        if (bus == 1) {
            redLED = !redLED;    //Toggle RED led
            count = count + ((count<99) ? 1 : 0);            //Increment count
        }
        if (bus == 2) {
            yellowLED = !yellowLED;
            count = count - ((count>0) ? 1 : 0);
        }
        if (bus == 3){
            count = 0;
        }
        else {
            greenLED = !greenLED;
        }

            disp = count;       //Update display

        // Slow it down a bit (and debounce the switches)
        wait_us(100000);  
        redLED = 0;
        yellowLED = 0;
        greenLED = 0;
    }
}


