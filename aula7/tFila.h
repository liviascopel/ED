//  Created by Lívia H. R. Scopel on 08/05/24.

#ifndef TFILA_H
#define TFILA_H

#include "amostra.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct fila tFila;
typedef struct celula tCelula;


tFila *criaFila();

void imprimeFilaAmostras(tFila *f);

void insereInicioFila(tFila *f, Amostra *amostra);

void insereFinalFila(tFila *f, Amostra *amostra);

void liberaFila(tFila *f);

tCelula *ObtemPrimeiraCelula(tFila *f);

Amostra *ObtemAmostraCelula(tCelula *c);

tCelula *ProximaCelula(tCelula *c);

void liberaCelula(tCelula *c);

void moveCelulaLista(tCelula *c, tFila *f, tFila *dest);

#endif