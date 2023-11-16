#include "uop_msb.h"
#include <chrono>
using namespace uop_msb;
extern int getAverageDelay(double alpha);

AnalogIn pot(AN_POT_PIN);
AnalogIn LDR(AN_LDR_PIN);
DigitalOut redLED(TRAF_RED1_PIN);
LCD_16X2_DISPLAY disp;
PwmOut dispBackLight(LCD_BKL_PIN);

int main()
{
    //Configure the PWM for the backlight 
    dispBackLight.period(0.001f);   // 1ms
    dispBackLight.write(1.0);       // 100% duty

    //Update display
    disp.cls();
    disp.printf("PwmOut");

    //Implement a delay (BLOCKING)
    wait_us(2000000);

    //Update display
    disp.locate(1, 0);
    disp.printf("Turn the POT");

    //Implement another delay (BLOCKING)
    wait_us(2000000);

    //Timer for the pot
    Timer tmr;
    Timer tmr2;
    tmr.start();
    tmr2.start();

    while(true) {
        
        //Once every 250ms, re-read the POT and update the duty
        if (tmr.elapsed_time() >= 250ms) {
            float u = pot;              // Every 250ms, read the pot... 
            dispBackLight.write(u);     // ... and update the brightness.
            tmr.reset();
            if (u >= 0.5) {
                redLED = 1;
            }
            else {
                redLED = 0;
            }
        }
        if (tmr2.elapsed_time() >= 1s) {
            float u = pot;
            float v = LDR;
            
            disp.locate(0, 0);
            disp.cls();
            disp.printf("Pot = %0.5f", u);

            disp.locate(1, 0);
            disp.printf("LDR = %0.5f", v);

            tmr2.reset();
        }
        
        //Other non-blocking code could go here
        
    }

}




