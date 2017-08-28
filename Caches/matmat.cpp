#include <iostream> 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

#define MAX 10

int **crear_matrix(){
    int **matrix = new int*[MAX];

    for(int i=0;i<MAX;i+=1){
        matrix[i]=new int[MAX];
        for(int a=0;a<MAX;a+=1){
            matrix[i][a]=rand()%100000;
        }
    }
    return matrix;
}

int **matrix_ceros(){
    int **matrix = new int*[MAX];

    for(int i=0;i<MAX;i+=1){
        matrix[i]=new int[MAX];
        for(int a=0;a<MAX;a+=1){
            matrix[i][a]=0;
        }
    }
    return matrix;
}

void mostrar_matrix(int **matrix){
    for(int i=0;i<MAX;i++){
        for(int a=0;a<MAX;a++){
            cout << matrix[i][a] << '\t';
        }
        cout << endl;
    }
}

int **mult(int **a, int **b){
	int **y = matrix_ceros();
	for(int i = 0; i < MAX; i++){
		for(int j = 0; j < MAX; j++){
			for(int k = 0; k < MAX; k++){
				y[i][j] += a[i][k] * b[k][j];
			}
		}
	}
	return y;
}

int **multbloq(int **a, int **b){
	int **y = matrix_ceros();
	int tm = MAX/10;
	for(int i = 0; i < MAX; i+=tm){
		for(int j = 0; j < MAX; j+=tm){
			for(int k = 0; k < MAX; k+=tm){
				for(int i2 = i; i2 < i+tm; i2++){
					for(int j2 = j; j2 < j+tm; j2++){
						for(int k2 = k; k2 < k+tm; k2++){
							y[i2][j2] += a[i2][k2] * a[k2][j2];
						}
					}
				}
			}
		}
	}
	return y;
}

int main(int argc, char const *argv[])
{
	int **a = crear_matrix();
	int **b = crear_matrix();
	int **r = multbloq(a,b);
	return 0;
}