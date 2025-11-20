#include <iostream>
#include <vector>
using namespace std;
void foo(const int n){
    //int& nc = const_cast<int*>(n)
    //nc = 9 --- можно


    //n = 10; нельзя
}
void bar(int& x){
    
    x = 9;
}

int main(){
    const int N = 10; // инициализация сразу
    const int x = 10;
    const int* px = &x;  //   указатель на константу

    //*px = 11;  Нельзя
    int y = 5;
    int* const py = &y;  // константный указатель



    cout << px << endl;
    cout << *px << endl;


    int t = 7;
    int& rt = t;
    int g = 15;
    cout << t << endl;
    rt = g;
    cout << t << endl;
    bar(t);
    cout << t << endl;



    // массив фиксированной длины
    int arr[20] = {1,2,3,4,5,6};// стек
    cout << *arr << endl;       // 'элемент с 0 индексом      arr[0]
    cout << *(arr + 1) << endl; // 'элемент с 1 индексом      arr[1]
    cout << sizeof(arr) << endl; //

    // динамический массив
    int* arr_dyn = new int[20];

    *arr_dyn = 0;
    *(arr_dyn + 1) = 0; // arr_dyn[1] = 0;

    delete[] arr_dyn;


    // Vector - динамический массив

    vector<int> vec(20);
    vec[1] = 1;
    vec.push_back(21);

    vec.resize(30);
    vec.reserve(40);

    using Vector = vector<int>;
    Vector vec[90];
}