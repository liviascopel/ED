/**
 * Cliente do tArvoreBB, testando o tipo tAluno
 * arquivo tAluno.c
 *
 * Created by Livia H. R. Scopel on 05/07/2024
 */

#include "tAluno.h"
#include "tArvoreBB.h"

struct Aluno
{
    int matricula;
    char *nome;
};

tAluno *criarAluno(int matricula, char *nome)
{
    tAluno *aluno = (tAluno *)malloc(sizeof(tAluno));

    aluno->matricula = matricula;
    aluno->nome = strdup(nome);

    return aluno;
}

int compararAlunos(void *a, void *b)
{
    tAluno *aluno_a = (tAluno *)a;
    tAluno *aluno_b = (tAluno *)b;

    if (aluno_a->matricula < aluno_b->matricula)
        return -1;
    else if (aluno_a->matricula == aluno_b->matricula)
        return 0;
    else
        return 1;
}

void imprimeAluno(void *a)
{
    tAluno *aluno = (tAluno *)a;

    printf("Matricula: %03d\nNome: %s\n\n", aluno->matricula, aluno->nome);
}

void *liberaAluno(void *a)
{
    tAluno *aluno = (tAluno *)a;

    free(aluno->nome);
    free(aluno);

    return NULL;
}

/*
int main ()
{
    tAluno *a = criarAluno(7, "Livia");
    tAluno *b = criarAluno(1, "Paula");
    tAluno *c = criarAluno(6, "Joao");
    tAluno *d = criarAluno(3, "Samuel");

    tArvoreBB *arvore = criaArvore();

    arvore = insereArvore(arvore, a, compararAlunos);
    arvore = insereArvore(arvore, b, compararAlunos);
    arvore = insereArvore(arvore, c, compararAlunos);
    arvore = insereArvore(arvore, d, compararAlunos);

    imprimeArvore(arvore, imprimeAluno);

    retiraArvore(arvore, b, compararAlunos, liberaAluno);

    imprimeArvore(arvore, imprimeAluno);

    liberaArvore(arvore, liberaAluno);

    return 0;
}
*/