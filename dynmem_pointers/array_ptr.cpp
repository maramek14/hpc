#include <iostream>

int main() {

        int size = 5;
        int* arr = new int[size];

        for (int i = 0; i<size; i++ ){
            arr[i]=2*i;
        }

        std::cout << "Array Elements: ";
        for (int i = 0; i < size; i++)
        {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;

        delete[] arr;
        arr = nullptr;

        return 0;
        
}