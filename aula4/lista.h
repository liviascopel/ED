#ifndef _LISTA_H
#define _LISTA_H

#include "produto.h"

typedef struct celula tCelula;
typedef struct lista tLista;

tLista *CriaLista ();

void InsereProdutoLista (tLista *lista, tCelula *celula);

void RetiraProdutoLista (tLista *lista, int codigo);

void ImprimeLista (tLista *lista);

void DesalocaLista (tLista *lista);

tCelula *CriaCelula (tProduto *prod);

void DesalocaCelula (tCelula *celula);

#endif