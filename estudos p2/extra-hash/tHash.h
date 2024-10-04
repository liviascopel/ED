/**
 * Created by Livia H. R. Scopel on 13/07/2024
 * Arquivo tHash.h
 */

#ifndef HASH_H
#define HASH_H

#define NUMEROPALAVRAS 64 /* dimensão máxima de cada palavra */
#define NUMEROTABELA 127 /* dimensão da tabela hash */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Palavra tPalavra;

typedef tPalavra *Hash[NUMEROTABELA];

void Inicializa(Hash tab);

int hash(char *string);

void Imprime(Hash tab);

typedef tPalavra* Hash[NUMEROTABELA];

int LePalavra(FILE *fp, char *string);

tPalavra *Acessa(Hash tab, char *string);

int ContaElementos(Hash tab);

void Incrementa(tPalavra *p);

int Compara(const void *v1, const void *v2);

tPalavra **CriaVetor(int n, Hash tab);

int RetornaRepeticoes(tPalavra *vet);

char *RetornaPalavra(tPalavra *vet);

#endif