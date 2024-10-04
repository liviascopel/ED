#include "tFilial.h"
#include "tEstoque.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct filial {
    char *nome;
    tEstoque * estoque;
};

tFilial * CriaFilial() {
    char nome[31];

    tFilial * filial = (tFilial*) calloc (1, sizeof(tFilial));

    scanf("%*[^\n]"); // consome tudo até o \n
    scanf("%*c"); // consome o \n

    printf("\nDigite o nome da filial: ");
    scanf("%30[^\n]", nome);
    filial->nome = strdup(nome);

    filial->estoque = CriaEstoque();
    printf("Filial criada com sucesso!\n\n");

    return filial;
}

char *ObtemNomeFilial(tFilial * filial) {
    return filial->nome;
}

tEstoque * ObtemEstoqueFilial (tFilial * filial) {
    return filial->estoque;
}

int CalculaEstoqueFilial(tFilial * filial) {
    return CalculaEstoque(filial->estoque);
}

void DesalocaFilial(tFilial * filial) {
    DesalocaEstoque(filial->estoque);
    free(filial->nome);
    free(filial);
}

