#pragma once
#include <cstdint>
#include <cstring>

namespace cls {
    constexpr uint8_t CHAR_ARR_MAX_LEN = 255;

    class C_Student {
    public:
        /// @brief          Explicit Constrcutor
        /// @param name     -> Student name
        /// @param surname  -> Student surname
        /// @param marks    -> Student marks (7)
        /// @param group    -> Student group
        C_Student(char *name, char *surname, uint16_t *marks, uint16_t marksCount);

        /// @brief          Explicit destructor
        ~C_Student();

        /// @brief          Computes average mark from the student marks
        /// @return         Scalar value represnting average mark (double)
        double computeAvg();

        /// @brief          Getter Name
        /// @return         m_name
        char* getName();

        /// @brief          Getter Surname
        /// @return         m_surname
        char* getSurname();

        /// @brief          Getter Marks
        /// @return         Pointer to the first element of the array
        uint16_t *getMarks();

        /// @brief          Getter Number of Marks
        /// @return         m_markCount
        uint16_t getMarksCount();
    private:
        char        *m_name;
        char        *m_surname;
        uint16_t    *m_marks;
        uint16_t    m_marksCount;
    };
    
    typedef struct {
        C_Student student;
        double avg_mark;
    } StudentSituation_t;

    C_Student::C_Student(char *name, char *surname, uint16_t *marks, uint16_t marksCount) : m_marksCount(marksCount) {
        size_t lenName = strlen(name);
        size_t lenSurname = strlen(surname);

        m_name = (char*)malloc(sizeof(char) * lenName);
        if(!m_name) {
            cout << "Failed to alloc memory for the name\n";
            return;
        }
        
        m_surname = (char*)malloc(sizeof(char) * lenSurname);
        if(!m_surname) {
            cout << "Failed to alloc memory for the surname\n";
            return;
        }

        m_marks = (uint16_t*)malloc(sizeof(uint16_t) * m_marksCount);
        if(!m_marks) {
            cout << "Failed to alloc memory for the marks\n";
            return;
        }
        
        strcpy(m_surname, surname);
        strcpy(m_name, name);
        memcpy(m_marks, marks, sizeof(uint16_t) * m_marksCount);
    }
    
    C_Student::~C_Student() {
        cout << "::DESTRUCTOR CALLED::\n";
    }

    double C_Student::computeAvg() {
        uint16_t sum = 0U;
        for(uint16_t i = 0U; i < m_marksCount; i++) {
            sum += m_marks[i];
        }

        return static_cast<double>(sum) / m_marksCount;
    }
    char *C_Student::getName() { return m_name; }

    char *C_Student::getSurname() { return m_surname; }

    uint16_t *C_Student::getMarks() { return m_marks; }

    uint16_t C_Student::getMarksCount() { return m_marksCount; }
} // namespace cls
