/*
na teoria, precisariamos de funções genéricas de comparar, imprimir, liberar.
*/

#include "utils.h"

void imprimeInteiro (void *elemento);

int main()
{
    tArvore *a = criaArvoreVazia();


    a = insereElemento(a, (void*)10);
    a = insereElemento(a, (void*)7);
    a = insereElemento(a, (void*)4);
    a = insereElemento(a, (void*)6);
    a = insereElemento(a, (void*)1);
    a = insereElemento(a, (void*)8);

    imprimeArvore(a, imprimeInteiro);

    a = retiraElemento(a, (void*)10);

    imprimeArvore(a, imprimeInteiro);

    liberaArvore(a);

    return 0;
}

void imprimeInteiro (void *elemento)
{
    int *num = (int *)elemento;
    printf("%d\n", *num);
}