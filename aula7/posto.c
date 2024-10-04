//  Created by Lívia H. R. Scopel on 08/05/24.

#include "posto.h"

#include "amostra.h"
#include "tFila.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct posto {
    char *nome;
    tFila *amostras_nao_processadas;
    tFila *amostras_positivas;
    tFila *amostras_negativas;
};

Posto* inicPosto(char* nome) {
    Posto *posto = calloc (1, sizeof(Posto));

    posto->nome = strdup(nome);

    posto->amostras_nao_processadas = criaFila();
    posto->amostras_positivas = criaFila();
    posto->amostras_negativas = criaFila();

    return posto;
}

void imprimePosto(Posto* posto) {
    printf("Dados do Posto: %s\n", posto->nome);
    printf("Amostras não processadas\n");
    imprimeFilaAmostras(posto->amostras_nao_processadas);
    printf("\n");
 
    printf("Amostras com resultados positivos\n");
    imprimeFilaAmostras(posto->amostras_positivas);
    printf("\n");
 
    printf("Amostra com resultados negativos\n");
    imprimeFilaAmostras(posto->amostras_negativas);
    printf("\n");
}

void realizaColeta(Posto* posto, char* pessoa, int idade) {
    Amostra *nova_amostra = inicAmostra(pessoa, idade);
    if (idade <= 60) {
        insereFinalFila(posto->amostras_nao_processadas, nova_amostra);
        return;
    }
    insereInicioFila(posto->amostras_nao_processadas, nova_amostra);
}

void processaLoteAmostras(Posto* posto) {

    tCelula *celula_amostra = ObtemPrimeiraCelula(posto->amostras_nao_processadas);
    Amostra *amostra = NULL;
    tCelula *aux = NULL;
    if (celula_amostra != NULL)
        amostra = ObtemAmostraCelula(celula_amostra);

    while (celula_amostra != NULL) {
        aux = celula_amostra;
        celula_amostra = ProximaCelula(celula_amostra);

        if (retornaCargaViral(amostra) >= LIMITE_CARGA_VIRAL) {
            registraResultado(amostra, 1);
            moveCelulaLista(aux, posto->amostras_nao_processadas, posto->amostras_positivas);
        } else {
            registraResultado(amostra, 0);
            moveCelulaLista(aux, posto->amostras_nao_processadas, posto->amostras_negativas);
        }
        if (celula_amostra != NULL) {
            amostra = ObtemAmostraCelula(celula_amostra);
        }
    }
}

void liberaPosto(Posto* posto) {
    if (posto == NULL)
        return;

    free(posto->nome);

    liberaFila(posto->amostras_nao_processadas);
    liberaFila(posto->amostras_positivas);
    liberaFila(posto->amostras_negativas);

    free(posto);
}