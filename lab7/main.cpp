#include <iostream>
#include <vector>
#include <array>
using namespace std;

//Вариант 6

void p1(vector<int>& arr){
    cout << "[";
    for (int i = 0; i < arr.size(); ++i){
        if(i!= 0){
            cout << " ";
        }
        cout << arr.at(i);
    }
    cout << "]";
    cout << endl;
}
void p2(vector<int>& arr){
    int element;
    cin >> element;
    arr.insert(arr.begin(), element);
}
void p3(vector<int>& arr){
    int element;
    cin >> element;
    arr.push_back(element);
}
void p4(vector<int>& arr){
    arr.clear();
}
void p5(vector<int>& arr){
    int element;
    cin >> element;
    int s = arr.size();

    int c = 0;
        for (int i = 0; i < s; ++i){
            if (arr.at(i) == element){
                ++c;
            }
        }

    cout << "[";
    for (int i = 0; i < s; ++i){
        if (arr.at(i) == element){
            cout << i;

            if (c > 1){
            cout << ',';
            --c;
            }
        }
    }
    cout << "]";
}
void p6(vector<int>& arr){
    int c = 0;
    cout << "Было: ";
    p1(arr);
    cout << endl;
    for (int i = 0; i < arr.size(); i+= 2){
        if(abs(arr.at(i)) % 2 != 0){
            arr.insert(arr.begin()+i+1, 0);
            ++c;
            ++i;
        }
    }
    if (c == 0){
        arr.insert(arr.begin(), -1);
        arr.push_back(-1);
    }
    cout << "Стало: ";
    p1(arr);

}
void p7(vector<int>& arr){

    int k;
    cin >> k;

    cout << "Было: ";
    p1(arr);

    vector<int> kArr;
    bool cond = 0;
    int summ = 0;
    for (int i = 1; i <= k; ++i){
        if (summ + i <=k){
            summ += i;
            kArr.push_back(i);   
        }
        if (summ==k){
            cond = true;
            break;
        } else if (summ + i > k){
            break;
        }
    }
    int j = 2;
    if(cond){
        int cb = 0;
        int switcher = 1; 
        for (int i = 0; i < kArr.size(); i+=1){
            if(switcher){
                arr.insert(arr.begin()+cb, kArr.at(i));
                ++cb;
                --switcher;
            }else{
                arr.push_back(kArr.at(i)); 
                ++switcher;
            }
        }
    } else{
        for (int i = 0; i < arr.size(); i+= 2){
            arr.insert(arr.begin()+i+1, arr.at(i));
            ++i;
        }

    }
    cout << "Стало: ";
    p1(arr);

}
void console_menu(){

    vector<int> array;
    array.reserve(1000);

    int p = 1;

    while(p){
        cout << "0. Выход." << endl;
        cout << "1. Просмотр массива." << endl;
        cout << "2. Добавить элемент в начало." << endl;
        cout << "3. Добавить элемент в конец." << endl;
        cout << "4. Очистка всего массива." << endl;
        cout << "5. Поиск элемента в массиве." << endl;
        cout << "6. В массиве после каждого нечетного числа стоящего на четной позиции вставить 0, если таких нет – добавить -1 в начале и в конце." << endl;
        cout << "7. Добавить слагаемые(ДОП)" << endl;
        cout << "Выберите пункт: ";
        cin >> p;
        cout << endl;

        if (p == 0){
            break;
        } else if (p == 1){
            p1(array);
        } else if (p == 2){
            p2(array);
        } else if (p == 3){
            p3(array);
        } else if (p == 4){
            p4(array);
        } else if (p == 5){
            p5(array);
        } else if (p == 6){
            p6(array);
        }else if (p == 7){
            p7(array);
        }
        cout << endl;
    }
}
void read_array(array<int, 10> arr){
        cout << "[";
    for (int i = 0; i < arr.size(); ++i){
        if(i!= 0){
            cout << " ";
        }
        cout << arr.at(i);
    }
    cout << "]";
}
void my_sort(array<int, 10> arr, bool reverse){
    cout << "Передача аргумента по значению: ";
    int s = arr.size();

    for (int i = 0; i < s; ++i){
        for (int j = i + 1; j < s; ++j){
            if (!reverse){
                if(arr.at(i) > arr.at(j)){
                    swap(arr.at(i), arr.at(j));
                }
            } else {
                if(arr.at(i) < arr.at(j)){
                    swap(arr.at(i), arr.at(j));
                }   
            }
        }
    }
    
    read_array(arr);
    cout << endl;
    cout << "Массив поменялся внутри функции, но не снаружи: ";
}
void my_sort_r(array<int, 10>& arr, bool reverse){
    cout << "Передача аргумента по ссылке: ";
    int s = arr.size();

    for (int i = 0; i < s; ++i){
        for (int j = i + 1; j < s; ++j){
            if (!reverse){
                if(arr.at(i) > arr.at(j)){
                    swap(arr.at(i), arr.at(j));
                }
            } else {
                if(arr.at(i) < arr.at(j)){
                    swap(arr.at(i), arr.at(j));
                }   
            }
        }
    }
    
    read_array(arr);
    cout << endl;
    cout << "Массив поменялся как внутри функции, так и снаружи: ";
}
void my_sort_p(array<int, 10>* arr, bool reverse){
cout << "Передача аргумента по указателю: ";
    int s = (*arr).size();
    for (int i = 0; i < s; ++i){
        for (int j = i + 1; j < s; ++j){
            if (!reverse){
                if((*arr).at(i) > (*arr).at(j)){
                    swap((*arr).at(i), (*arr).at(j));
                }
            } else {
                if((*arr).at(i) < (*arr).at(j)){
                    swap((*arr).at(i), (*arr).at(j));
                }   
            }
        }
    }
    
    read_array(*arr);
    cout << endl;
    cout << "Массив поменялся как внутри функции, так и снаружи: ";
}
int main(){
    // ПУНКТ 1
    console_menu();

    // ПУНКТ 2
    const int N = 10;
    array<int, N> my_array;

    my_array = {9,1,-3,6,7,-1,-8,-7,-10,9};
    my_sort(my_array, 0);
    read_array(my_array);
    cout << endl;
    cout << "Для обращения к аргументу внутри функции не требуется разыменование (*arr)" << endl;
    cout << endl;

    my_array = {9,1,-3,6,7,-1,-8,-7,-10,9};
    my_sort_r(my_array, 0);
    read_array(my_array);
    cout << endl;
    cout << "Для обращения к аргументу внутри функции требуется разыменование (*arr)" << endl;
    cout << endl;

    my_array = {9,1,-3,6,7,-1,-8,-7,-10,9};
    my_sort_p(&my_array, 1);
    read_array(my_array);
    cout << endl;
    cout << "Для обращения к аргументу внутри функции не требуется разыменование (*arr)" << endl;
    cout << endl;


    // ПУНКТ 3

    /*
    Пункт 1 требует использование std::vector, так как необходим динамический массив.
    Пункт 2 требует использование std::array, так как необходим статический массив.
    При этом и std::vector, и std::array можно использовать для задач со статическим массивом.
    */
}