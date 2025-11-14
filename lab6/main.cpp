#include <iostream>
using namespace std;

//Вариант 6


int c = 0;

int* find_zeroes(int** matr, int M, int N){

    int* zeroes = (int*)malloc(M*N*sizeof(int));

    
    for (int m = 0; m < M; ++m){
        for (int n = 0; n < N; ++n){
            if (matr[m][n] == 0){
                zeroes[c] = m;
                ++c; 
                //break; 
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

    int matrix[M][N];

    for (int m = 0; m < M; ++m){
        for (int n = 0; n < N; ++n){
            int a;
            cin >> a;
            matrix[m][n] = a;
        }
    }

    int A = matrix[0][0];
    int B = matrix[0][1];
    int C = matrix[1][0];
    int D = matrix[1][1];

    int new_M = M + A;
    int new_N = N + B;

    int** dyn_matrix = (int**)calloc(new_M, sizeof(int*));
    for (int m = 0; m < new_M; ++m){
        dyn_matrix[m] = (int*)calloc(new_N, sizeof(int));

        for (int n = 0; n < new_N; ++n){

        if (m >= A && n >= B){
            dyn_matrix[m][n] = matrix[m - A][n - B];
        }
        else{
            dyn_matrix[m][n] = m*C + n*D;
        }
    }

    }



    

    
    int* zeroes = find_zeroes(dyn_matrix, new_M, new_N);
    int k = 0;
    for (int i = 0; i < new_M; ++i){
        
        for (int j = 0; j < c; ++j){
            if (i == zeroes[j]){
                free(dyn_matrix[i-k]);
                ++k;
                break;
            }
        }
        
    }
    new_M -= k;
for (int m = 0; m < new_M; ++m){
    cout << endl;
    for (int n = 0; n < new_N; ++n){
        cout << dyn_matrix[m][n] << '\t';
    }
}

free(zeroes);
free(dyn_matrix);
}


