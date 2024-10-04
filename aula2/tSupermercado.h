#ifndef _TSUPERMERCADO_H
#define _TSUPERMERCADO_H

#include "tFilial.h"

typedef struct supermercado tSupermercado;

tSupermercado * CriaSupermercado();

tFilial ** ObtemFiliais(tSupermercado * supermercado);

char *ObtemNomeSupermercado(tSupermercado * supermercado);

void AdicionaFilialSupermercado(tSupermercado * supermercado, tFilial * filial, int qtd_filiais);

void DesalocaSupermercado(tSupermercado * supermercado, int qtd_filiais);

#endif