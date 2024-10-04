#include "abb.h"

struct Arvore
{
    tArvore *esq;
    tArvore *dir;
    void *elemento;
};

tArvore *criaArvoreVazia()
{
    return NULL;
}

tArvore *criaArvore(void *elemento)
{
    tArvore *a = calloc(1, sizeof(tArvore));

    a->elemento = elemento;

    return a;
}

tArvore *insereElementoArvore(tArvore *arvore, void *elemento, int (*compara)(void *, void *))
{
    if (arvore == NULL)
    {
        arvore = criaArvore(elemento);
    }
    if (compara(elemento, arvore->elemento) == -1) // elemento < arvore->elemento
    {
        arvore->esq = insereElementoArvore(arvore->esq, elemento, compara);
    }
    else if (compara(elemento, arvore->elemento) == 1)
    {
        arvore->dir = insereElementoArvore(arvore->dir, elemento, compara);
    }
    return arvore;
}

tArvore *buscaElementoArvore(tArvore *arvore, void *elemento, int (*compara)(void *, void *))
{
    if (arvore == NULL)
    {
        return NULL;
    }
    if (compara(elemento, arvore->elemento) == -1)
    {
        return buscaElementoArvore(arvore->esq, elemento, compara);
    }
    else if (compara(elemento, arvore->elemento) == 1)
    {
        return buscaElementoArvore(arvore->dir, elemento, compara);
    }
    else
    {
        return arvore;
    }
}

void imprimeArvore(tArvore *arvore, void (*imprime)(void *))
{
    if (arvore == NULL)
        return;
    imprimeArvore(arvore->esq, imprime);
    imprime(&arvore->elemento);
    imprimeArvore(arvore->dir, imprime);
}

tArvore *liberaArvore(tArvore *arvore, void (*libera)(void *))
{
    if (arvore == NULL)
        return NULL;
    liberaArvore(arvore->dir, libera);
    liberaArvore(arvore->esq, libera);
    libera(&arvore->elemento);
    free(arvore);
}

tArvore *retiraElementoArvore(tArvore *arvore, void *elemento, int (*compara)(void *, void *), void (*libera)(void *))
{
    if (arvore == NULL)
        return NULL;
    if (compara(elemento, arvore->elemento) == -1)
    {
        retiraElementoArvore(arvore->esq, elemento, compara, libera);
    }
    else if (compara(elemento, arvore->elemento) == 1)
    {
        retiraElementoArvore(arvore->dir, elemento, compara, libera);
    }
    else
    {
        if (arvore->dir && arvore->esq == NULL)
        {
            libera(arvore->elemento);
            liberaArvore(arvore, libera);
            return NULL;
        }
        else if (arvore->esq == NULL)
        {
            tArvore *aux = arvore;
            arvore = arvore->dir;
            liberaArvore(aux, libera);
        }
        else if (arvore->dir == NULL)
        {
            tArvore *aux = arvore;
            arvore = arvore->esq;
            liberaArvore(aux, libera);
        }
        else
        {
            tArvore *aux = arvore->esq;
            while (arvore->dir != NULL)
            {
                arvore = arvore->dir;
            }
            arvore->elemento = aux->elemento;
            aux->elemento = elemento;
            retiraElementoArvore(arvore->esq, elemento, compara, libera);
        }
    }
}