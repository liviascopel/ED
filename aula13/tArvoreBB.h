/**
 * tArvoreBB.h
 * Created by Livia H R Scopel on 26/06/2024
 * 
 * Implemente um TAD árvore binária de busca (ABB) de alunos, com as funcionalidades básicas de: criação, busca, 
 * impressão, inserção, retirada e liberação. Você escolhe o critério de ordenação para sua ABB.
 */

#ifndef ARVORE_H
#define ARVORE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct arvore tArvore;

tArvore *CriaArvore(int num, tArvore *esq, tArvore *dir);

tArvore *BuscaArvore(tArvore *arvore, int elemento);

void ImprimeArvore(tArvore *arvore);

tArvore *InsereElementoArvore(tArvore *arvore, int num);

tArvore *RetiraElementoArvore();

tArvore *LiberaArvore(tArvore *arvore);

int ArvoreVazia(tArvore *arvore);

#endif