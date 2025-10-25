/* Ex3_1
Create a class named Student that has as private attributes the name, surname, some marks
(array 7 int values), the group. Allocate the necessary amount of memory for storing n
students. Determine the average mark with a method from the class for each student and
use it for sorting the students. Display the ordered array (name, surname, group,
average_mark). The destructor will display a message.
*/


#include <iostream>
#include <vector>

using namespace std;

#include "ClassRoom.h"

void bubbleSort(vector<cls::StudentSituation_t> &container, uint64_t &size) {
    for(uint64_t i = 0; i < size - 1; i++) {
        for(uint64_t j = 0; j < size - i - 1; j++) {
            if(container[j].avg_mark < container[j + 1].avg_mark) {
                swap(container[j], container[j + 1]);
            }
        }
    }
}

void displayStudentInfo(cls::StudentSituation_t &container) {
    cout << "\tName: " << container.student.getName() << "\n";
    cout << "\tSurname: " << container.student.getSurname() << "\n";

    cout << "\tGrades: ";
    uint16_t *grades = container.student.getMarks();
    for(uint8_t i = 0; i < 7; i++) {
        cout << grades[i] << " ";
    }
    cout << "\n\tGroup: " << container.student.getGroup() << "\n";
    cout << "\tAverage Mark: " << container.avg_mark << "\n\n";
}

int main() {
    uint64_t n;
    std::vector<cls::StudentSituation_t> classSitutation;

    cout << "Please specify how many studens we have in our classroom: "; cin >> n;
    classSitutation.reserve(n);

    for(uint64_t i = 0U; i < n; i++) {
        char name[cls::CHAR_ARR_MAX_LEN], surname[cls::CHAR_ARR_MAX_LEN];
        uint16_t marks[7];
        uint16_t group;
        cout << "Please enter student " << (i + 1) << " information: \nName: "; cin >> name;
        cout << "Surname: "; cin >> surname;
        
        cout << "Marks(7): ";
        for(uint8_t j = 0U; j < 7; j++) {
            cin >> marks[j];
        }
        cout << "Group: "; cin >> group;
        
        cls::C_Student tempStudentObj(name, surname, &marks[0], group);
        double avg = tempStudentObj.computeAvg();

        classSitutation.push_back({ tempStudentObj, avg });
    }

    bubbleSort(classSitutation, n);

    for(uint64_t i = 0; i < n; i++) {
        cout << "Student " << (i+1) << " Information: \n";
        displayStudentInfo(classSitutation[i]);
    }

    return 0;
}//main