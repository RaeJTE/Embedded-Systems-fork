#include "uop_msb.h"
#include <chrono>
#include <cstdint>
using namespace uop_msb;
using namespace chrono;

//Output
DigitalOut redLED(TRAF_RED1_PIN);
DigitalOut yellowLED(TRAF_YEL1_PIN);
DigitalOut greenLED(TRAF_GRN1_PIN);

//Analogue Inputs
AnalogIn ldr(AN_LDR_PIN);
Buzzer buzz;


int main()
{
    float samples[100] = {0};
    int size = *(&samples + 1) - samples; //This gives the length of the array, by using the fact that a pointer +1 will skip to the memory location just after the end of the array and that subtract the position of the array start is the legnth of the array
    printf("n is %i \n", size);


    for (unsigned int m=0; m<100; m++) {
        printf("Sample number: %i is %f \n", m, samples[m]);
    }

    // Automatic headlamp 
    while (true) {

        float sum = 0;

        for (unsigned int m=0; m<100; m++) {
            unsigned short ldrVal   = ldr.read_u16();
            samples[m] = ldrVal;
            sum += samples[m];
            wait_us(10000);      // 10ms
        }

        // TASK a. Calculate the average value in samples
        float mean = 0;
        for (unsigned int m=0; m<100; m++) {
            mean = sum/size;
        }
        printf("The mean of the samples is: %f \n", mean); //seem to get 4,670 +/- 50 when uncovered; 23,800 +/- 1,000 when covered.

        // TASK b. Display to 1dp
        printf("The mean to 1dp is: %0.1f \n", mean);

        // TASK c. Switch green LED on when dark;
        if (mean > 23000) {
            redLED = 1;
        }
        else if (mean < 5000) {
            redLED = 0;
        }

    }  
}


