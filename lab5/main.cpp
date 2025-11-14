#include <iostream>
#include <cmath>


//Вариант 6

/*  
Условия:    В начале каждой функции выводить текст с информацией какая именно функция используется 
            например "исп. функция суммы 2х чисел", числа вводятся целые, для выбора какая функция должна вызываться 
            в п. 1 использовать правило "если число = 0, считаем что его нет" т.е. ввод (1;0;2) считать как два числа, 
            (1;5;3) как три числа, а (0;0;7) как одно число. Функции в п. 1 должны вернуть численное значение.
            Реализовать возможность для пользователя ввести номер  пункта который будет выполняться (1 или 2).
            Задание п.2 написано после всех вариантов и является обобщенным упрощение, все желающие могут сделать дополнительное задание.
            Разбиение на файлы не обязательно.

*/
int find_digits(int number){
    std::cout << "Используется функция подсчета разрядов числа" << std::endl;

    int digits = 0;
    while(number > 0){
        number /= 10;
        ++digits;
    }
    return digits;
}

int function(int N ,int arr[]){
    std::cout << "Используется функция склеивания чисел" << std::endl;
    int result;
    int digits = 0;
    for (int i = N - 1; i >= 0; --i)
    {
        if(arr[i] != 0){
            result += arr[i] * pow(10, digits);
            digits = find_digits(result);
        } else {
            continue;
        }
    }
    return result;
}

int function(int a){
    std::cout << "Используется функция нахождения противоположного числа" << std::endl;
    return a * (-1);
}

void p1(){
    std::cout << "Используется функция Пункта 1" << std::endl;

    const int N = 3;
    int arr[N];
    std::cout << "Введите "<< N <<" чисел: " << std::endl;
    
    for (int i = 0; i < N; ++i)
    {
        std::cin >> arr[i];
    }
    int elements = 0;
    int index;
    for (int i = 0; i < N; ++i)
    {
        if (arr[i] != 0)
        {
            ++elements;
            index = i;
        }
        
    }
    int result = 0;
    if (elements == 2)
    {
        result = function(N, arr);
    } else if(elements == 1){
        result = function(arr[index]);
    }
    std::cout << "Результат работы функции: " << result << std::endl;
    

}

void p2(int a, int b, int c){
        std::cout << "Используется функция Пункта 2" << std::endl;

  // Для хранения информации о длине стороны треугольника подходит тип int,
  // так как сторона может быть только целым числом по условию.
  

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

void choose_p(){
    std::cout << "Используется функция выбора пункта" << std::endl;
    std::cout << "Выберите пункт: ";
    int p;
    std::cin >> p;
    switch (p)
    {
    case 1:
        p1();
        break;
    case 2:
        int a;
        int b;
        int c;
        std::cout << "Введите стороны треугольника через пробел: ";
        std::cin >> a >> b >> c;

        p2(a,b,c);
        break;
    default:
        break;
    }
}

int main(){

//  1)  Для двух чисел – вернуть их склеенную запись в порядке ввода (если А=1, В=34, то АВ=134).

    
//  2)  Для одного числа – противоположное ему.
bool yes = 0;
do{
    choose_p();
    std::cout << "Продолжить? ";
    std::cin >> yes;
    std::cout << std::endl;
}while(yes);

}
