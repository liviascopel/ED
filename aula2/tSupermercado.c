#include "tSupermercado.h"
#include "tFilial.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct supermercado {
    char *nome;
    tFilial ** filiais;
    int valor_total_estoque;
};

tSupermercado * CriaSupermercado() {
    char nome[31];

    tSupermercado * supermercado = (tSupermercado*) calloc (1, sizeof(tSupermercado));

    printf("Digite o nome do supermercado: ");
    scanf("%30[^\n]", nome);
    supermercado->nome = strdup(nome);

    supermercado->filiais = (tFilial**) calloc (1, sizeof(tFilial*));

    return supermercado;
}

tFilial ** ObtemFiliais(tSupermercado * supermercado) {
    return supermercado->filiais;
}

char *ObtemNomeSupermercado(tSupermercado * supermercado) {
    return supermercado->nome;
}

void AdicionaFilialSupermercado(tSupermercado * supermercado, tFilial * filial, int qtd_filiais) {
    supermercado->filiais = (tFilial**) realloc (supermercado->filiais, qtd_filiais * sizeof(tFilial*));
    supermercado->filiais[qtd_filiais-1] = filial;
}

void DesalocaSupermercado(tSupermercado * supermercado, int qtd_filiais) {
    for (int i = 0; i < qtd_filiais; i++) {
        DesalocaFilial(supermercado->filiais[i]);
    }
    free(supermercado->filiais);
    free(supermercado->nome);
    free(supermercado);
}