#include <iostream>
#include <cmath>
#include <utility>
#include <boost/timer/timer.hpp>


double leibniz(int n1) {
    double sum = 0.0;
    for (int k = 0; k < n1; k++)
        {
            sum += pow(-1,k)/(2.0 *k+1);
        }
    
    
    return {sum*4};
    
}

double wallis(int n2) {
    double product = 1.0;
    for (int k = 1; k < n2; k++)
        {
            product *= (4*pow(k,2)/(4*pow(k,2)-1));
        }
    
    
    return {product*2};
}

int main(){
    boost::timer::auto_cpu_timer t; 
    int n1=0;
    int n2=0;
    int gap=100;
    double pi_leib= leibniz(n1);
    double pi_wallis = wallis(n2);

    while (std::abs((pi_leib-M_PI))>= 0.5e-7){
        n1+= gap;
        pi_leib= leibniz(n1);
    }



    while (std::abs((pi_wallis-M_PI))>= 0.5e-7){
        n2+=gap;
        pi_wallis=wallis(n2);
    }

    n1=n1+gap;
    n2=n2+gap;
    pi_leib=leibniz(n1);
    pi_wallis=wallis(n2);

    std::cout << "leibniz pi approximation is: " << pi_leib << " with n= "<< n1 << std::endl;
    std::cout << "wallis pi approximation is: " << pi_wallis << " with n=" << n2 << std::endl;
    std::cout << "pi is: " << M_PI << std::endl;

    return 0;
}