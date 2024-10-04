#include "lista.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct celula {

    tCelula *prox;
    tProduto *prod;
};

struct lista {

    tCelula *prim;
    tCelula *ult;
    int qtdProdutos;
};

tLista *CriaLista () {

    // cria a lista e atribui null a seus ponteiros
    tLista *lista = (tLista*) calloc (1, sizeof(tLista));

    lista->prim = NULL;
    lista->ult = NULL;

    return lista;
}

void InsereProdutoLista (tLista* lista, tCelula *celula) {

    lista->qtdProdutos++;

    if (lista->prim == NULL && lista->ult == NULL) {
        // inserir o primeiro elemento da lista
        lista->prim = celula;
        lista->ult = celula;
    } 
    else {
        lista->ult->prox = celula;
        lista->ult = lista->ult->prox;
    }
    lista->ult->prox = NULL;
}

void RetiraProdutoLista(tLista *lista, int codigo) {

    // verifica se a lista eh valida ou vazia
    if (lista == NULL || lista->qtdProdutos == 0) {
        printf("A lista está vazia!\n");
        return;
    }

    tCelula *celula = lista->prim;
    tCelula *ant = NULL;

    // ate achar o codigo ou acabar a lista
    while (celula != NULL && codigo != ObtemCodigoProduto(celula->prod)) {
        ant = celula;
        celula = celula->prox;
    }

    // se chegar ao final sem achar, a celula vai ser null
    if (celula == NULL) {
        printf("Produto com código %d não encontrado\n", codigo);
        return;
    }

    // se o produto a ser retirado for o primeiro, a primeira celula vira a segunda
    if (lista->prim == celula) {
        lista->prim = celula->prox;
    } 

    // se nao, liga a anterior a seguinte da eliminada
    else {
        ant->prox = celula->prox;
    }

    // se o produto a ser retirado for o ultimo, a penultima celula vira a ultima
    if (lista->ult == celula) {
        lista->ult = ant;
    }

    lista->qtdProdutos--;
    free(celula);
}

void ImprimeLista (tLista *lista) {
    tCelula * celula = lista->prim;

    if (lista->qtdProdutos == 0) {
        printf("A lista esta vazia!\n\n");
    }

    while (celula != NULL) {
        ImprimeProduto(celula->prod);
        celula = celula->prox;
    }
}

void DesalocaLista (tLista *lista) {
    if (lista->qtdProdutos > 0) {
        tCelula *celula = lista->prim;
        tCelula *prox;

        while (celula != NULL) {
            prox = celula->prox;
            DesalocaCelula(celula);
            celula = prox;
        }
    }
    

    free(lista);
}

tCelula *CriaCelula (tProduto *prod) {

    tCelula *celula = (tCelula*) calloc (1, sizeof(tCelula));

    celula->prod = prod;
    celula->prox = NULL;

    return celula;
}

void DesalocaCelula (tCelula *celula) {
    free(celula);
    // depois tem que desalocar os produtos individualmente
}