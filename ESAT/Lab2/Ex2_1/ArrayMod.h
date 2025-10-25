#pragma once

#include <climits>
#include <cstring>
namespace arrOps {
    class C_ArrayMod {
    public:
        /// @brief Explicit constructor
        /// @param arr Pointer to the array elements to be set inside our class
        /// @param size Size of the array
        C_ArrayMod(int *arr, int &size);

        /// @brief Explicit destructor
        ~C_ArrayMod();

        /// @brief Setter for a specific element inside the array
        /// @param idx Index in the array to be set
        /// @param value Value to be set
        void setArrayEl(int &idx, int &value);

        /// @brief Getter for the entire array
        /// @return returns the pointer to the array
        int *getArray();

        /// @brief Getter for a specific element inside the array
        /// @param idx Index in the array to be fetched
        /// @return returns the value at the specified index
        int getArrayEl(int &idx);

        /// @brief Getter for the size of our array
        /// @return returns the actual size of the array
        int getArraySize();

        /// @brief Displays the whole array
        void displayArray();

        /// @brief Performs subtraction on the 2 objects member array
        /// @param arrObj1 Object 1
        /// @param arrObj2 Object 2
        /// @return Returns a new object with the result of the subtraction. (If the source arrays have different lengths, the result has the length of the shortest array.)
        static C_ArrayMod sub(C_ArrayMod &arrObj1, C_ArrayMod &arrObj2);
    private:
        int *m_array;
        int  m_size;
    };
    
    C_ArrayMod::C_ArrayMod(int *arr, int &size) {
        m_size = size;

        m_array = (int*)malloc(sizeof(int) * m_size);
        if(!m_array) {
            cout << "Failed to allocate heap mem for the array\n";
            return;
        }

        std::memcpy(m_array, arr, size * sizeof(int));
    }
    
    C_ArrayMod::~C_ArrayMod() {
        if(m_array) {
            delete[] m_array;
        }
    }

    void C_ArrayMod::setArrayEl(int &idx, int &value) {
        if(idx < 0 || idx >= m_size) {
            cout << "Invalid index!\n";
            return;
        }

        m_array[idx] = value;
    }

    int *C_ArrayMod::getArray() { return m_array; }

    int C_ArrayMod::getArrayEl(int &idx) { 
        if(idx < 0 || idx >= m_size) {
            cout << "Invalid index!\n";
            return INT_MAX;
        }
        return m_array[idx]; 
    }

    int C_ArrayMod::getArraySize() {return m_size; }

    void C_ArrayMod::displayArray()
    {
        cout << "Array: ";
        for(int i = 0; i < m_size; i++) {
            cout << m_array[i] << " ";
        }
        cout << "\n\n";
    }

    C_ArrayMod C_ArrayMod::sub(C_ArrayMod &arrObj1, C_ArrayMod &arrObj2) {
        int size1 = arrObj1.getArraySize();
        int size2 = arrObj2.getArraySize();

        int size = size1 >= size2 ? size2 : size1;

        int *arr = (int*)malloc(sizeof(int) * size);

        for(int i = 0; i < size; i++) {
            arr[i] = arrObj1.getArrayEl(i) - arrObj2.getArrayEl(i);
        }
        return C_ArrayMod(arr, size);
    }

} // namespace arrOps 
