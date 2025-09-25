#include <iostream>
#include <cmath>
//Вариант 6
//Используя формулу Герона найти площадь треугольника с заданными сторонами.

int main(){
    double a = 0;  // Для хранения информации о длине стороны треугольника подходит тип double,
    double b = 0;  // так как сторона может быть не целым числом, например 2.5, 
    double c = 0;  // а double хранит числа с плавающей точкой.

    std::cout << "Введите стороны треугольника через пробел: ";
    std::cin >> a >> b >> c;

    double p = (a + b + c)/2;   // Так как полупериметр может быть суммой вещественных чисел, ему тоже подойдет тип double. 

    double s = sqrt(p*(p-a)*(p-b)*(p-c)); /* Так же, как и с полупериметром, в процессе вычисления могут использоваться 
                                            или появляться вещественные числа, для работы с которыми подойдет тип double */ 

    unsigned short bit_in_uns_short = 16; // кол-во бит целое и не отрицательное, входит в диапозон значений unsigned short
    unsigned short bit_in_long_long = 64;
    unsigned short bit_in_double = 64;

    unsigned short min_value_uns_short = 0;   // так как в переменных хранятся мин и макс значения типа unsigned short, они лежат в его диапозоне значений.
    unsigned short max_value_uns_short = pow(2, bit_in_uns_short) -1 ;

    std::cout << "Площадь треугольника равна: " << s << ". Значение хранится в переменной c типом double" << std::endl;
    std::cout << "unsigned short занимает " << bit_in_uns_short << " бит, мин. значение = " << min_value_uns_short << ", макс. значение = " << max_value_uns_short << std::endl;
    std::cout << "double, занимает " << bit_in_double << " бита, кол-во значащих десятичных цифр: 15-16 " << std::endl;
}
