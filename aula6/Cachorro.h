//
//  Created by Lívia Scopel on 25/04/24.
//

#ifndef _CACHORRO_H
#define _CACHORRO_H

#include <stdio.h>
#include "Gato.h"

typedef struct cachorro Cachorro;

Cachorro *inicCachorro(char *nome, agressividade ag);

char *ObtemNomeCachorro(Cachorro *c);

int ObtemTipoCachorro(Cachorro* c);

void ImprimeCachorro(Cachorro* c);

void atribuiNivelAgressividadeCachorro(Cachorro *c, agressividade ag);

void liberaCachorro(Cachorro* cachorro);

#endif