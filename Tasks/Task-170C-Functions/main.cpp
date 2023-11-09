#include "uop_msb.h"

// LED Bar Display
BusOut dataBits(LED_D0_PIN, LED_D1_PIN, LED_D2_PIN, LED_D3_PIN, LED_D4_PIN, LED_D5_PIN, LED_D6_PIN, LED_D7_PIN);
DigitalOut LED_BAR_OE(LED_BAR_OE_PIN,1);
DigitalOut LED_RED_LE(LED_RED_LE_PIN);
DigitalOut LED_GRN_LE(LED_GRN_LE_PIN);
DigitalOut LED_BLUE_LE(LED_BLUE_LE_PIN);
AnalogIn pot(AN_POT_PIN);

void setLatch(uint8_t dat, char col);
void led_init(uint8_t dat, bool enabled);
int getDelayMS();

int main()
{
    printf("Functions demo\n");

    led_init(0x00, true);

    int array [3][10] = { //array is randomised, but remains the same while the code is running.
        rand()%255, rand()%255, rand()%255,
        rand()%255, rand()%255, rand()%255,
        rand()%255, rand()%255, rand()%255,
        rand()%255, rand()%255, rand()%255,
        rand()%255, rand()%255, rand()%255,
        rand()%255, rand()%255, rand()%255,
        rand()%255, rand()%255, rand()%255,
        rand()%255, rand()%255, rand()%255,
        rand()%255, rand()%255, rand()%255,
        rand()%255, rand()%255, rand()%255
    };


    while(true) {

        for (int n = 0; n < 10; n++) {
            setLatch(array[0][n], 'r');
            setLatch(array[1][n], 'g');
            setLatch(array[2][n], 'b');

            //Get delay value
            int delay_ms = getDelayMS();

            //Enable all the LED BAR Latch Outputs
            LED_BAR_OE = 0;

            //Wait
            wait_us(delay_ms*1000);

            //Disable the latch outputs
            LED_BAR_OE = 1;

            //Wait
            wait_us(delay_ms*1000);    
        }

/*        //Update the red
        setLatch(rand()%255,'r');

        //Update the green
        setLatch(rand()%255, 'g');

        //Update the blue
        setLatch(rand()%255, 'b'); */
        
    }

}

void setLatch(uint8_t dat, char col)
{
    //For safety
    LED_RED_LE = 0;
    LED_GRN_LE = 0;
    LED_BLUE_LE = 0;

    //Now follow the sequence
    wait_us(1);
    dataBits = dat;    //Set the 8-bit data pattern
    wait_us(1);

    //Depending on the chosen colour
    switch (col)
    {
        case 'r':
            LED_RED_LE  = 1;    //Copy dataBits to red latch outputs
            wait_us(1);         
            LED_RED_LE  = 0;    //Ignore inputs (dataBits)
            break;
        case 'g':
            LED_GRN_LE  = 1;    //Copy dataBits to red latch outputs
            wait_us(1);         
            LED_GRN_LE  = 0;    //Ignore inputs (dataBits)
            break;
        case 'b':
            LED_BLUE_LE  = 1;    //Copy dataBits to red latch outputs
            wait_us(1);         
            LED_BLUE_LE  = 0;    //Ignore inputs (dataBits)
            break;
    }
    wait_us(1); 
}

void led_init(uint8_t dat, bool enabled)
{
    //Disable the LED outputs
    LED_BAR_OE = 1;

    //Set data to 0
    dataBits = dat;

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

int getDelayMS() 
{
    float p = pot; // 0 ... 1
    int delay = 100 + 900*p;    //100...1000ms
    return delay;
}



