//
//  Created by Lívia Scopel on 25/04/24.
//

#include "Gato.h"
#include <stdlib.h>
#include <string.h>

struct gato {
    char *nome;
    agressividade ag;
};

Gato *inicGato(char *nome, agressividade ag) {
    Gato * gato = (Gato*) calloc (1, sizeof(Gato));

    gato->nome = strdup(nome);
    gato->ag = ag;

    return gato;
}

char *ObtemNomeGato(Gato *g) {
    return g->nome;
}

int ObtemTipoGato(Gato* g) {
    return g->ag;
}

void ImprimeGato(Gato* g) {
    printf("NOME: %s ", g->nome);
    if (g->ag == 0) {
        printf("- OBS: MANSO\n");
    } else if (g->ag == 1) {
        printf("- OBS: BRAVO\n");
    }
}

void atribuiNivelAgressividadeGato(Gato *g, agressividade ag) {
    g->ag = ag;
}

void liberaGato(Gato* gato) {
    free(gato->nome);
    free(gato);
}