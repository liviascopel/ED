#ifndef _PRODUTO_H
#define _PRODUTO_H

typedef struct produto tProduto;

tProduto *CriaProduto (int codigo, char *nome, int preco);

int ObtemCodigoProduto (tProduto *prod);

void ImprimeProduto(tProduto *prod);

void liberaProduto (tProduto *prod);

#endif