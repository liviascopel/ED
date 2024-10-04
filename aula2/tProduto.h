#ifndef _TPRODUTO_H
#define _TPRODUTO_H

typedef struct produto tProduto;

tProduto * CriaProduto ();

char *ObtemNomeProduto(tProduto * produto);

int ObtemValorProduto(tProduto * produto);

void DesalocaProduto(tProduto * produto);

tProduto ** CriaListaProdutos();

void AdicionaProdutoLista(tProduto *** lista, int qtd_produtos);

void DesalocaListaProdutos(tProduto ** lista, int qtd_produtos);

void ImprimeListaProdutos(tProduto ** lista, int qtd_produtos);

#endif