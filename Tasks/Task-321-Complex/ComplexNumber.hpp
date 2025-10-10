//
//  ComplexNumber.hpp
//  Complex
//
//  Created by Nicholas Outram on 21/09/2017.
//  Copyright © 2017 Nicholas Outram. All rights reserved.
//

#ifndef ComplexNumber_hpp
#define ComplexNumber_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

class ComplexNumber {
private:
    double real;
    double imag;
    
public:
    //Default constructor
    ComplexNumber() {
        this->real = 0.0;
        this->imag = 0.0;
    }
    
    //Constructor 2 - default of second parameter is 1 if not specified, but here is changed to 0
    ComplexNumber(const double r, const double i=0.0) {
        this->real = r;
        this->imag = i;
    }
    
    //Copy constructors
    ComplexNumber(const ComplexNumber& c) {
        this->imag = c.imag;
        this->real = c.real;
    }

    //Destructor
    ~ComplexNumber() {
        cout << "Bye'ee" << endl;
    }
    
    //Read-only accessors
    double getReal() {
        return this->real;
    }

    double getImag() {
        return this->imag;
    }

    //Conjugate - verb, so perform in place
    void conjugate() {
        this->imag *= -1.0;
    }
    
    //Conjugated - adjective, so return new copy
    ComplexNumber conjugated() {
        return ComplexNumber(this->real, -1.0*this->imag);
    }

    //Add in place
    void add(const ComplexNumber& c) {
        this->real += c.real;
        this->imag += c.imag;
    }
    
    //Add
    ComplexNumber addedTo(const ComplexNumber& c) {
        return ComplexNumber(this->real+c.real, this->imag+c.imag);
    }
    
    //Display
    void display() {
        cout << this->real << " + " << this->imag << "j" << endl;
    }

    //Negate - negate original
    void negate()
    {
        this->real *= -1;
        this->imag *= -1;
    }

    //Negated - return negated copy
    ComplexNumber negated() {
        return ComplexNumber(-1.0*this->real, -1.0*this->imag);
    }

    //Subtract in place
    void subtract(const ComplexNumber& c) {
        this->real -= c.real;
        this->imag -= c.imag;
    }
    
    //Subtracted from - copy returned
    ComplexNumber subtractFrom(const ComplexNumber& c) {
        return ComplexNumber(c.real-this->real, c.imag-this->imag);
    }

    //Multiply in place
    void multiply(const ComplexNumber& c) {
        this->real *= c.real;
        this->imag *= c.imag;
    }
    
    //Multiplied with - copy returned
    ComplexNumber multipyWith(const ComplexNumber& c) {
        return ComplexNumber(this->real*c.real, this->imag*c.imag);
    }

    //Divide in place
    void divide(const ComplexNumber& c) {
        this->real /= c.real;
        this->imag /= c.imag;
    }
    
    //Divided by - cpopy returned
    ComplexNumber divideBy(const ComplexNumber& c) {
        return ComplexNumber(this->real/c.real, this->imag/c.imag);
    }
    
};


#endif /* ComplexNumber_hpp */
