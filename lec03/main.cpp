#include <iostream>
#include <cmath>
#include <limits>

//using std::cin;

int main(){
/*
    float r = 2;
    const double PI = acos(-1);
    float S = PI*r*r;

    std::cout << S << std::endl;
    */

    
    //std::cout << std::numeric_limits<int>::max();

    
  /*  int x = 0b0010;
    int y = x << 1;  // x*2^1
    //0b0100
    int z = x >> 1ж // x/2^1
    //0b0001
    std::cout << y << std::endl;

    //битовые операции
    int a = 0b0010;
    int b = 0b1110;
    // a & b = 0b0010   И
    // a | b = 0b1110   ИЛИ
    // ~a = 0b0001
    // a ^ b = 0b1100  XOR*/


    int x = 11;
    bool isEven = x % 2;

    // Логические операторы 
    // ==, !=,  <, >, <=, >=, !, &&, ||
    int a = 10;
    int b = 11;
    std::cout << ((a < b) && (b%2 == 0)) << std::endl;

    if (isEven) {
        std::cout << "Even" << std::endl;
    } else {
        std::cout << "Odd" << std::endl;
    }
    int number = 5;
    switch(number){
        case 0: break;
        case 1: break;
        // ...
        default: break;
    }
    //тернарный оператор
    std::cout << (a % 2 == 0 ? "Even" : "Odd");

}