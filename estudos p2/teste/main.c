#include "abb.h"

int compara(void *elemento1, void *elemento2)
{
    if (elemento1 < elemento2)
        return -1;
    if (elemento1 > elemento2)
        return 1;
    return 0;
}

void libera(void *elemento)
{
    return;
}

void imprime(void *elemento)
{
    int *num = (int*)elemento;
    printf("%d\n", *num);
}

int main()
{   
    tArvore *a = criaArvoreVazia();

    a = insereElementoArvore(a, (void*)10, compara);
    a = insereElementoArvore(a, (void*)9, compara);
    a = insereElementoArvore(a, (void*)6, compara);
    a = insereElementoArvore(a, (void*)12, compara);

    imprimeArvore(a, imprime);

    liberaArvore(a, libera);
}

