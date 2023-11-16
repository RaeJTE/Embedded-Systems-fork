#include <stdio.h>
#include <math.h>
#include "ComplexMaths.hpp"


//Return functions
ComplexNumber_C complexAddition(const ComplexNumber_C a, const ComplexNumber_C b) {
    ComplexNumber_C z = a;
    z.real += b.real;
    z.imag += b.imag;
    return z;
}

ComplexNumber_C complexConjugate(const ComplexNumber_C a) {
    ComplexNumber_C z = a; 
    z.imag = -a.imag;
    return z;
}

ComplexNumber_C complexNegative(const ComplexNumber_C a) {
    ComplexNumber_C z = a;
    z.real = -a.real;
    z.imag = -a.imag;
    return z;
}

ComplexNumber_C complexSubtract(const ComplexNumber_C a, const ComplexNumber_C b) {
    ComplexNumber_C z;
    z = complexAddition(a, complexNegative(b));
    return z;
}

float complexMag(const ComplexNumber_C a) {
    float z;
    z = sqrt(a.real*a.real + a.imag*a.imag);
    return z;
}

ComplexNumber_C complexMult(const ComplexNumber_C a, const ComplexNumber_C b) {
    ComplexNumber_C z;
    z.real = a.real*b.real - a.imag*b.imag;
    z.imag = a.real*b.imag + a.imag*b.real;
    return z;
}

ComplexNumber_C complexDiv(const ComplexNumber_C a, const ComplexNumber_C b) {
    ComplexNumber_C y, z;
    y = complexMult(a, complexConjugate(b));
    z.real = y.real/(complexMag(b)*complexMag(b));
    z.imag = y.imag/(complexMag(b)*complexMag(b));
    return z;
}




//In place functions
void complexDisp(const char *strName, const ComplexNumber_C u) {
    printf("%s = %f + j%f\n", strName, u.real, u.imag);
}

void complexNegateInplace(ComplexNumber_C& a) {
    a.imag = -a.imag;
    a.real = -a.real;
}

void pntrComplexNegateInplace(ComplexNumber_C* a) {
    a->imag = -a->imag;
    a->real = -a->real;
}

void complexConjugateInPlace(ComplexNumber_C& a) {
    a.imag = -a.imag;
}

void pntrComplexConjugateInPlace(ComplexNumber_C* a) {
    a->imag = -a->imag;
}

