// Created by Lívia H. R. Scopel on 05/06/2024
// Implementação de uma lista usando algoritmos recursivos

#include "tLista.h"

struct lista
{
    tCelula *celula;
    tLista *sublista;
};

struct celula
{
    tCelula *prox; // aponta para a sublista
    int elemento;
};

tCelula *criaCelula(int elemento)
{
    tCelula *celula = calloc(1, sizeof(tCelula));

    celula->elemento = elemento;
    celula->prox = NULL;

    return celula;
}

int listaVazia(tLista *lista)
{
    return lista->celula == NULL;
}

tLista *criaListaVazia()
{
    tLista *lista = calloc(1, sizeof(tLista));

    lista->sublista = NULL;
    lista->celula = NULL;

    return lista;
}

tLista *criaLista(tCelula *celula)
{
    tLista *lista = calloc(1, sizeof(tLista));

    lista->sublista = NULL;
    lista->celula = celula;

    return lista;
}

void insereElementoLista(tLista *lista, int elemento)
{
    if (listaVazia(lista)) // se a lista estiver vazia
    {
        tCelula *celula = criaCelula(elemento);
        lista->celula = celula;
        lista->sublista = NULL;
    }
    else if (lista->sublista == NULL) //se a lista tiver apenas um elemento
    {
        tCelula *celula = criaCelula(elemento);
        lista->sublista = criaLista(celula);
        lista->sublista->celula = celula;
    }
    else
    {
        insereElementoLista(lista->sublista, elemento);
    }
}

tLista *retiraElementoLista(tLista *lista, int elemento)
{
    if (!listaVazia(lista))
    {
        if (lista->celula->elemento == elemento)
        {
            tLista *aux = lista;
            lista = lista->sublista;
            free(aux->celula);
            free(aux);
        }
        else
        {
            lista->sublista = retiraElementoLista(lista->sublista, elemento);
        }
    }
    return lista;
}

void imprimeLista(tLista *lista)
{
    if (lista->celula == NULL)
    {
        printf("Lista vazia");
        return;
    }
    else
    {
        printf("%d ", lista->celula->elemento);
        if (lista->sublista != NULL)
            imprimeLista(lista->sublista);
    }
}

void liberaLista(tLista *lista)
{
    if (lista->celula != NULL)
    {
        if (lista->sublista != NULL)
            liberaLista(lista->sublista);
        free(lista->celula);
        free(lista);
    }
}

int main()
{
    tLista *lista = criaListaVazia();

    imprimeLista(lista);
    printf("\n");

    insereElementoLista(lista, 3);
    insereElementoLista(lista, 1);
    insereElementoLista(lista, 2);

    imprimeLista(lista);
    printf("\n");

    lista = retiraElementoLista(lista, 1);

    imprimeLista(lista);
    printf("\n");

    liberaLista(lista);

    return 0;
}