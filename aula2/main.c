#include "tProduto.h"
#include "tItem.h"
#include "tEstoque.h"
#include "tFilial.h"
#include "tSupermercado.h"

#include <stdio.h>
#include <stdlib.h>

int CalculaEstoqueTotal(tFilial ** filiais, int qtd_filiais);

int main () {
    int qtd_produtos = 0;
    int qtd_filiais = 0;
    int qtd_estoque = 0;
    int qtd = 0;
    int opcao, opcao_filial;
    int valor = 0;

    // DECLARANDO VARIAVEIS BASE
    tSupermercado * supermercado = CriaSupermercado();
    tProduto ** lista_produtos = CriaListaProdutos();
    tFilial * f = NULL;

    do {
        printf("================ MENU ================\n");
        printf("Escolha uma das seguintes opções:\n");
        printf("1 - Cadastrar novo produto\n");
        printf("2 - Cadastrar nova filial\n");
        printf("3 - Cadastrar itens de estoque para uma filial\n");
        printf("4 - Calcular o estoque da filial\n");
        printf("5 - Calcular o estoque do supermercado\n");
        printf("6 - Imprimir informações do supermercado\n");
        printf("7 - Sair do programa\n");

        scanf("%d", &opcao);
        // CADASTRAR NOVO PRODUTO
        if (opcao == 1) {
            printf("\n= Opcao escolhida - Cadastrar novo produto\n");
            qtd_produtos++;
            AdicionaProdutoLista(&lista_produtos, qtd_produtos);
        }

        // CADASTRAR NOVA FILA
        else if (opcao == 2) {
            printf("\n= Opcao escolhida - Cadastrar nova filial\n");
            qtd_filiais++;
            AdicionaFilialSupermercado(supermercado, CriaFilial(), qtd_filiais);
        }

        // CADASTRAR ITENS DE ESTOQUE PARA UMA FILIAL
        else if (opcao == 3) {
            printf("\n= Opcao escolhida - Cadastrar itens de estoque para uma filial\n");
            if (qtd_filiais == 0) {
                printf("ERRO: voce nao tem nenhuma filial cadastrada\n");
                continue;
            }

            printf("Escolha uma filial de 0 a %d\n", qtd_filiais - 1);
            scanf("%d", &opcao_filial);
            if (opcao > qtd_filiais-1) {
                printf("ERRO: voce nao tem essa filial cadastrada\n");
                continue;
            }

            f = ObtemFiliais(supermercado)[opcao_filial];
            printf("\nFilial escolhida - %s\n\n", ObtemNomeFilial(f));
            printf("Digite o estoque dos seguintes produtos:\n");

            for (int i = 0; i < qtd_produtos; i++) {
                printf("Produto: %s Quantidade: ", ObtemNomeProduto(lista_produtos[i]));
                scanf("%d", &qtd);

                if (qtd > 0) {
                    qtd_estoque++;

                    tItem * item = CriaItem(qtd, lista_produtos[i]);
                    AdicionaItemEstoque(ObtemEstoqueFilial(f), item);

                    printf("Produto adicionado ao estoque com sucesso!\n");
                }
            }
            printf("\nAcabaram os produtos!\n\n");
        }

        // CALCULAR O ESTOQUE DE UMA FILIAL
        else if (opcao == 4) {
            printf("\n= Opcao escolhida - Calcular o estoque da filial\n");
            printf("Escolha uma filial de 0 a %d\n", qtd_filiais - 1);
            scanf("%d", &opcao_filial);
            if (opcao > qtd_filiais-1) {
                printf("ERRO: voce nao tem essa filial cadastrada\n");
                continue;
            }

            f = (ObtemFiliais(supermercado))[opcao_filial];
            printf("\nFilial escolhida - %s\n", ObtemNomeFilial(f));

            valor = CalculaEstoqueFilial(f);
            printf("Estoque: %d\n\n", valor);
        }

        // CALCULAR O ESTOQUE DO SUPERMERCADO
        else if (opcao == 5) {
            valor = 0;
            printf("\n= Opcao escolhida - Calcular o estoque do supermercado\n");
            
            valor = CalculaEstoqueTotal(ObtemFiliais(supermercado), qtd_filiais);
            printf("Estoque: %d\n\n", valor);
        }

        // IMPRIMIR INFORMACOES DO SUPERMERCADO
        else if (opcao == 6) {
            printf("\n= Opcao escolhida - Imprimir informações do supermercado\n\n");
            printf("Nome: %s, Estoque Total: %d\n", ObtemNomeSupermercado(supermercado), CalculaEstoqueTotal(ObtemFiliais(supermercado), qtd_filiais));
            
            for (int i = 0; i < qtd_filiais; i++) {
                printf("\tFilial: %s\n", ObtemNomeFilial(ObtemFiliais(supermercado)[i]));
                printf("\tEstoque: %d\n", CalculaEstoqueFilial(ObtemFiliais(supermercado)[i]));

                ImprimeEstoque(ObtemEstoqueFilial(ObtemFiliais(supermercado)[i]));
            }
            printf("\n");
        }
    } while (opcao != 7);
    // LIBERANDO A MEMÓRIA ALOCADA
    DesalocaListaProdutos(lista_produtos, qtd_produtos);
    DesalocaSupermercado(supermercado, qtd_filiais);

    return 0;
}

int CalculaEstoqueTotal(tFilial ** filiais, int qtd_filiais) {
    int valor = 0;
    for (int i = 0; i < qtd_filiais; i++) {
        valor += CalculaEstoqueFilial(filiais[i]);
    }
    return valor;
}