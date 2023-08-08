#include<iostream>
#include<cassert>
#include<cstddef>

/*
13.9 Destructors
special type of class member function that is executed when the object of that
class is destroyed
it is needed if the object holds any resources of if any maintenance needs to be 
done before the object is destroyed
Naming Rules:
 1. same name as class preceded by a tilde(~)
 2. it cant take arguments
 3. no return type

there can only be one destructor


*/


class IntArray {
private:
    int* m_array{};
    int m_length{};
public:
    IntArray(int length) {
        assert(length > 0);

        m_array = new int[static_cast<std::size_t>(length)]{};
        m_length = length;
    }

    ~IntArray() { // destructor
        delete[] m_array;
    }
    void setValue(int index, int value) { m_array[index] = value; }
    int getValue(int index) { return m_array[index]; }

    int getLength() { return m_length; }
};

int main() {
    IntArray ar ( 10 ); //allocate 10 integers; when initializing an array we use round brackets
    for (int count{ 0 }; count < ar.getLength(); ++count) {
        ar.setValue(count, count + 1);
    }
    std::cout << "The value of element 5 is: " << ar.getValue(5) << '\n';
    
    return 0;
} // ar is destroyed here so the ~IntArray() destructor is called here