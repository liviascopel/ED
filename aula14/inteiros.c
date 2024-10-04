/**
 * Cliente do tArvoreBB, testando o tipo inteiro
 * arquivo inteiros.c
 *
 * Created by Livia H. R. Scopel on 05/07/2024
 */

#include "inteiros.h"
#include "tArvoreBB.h"

int compararInteiros(void *a, void *b)
{
    int int_a = *((int *)a);
    int int_b = *((int *)b);

    if (int_a < int_b)
        return -1;
    else if (int_a == int_b)
        return 0;
    else
        return 1;
}

void imprimeInteiro(void *a)
{
    int int_a = *((int *)a);
    printf("%d\n", int_a);
}

void *liberaInteiro(void *a)
{
    return NULL;
}
/*
int main()
{
    tArvoreBB *a = criaArvore();

    int num1 = 6;

    a = insereArvore(a, &num1, compararInteiros);
    int num2 = 8;
    a = insereArvore(a, &num2, compararInteiros);
    int num3 = 2;
    a = insereArvore(a, &num3, compararInteiros);
    int num4 = 4;
    a = insereArvore(a, &num4, compararInteiros);
    int num5 = 1;
    a = insereArvore(a, &num5, compararInteiros);
    int num6 = 3;
    a = insereArvore(a, &num6, compararInteiros);

    imprimeArvore(a, imprimeInteiro);

    retiraArvore(a, &num4, compararInteiros, liberaInteiro);

    imprimeArvore(a, imprimeInteiro);

    liberaArvore(a, liberaInteiro);

    return 0;
}

*/