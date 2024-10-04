/**
 * Created by Livia H R Scopel on 13/06/2024
 * 
 * Implemente o TAD árvore da aula passada com a seguinte modificação: faça um TAD árvore de alunos (e não de char, como na aula). Use o nome do aluno como chave de busca na 
 * função pertence. Além disto, faça as funções:
 * int folhas (Arv* a); //retorna o número de folhas da árvore
 * int ocorrencias (Arv* a , char* nome); //retorna o número de vezes que o aluno aparece na árvore
 * int altura (Arv* a); retorna a altura da árvore
 */

#ifndef ARVORE_H
#define ARVORE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct arvore tArvore;

typedef struct aluno tAluno;

tArvore *criaArvore(tAluno* aluno, tArvore* esq, tArvore* dir); //cria uma árvore com um aluno e duas subárvores

tArvore *criaArvoreVazia(); //cria uma árvore vazia

void liberaArvore(tArvore* a); //libera a árvore

int pertence(tArvore* a, char* nome); //verifica se um aluno está na árvore

int arvoreVazia (tArvore* a); //verifica se a árvore está vazia

void imprimeArvore (tArvore* a); //imprime a árvore

int folhas (tArvore* a); //retorna o número de folhas da árvore

int ocorrencias (tArvore* a , char* nome); //retorna o número de vezes que o aluno aparece na árvore

int altura (tArvore* a); //retorna a altura da árvore

#endif