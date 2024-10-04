#include "utils.h"

struct Arvore
{
    tArvore *dir;
    tArvore *esq;
    void * elemento;
};

tArvore *criaArvoreVazia()
{
    return NULL;
}

tArvore *criaArvore(void * elemento)
{
    tArvore *a = calloc(1, sizeof(tArvore));

    a->elemento = elemento;

    return a;
}

tArvore *insereElemento(tArvore *a, void * elemento)
{
    if (a == NULL)
    {
        a = criaArvore(elemento);
    }
    if (elemento > a->elemento)
    {
        a->dir = insereElemento(a->dir, elemento);
    }
    else if (elemento < a->elemento)
    {
        a->esq = insereElemento(a->esq, elemento);
    }
    return a;
}

tArvore *buscaElemento(tArvore *a, void * elemento)
{
    if (a == NULL)
    {
        return NULL;
    }
    if (elemento < a->elemento)
    {
        return buscaElemento(a->esq, elemento);
    }
    else if (elemento > a->elemento)
    {
        return buscaElemento(a->dir, elemento);
    }
    else
    {
        return a;
    }
}

tArvore *retiraElemento(tArvore *a, void * elemento)
{
    if (a == NULL)
    {
        return NULL;
    }
    else if (elemento < a->elemento)
    {
        retiraElemento(a->esq, elemento);
    }
    else if (elemento > a->elemento)
    {
        retiraElemento(a->dir, elemento);
    }
    else // quando for igual
    {
        if (a->dir == NULL && a->esq == NULL)
        {
            free(a);
            a = NULL;
        }
        else if (a->dir == NULL) // so tem filho na esquerda
        {
            tArvore *aux = a;
            a = a->esq;
            free(aux);
        }
        else if (a->esq == NULL)
        {
            tArvore *aux = a;
            a = a->dir;
            free(aux);
        }
        else {
            tArvore *aux = a->esq;
            while (aux->dir != NULL) 
            {
                aux = aux->dir; 
            }
            a->elemento = aux->elemento;
            aux->elemento = elemento;
            retiraElemento(a->esq, elemento);
        }
    }
    return a;
}

void imprimeArvore(tArvore *a, void (*imprime) (void*))
{
    if (a == NULL)
    {
        return;
    }
    imprimeArvore(a->esq, imprime);
    imprime(&a->elemento);
    imprimeArvore(a->dir, imprime);
}

void liberaArvore(tArvore *a)
{
    if (a == NULL)
    {
        return;
    }
    liberaArvore(a->dir);
    liberaArvore(a->esq);
    free(a);
}