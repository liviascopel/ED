/**
 * Definição do tipo tArvoreBB (árvore binária de busca) genérica
 * Created by Livia H. R. Scopel on 05/07/2024
 */

#ifndef ARVOREBB_H
#define ARVOREBB_H

#include <stdio.h>
#include <stdlib.h>

typedef struct ArvoreBB tArvoreBB;

tArvoreBB* criaArvore();

void imprimeArvore(tArvoreBB* arvore, void (*imprime)(void*));

tArvoreBB* buscaArvore(tArvoreBB* arvore, void* dado, int (*compara)(void*, void*));

tArvoreBB* insereArvore(tArvoreBB* arvore, void* dado, int (*compara)(void*, void*));

tArvoreBB* retiraArvore(tArvoreBB* arvore, void* dado, int (*compara)(void*, void*), void* (*libera)(void*));

void liberaArvore(tArvoreBB* arvore, void*(*libera)(void*));

#endif