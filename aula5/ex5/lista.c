#include "lista.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct celula {

    tCelula *prox;
    tCelula *ant;
    tProduto *prod;
};

tLista *CriaLista () {

    // cria a lista e atribui null a seus ponteiros
    //tLista *lista = (tLista*) calloc (1, sizeof(tCelula));

    //lista = NULL;

    return NULL;
}

tLista* InsereProdutoLista (tLista* lista, tCelula *celula) {

    if (lista != NULL) {
        // qqr elemento da lista
        celula->prox = lista;
        lista->ant = celula;
        lista = celula;
    } 
    else {
        // inserir o primeiro elemento da lista
        lista = celula;
    }
    return lista;
    
}

tLista* RetiraProdutoLista(tLista *lista, int codigo) {

    // verifica se a lista eh valida ou vazia
    if (lista == NULL) {
        printf("A lista está vazia!\n");
        return lista;
    }

    tCelula *celula = lista;

    // ate achar o codigo ou acabar a lista
    while (celula != NULL && codigo != ObtemCodigoProduto(celula->prod)) {
        celula = celula->prox;
    }

    // se chegar ao final sem achar, a celula vai ser null
    if (celula == NULL) {
        printf("Produto com código %d não encontrado\n", codigo);
        return lista;
    }

    // se o produto a ser retirado for o primeiro, a primeira celula vira a segunda
    if (lista == celula) {
        lista = celula->prox;
        celula->prox->ant = NULL;
    } 

    // se nao, liga a anterior a seguinte da eliminada
    else {
        celula->ant->prox = celula->prox;
        celula->ant->prox = celula->prox;
        if (celula->prox != NULL)
            celula->prox->ant = celula->ant;
    }

    free(celula);
    return lista;
}

void ImprimeLista (tLista *lista) {
    tCelula * celula = lista;

    if (celula == NULL) {
        printf("A lista esta vazia!\n\n");
        return;
    }

    while (celula != NULL) {
        ImprimeProduto(celula->prod);
        celula = celula->prox;
    }
}

void DesalocaLista (tLista *lista) {
    if (lista != NULL) {
        tCelula *celula = lista;
        tCelula *prox;

        while (celula != NULL) {
            prox = celula->prox;
            DesalocaCelula(celula);
            celula = prox;
        }
    }
}

tCelula *CriaCelula (tProduto *prod) {

    tCelula *celula = (tCelula*) calloc (1, sizeof(tCelula));

    celula->ant = NULL;
    celula->prox = NULL;
    celula->prod = prod;

    return celula;
}

void DesalocaCelula (tCelula *celula) {
    free(celula);
    // depois tem que desalocar os produtos individualmente
}