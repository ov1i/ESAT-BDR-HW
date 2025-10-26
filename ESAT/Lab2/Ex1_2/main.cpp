/* Ex1_2
Implement a class called Complex that overloads the arithmetical operators (+, -, *, /) for performing
the corresponding operations when applied to Complex instances (use both friend functions (*, /) and
member methods (+, -)).
Note: The Complex numbers will have a real and an imaginary part, both coefficients being represented
as real numbers.
*/


#include <iostream>

using namespace std;

#include "Complex.h"

complx::C_Complex readComplexNo() {
    double realPart, imPart;

    cout << "Please enter a complex number(doubles): \n";
    cout << "Real part: "; cin >> realPart;
    cout << "Imaginary part: "; cin >> imPart;

    complx::C_Complex obj(realPart, imPart);

    return obj;
}

int main() {
    
    complx::C_Complex no1 = readComplexNo();
    complx::C_Complex no2 = readComplexNo();
    complx::C_Complex res;

    cout << ":::Performing addition::: \n";
    res = no1 + no2;
    cout << "Addition result: \n\treal= " << no1.getReal() << " \n\tim= " << no1.getIm() << "i\n"; 

    cout << ":::Performing subtraction::: \n";
    res = no1 - no2;
    cout << "Subtraction result: \n\treal= " << no1.getReal() << " \n\tim= " << no1.getIm() << "i\n"; 

    cout << ":::Performing multiplication::: \n";
    res = no1 * no2;
    cout << "Multiplication result: \n\treal= " << no1.getReal() << " \n\tim= " << no1.getIm() << "i\n"; 

    cout << ":::Performing division::: \n";
    res = no1 / no2;
    cout << "Division result: \n\treal= " << no1.getReal() << " \n\tim= " << no1.getIm() << "i\n"; 
    return 0;
}//main