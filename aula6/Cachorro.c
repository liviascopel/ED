//
//  Created by Lívia Scopel on 25/04/24.
//

#include "Cachorro.h"
#include <stdlib.h>
#include <string.h>

struct cachorro {
    char *nome;
    agressividade ag;
};

Cachorro* inicCachorro(char *nome, agressividade ag) {
    Cachorro * cachorro = (Cachorro*) calloc (1, sizeof(Cachorro));

    cachorro->nome = strdup(nome); //lembrar de desalocar
    cachorro->ag = ag;

    return cachorro;
}

int ObtemTipoCachorro(Cachorro* c) {
    return c->ag;
}

char *ObtemNomeCachorro(Cachorro *c) {
    return c->nome;
}

void ImprimeCachorro(Cachorro* c) {
    printf("NOME: %s ", c->nome);
    if (c->ag == 0) {
        printf("- OBS: MANSO\n");
    } else if (c->ag == 1) {
        printf("- OBS: BRAVO\n");
    }
}

void atribuiNivelAgressividadeCachorro(Cachorro *c, agressividade ag) {
    c->ag = ag;
}

void liberaCachorro(Cachorro* cachorro) {
    free(cachorro->nome);
    free(cachorro);
}