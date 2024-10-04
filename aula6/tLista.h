//
//  Created by Lívia Scopel on 25/04/24.
//

#ifndef _TLISTA_H
#define _TLISTA_H

#include <stdio.h>
#include "Cachorro.h"
#include "Gato.h"

typedef struct lista tLista;
typedef struct celula tCelula;

typedef enum {
    CACHORRO,
    GATO
} pet;

tCelula *criaCelula(pet tipo, tCelula *prox, void *animal);

void adicionaCelulaLista(tLista *lista, tCelula *celula);

tLista *criaLista();

void desalocaLista(tLista *lista);

void desalocaCelula(tCelula *celula);

void ImprimeLista(tLista * l);

tCelula *ObtemPrim (tLista* l);

pet ObtemTipoPet(tCelula *c);

tCelula *ObtemProx(tCelula * c);

void mudaCelulaLista(tLista *lor, tLista *ldest, tCelula *c);

tCelula *encontraCelulaCachorro(tLista *l, Cachorro *c);

tCelula *encontraCelulaGato(tLista *l, Gato *g);

#endif