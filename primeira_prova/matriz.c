#include <stdio.h>
#include <stdlib.h>

#define MATRIX_ROWS 10
#define LIST_SIZE 10

// Função para obter o valor da matriz com base nas posições fornecidas
int multi(int f1, int f2, const int matriz[MATRIX_ROWS][LIST_SIZE]) {

    return matriz[f1 - 1][f2 - 1];
}

int main() {
    // Declaração da matriz
    int matrix[MATRIX_ROWS][LIST_SIZE];
    int resul;

    // Preenchimento da matriz
    for (int i = 0; i < MATRIX_ROWS; i++) {
        for (int j = 0; j < LIST_SIZE; j++) {
            matrix[i][j] = (j + 1) * (i + 1);
        }
    }

    resul = multi(2,9,matrix);

    printf("%d", resul);
    return 0;
}
