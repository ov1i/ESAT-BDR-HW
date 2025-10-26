/* Ex2_2
Modify the operator – overload, allowing multiple occurrences of the initial string from example 1 to
be dropped. Test the functionalities.
*/


#include <iostream>

using namespace std;

#include "String_static.h"


int main() {
    char xx[dim];
    
    cout << "\nWrite an array of chars (object 1): ";
    cin.getline(xx, sizeof(xx));// //gets_s(xx, sizeof(xx));
    C_String ob1(xx);

    cout << "\nWrite an array of chars (object 2): ";
    cin.getline(xx, (sizeof(xx) / sizeof(xx[0])));//gets_s(xx, _countof(xx));
    C_String ob2(xx);
    
    C_String ob3;//default constructor called
    ob3 = ob1 + ob2;//implicit assign, + overloading
    cout << "\nThe array after addition: " << ob3.getSir();

    cout << "\nThe array to be subtracted from the 1-st one: ";
    cin.getline(xx, (sizeof(xx) / sizeof(xx[0])));//gets_s(xx, _countof(xx));
    C_String ob4(xx);

    C_String ob5 = ob1 - ob4;//implicit copy constructor, cloning, - overload
    cout << "\nThe subtraction result: " << ob5.getSir( );

    char c = ob5[0]; //overloading []
    cout << "\nFirst character: " << c;

    C_String obx = move(ob3);//implicit move/copy constructor
    cout << "\nThe array from obx after moving ob3: " << obx.getSir() << " \n";
    
    return 0;
}//main