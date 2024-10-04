#include "utils.h"

#include <time.h>

int main () {
    time_t inicio, fim;
    double tempo_execucao;

    inicio = time(NULL);

    int vetor[100000];

    for (int i = 0; i < 100000; i++) {
        vetor[i] = rand() % 100001;
    }   

    quickSort(vetor, 100000);

    fim = time(NULL);
    tempo_execucao = difftime(fim, inicio);

    printf("Tempo de execução: %.2f segundos\n", tempo_execucao);

    return 0;
}