/*
 * TAD PILHA DUPLA
 * Created by: Lívia H. R. Scopel
 */

#ifndef pilha_multipla
#define pilha_multipla

#include <stdio.h>
#include <stdlib.h>

typedef struct indice tIndice;

typedef struct pilhaMultipla tPilhaMultipla;

tPilhaMultipla* criaPilhaMultipla();

void ImprimePilha(tPilhaMultipla *p);

void LiberaPilha(tPilhaMultipla *p);

void InsereElementoPilha(tPilhaMultipla *p, int pilha, int elemento);

#endif