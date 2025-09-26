#include <iostream>
#include <cmath>
//Вариант 6
//Используя формулу Герона найти площадь треугольника с заданными сторонами.

int main(){

    int a = 1;  // Для хранения информации о длине стороны треугольника подходит тип int,
    int b = 1;  // так как сторона может быть только целым числом по условию.
    int c = 1;  

    std::cout << "Введите стороны треугольника через пробел: ";
    std::cin >> a >> b >> c;

    double p = (a + b + c)/2.0;   // Так как в сумме может получиться нечетное число, ему подойдет тип double. 

    double s = sqrt(p*(p-a)*(p-b)*(p-c)); /* В процессе вычисления могут использоваться 
                                            или появляться вещественные числа, для работы с которыми подойдет тип double */ 

    unsigned short bit_in_uns_short = sizeof(unsigned short) * 8; /*Число бит целочисленно, неотрицательно и не велико*/
    unsigned short bit_in_long_long = sizeof(long long) * 8;
    unsigned short bit_in_double = sizeof(double) * 8;

    unsigned short min_value_uns_short = std::numeric_limits<unsigned short>::min();   // так как в переменных хранятся мин и макс значения типа unsigned short, они лежат в его диапозоне значений.
    unsigned short max_value_uns_short = std::numeric_limits<unsigned short>::max();

    double min_value_double = std::numeric_limits<double>::lowest(); // так как в переменных хранятся мин и макс значения типа double, они лежат в его диапозоне значений.
    double max_value_double = std::numeric_limits<double>::max(); 

    std::cout << "Площадь треугольника равна: " << s << ". Значение хранится в переменной c типом double" << std::endl;
    std::cout << "unsigned short занимает " << bit_in_uns_short << " бит, мин. значение = " << min_value_uns_short << ", макс. значение = " << max_value_uns_short << std::endl;
    std::cout << "double, занимает " << bit_in_double << " бита, мин. значение = " << min_value_double << ", макс. значение = " << max_value_double << std::endl;
}
