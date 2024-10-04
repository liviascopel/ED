/* ABB */

#ifndef ABB_H
#define ABB_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Arvore tArvore;

tArvore *criaArvoreVazia();

tArvore *criaArvore(void *elemento);

tArvore *insereElementoArvore(tArvore* arvore, void *elemento, int (*compara)(void*, void*));

tArvore* buscaElementoArvore(tArvore* arvore, void *elemento, int (*compara)(void*, void*));

tArvore *retiraElementoArvore(tArvore* arvore, void *elemento, int (*compara)(void*, void*), void (*libera)(void*));

void imprimeArvore(tArvore* arvore, void (*imprime)(void*));

tArvore *liberaArvore(tArvore* arvore, void (*libera) (void*));

#endif