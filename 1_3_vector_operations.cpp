#include <iostream>
#include <memory>
using namespace std;
// Function to perform element-wise vector addition using dynamic memory
unique_ptr<int[]> vecadd(const int* a, const int* b, size_t size) {
    unique_ptr<int[]> result(new int[size]);
    for (size_t i = 0; i < size; i++) {
        result[i] = a[i] + b[i];
    }
    return result;
}

// Function to compute the dot product of two vectors using pointers
int dot(const int* a, const int* b, size_t size) {
    int result = 0;
    for (size_t i = 0; i < size; i++) {
        result += a[i] * b[i];
    }
    return result;
}

// Function to perform matrix multiplication using dynamic memory allocation
unique_ptr<unique_ptr<int[]>[]> multiply(const int* const* A, const int* const* B, size_t rows, size_t inner, size_t cols) {
    auto result = make_unique<unique_ptr<int[]>[]>(rows);
    for (size_t i = 0; i < rows; i++) {
        result[i] = make_unique<int[]>(cols);
        for (size_t j = 0; j < cols; j++) {
            result[i][j] = 0;
            for (size_t k = 0; k < inner; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return result;
}

int main() {
    size_t size = 3;
    unique_ptr<int[]> vec1(new int[size]{1, 2, 3});
    unique_ptr<int[]> vec2(new int[size]{4, 5, 6});
    
    // Test vector addition
    unique_ptr<int[]> sum = vecadd(vec1.get(), vec2.get(), size);
    cout << "Vector addition result: ";
    for (size_t i = 0; i < size; i++) cout << sum[i] << " ";
    cout << endl;
    
    // Test dot product
    cout << "Dot product result: " << dot(vec1.get(), vec2.get(), size) << endl;
    
    // Test matrix multiplication
    size_t rows = 2, cols = 2, inner = 2;
    auto mat1 = make_unique<unique_ptr<int[]>[]>(rows);
    auto mat2 = make_unique<unique_ptr<int[]>[]>(inner);
    for (size_t i = 0; i < rows; i++) {
        mat1[i] = make_unique<int[]>(inner);
        for (size_t j = 0; j < inner; j++) {
            mat1[i][j] = (i * inner) + j + 1;
        }
    }
    for (size_t i = 0; i < inner; i++) {
        mat2[i] = make_unique<int[]>(cols);
        for (size_t j = 0; j < cols; j++) {
            mat2[i][j] = (i * cols) + j + 5;
        }
    }
    
    auto product = multiply(mat1.get(), mat2.get(), rows, inner, cols);
    
    cout << "Matrix multiplication result:" << endl;
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) cout << product[i][j] << " ";
        cout << endl;
    }
    
    return 0;
}
