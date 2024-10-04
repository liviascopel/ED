#include "matriz.h"

#include <stdio.h>
#include <stdlib.h>

int main () {
    int cont = 0;
    int nlinhas = 3, ncolunas = 3;

    if (nlinhas == 0 || ncolunas == 0) {
        printf("Uma das matrizes possui linhas ou colunas igual a zero\n");
        exit;
    }

    Matriz* mat1 = InicializaMatriz(nlinhas, ncolunas);
    Matriz* mat2 = InicializaMatriz(nlinhas, ncolunas);

    if (mat1 == NULL || mat2 == NULL) {
        printf("Uma das matrizes não conseguiu ser alocada\n");
        exit;
    }

    // salva elementos da matriz 1
    for(int i = 0; i < recuperaNLinhas(mat1); i++) {
        for(int j = 0; j < recuperaNColunas(mat1); j++) {
            modificaElemento (mat1, i, j, cont);
            cont++;
        }
    }
    imprimeMatriz(mat1);

    // salva elementos da matriz 2
    for(int i = 0; i < recuperaNLinhas(mat2); i++) {
        for(int j = 0; j < recuperaNColunas(mat2); j++) {
            modificaElemento (mat2, i, j, cont);
            cont--;
        }
    }
    imprimeMatriz(mat2);

    // transposta da matriz 1
    Matriz* mat1_transposta = transposta(mat1);
    imprimeMatriz(mat1_transposta);

    // multiplica mat1 por mat2
    if (recuperaNColunas(mat1) == recuperaNLinhas(mat2)) {
        Matriz* multiplica = multiplicacao(mat1, mat2);
        imprimeMatriz(multiplica);
        destroiMatriz(multiplica);
    } else {
        printf("A quantidade de linhas e colunas não eh igual! Nao podemos multiplicar");
    }

    // libera a memoria alocada
    destroiMatriz(mat1);
    destroiMatriz(mat2);
    destroiMatriz(mat1_transposta);

    return 0;
}