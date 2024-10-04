#ifndef _TITEM_H
#define _TITEM_H

#include "tProduto.h"

typedef struct item tItem;

tItem * CriaItem (int quantidade, tProduto * produto);

int ObtemValorItem(tItem *item);

int ObtemQuantidadeItem(tItem * item);

tProduto * ObtemProdutoItem(tItem * item);

void DesalocaItem(tItem * item);

#endif