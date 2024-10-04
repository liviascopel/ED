#ifndef _LISTA_H
#define _LISTA_H

#include "produto.h"

typedef struct celula tCelula;
typedef tCelula tLista;

tLista *CriaLista ();

tLista* InsereProdutoLista (tLista *lista, tCelula *celula);

tLista* RetiraProdutoLista (tLista *lista, int codigo);

void ImprimeLista (tLista *lista);

void DesalocaLista (tLista *lista);

tCelula *CriaCelula (tProduto *prod);

void DesalocaCelula (tCelula *celula);

#endif