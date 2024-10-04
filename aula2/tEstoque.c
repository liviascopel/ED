#include "tEstoque.h"
#include "tItem.h"

#include <stdio.h>
#include <stdlib.h>

struct estoque {
    int valor;
    tItem ** itens_estoque;
};

tEstoque * CriaEstoque() {
    tEstoque * estoque = (tEstoque*) calloc (1, sizeof(tEstoque));
    estoque->itens_estoque = (tItem**) calloc (1, sizeof(tItem*)); //cria uma posicao de item;

    return estoque;
}

void AdicionaItemEstoque(tEstoque * estoque, tItem * item) {
    estoque->valor++;
    estoque->itens_estoque = (tItem**) realloc (estoque->itens_estoque, estoque->valor * sizeof(tItem*));
    estoque->itens_estoque[estoque->valor-1] = item;
}

void DesalocaEstoque(tEstoque * estoque) {
    for (int i = 0; i < estoque->valor; i++) {
        DesalocaItem(estoque->itens_estoque[i]);
    }
    free(estoque->itens_estoque);
    free(estoque);
}

int CalculaEstoque(tEstoque * estoque) {
    int soma = 0;
    for (int i = 0; i < estoque->valor; i++) {
        soma = soma + ObtemValorItem(estoque->itens_estoque[i]);
    }
    return soma;
}

void ImprimeEstoque(tEstoque * estoque) {
    char *nome = '\0';
    int valor, quantidade;

    for (int i = 0; i < estoque->valor; i++) {
        tItem * item = estoque->itens_estoque[i];
        tProduto * p = ObtemProdutoItem(item);
        char *nome = ObtemNomeProduto(p);
        valor = ObtemValorProduto(p);
        quantidade = ObtemQuantidadeItem(item);

        printf("\t\tItem: %s, valor unitário: %d, quantidade: %d\n", nome, valor, quantidade);
    }
}