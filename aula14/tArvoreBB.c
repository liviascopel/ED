/**
 * Implementação do tipo tArvoreBB (árvore binária de busca) genérica
 * Created by Livia H. R. Scopel on 05/07/2024
 */

#include "tArvoreBB.h"

struct ArvoreBB {
    void *elemento;
    tArvoreBB *esq;
    tArvoreBB *dir;
};

tArvoreBB *criaArvore()
{
    return NULL;
}

void imprimeArvore(tArvoreBB* arvore, void (*imprime)(void*))
{
    if (arvore != NULL)
    {
        imprimeArvore(arvore->esq, imprime);
        imprime(arvore->elemento);
        imprimeArvore(arvore->dir, imprime);
    }
}

tArvoreBB* buscaArvore(tArvoreBB* arvore, void* dado, int (*compara)(void*, void*))
{
    if (arvore == NULL || compara(dado, arvore->elemento) == 0)
    {
        return arvore;
    }
    if (compara(dado, arvore->elemento) < 0)
    {
        return buscaArvore(arvore->esq, dado, compara);
    }
    else
    {
        return buscaArvore(arvore->dir, dado, compara);
    }
}

tArvoreBB* insereArvore(tArvoreBB* arvore, void* dado, int (*compara)(void*, void*))
{
    if (arvore == NULL)
    {
        arvore = (tArvoreBB*) malloc(sizeof(tArvoreBB));
        arvore->elemento = dado;
        arvore->esq = arvore->dir = NULL;
    }
    else if (compara(dado, arvore->elemento) < 0)
    {
        arvore->esq = insereArvore(arvore->esq, dado, compara);
    }
    else
    {
        arvore->dir = insereArvore(arvore->dir, dado, compara);
    }
    return arvore;
}

tArvoreBB* retiraArvore(tArvoreBB* arvore, void* dado, int (*compara)(void*, void*), void* (*libera)(void*))
{
    if (arvore == NULL)
    {
        return NULL;
    }
    else if (compara(dado, arvore->elemento) < 0)
    {
        arvore->esq = retiraArvore(arvore->esq, dado, compara, libera);
    }
    else if (compara(dado, arvore->elemento) > 0)
    {
        arvore->dir = retiraArvore(arvore->dir, dado, compara, libera);
    }
    else if (arvore->elemento == dado)
    {
        // se não houver filhos
        if (arvore->esq == NULL && arvore->dir == NULL)
        {
            libera(arvore->elemento);
            free(arvore);
            return NULL;
        }
        // se houver apenas filho à esquerda
        if (arvore->dir == NULL)
        {
            tArvoreBB *aux = arvore->esq;
            libera(arvore->elemento);
            free(arvore);
            return aux;
        }
        // se houver apenas filho à direita
        if (arvore->esq == NULL)
        {
            tArvoreBB *aux = arvore->dir;
            libera(arvore->elemento);
            free(arvore);
            return aux;
        }
        // se houver dois filhos
        else {
            tArvoreBB *aux = arvore->esq;
            while (aux->dir != NULL)
            {
                aux = aux->dir;
            }
            arvore->elemento = aux->elemento;
            aux->elemento = dado;
            arvore->esq = retiraArvore(arvore->esq, dado, compara, libera);
        }
    }
    return arvore;
}

void liberaArvore(tArvoreBB* arvore, void* (*libera)(void*))
{
    if (arvore != NULL)
    {
        liberaArvore(arvore->esq, libera);
        liberaArvore(arvore->dir, libera);
        libera(arvore->elemento);
        free(arvore);
    }
}