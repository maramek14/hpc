#include <iostream>
#include <vector>
#include <chrono> // For measuring time

int main() {
    const int N = 10000000; // 10 million elements
    std::vector<int> numbers(N, 1); // Large array of integers

    std::vector<int> temp(N, 0); // Dummy variable to flush cache

    int sum = 0;

    // Measure time for sequential access
    auto start1 = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < N; i +=2) {
        sum += numbers[i]; // Accessing elements in order
    }
    auto end1 = std::chrono::high_resolution_clock::now();
    double time1 = std::chrono::duration<double, std::milli>(end1 - start1).count();

    temp.assign(N, 0); // Ensure cache is overwritten

    // Measure time for strided access (every 10th element)
    sum = 0;
    auto start2 = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < N; i += 10) {
        sum += numbers[i]; // Accessing every 10th element
    }
    auto end2 = std::chrono::high_resolution_clock::now();
    double time2 = std::chrono::duration<double, std::milli>(end2 - start2).count();

    std::cout << "Time for sequential access: " << time1 << " ms" << std::endl;
    std::cout << "Time for strided access: " << time2 << " ms" << std::endl;

    return 0;
}
