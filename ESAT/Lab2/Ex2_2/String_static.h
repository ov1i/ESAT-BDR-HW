#pragma once
#include <cstring>
#include <cstdint>

constexpr uint8_t dim = 31;//30+1 for \0

class C_String {
    public:
    /// @brief          Default constructor
    C_String() =default;

    /// @brief          Explicit constructor
    /// @param x        -> x value to be set
    C_String(char x[dim]) {
        strcpy(m_sir, x);
    }

    /// @brief          Getter for our string
    /// @return         m_sir
    char* getSir( ) {
        return m_sir;
    }
    
    /// @brief          Operator + overloading for concatenation
    /// @param x1       -> String to be concatenated with
    /// @return         Returns a new instance of our class with the strings concatenated
    C_String operator+ (C_String x1) { // overloading with method (member function)
        C_String rez;
        strcpy(rez.m_sir, m_sir);//attention at m_sir length
        strcat(rez.m_sir, x1.m_sir);
        return rez;
    }

    /// @brief          Operator [] overloading for returning a character from a certain position
    /// @param poz      -> Index inside the string to be accessed 
    /// @return         Returns the value at the index specified location
    char operator[](int poz) {
        char rez;
        rez = m_sir[poz];
        return rez;
    }

    /// @brief          Friend function for overloading – operator
    /// @param x1       -> String from which we will remove
    /// @param x2       -> String we will remove
    /// @return         -> Returns a new string after the x2 was removed from x1
    friend C_String operator- (C_String& x1, C_String& x2);

    private:
        char m_sir[dim];
};//C_String

C_String operator- (C_String& x1, C_String& x2) {
    char* pp;
    char buf[dim];
    strcpy(buf, x1.m_sir);

    do {
        pp = strstr(buf, x2.m_sir);
        if(pp == NULL) {
            break;
        }
        else {
            strncpy(buf, buf, pp - x1.m_sir);
            strcpy(buf + (pp - buf), pp + strlen(x2.m_sir));
            
        }
    } while(pp != NULL);

    return C_String(buf);
}