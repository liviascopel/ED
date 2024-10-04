#include "tPilhaMultipla.h"

#define QTD_PILHAS 4
#define TAM_PILHA 20

struct indice
{
    int topo;
    int base;
};

struct pilhaMultipla
{
    int vetoror[TAM_PILHA];
    tIndice pilhas[QTD_PILHAS];
};

tPilhaMultipla *criaPilhaMultipla()
{
    tPilhaMultipla *p = calloc(1, sizeof(tPilhaMultipla));

    for (int i = 0; i < QTD_PILHAS; i++)
    {
        p->pilhas[i].base = i * TAM_PILHA / QTD_PILHAS;
        p->pilhas[i].topo = 20;
    }

    return p;
}

void ImprimePilha(tPilhaMultipla *p)
{
    for (int i = 0; i < TAM_PILHA; i++)
    {
        printf("%d ", p->vetoror[i]);
    }
    printf("\n");
}

void LiberaPilha(tPilhaMultipla *p)
{
    free(p);
}

void InsereElementoPilha(tPilhaMultipla *p, int pilha, int elemento)
{
    int n = pilha - 1;
    if (p->pilhas[n].topo == 20) // pilha vazia
    {
        p->pilhas[n].topo = p->pilhas[n].base;
        p->vetoror[p->pilhas[n].topo] = elemento;
    }
    else if (pilha == QTD_PILHAS) // ultima pilha
    {
        if (p->pilhas[n].topo < TAM_PILHA - 1)
        {
            p->pilhas[n].topo++;
            p->vetoror[p->pilhas[n].topo] = elemento;
        }
        else
        {
            printf("Pilha cheia\n");
        }
    }
    else if (p->pilhas[n].topo + 1 < p->pilhas[n + 1].base)
    {
        p->pilhas[n].topo++;
        p->vetoror[p->pilhas[n].topo] = elemento;
    }
    else
    {
        printf("Pilha cheia\n");
    }
}

int main()
{
    tPilhaMultipla *p = criaPilhaMultipla();
    ImprimePilha(p);

    InsereElementoPilha(p, 1, 1);
    InsereElementoPilha(p, 2, 1);
    InsereElementoPilha(p, 3, 1);
    InsereElementoPilha(p, 4, 1);

    ImprimePilha(p);

    InsereElementoPilha(p, 1, 2);
    InsereElementoPilha(p, 2, 2);
    InsereElementoPilha(p, 3, 2);
    InsereElementoPilha(p, 4, 2);

    InsereElementoPilha(p, 1, 3);
    InsereElementoPilha(p, 2, 3);
    InsereElementoPilha(p, 3, 3);
    InsereElementoPilha(p, 4, 3);

    InsereElementoPilha(p, 1, 4);
    InsereElementoPilha(p, 2, 4);
    InsereElementoPilha(p, 3, 4);
    InsereElementoPilha(p, 4, 4);

    ImprimePilha(p);

    InsereElementoPilha(p, 4, 5);

    ImprimePilha(p);

    InsereElementoPilha(p, 4, 6);

    ImprimePilha(p);

    LiberaPilha(p);
    return 0;
}