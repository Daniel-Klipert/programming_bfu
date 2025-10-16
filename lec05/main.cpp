#include <iostream>
#include <cmath>
#include <limits>



int main(){

    //Алгоритм распаковки натурального числа
     int x = 123;
     int sum = 0;
     int mult = 1;
     int max_d = 0;
     int min_d = 9;
     while (x > 0){
        int d = x % 10;
        sum += d;
        mult *= d;
        min_d = std::min(min_d, d);
        max_d = std::max(max_d, d);

        x /= 10;
     }
    std::cout << sum << std::endl;
    std::cout << mult << std::endl;
    std::cout << min_d << std::endl;
    std::cout << max_d << std::endl;
   
     //Область видимости
    int z = 1;
    {
       int y = z; //сработает
    }
    //z = y;  не сработает


    //Массивы
    const int len = 5;
    int arr[len];
    arr[0] = 5;
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 50;
    arr[4] = 10;

    for (int i =0; i < len - 1; ++i){
        for(int j = i+1; j < len; ++j){
            if(arr[i] > arr[j]){
                std::swap(arr[i],arr[j]);
            }
        }
    }
}