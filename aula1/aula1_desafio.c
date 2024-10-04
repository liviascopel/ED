/*
DESAFIO: Implemente uma função que receba um vetoror de inteiros (vetor) de tamanho n. Essa função deve alocar dinâmicamente um outro 
vetoror também de tamanho n que contenha os endereços dos valores do vetoror de inteiros de forma ordenada crescente, ficando a primeira
posição do vetoror de ponteiros o endereço do menor valor até a última posição, que conterá o endereço do maior valor. Essa função deve 
obedecer ao protótipo:  int** inverte2 (int n, int* vetor);
*/

#include <stdio.h>
#include <stdlib.h>

int** inverte2 (int n, int* vetor) {
    int** vetor_2 = (int**) calloc (1, n * sizeof(int*));

    for (int i = 0; i < n-1; i++) {
        vetor_2[i] = &vetor[i];
        printf("%d\n", *vetor_2[i]);
        for (int j = i+1; j < n; j++) {
            if ((&vetor[j]) < vetor_2[i]) {
                vetor_2[i] = &vetor[j];
            }
        }
    }
    return vetor_2;
}

int main () {

    int* vetor = (int*) calloc (1, 5 * sizeof(int));

    vetor[0] = 4;
    vetor[1] = 3;
    vetor[2] = 2;
    vetor[3] = 1;
    vetor[4] = 0;

    printf("%d %d %d %d %d\n", vetor[0], vetor[1], vetor[2], vetor[3], vetor[4]);

    int** vetor_2 = inverte2(5, vetor);

    for (int i = 0; i < 5; i++) {
        printf("%d ", *(*vetor_2 + i));
    }

    free(vetor);
    free(vetor_2);

    return 0;
}