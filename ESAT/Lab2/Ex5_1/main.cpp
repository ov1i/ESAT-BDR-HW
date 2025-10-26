/* Ex5_1
Write a C++ application that reads a 3D point from the keyboard by giving the x, y and z
coordinates. Write a method that moves the point with a given distance on each of the three
axes. Verify if the line between the first (initial position of the point) and the second position
of this point (after translation on all directions) crosses a third given point.
*/


#include <iostream>

using namespace std;

#include "Geometry.h"

int main() {
    geom::vec3i64 pos;
    
    cout << "Please input a initial postion in 3D(x,y,z): ";
    for(uint8_t i = 0U; i < 3; i++) {
        cin >> pos.at(i);
    } 
    geom::C_Geometry geomSolver(pos);

    cout << "Please input the translation value in 3D(x,y,z): ";
    for(uint8_t i = 0U; i < 3; i++) {
        cin >> pos.at(i);
    }

    geomSolver.translate3D(pos);

    pos = geomSolver.getPosition();
    cout << "New translated position is: ";
      for(uint8_t i = 0U; i < 3; i++) {
        cout << pos.at(i) << " ";
    }

    pos = geomSolver.getShadowPosition();
    cout << "\nInternal shadow position is: ";
      for(uint8_t i = 0U; i < 3; i++) {
        cout << pos.at(i) << " ";
    }

    cout << "\nPlease input a new position to check line mapping in 3D(x,y,z): ";
    for(uint8_t i = 0U; i < 3; i++) {
        cin >> pos.at(i);
    }

    if(geomSolver.isOnLine(pos)) {
        cout << "The new point lies on the line formed by the old and new position of our point!\n\n";
    } else {
        cout << "The new point doesn't lie on the line formed by the old and new position of our point!\n\n";
    }

    
    return 0;
}//main