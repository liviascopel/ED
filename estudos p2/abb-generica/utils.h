/**
 * arvore binaria de busca
 */

/**
 * arvore binaria de busca genérica!
 * 7 funções - abb
 */

#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Arvore tArvore;

tArvore *criaArvoreVazia();

tArvore *criaArvore(void *elemento);

tArvore *insereElemento(tArvore *a, void *elemento);

tArvore *buscaElemento(tArvore *a, void * elemento);

tArvore *retiraElemento(tArvore *a, void * elemento);

void imprimeArvore(tArvore *a, void (*imprime) (void*));

void liberaArvore(tArvore *a);

#endif