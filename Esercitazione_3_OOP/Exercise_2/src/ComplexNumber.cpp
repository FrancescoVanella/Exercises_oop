#include "ComplexNumber.hpp"

namespace ComplexLibrary{

Complex coniugate(Complex &z1)
{
    Complex z( z1.a, (-1)*z1.b);
    return z;
}

ostream& operator<<(ostream& os , const Complex& z)
{
    if (z.a >= 0)
        os << '(' << z.a << "+" << z.b << "i" << ')' << endl;
    else
        os << '(' << z.a << "-" << z.b << "i" << ')' << endl;
    return os;
}


Complex operator+(const Complex &z1, const Complex &z2)
{
    Complex z(z1.a + z2.a, z1.b + z2.b);
    return z;
}

bool operator==(const Complex &z1, const Complex &z2)
{
    if (z1.a==z2.a && z1.b==z2.b)
        return true;
    else
        return false;
}

}
