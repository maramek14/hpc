#include <iostream>

int main() {
    int* ptr = new int;
    *ptr =42;

    std::cout << "Value of ptr: " << *ptr << std::endl;

    delete ptr;
    ptr= nullptr;

    std::cout << "Value of ptr: " << *ptr << std::endl;



    return 0;
}