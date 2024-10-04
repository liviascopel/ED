//  Created by Lívia H. R. Scopel on 08/05/24.

#include "tFila.h"

struct fila
{
    tCelula *prim;
    tCelula *ult;
};

struct celula
{
    Amostra *amostra;
    tCelula *prox;
};

tFila *criaFila()
{
    tFila *f = calloc(1, sizeof(tFila));

    f->prim = NULL;
    f->ult = NULL;

    return f;
}

tCelula *criaCelula(Amostra *amostra)
{
    tCelula *c = calloc(1, sizeof(tCelula));

    c->amostra = amostra;
    c->prox = NULL;

    return c;
}

void imprimeFilaAmostras(tFila *f)
{
    tCelula *celula_amostra = f->prim;
    Amostra *amostra = NULL;
    if (celula_amostra != NULL)
    {
        amostra = ObtemAmostraCelula(celula_amostra); // f->prim->amostra;
    }

    while (celula_amostra != NULL)
    {        
        imprimeAmostra(amostra);
        
        celula_amostra = ProximaCelula(celula_amostra);
        if (celula_amostra != NULL)
            amostra = ObtemAmostraCelula(celula_amostra);
    }
}

void insereInicioFila(tFila *f, Amostra *amostra)
{
    tCelula *celula = criaCelula(amostra);
    // printf("criou a celula p inserir na fila\n");

    if (f->prim == NULL)
    {
        f->prim = celula;
        f->ult = celula;
        return;
    }
    celula->prox = f->prim;
    f->prim = celula;
}

void insereFinalFila(tFila *f, Amostra *amostra)
{
    tCelula *celula = criaCelula(amostra);

    if (f->prim == NULL)
    {
        f->prim = celula;
        f->ult = celula;
        return;
    }
    f->ult->prox = celula;
    f->ult = celula;
    celula->prox = NULL;
}

void liberaFila(tFila *f)
{
    if (f == NULL) {
        return;
    }
    tCelula *celula = f->prim;
    tCelula *ant = NULL;

    while (celula != NULL)
    {
        ant = celula;
        celula = celula->prox;
        if (ant != NULL)
        {
            liberaCelula(ant);
        }
    }
    free(f);
}

void liberaCelula(tCelula *c)
{
    if (c->amostra != NULL) {
        liberaAmostra(c->amostra);
    }
    free(c);
}

void moveCelulaLista(tCelula *c, tFila *f, tFila *dest)
{
    tCelula *celula = f->prim;
    tCelula *ant = NULL;
    Amostra *amostra = NULL;

    while (celula != NULL)
    {
        if (celula == c)
        {
            amostra = celula->amostra;
            if (ant == NULL)
            {
                f->prim = celula->prox;
            }
            else
            {
                ant->prox = celula->prox;
            }
            insereFinalFila(dest, c->amostra);
            free(celula);

            return;
        }
        ant = celula;
        celula = celula->prox;
    }
}

tCelula *ProximaCelula(tCelula *c)
{
    return c->prox;
}

tCelula *ObtemPrimeiraCelula(tFila *f)
{
    return f->prim;
}

Amostra *ObtemAmostraCelula(tCelula *c)
{
    if (c == NULL)
        return NULL;
    return c->amostra;
}