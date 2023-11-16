#include "mbed.h"
#include "ComplexMaths.hpp"


ComplexNumber_C complexAdd(const ComplexNumber_C a, const ComplexNumber_C b) {
    ComplexNumber_C y = a;
    y.real += b.real;
    y.imag += b.imag;
    return y;
}

void complexDisplay(const char *strName, const ComplexNumber_C u) {
    printf("%s = %f + j%f\n", strName, u.real, u.imag);
}

// TASK - write and test complexConjugate, complexNegate, complexSubtract, complexMagnitude, complexMultiply and complexDivide

int main() {
    printf("\n\nTASK312\n");

    //Create instance of a complex number
    ComplexNumber_C p = {2.0, 3.0};
    ComplexNumber_C q = {1.0, 1.0};
    complexDisp("p", p);
    complexDisp("q", q);
 
    ComplexNumber_C sum = complexAdd(p, q);
    complexDisp("p+q", sum);

    complexNegateInplace(p);
    pntrComplexNegateInplace(&q);
    printf("(%f + j%f) / (%f + j%f) = %f + j%f \n", p.real, p.imag, q.real, q.imag, complexDiv(p, q).real,  complexDiv(p , q).imag);

    
    while (true) {
    }
}
