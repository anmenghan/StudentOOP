#include <iostream>
#include <istream>
#include <iomanip>
#include "complex.h"

using namespace std;

Complex::Complex(double real, double imag) :real(real), imag(imag) {}
bool operator== (const Complex& c1, const Complex& c2) {
    return true;  // temp!
    
}



ostream& operator<< (ostream& os, const Complex& c) {
    
    /*
     * Outputting a `Complex` instance, while illustrating some of the
     * capabilities of I/O streams: `setprecision` gives us a fixed
     * number of decimal places, while `showpos` turns on the plus
     * sign for positive numbers.
     * */
    os << "Real:" << setprecision(5) << c.real << showpos
    << c.get_imag() << noshowpos;
    return os;
}

/*
 * Read a `Complex` number from an input stream.
 * */

istream& operator>> (istream& is, Complex& c) {
    is >> c.real >> c.imag;
    return is;
}





Complex::operator bool() const {
    if ((real == 0) || (imag == 0)){
        return true;
    }
    else {
        return false;
    }
}



Complex& Complex::operator++() {
    ++real;
    return *this;
}

Complex& Complex::operator--() {
    --real;
    return *this;
}

Complex Complex::operator++(int dummy) {
    Complex holder(*this);
    real++;
    return holder;
}

Complex Complex::operator--(int dummy) {
    Complex holder(*this);
    real--;
    return holder;
}

Complex operator+(const Complex& c1,const Complex& c2) {
    double real_number = c1.get_real() + c2.get_real();
    double imag_number = c1.get_imag() + c2.get_imag();
    Complex sum = Complex(real_number, imag_number);
    return sum;
}

Complex operator-(const Complex& c1, const Complex& c2) {
    double real_number = c1.get_real() - c2.get_real();
    double imag_number = c1.get_imag() - c2.get_imag();
    Complex sub = Complex(real_number, imag_number);
    return sub;
}

double Complex::get_real() const {
    return real;
}



double Complex::get_imag() const {
    return imag;
}


Complex Complex::operator*(const int i) {
    real *= i;
    imag *= i;
    return *this;
}

Complex Complex::operator-=(const Complex& c) {
    real -= c.get_real();
    imag -= c.get_imag();
    return *this;
    
}
