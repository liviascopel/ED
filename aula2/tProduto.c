#include "tProduto.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct produto {
    char* nome;
    int valor;
};

tProduto * CriaProduto () {
    char nome[31];
    int valor;

    tProduto * produto = (tProduto*) calloc (1, sizeof(tProduto));

    scanf("%*[^\n]"); // consome tudo até o \n
    scanf("%*c"); // consome o \n

    printf("\nDigite o nome do produto: ");
    scanf("%30[^\n]", nome);
    scanf("%*c"); // consome o \n
    produto->nome = strdup(nome);
    printf("Digite o valor do produto: ");
    scanf("%d", &valor);
    produto->valor = valor;

    printf("Produto criado com sucesso!\n\n");

    return produto;
}

char *ObtemNomeProduto(tProduto * produto) {
    return produto->nome;
}

int ObtemValorProduto(tProduto * produto) {
    return produto->valor;
}

void DesalocaProduto(tProduto * produto) {
    free(produto->nome);
    free(produto);
}

tProduto ** CriaListaProdutos() {
    tProduto ** lista = (tProduto**) calloc (1, sizeof(tProduto*));
    
    return lista;
}

void AdicionaProdutoLista(tProduto *** lista, int qtd_produtos) {
    *lista = (tProduto**) realloc(*lista, (qtd_produtos) * sizeof(tProduto*));
    (*lista)[qtd_produtos - 1] = CriaProduto();
}

void DesalocaListaProdutos(tProduto ** lista, int qtd_produtos) {
    for (int i = 0; i < qtd_produtos; i++) {
        DesalocaProduto(lista[i]);
    }
    free(lista);
}

void ImprimeListaProdutos(tProduto ** lista, int qtd_produtos) {
printf("LISTA DE PRODUTOS:\n");
    for (int i = 0; i < qtd_produtos; i++) {
        if (lista[i] != NULL)
            printf("Produto: %s valor: %d", lista[i]->nome, lista[i]->valor);
    }
}