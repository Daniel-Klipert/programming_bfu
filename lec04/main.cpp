#include <iostream>
#include <cmath>
#include <limits>



int main(){

    //Цикл
    int i = 1; 
    while (i <= 10){
        std::cout << i << std::endl;
        ++i;
    }

    for(int i = 1; i <= 10; ++i){
        std::cout << i << std::endl;
    }
    for(int i = 1;; ++i){
        std::cout << i << std::endl;
    }

    do {
        std::cout << i << std::endl;
    }  while(i < 1);

    
}