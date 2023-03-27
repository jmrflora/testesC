#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void exibirMatriz(int matriz[][5], int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void function (int m[][5], int linhas, int colunas){
    int i,j;
    for(i = 0;i<5;i++){

        for(j=0;j<5;j++){
            m[i][j] = j + 1 + i;
        }
    }
}

int main() {
    int matriz[5][5];
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            matriz[i][j] = 0;
        }
    }
    exibirMatriz(matriz, 5, 5);
    function(matriz,5,5);
    exibirMatriz(matriz, 5, 5);
    return 0;
}

