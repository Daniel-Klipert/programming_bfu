#include <iostream>
#include <limits>

//Вариант 6

/*  
Условия:    В пункте 1, размер массива равен №варианта + 3.
            В пункте 2, матрицы формата 3 строки х 4 столбца.
            Числа вводятся корректно и все они типа int. Из нескольких одинаковых значений выбирать первое.

*/

int main(){

//  1)  Упорядочить массив по возрастанию, если есть число, начинающееся с 3.

    int lenght = 9;
    int array[lenght];
    std::cout << "Введите " << lenght << " значений: ";
    for (int i = 0; i < lenght; ++i){
        std::cin >> array[i]; 

    }
    bool is_have = 0;
    for (int i = 0; i < lenght; ++i){
        int number = abs(array[i]);
        int digit = 0;
        while (number != 0){
            digit = number % 10;
            number /= 10;
        }
        if (digit == 3){
            is_have = 1;
            break;
        }
    }
    if (is_have){
        for (int i = 0; i < lenght - 1; ++i){
            
            
            for (int j = i + 1; j < lenght; ++j){
                for (int k = 0; k < lenght; ++k){
            }
                
                int left = array[i];
                int right = array[j];

                if (right < left){
                    array[i] = right;
                    array[j] = left;
                }

        }
        }
        for (int k = 0; k < lenght; ++k){
                std::cout << array[k] << " ";
            }
    } else{
        std::cout << "Ни одно число не начинается с цифры 3";
    }
    std::cout << std::endl;
//  2)  Найти строку с максимально отдаленным от 0 значением суммы элементов и заменить все значения в ней на 999.
    int rows = 3;
    int columns = 4;
    int matrix[rows][columns];

    for (int i = 0; i < rows; ++i){
        std::cout << "Введите " << columns << " элементов " << i + 1 << " строки" << std::endl;
        for (int j = 0; j < columns; ++j){
            std::cin >> matrix[i][j];
        }
    }
    int max_sum;
    int row;
    bool first_sum = 1;

    for(int i = 0; i < rows; ++i){
        int cur_sum = 0;
        for(int j = 0; j < columns; ++j){
            cur_sum += matrix[i][j];
        }
        if (first_sum){
            max_sum = cur_sum;
            row = i;
            first_sum = 0;
        }
        if (abs(max_sum) < abs(cur_sum)){
            max_sum = cur_sum;
            row = i;
        }
    }

    for (int i = 0; i < columns; ++i){
        matrix[row][i] = 999;
    }
    for(int i = 0; i < rows; ++i){
        std::cout << std::endl;
        for(int j = 0; j < columns; ++j){
            std::cout << matrix[i][j] << " ";
        }
    }

}
