#ifndef T_LISTA
#define T_LISTA

#include <stdio.h>
#include <stdlib.h>

typedef struct lista tLista;

typedef struct celula tCelula;

tLista *criaLista(tCelula *celula);

tLista *criaListaVazia();

void insereElementoLista(tLista *lista, int elemento);

tLista* retiraElementoLista(tLista *lista, int elemento);

void liberaLista(tLista *lista);

void imprimeLista(tLista *lista);

#endif