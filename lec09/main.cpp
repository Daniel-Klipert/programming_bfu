#include <iostream>
#include "circle.hpp"



int main(){
//std::cout << kd::radius(3) << std::endl;

int* p = new int;
int* px = (int*)malloc(sizeof(int));
*p = 20;

std::cout << *p << std::endl;
delete p;
free(px);

int* arr_dyn = new int[10];
delete[] arr_dyn;
}