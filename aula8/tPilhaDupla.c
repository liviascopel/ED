#include "tPilhaDupla.h"

struct indice
{
    int topo;
    int base;
};

struct pilhaDupla
{
    int vetoror[10];
    tIndice pilha1, pilha2;
};

tPilhaDupla *criaPilhaDupla()
{
    tPilhaDupla *p = calloc(1, sizeof(tPilhaDupla));

    p->pilha1.base = 0;
    p->pilha1.topo = -1;
    p->pilha2.base = 9;
    p->pilha2.topo = 10;

    return p;
}

void ImprimePilha(tPilhaDupla *p)
{

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", p->vetoror[i]);
    }
    printf("\n");
}

void LiberaPilha(tPilhaDupla *p)
{
    free(p);
}

void InsereElementoPilha(tPilhaDupla *p, int pilha, int elemento)
{
    if (pilha == 1)
    {
        if (p->pilha1.topo == -1) //pilha vazia
        {
            p->pilha1.topo = p->pilha1.base;
            p->vetoror[p->pilha1.topo] = elemento;
        }
        else if (p->pilha1.topo+1 < p->pilha2.topo)
        {
            p->pilha1.topo++;
            p->vetoror[p->pilha1.topo] = elemento;
        }
        else
        {
            printf("Pilha cheia\n");
        }
    }

    if (pilha == 2)
    {
        if (p->pilha2.topo == 10) //pilha vazia
        {
            p->pilha2.topo = p->pilha2.base;
            p->vetoror[p->pilha2.topo] = elemento;
        }
        else if (p->pilha2.topo-1 > p->pilha1.topo)
        {
            p->pilha2.topo--;
            p->vetoror[p->pilha2.topo] = elemento;
        }
        else
        {
            printf("Pilha cheia\n");
        }
    }
}

int main()
{
    tPilhaDupla *p = criaPilhaDupla();

    ImprimePilha(p);

    InsereElementoPilha(p, 1, 1);
    InsereElementoPilha(p, 1, 2);
    InsereElementoPilha(p, 1, 3);
    InsereElementoPilha(p, 1, 4);
    InsereElementoPilha(p, 1, 5);

    ImprimePilha(p);

    InsereElementoPilha(p, 2, 1);
    InsereElementoPilha(p, 2, 2);
    InsereElementoPilha(p, 2, 3);
    InsereElementoPilha(p, 2, 4);
    InsereElementoPilha(p, 2, 5);

    ImprimePilha(p);

    InsereElementoPilha(p, 2, 6);

    ImprimePilha(p);

    InsereElementoPilha(p, 1, 6);

    ImprimePilha(p);

    LiberaPilha(p);
    return 0;
}