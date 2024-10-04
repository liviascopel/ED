#include "produto.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct produto {
    int codigo;
    char *nome;
    int preco;
};

tProduto *CriaProduto (int codigo, char *nome, int preco) {
    tProduto *prod = (tProduto*) calloc (1, sizeof(tProduto));

    prod->codigo = codigo;
    prod->preco = preco;
    prod->nome = strdup(nome); // desalocar memoria

    return prod;
}

int ObtemCodigoProduto (tProduto *prod) {
    return prod->codigo;
}

void ImprimeProduto(tProduto *prod) {
    printf("codigo: %d - nome: %s - preco: %d\n", prod->codigo, prod->nome, prod->preco);
}

void liberaProduto (tProduto *prod) {
    free(prod->nome);
    free(prod);
}