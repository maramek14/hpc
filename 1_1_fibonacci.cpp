#include <iostream>
#include <vector>

int main() {
    const int N=15;
    std::vector <int> fibo(N);
    fibo[0] = 1;
    fibo[1]=1;

    for (int i=2; i<15; i++){
    
       fibo[i]=fibo[i-1]+fibo[i-2];
       
    }

    std::cout << "Fibonacci sequence is: " ;
    for (int element : fibo){
        std::cout << element << " ";

    } 
    std::cout << std::endl;

    return 0;
    
}