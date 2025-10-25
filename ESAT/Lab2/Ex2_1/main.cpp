/* Ex2_1
Write a C++ application that models as objects one-dimensional arrays of real numbers of
size dim, as an attribute, the array being given by a pointer. Instantiate two objects of this
class and store in a third one the result of subtracting each of the two real number arrays’
elements. If the source arrays have different lengths, the result has the length of the shortest
array. Initialization, subtraction, and display may be implemented with class methods, but
can also be done with global functions. Add a supplementary setter to the class that can
modify an item from a specified position. Modify some elements in the array with this setter
and perform the implemented operations.
*/

#include <iostream>

using namespace std;

#include "ArrayMod.h"

int main() {
    int size1, size2;
    cout << "Please enter the size of array 1: "; cin >> size1;
    cout << "Please enter the size of array 2: "; cin >> size2;

    int *arr1, *arr2;

    arr1 = (int*)malloc(sizeof(int) * size1);
    arr2 = (int*)malloc(sizeof(int) * size2);

    cout << "Please enter the array 1(size: " << size1 << "): ";
    for(int i = 0; i < size1; i++) {
        cin >> arr1[i];
    }

    cout << "Please enter the array 2(size: " << size2 << "): ";
    for(int i = 0; i < size2; i++) {
        cin >> arr2[i];
    }

    cout << ":::Creating objects:::\n";
    arrOps::C_ArrayMod arrObj1(arr1, size1);
    arrOps::C_ArrayMod arrObj2(arr2, size2);
    cout << ":::Objects created:::\n\n";
    
    cout << ":::Subtracting the two arrays:::\n";
    arrOps::C_ArrayMod arrObj3 = arrOps::C_ArrayMod::sub(arrObj1, arrObj2);
    cout << ":::Subtraction done:::\nResults: ";
    arrObj3.displayArray();

    int n;
    do {
        cout << "How many elements you want to modify in array 1? ";
        cin >> n;
    } while(n < 0 || n > size1);
    
    int idx, val;
    for(int i = 0; i < n; i++) {
        cout << "Which element you want to modify? ";
        cin >> idx;
        if(idx > size1 || idx < 0) {
            cout << "Invalid idx! \n";
            i--;
            continue;
        }
        
        cout << "Please enter the new value: "; cin >> val;
        arrObj1.setArrayEl(idx, val);
    }

    do {
        cout << "How many elements you want to modify in array 2? ";
        cin >> n;
    } while(n < 0 || n > size2);

    for(int i = 0; i < n; i++) {
        cout << "Which element you want to modify? ";
        cin >> idx;
        if(idx > size2 || idx < 0) {
            cout << "Invalid idx! \n";
            i--;
            continue;
        }
        
        cout << "Please enter the new value: "; cin >> val;
        arrObj2.setArrayEl(idx, val);
    }

    cout << ":::Subtracting the two arrays:::\n\n";
    arrOps::C_ArrayMod arrObj4 = arrOps::C_ArrayMod::sub(arrObj1, arrObj2);
    cout << ":::Subtraction done:::\nResults: ";
    arrObj4.displayArray();

    return 0;
}//main