#ifndef _TFILIAL_H
#define _TFILIAL_H

#include "tEstoque.h"

typedef struct filial tFilial;

tFilial * CriaFilial();

char *ObtemNomeFilial(tFilial * filial);

tEstoque * ObtemEstoqueFilial (tFilial * filial);

int CalculaEstoqueFilial(tFilial * filial);

void DesalocaFilial(tFilial * filial);

#endif