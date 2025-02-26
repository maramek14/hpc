#include <iostream>

void modifyValue(int* ptr){
    *ptr = 100;
}

int main() {
    int num = 50;
    std::cout << "Before: " << num << std::endl;

    modifyValue(&num);

    std::cout << "After: " << num << std::endl;

    return 0;
}