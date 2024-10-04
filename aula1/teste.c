#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int** inverte2(int n, int* vetor) {
    // Aloca dinamicamente um vetoror de ponteiros
    int** vetor_2 = (int**)malloc(n * sizeof(int*));

    // Preenche o vetoror de ponteiros com os endereços dos valores do vetoror de inteiros
    for (int i = 0; i < n; i++) {
        vetor_2[i] = &vetor[i];
    }

    // Ordena o vetoror de ponteiros de acordo com os valores apontados
    qsort(vetor_2, n, sizeof(int*), compare);

    return vetor_2;
}

int main() {
    int vetor[] = {4, 2, 6, 1, 8};
    int n = sizeof(vetor) / sizeof(vetor[0]);

    int** vetor_2 = inverte2(n, vetor);

    // Imprime os valores apontados pelo vetoror de ponteiros
    for (int i = 0; i < n; i++) {
        printf("%d ", *(vetor_2[i]));
    }
    
    // Libera a memória alocada para o vetoror de ponteiros
    free(vetor_2);

    return 0;
}