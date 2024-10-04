// Created by Livia H R Scopel on 13/06/2024

#include "arvore.h"

struct arvore
{
    tAluno *aluno;
    tArvore *esq;
    tArvore *dir;
};

struct aluno
{
    char *nome;
    int matricula;
};

tAluno *criaAluno(char *nome, int matricula)
{
    tAluno *a = calloc(1, sizeof(tAluno));

    a->nome = nome;
    a->matricula = matricula;

    return a;
}

tAluno *liberaAluno(tAluno *a)
{
    free(a);
    return NULL;
}

tArvore *criaArvoreVazia()
{
    return NULL;
}

int arvoreVazia(tArvore *a)
{
    return a == NULL;
}

tArvore *criaArvore(tAluno *aluno, tArvore *esq, tArvore *dir)
{
    tArvore *a = calloc(1, sizeof(tArvore));

    a->aluno = aluno;
    a->esq = esq;
    a->dir = dir;

    return a;
}

void liberaArvore(tArvore *a)
{
    if (!arvoreVazia(a))
    {
        liberaArvore(a->esq);
        liberaArvore(a->dir);
        free(a);
    }
    return;
}

int pertence(tArvore *a, char *nome)
{
    if (arvoreVazia(a))
    {
        return 0;
    }
    else
    {
        return a->aluno->nome == nome || pertence(a->esq, nome) || pertence(a->dir, nome);
    }
}

void imprimeArvore(tArvore *a)
{
    if (!arvoreVazia(a))
    {
        printf("%s\n", a->aluno->nome);
        imprimeArvore(a->esq);
        imprimeArvore(a->dir);
    }
    return;
}

int folhas(tArvore *a)
{
    if (arvoreVazia(a))
    {
        return 0;
    }
    else if (a->esq == NULL || a->dir == NULL)
    {
        return 1;
    }
    else
    {
        return folhas(a->esq) + folhas(a->dir);
    }
}

int ocorrencias(tArvore *a, char *nome)
{
    if (arvoreVazia(a))
    {
        return 0;
    }
    else
    {
        return (a->aluno->nome == nome) + ocorrencias(a->esq, nome) + ocorrencias(a->dir, nome);
    }
}

int maxNos(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int altura(tArvore *a)
{
    if (arvoreVazia(a))
        return -1;
    else
        return 1 + maxNos(altura(a->esq), altura(a->dir));
}

int main ()
{
    tAluno *a1 = criaAluno("Lívia", 1);
    tAluno *a2 = criaAluno("Samuel", 2);
    tAluno *a3 = criaAluno("Paula", 3);
    tAluno *a4 = criaAluno("Joao", 4);
    tAluno *a5 = criaAluno("Igor", 5);


    tArvore *arvore = criaArvore(a1, 
    criaArvore(a2, criaArvore(a4, criaArvoreVazia(), criaArvoreVazia()), criaArvore(a5, criaArvoreVazia(), criaArvoreVazia())), 
    criaArvore(a3, criaArvore(a1, criaArvoreVazia(), criaArvoreVazia()), criaArvoreVazia()));

    imprimeArvore(arvore);
    printf("\n");

    printf("Folhas: %d\n", folhas(arvore));
    printf("Ocorrências de Lívia: %d\n", ocorrencias(arvore, "Lívia"));
    printf("Altura: %d\n", altura(arvore));

    liberaArvore(arvore);
    liberaAluno(a1);
    liberaAluno(a2);
    liberaAluno(a3);
    liberaAluno(a4);
    liberaAluno(a5);

    return 0;
}