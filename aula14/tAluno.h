/**
 * Cliente do tArvoreBB, testando o tipo tAluno
 * arquivo tAluno.h
 * 
 * Created by Livia H. R. Scopel on 05/07/2024
 */

#ifndef ALUNO_H
#define ALUNO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Aluno tAluno;

int compararAlunos(void *a, void *b);

void imprimeAluno(void *a);

void *liberaAluno(void *a);

#endif