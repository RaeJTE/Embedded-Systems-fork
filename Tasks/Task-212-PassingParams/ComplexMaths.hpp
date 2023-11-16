#ifndef _ComplexMaths_
#define _ComplexMaths_

typedef struct {
  double real;
  double imag;
} ComplexNumber_C;

//Return functions
extern ComplexNumber_C complexAddition(const ComplexNumber_C a, const ComplexNumber_C b);
extern ComplexNumber_C complexConjugate(const ComplexNumber_C a);
extern ComplexNumber_C complexNegative(const ComplexNumber_C a);
extern ComplexNumber_C complexSubtract(const ComplexNumber_C a, const ComplexNumber_C b);
extern float complexMag(const ComplexNumber_C a);
extern ComplexNumber_C complexMult(const ComplexNumber_C a, const ComplexNumber_C b);
extern ComplexNumber_C complexDiv(const ComplexNumber_C a, const ComplexNumber_C b);
//In place functions
extern void complexDisp(const char *strName, const ComplexNumber_C u);
extern void complexNegateInplace(ComplexNumber_C& u);
extern void pntrComplexNegateInplace(ComplexNumber_C* u);
extern void complexConjugateInPlace(ComplexNumber_C& a);
extern void pntrComplexConjugateInPlace(ComplexNumber_C* a);

#endif

