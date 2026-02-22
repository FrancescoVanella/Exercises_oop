#ifndef __COMPLEX_H
#define __COMPLEX_H

#include <iostream>
#include <cmath>


using namespace std;


namespace ComplexLibrary{

struct Complex
{
    double a;
    double b;

    Complex(double x1, double x2):
        a(x1),
        b(x2)
    {
        ;
    }

    Complex() = default;

};



ostream& operator<<(ostream& os, const Complex &z);
Complex operator+(const Complex &z1, const Complex &z2);
bool operator ==(const Complex &z1, const Complex &z2);

Complex coniugate( Complex &z1);
}
#endif
