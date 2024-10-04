#ifndef _TESTOQUE_H
#define _TESTOQUE_H

#include "tItem.h"

typedef struct estoque tEstoque;

tEstoque * CriaEstoque();

void AdicionaItemEstoque(tEstoque * estoque, tItem * item);

int CalculaEstoque(tEstoque * estoque);

void ImprimeEstoque(tEstoque * estoque);

void DesalocaEstoque(tEstoque * estoque);

#endif