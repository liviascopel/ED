//
//  Created by Lívia Scopel on 25/04/24.
//

#include "tLista.h"
#include "Gato.h"
#include "Cachorro.h"

#include <stdlib.h>

// implementação da lista simplesmente encadeada com sentinela

struct celula {
    pet tipo;
    tCelula *prox;
    void *animal;
};

struct lista {
    tCelula* prim;
    tCelula* ult;
};

tCelula *criaCelula(pet tipo, tCelula *prox, void *animal) {
    tCelula *celula = (tCelula*) calloc (1, sizeof(tCelula));

    celula->tipo = tipo;
    celula->prox = NULL;
    celula->animal = animal;

    return celula;
}

tLista *criaLista() {
    tLista *lista = (tLista*) calloc (1, sizeof(tLista));

    lista->prim = NULL;
    lista->ult = NULL;

    return lista;
}

void desalocaLista(tLista *lista) {
    while (lista->prim != NULL) { //lista não vazia
        tCelula *celula = lista->prim;
        lista->prim = celula->prox;
        desalocaCelula(celula);
    }
    free(lista);
}

void desalocaCelula(tCelula *celula) {
    free(celula);
}

void adicionaCelulaLista(tLista *lista, tCelula *celula) {
    if (lista->prim == NULL) { // lista vazia, coloca a primeira célula como primeira e ultima
        lista->prim = celula;
        lista->ult = celula;
    } else { // se nao estiver vazia, coloca na ultima posicao e atualiza a sentinela de ult
        lista->ult->prox = celula;
        lista->ult = celula;
    }
    celula->prox = NULL;
}

void ImprimeLista(tLista * l) {
    tCelula * c = l->prim;
    while (c != NULL) {
        if (c->tipo == CACHORRO) {
            ImprimeCachorro(c->animal);
        } else if (c->tipo == GATO) {
            ImprimeGato(c->animal);
        }
        c = c->prox;
    }
    printf("\n");
}

tCelula *ObtemPrim (tLista* l) {
    return l->prim;
}

pet ObtemTipoPet(tCelula *c) {
    return c->tipo;
}

tCelula *ObtemProx(tCelula * c) {
    return c->prox;
}

void mudaCelulaLista(tLista *lor, tLista *ldest, tCelula *c) {
    tCelula *cel = lor->prim;
    tCelula *ant = NULL;

    // procurando a célula a ser tirada da lista de origem
    while(cel != NULL && cel != c) {
        ant = cel;
        cel = cel->prox;
    }
    if (cel == NULL) {
        return;
    } // cel encontrada
    if (cel != lor->prim && cel != lor->ult) { //está no meio
        ant->prox = cel->prox;
    } //se for a primeira, atualiza o sentinela
    if (cel == lor->prim) {
        lor->prim = cel->prox;
    } // se for a ultima, atualiza o sentinela
    if (cel == lor->ult) {
        lor->ult = ant;
        ant->prox = NULL;
    }

    adicionaCelulaLista(ldest, cel);
}

tCelula *encontraCelulaCachorro(tLista *l, Cachorro *c) {
    tCelula *cel = l->prim;
    while(cel != NULL && ObtemNomeCachorro(cel->animal) != ObtemNomeCachorro(c)) { //varre a lista até achar o cachorro
        cel = cel->prox;
    }
    if (cel == NULL) { //se nao achou
        return NULL;
    }
    return cel;
}

tCelula *encontraCelulaGato(tLista *l, Gato *g) {
    tCelula *cel = l->prim;
    while(cel != NULL && ObtemNomeGato(cel->animal) != ObtemNomeGato(g)) { //varre a lista até achar o gato
        cel = cel->prox;
    }
    if (cel == NULL) { //se nao achou
        return NULL;
    }
    return cel;
}