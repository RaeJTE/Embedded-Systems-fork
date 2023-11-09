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


/*float Wrap(int kX, int const kLowerBound, int const kUpperBound) {
            int range_size = kUpperBound - kLowerBound + 1;

            if (kX < kLowerBound)
                kX += range_size * ((kLowerBound - kX) / range_size + 1);

            return kLowerBound + (kX - kLowerBound) % range_size;
        }
        
        This function is no longer needed, but it was cool so I wanted to keep it recorded
        Its purpose it to let you make a range over which numbers will wrap back around - could implement with button counter from Task-134 */


int main()
{
    float samples[100] = {0};
    int size = *(&samples + 1) - samples; //This gives the length of the array, by using the fact that a pointer +1 will skip to the memory location just after the end of the array and that subtract the position of the array start is the legnth of the array
    printf("n is %i \n", size);
    float mean = 0;

    // Automatic headlamp 
    while (true) {

        float sum = 0;



        for (unsigned int m=0; m<100; m++) {
            unsigned short ldrVal   = ldr.read_u16();
            sum -= samples [m]; //removes oldest value
            samples[m] = ldrVal;
            sum += samples[m]; //adds newest value
            mean = sum/size;

            if (mean > 23000) {
            redLED = 1;
            }
            else if (mean < 5000) {
            redLED = 0;
            }
            wait_us(10000);      // 10ms
            printf("The mean to 1dp is: %0.1f \n", mean);
        }


    }  
}


