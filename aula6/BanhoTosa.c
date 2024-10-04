//
//  Created by Lívia Scopel on 25/04/24.
//

#include "BanhoTosa.h"
#include "tLista.h"
#include "Cachorro.h"
#include "Gato.h"

#include <stdlib.h>
#include <string.h>

struct banhotosa {
    char *nome;
    tLista *mansos;
    tLista *bravos;
};

BanhoTosa* inicBanhoTosa(char* nome) {

    BanhoTosa* loja = (BanhoTosa*) calloc (1, sizeof(BanhoTosa));

    loja->nome = strdup(nome);
    loja->mansos = criaLista();
    loja->bravos = criaLista();

    return loja;
}

void cadastraCachorro(BanhoTosa* loja, Cachorro* dog) {

    tCelula *c = criaCelula(CACHORRO, NULL, dog);

    if (ObtemTipoCachorro(dog) == MANSO) { //se for manso add na lista de mansos
        adicionaCelulaLista(loja->mansos, c);
    } else if (ObtemTipoCachorro(dog) == BRAVO) { //se for bravo add na lista de bravos
        adicionaCelulaLista(loja->bravos, c);
    }
}

void cadastraGato(BanhoTosa* loja, Gato* cat) {

    tCelula *c = criaCelula(GATO, NULL, cat);

    if (ObtemTipoGato(cat) == MANSO) { //se for manso add na lista de mansos
        adicionaCelulaLista(loja->mansos, c);
    } else if (ObtemTipoGato(cat) == BRAVO) { //se for bravo add na lista de bravos
        adicionaCelulaLista(loja->bravos, c);
    }
}

void imprimeBanhoTosa(BanhoTosa* loja) {

    printf("LOJA: %s\n\n", loja->nome);
    printf("LISTA ANIMAIS MANSOS:\n");
    ImprimeLista(loja->mansos);

    printf("LISTA ANIMAIS BRAVOS:\n");
    ImprimeLista(loja->bravos);
}

float calculaReceita(BanhoTosa* loja) {

    float receita = 0;

    // para os mansos
    tCelula *c = ObtemPrim(loja->mansos);
    while (c != NULL) {
        if (ObtemTipoPet(c) == GATO) {
            receita += 30;
        } else if (ObtemTipoPet(c) == CACHORRO) {
            receita += 40;
        }
        c = ObtemProx(c);
    }

    // para os bravos
    c = ObtemPrim(loja->bravos);
    while (c != NULL) {
        if (ObtemTipoPet(c) == GATO) {
            receita += 35;
        } else if (ObtemTipoPet(c) == CACHORRO) {
            receita += 45;
        }
        c = ObtemProx(c);
    }

    return receita;
}

void liberaBanhoTosa(BanhoTosa* loja) {

    desalocaLista(loja->mansos);
    desalocaLista(loja->bravos);
    free(loja->nome);
    free(loja);
}

void atualizaSituacaoCachorro(BanhoTosa *loja, Cachorro *c) {

    tCelula * cel;

    if (ObtemTipoCachorro(c) == MANSO) { //se o cachorro for manso, ele era bravo
        cel = encontraCelulaCachorro(loja->bravos, c);
        mudaCelulaLista(loja->bravos, loja->mansos, cel); //muda ele de lista
    } else if (ObtemTipoCachorro(c) == BRAVO) {
        cel = encontraCelulaCachorro(loja->mansos, c);
        mudaCelulaLista(loja->mansos, loja->bravos, cel);
    }
}

void atualizaSituacaoGato(BanhoTosa *loja, Gato *g) {

    tCelula * cel;

    if (ObtemTipoGato(g) == MANSO) { //se o gato for manso, ele era bravo
        cel = encontraCelulaGato(loja->bravos, g);
        mudaCelulaLista(loja->bravos, loja->mansos, cel); //muda ele de lista
    } else if (ObtemTipoGato(g) == BRAVO) {
        cel = encontraCelulaGato(loja->mansos, g);
        mudaCelulaLista(loja->mansos, loja->bravos, cel);
    }
}