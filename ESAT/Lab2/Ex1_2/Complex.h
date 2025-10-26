#pragma once
#include <cmath>

namespace complx {
    class C_Complex {
    public:
        /// @brief          Explicit constructor
        /// @param real     -> Real part of the complex number
        /// @param im       -> Imaginary part of the complex number
        C_Complex(double real, double im);

        /// @brief          Default constructor
        C_Complex() = default;

        /// @brief          Default destructor
        ~C_Complex() = default;
        
        /// @brief          Getter for the real part of the complex number
        /// @return         -> m_real
        double getReal();

        /// @brief          Getter for the imaginary part of the complex number
        /// @return         -> m_im
        double getIm();

        /// @brief          Operator overloading using a method for allowing addition of 2 complex numbers
        /// @param          -> Complex number to be added from the current instance
        /// @return         -> Returns a pointer to a new instance after performing a custom addition
        C_Complex operator+(C_Complex&);

        /// @brief          Operator overloading using a method for allowing subtraction of 2 complex numbers
        /// @param          -> Complex number to be subtracted from the current instance
        /// @return         -> Returns a pointer to a new instance after performing a custom subtraction
        C_Complex operator-(C_Complex&);

        /// @brief          Operator overloading using a friend function for allowing multiplication of 2 complex numbers
        /// @param          -> First complex number
        /// @param          -> Second complex number
        /// @return         -> Returns a new instance after performing a custom multiplication of the two numbers
        friend C_Complex operator*(C_Complex&, C_Complex&);

        /// @brief          Operator overloading using a friend function for allowing division of 2 complex numbers
        /// @param          -> First complex number
        /// @param          -> Second complex number
        /// @return         -> Returns a new instance after performing a custom division of the two numbers
        friend C_Complex operator/(C_Complex&, C_Complex&);
    private:
        double m_real;
        double m_im;
    };
    
    C_Complex::C_Complex(double real, double im) {
        m_real = real;
        m_im = im;
    }

    double C_Complex::getReal() { return m_real; }

    double C_Complex::getIm() { return m_im; }

    C_Complex C_Complex::operator+(C_Complex &obj) {
        this->m_real += obj.m_real;
        this->m_im   += obj.m_im;

        return *this;
    }

    C_Complex C_Complex::operator-(C_Complex &obj) {
        this->m_real -= obj.m_real;
        this->m_im   -= obj.m_im;

        return *this;
    }

    C_Complex operator*(C_Complex &obj1, C_Complex &obj2) {
        double realPart = obj1.m_real * obj2.m_real - obj1.m_im * obj2.m_real;
        double imPart = obj1.m_real * obj2.m_im + obj1.m_im * obj2.m_real;
        C_Complex newObj(realPart,imPart);

        return newObj;
    }

    C_Complex operator/(C_Complex &obj1, C_Complex &obj2) {
        double denom = std::pow(obj2.m_real, 2) + std::pow(obj2.m_im, 2);
        double realPart = ((obj1.m_real * obj2.m_real) + (obj1.m_im * obj2.m_real)) / denom;
        double imPart = ((obj1.m_im * obj2.m_real) - (obj1.m_real * obj2.m_im)) / denom;
        C_Complex newObj(realPart,imPart);

        return newObj;
    }
} // namespace complx 