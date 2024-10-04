/**
 * arvore binaria de busca
 */

/**
 * arvore binaria de busca
 * 7 funções
 */

#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Arvore tArvore;

tArvore *criaArvoreVazia();

tArvore *criaArvore(int elemento);

tArvore *insereElemento(tArvore *a, int elemento);

tArvore *buscaElemento(tArvore *a, int elemento);

tArvore *retiraElemento(tArvore *a, int elemento);

void imprimeArvore(tArvore *a);

void liberaArvore(tArvore *a);

#endif