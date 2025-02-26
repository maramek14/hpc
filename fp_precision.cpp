#include <iostream>
#include <iomanip>

int main() {
    float sum = 0.0f;

    for (int i = 0; i<10; i++){
        sum += 0.1f;
    }

    double sum2 = 0.0;
    for (int i = 0; i < 10; i++)
    {
        sum2 += 0.1;
    }
    
    float sumk = 0.0f, c=0.0f;

    for (int i = 0; i < 10; i++)
    {
        float y = 0.1f-c;
        float t = sumk + y;
        c= (t-sumk)-y;
        sumk = t;
    }
    

    std::cout << "Double Precision Result: " << sum2 << std::endl;
    std::cout << std::fixed << std::setprecision(10);
    std::cout << "Kahan Summation Result: " << sumk << std::endl;
    std::cout << "Expected Result: 1.0" << std::endl;
    std::cout << "Actual Result: " << sum << std::endl;

    return 0;
}