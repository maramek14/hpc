#include <iostream>
#include <vector>

int main() {
    const int N = 1000000000;
    std::vector<float> numbers(N,1.0f);

    float sum = 0.0f;
    int memory_accesses = 0;
    int computations = 0;

    for (int i = 0; i < N; i++){
        sum += numbers[i];
        computations++;
        memory_accesses += 2;
    }

    float arithmetic_intensity = (float)computations / memory_accesses;

    std::cout << "Final sum: " << sum << std::endl;
    std::cout << "Computations: " << computations << std::endl;
    std::cout << "Memory Accesses: " << memory_accesses << std::endl;
    std::cout << "Arithmetic Intensity: " << arithmetic_intensity << std::endl;

    return 0;
}
