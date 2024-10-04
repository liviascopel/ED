#include "tItem.h"
#include "tProduto.h"

#include <stdio.h>
#include <stdlib.h>

struct item {
    int quantidade;
    tProduto * produto;
};

tItem * CriaItem (int quantidade, tProduto * produto) {
    int qtd_estoque;
    tItem * item = (tItem*) calloc (1, sizeof(tItem)); //desalocar

    item->produto = produto;
    item->quantidade = quantidade;

    return item;
}

int ObtemValorItem(tItem *item) {
    return item->quantidade * ObtemValorProduto(item->produto);
}

int ObtemQuantidadeItem(tItem * item) {
    return item->quantidade;
}

tProduto * ObtemProdutoItem(tItem * item) {
    return item->produto;
}

void DesalocaItem(tItem * item) {
    free(item);
}

