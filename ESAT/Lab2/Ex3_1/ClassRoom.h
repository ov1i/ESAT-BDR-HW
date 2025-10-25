#pragma once
#include <cstdint>
#include <cstring>

namespace cls {

    constexpr uint8_t NO_OF_MARKS = 7;
    constexpr uint8_t CHAR_ARR_MAX_LEN = 255;
    class C_Student {
    public:
        /// @brief          Explicit Constrcutor
        /// @param name     -> Student name
        /// @param surname  -> Student surname
        /// @param marks    -> Student marks (7)
        /// @param group    -> Student group
        C_Student(char *name, char *surname, uint16_t *marks, uint16_t group);

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

        /// @brief          Getter Group
        /// @return         m_group
        uint16_t getGroup();
    private:
        char        *m_name;
        char        *m_surname;
        uint16_t     m_marks[NO_OF_MARKS];
        uint16_t    m_group;
    };
    
    typedef struct {
        C_Student student;
        double avg_mark;
    } StudentSituation_t;

    C_Student::C_Student(char *name, char *surname, uint16_t *marks, uint16_t group) : m_group(group) {
        size_t lenName = strlen(name);
        size_t lenSurname = strlen(surname);

        m_name = (char*)malloc(lenName * sizeof(char));
        if(!m_name) {
            cout << "Failed to alloc memory for the name\n";
            return;
        }
        
        m_surname = (char*)malloc(lenSurname * sizeof(char));
        if(!m_surname) {
            cout << "Failed to alloc memory for the surname\n";
            return;
        }
        
        strcpy(m_surname, surname);
        strcpy(m_name, name);
        memcpy(&m_marks, marks, sizeof(uint16_t) * 7);
    }
    
    C_Student::~C_Student() {
        cout << "::DESTRUCTOR CALLED::\n";
    }

    double C_Student::computeAvg() {
        uint8_t sum = 0U;
        for(uint8_t i = 0U; i < 7U; i++) {
            sum += m_marks[i];
        }

        return static_cast<double>(sum) / 7.0;
    }
    char *C_Student::getName() { return m_name; }

    char *C_Student::getSurname() { return m_surname; }

    uint16_t *C_Student::getMarks() { return &m_marks[0]; }

    uint16_t C_Student::getGroup() { return m_group; }
} // namespace cls
