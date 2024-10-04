//
//  Created by Lívia Scopel on 25/04/24.
//

#ifndef _GATO_H
#define _GATO_H

#include <stdio.h>

typedef struct gato Gato;

typedef enum {
    MANSO,
    BRAVO
} agressividade;

Gato *inicGato(char *nome, agressividade ag);

char *ObtemNomeGato(Gato *g);

int ObtemTipoGato(Gato* g);

void ImprimeGato(Gato* g);

void atribuiNivelAgressividadeGato(Gato *g, agressividade ag);

void liberaGato(Gato* gato);

#endif