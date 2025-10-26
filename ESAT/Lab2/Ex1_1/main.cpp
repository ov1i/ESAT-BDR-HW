/* Ex1_1
Modify example 3 in order to allow the addition of two CPunctText points. The name of the
new point will be created from the names of the compounding points by concatenation. Add
a method that returns the distance from a point to origin. Modify the class so that you
remove the afis() method by using appropriate getter methods instead. Also remove the
lungime_sir attribute by appropriately modifying the class methods. Also add a move
constructor. Test using as other variant the character string specific functions of VC ++ 1y/2z
(strcpy_s ( ) and strcat_s ( )). 
*/


//main
#define _CRT_SECURE_NO_WARNINGS
#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;
#include "CPunctText.h"
int main( ) {
    CPunctText cpt1(1, 2, "Punct1");//parameterized constructor call
    CPunctText cpt2(cpt1); //copy constructor call
    CPunctText cpt3 = cpt2; //copy constructor call
    CPunctText cpt4(4, 5); //parameterized constructor call, last implicit
    // cpt3.afis();
    // cpt4.afis();

    // cpt5.afis();
    
    cout << "Object has x= " << cpt3.getX() << endl;
    cout << "Object has y= " << cpt3.getY() << endl;
    cout << "Object has the array of characters = " << cpt3.getName() << endl;
    
    cout << "Object has x= " << cpt4.getX() << endl;
    cout << "Object has y= " << cpt4.getY() << endl;
    cout << "Object has the array of characters = " << cpt4.getName() << endl;
    
    cout << "\n\nPerforming addition between two points: \nAddition result: \n\n"; 
    CPunctText cpt5 = CPunctText::addPoints(cpt1, cpt4);
    cout << "Object has x= " << cpt5.getX() << endl;
    cout << "Object has y= " << cpt5.getY() << endl;
    cout << "Object has the array of characters = " << cpt5.getName();

    cout << "\nComputing the distance to the origin: \nDistance result: " << cpt5.computeDistance() << "\n";
    CPunctText cpt6 = move(cpt5);

    cout << "\n\n\n";

    return 0;
}//main