/*
 * TAD PILHA DUPLA
 * Created by: Lívia H. R. Scopel
 */

#ifndef pilha_dupla
#define pilha_dupla

#include <stdio.h>
#include <stdlib.h>

typedef struct indice tIndice;

typedef struct pilhaDupla tPilhaDupla;

tPilhaDupla* criaPilhaDupla();

void ImprimePilha(tPilhaDupla *p);

void LiberaPilha(tPilhaDupla *p);

void InsereElementoPilha(tPilhaDupla *p, int pilha, int elemento);

#endif