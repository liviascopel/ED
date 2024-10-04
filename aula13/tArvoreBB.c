/**
 * tArvoreBB.c
 * Created by Livia H R Scopel on 26/06/2024
 */

#include "tArvoreBB.h"

struct arvore
{
    int num;
    tArvore *esq;
    tArvore *dir;
};

tArvore *CriaArvore(int num, tArvore *esq, tArvore *dir)
{
    tArvore *a = calloc(1, sizeof(tArvore));

    a->num = num;
    a->dir = dir;
    a->esq = esq;

    return a;
}

tArvore *BuscaArvore(tArvore *arvore, int elemento)
{
    if (arvore == NULL)
    {
        return NULL;
    }
    if (arvore->num == elemento)
    {
        return arvore;
    }
    else if (arvore->num < elemento)
    {
        BuscaArvore(arvore->dir, elemento);
    }
    else if (arvore->num > elemento)
    {
        BuscaArvore(arvore->esq, elemento);
    }
}

void ImprimeArvore(tArvore *arvore)
{
    if (arvore == NULL)
    {
        return;
    }
    ImprimeArvore(arvore->esq);
    printf("%d ", arvore->num);
    ImprimeArvore(arvore->dir);
}

tArvore *InsereElementoArvore(tArvore *arvore, int num)
{
    if (ArvoreVazia(arvore))
    {
        return CriaArvore(num, NULL, NULL);
    }
    if (num >= arvore->num)
    {
        arvore->dir = InsereElementoArvore(arvore->dir, num);
    }
    else if (num < arvore->num)
    {
        arvore->esq = InsereElementoArvore(arvore->esq, num);
    }
    return arvore;
}

tArvore *RetiraElementoArvore(tArvore *arvore, int num)
{
    if (ArvoreVazia(arvore))
    {
        return NULL;
    }
    if (arvore->num > num)
    {
        arvore->esq = RetiraElementoArvore(arvore->esq, num);
    }
    else if (arvore->num < num)
    {
        arvore->dir = RetiraElementoArvore(arvore->dir, num);
    }
    else
    {
        // retira a raiz

        // caso 1: raiz folha
        if (ArvoreVazia(arvore->dir) && ArvoreVazia(arvore->esq))
        {
            return LiberaArvore(arvore);
        }
        // caso 2.1: filho somente à esquerda
        if (ArvoreVazia(arvore->dir) && !ArvoreVazia(arvore->esq))
        {
            tArvore *temp = arvore;
            arvore = arvore->esq;
            free(temp);
        }
        // caso 2.2: filho somente à direita
        if (!ArvoreVazia(arvore->dir) && ArvoreVazia(arvore->esq))
        {
            tArvore *temp = arvore;
            arvore = arvore->dir;
            free(temp);
        }
        // caso 3: dois filhos
        if (!ArvoreVazia(arvore->dir) && !ArvoreVazia(arvore->esq))
        {
            tArvore *temp = arvore->esq;
            while (temp->dir != NULL) {
                temp = temp->dir;
            }
            arvore->num = temp->num;
            temp->num = num;

            arvore->esq = RetiraElementoArvore(arvore->esq, num);
        }
    }

    return arvore;
}

int ArvoreVazia(tArvore *arvore)
{
    return arvore == NULL;
}

tArvore *LiberaArvore(tArvore *arvore)
{
    if (!ArvoreVazia(arvore))
    {
        LiberaArvore(arvore->esq);
        LiberaArvore(arvore->dir);
        free(arvore);
    }
    return NULL;
}

