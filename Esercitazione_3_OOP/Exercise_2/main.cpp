#include "src/ComplexNumber.hpp"
#include <cmath>
#include <iostream>

using namespace std;

int main()
{

    ComplexLibrary::Complex z1(1, 2);
    ComplexLibrary::Complex z2(1, -2);
    ComplexLibrary::Complex sum = z1 + z2;
    cout << "z1 + z2= " << sum << endl;



    ComplexLibrary::Complex con;
    con = ComplexLibrary::coniugate(z1);
    cout << "coniugato di z1= " << con << endl;

    if (z1==z2)
        cout << "z1 = c2" << endl;
    else
        cout << "z1 != z2" << endl;

    return 0;
}
