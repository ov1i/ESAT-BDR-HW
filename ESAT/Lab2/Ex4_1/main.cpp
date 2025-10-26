/* Ex4_1
Model in C++ a class named Student containing name, surname the number of marks and the
marks from the winter session exams specified as an int pointer. Display the name of the
students who have arrears exams and the first three students in the group based on the
average mark, that will be also displayed.
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

    uint16_t gradesCount = container.student.getMarksCount();
    cout << "\tNumber of marks: " << container.student.getMarksCount() << "\n";
    
    uint16_t *grades = container.student.getMarks();
    cout << "\tGrades: ";
    for(uint16_t i = 0; i < gradesCount; i++) {
        cout << grades[i] << " ";
    }

    cout << "\n\tAverage Mark: " << container.avg_mark << "\n\n";
}

int main() {
    uint64_t n;
    std::vector<cls::StudentSituation_t> classSitutation;

    do {
        cout << "Please specify how many studens we have in our classroom(min 3): "; cin >> n;
    } while(n <= 3);
    classSitutation.reserve(n);

    for(uint64_t i = 0U; i < n; i++) {
        char name[cls::CHAR_ARR_MAX_LEN], surname[cls::CHAR_ARR_MAX_LEN];
        uint16_t *marks;
        uint16_t marksCount;
        cout << "Please enter student " << (i + 1) << " information: \nName: "; cin >> name;
        cout << "Surname: "; cin >> surname;
        
        cout << "Number of marks: "; cin >> marksCount;

        marks = (uint16_t*)malloc(sizeof(uint16_t) * marksCount);
        if(!marks) {
            cout << "Failed to allocate memory on the heap for the student marks! \n\n";
            exit(-1);
        }

        cout << "Marks(n): ";
        for(uint16_t j = 0U; j < marksCount; j++) {
            cin >> marks[j];
        }
        
        cls::C_Student tempStudentObj(name, surname, marks, marksCount);
        double avg = tempStudentObj.computeAvg();

        classSitutation.push_back({ tempStudentObj, avg });
    }

    bubbleSort(classSitutation, n);

    cout << "\n\nFirst 3 students: \n";
    for(uint64_t i = 0; i < 3; i++) {
        cout << "Student " << (i+1) << " Information: \n";
        displayStudentInfo(classSitutation[i]);
    }

    cout << "\n\nStudents that have arrears exams are: \n";
    for(uint64_t i = 0; i < n; i++) {
        if(classSitutation[i].avg_mark < 4.5) {
            cout << "Student " << (i+1) << " Information: \n";
            displayStudentInfo(classSitutation[i]);
        }
    }

    return 0;
}//main