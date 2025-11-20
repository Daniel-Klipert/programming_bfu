#include <iostream>
using namespace std;

//Вариант 6


int c = 0;

int* find_zeroes(int** matr, int M, int N){

    int* zeroes = (int*)malloc(M*sizeof(int));

    for (int m = 0; m < M; ++m){
        for (int n = 0; n < N; ++n){
            if (matr[m][n] == 0){
                zeroes[c] = m;
                ++c; 
                break; 
            }
        }
    }

    if (c > 0){
    zeroes = (int*)realloc(zeroes, c*sizeof(int));
    }
    else{
        zeroes = (int*)realloc(zeroes, sizeof(int));
        zeroes[0] = -1;
    }
    return zeroes;
}


int main(){

    int M = 2;
    int N = 2;

    int** dyn_matrix = (int**)calloc(M, sizeof(int*));

    for (int m = 0; m < M; ++m){
        dyn_matrix[m] = (int*)calloc(N, sizeof(int));
        for (int n = 0; n < N; ++n){
            int a;
            cin >> a;
            while((m == 0) && (a<0)){
                cout << "Ошибка" << endl;
                cin >> a;
            }
            dyn_matrix[m][n] = a;
        }
    }

    int A = dyn_matrix[0][0];
    int B = dyn_matrix[0][1];
    int C = dyn_matrix[1][0];
    int D = dyn_matrix[1][1];

    int new_M = M + A;
    int new_N = N + B;

    dyn_matrix = (int**)realloc(dyn_matrix, new_M*sizeof(int*));

    for (int m = M; m < new_M; ++m){
        dyn_matrix[m] = (int*)calloc(new_N, sizeof(int));
    }

    for (int m = 0; m < new_M; ++m){
        dyn_matrix[m] = (int*)realloc(dyn_matrix[m], new_N*sizeof(int));
    }
        
    for (int m = new_M - 1; m >= 0; --m){
        for (int n = new_N - 1; n >= 0; --n){

            if ((m >= A) && (n >= B)){
                dyn_matrix[m][n] = dyn_matrix[m-A][n-B];
            }
            else{
                dyn_matrix[m][n] = m*C + n*D;
            }
        }

    }

    int* zeroes = find_zeroes(dyn_matrix, new_M, new_N);
    int r = 0;
    for (int i = 0; i < new_M; ++i){

        for (int j = 0; j < c; ++j){
            if (i == zeroes[j]){

                free(dyn_matrix[i - r]);
                for (int k = i - r; k < new_M - 1; ++k) {
                    dyn_matrix[k] = dyn_matrix[k + 1];
                }
                ++r;
                
                dyn_matrix = (int**)realloc(dyn_matrix, (new_M - r) * sizeof(int*));
                break;
            
            }
        }
    }

    new_M -= r;
    for (int m = 0; m < new_M; ++m){
        cout << endl;
        for (int n = 0; n < new_N; ++n){
            cout << dyn_matrix[m][n] << '\t';
        }
        cout << endl;
    }

    free(zeroes);
    for (int m = 0; m < new_M; ++m) {
		free(dyn_matrix[m]);
	}
    free(dyn_matrix);





int* pa = new int;
int* pb = new int;

cin >> *pa;
cin >> *pb;

*pa *= 2;

int* pTmp = new int;
*pTmp = *pa;
*pa = *pb;
*pb = *pTmp;

delete pa;
delete pb;
delete pTmp;
}