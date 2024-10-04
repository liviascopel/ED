#include "matriz.h"

#include <stdio.h>
#include <stdlib.h>

struct matriz {
    int linhas;
    int colunas;
    int ** matriz;
};

Matriz* InicializaMatriz (int nlinhas, int ncolunas) {

    Matriz * mat = (Matriz*) calloc (1, sizeof(Matriz));

    mat->matriz = (int**) calloc (1, nlinhas * sizeof(int*));
    for (int i = 0; i < nlinhas; i++) {
        mat->matriz[i] = (int*) calloc (1, ncolunas * sizeof(int));
    }

    mat->linhas = nlinhas;
    mat->colunas = ncolunas;

    return mat;
}

void modificaElemento (Matriz* mat, int linha, int coluna, int elem) {

    mat->matriz[linha][coluna] = elem;
}

int recuperaElemento(Matriz* mat, int linha, int coluna) {

    return mat->matriz[linha][coluna];
}

int recuperaNColunas (Matriz* mat) {

    return mat->colunas;
}

int recuperaNLinhas (Matriz* mat) {

    return mat->linhas;
}

Matriz* transposta (Matriz* mat) {

    Matriz* transposta = InicializaMatriz(mat->colunas, mat->linhas);

    for (int i = 0; i < mat->colunas; i++) {
        for (int j = 0; j < mat->linhas; j++) {
            transposta->matriz[i][j] = mat->matriz[j][i];
        }
    }

    return transposta;
}

Matriz* multiplicacao (Matriz* mat1, Matriz* mat2) {
    //condicao: o numero de colunas da mat1 == numero de linhas da mat2
    Matriz* multiplica = InicializaMatriz(mat1->linhas, mat2->colunas);
    
    if (mat1->colunas == mat2->linhas) {
        for (int i = 0; i < multiplica->linhas; i++) {
            for (int j = 0; j < multiplica->colunas; j++) {
                for (int k = 0; k < multiplica->colunas; k++) {
                    multiplica->matriz[i][j] += mat1->matriz[i][k] * mat2->matriz[k][j];
                }
            }
        }
    }
    return multiplica;
}

void imprimeMatriz(Matriz* mat) {

    for (int i = 0; i < mat->linhas; i++) {
        for (int j = 0; j < mat->colunas; j++) {

            printf("%d ", mat->matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void destroiMatriz (Matriz* mat) {

    for (int i = 0; i < mat->linhas; i++) {
        free(mat->matriz[i]);
    }
    free(mat->matriz);
    
    free(mat);
}