#include "produto.h"
#include "lista.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {

    tProduto * prod1 = CriaProduto(0, "Cafe", 5);
    tProduto * prod2 = CriaProduto(1, "Suco de uva", 10);
    tProduto * prod3 = CriaProduto(2, "Tomate", 3);
    tProduto * prod4 = CriaProduto(3, "Brocolis", 6);


    tLista * lista = CriaLista();
    ImprimeLista(lista);


    lista = InsereProdutoLista(lista, CriaCelula(prod1));
    ImprimeLista(lista);
    printf("\n");

    lista = InsereProdutoLista(lista, CriaCelula(prod2));
    ImprimeLista(lista);
    printf("\n");

    lista = InsereProdutoLista(lista, CriaCelula(prod3));
    ImprimeLista(lista);
    printf("\n");

    lista = RetiraProdutoLista(lista, 0);
    ImprimeLista(lista);
    printf("\n");

    lista = InsereProdutoLista(lista, CriaCelula(prod4));
    ImprimeLista(lista);
    printf("\n");


    DesalocaLista(lista);
    liberaProduto(prod1);
    liberaProduto(prod2);
    liberaProduto(prod3);
    liberaProduto(prod4);
    
    return 0;
}