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
    zeroes = (int*)realloc(zeroes, c);
    }
    else{
        zeroes = (int*)realloc(zeroes, 1);
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
            dyn_matrix[m][n] = a;
        }
    }


    int A = dyn_matrix[0][0];
    int B = dyn_matrix[0][1];
    int C = dyn_matrix[1][0];
    int D = dyn_matrix[1][1];

    int new_M = M + A;
    int new_N = N + B;

    dyn_matrix = (int**)realloc(dyn_matrix, new_M);
    for (int m = 0; m < new_M; ++m){
        dyn_matrix[m] = (int*)realloc(dyn_matrix[m], new_N);

        for (int n = 0; n < new_N; ++n){

            if (m >= A && n >= B){
                continue;
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
                ++r;
                for (int k = i - r ; k < new_M - r;++k){
                    free(dyn_matrix[k]);
                    dyn_matrix[k] = dyn_matrix[k + 1];
                }
                free(dyn_matrix[new_M - r]);
                dyn_matrix = (int**)realloc(dyn_matrix, new_M - r);
                
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
    }

    free(zeroes);
    for(int m =0; m < new_M; ++m){
        free(dyn_matrix[m]);
    }
    free(dyn_matrix);

}

