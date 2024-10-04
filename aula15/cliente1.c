/*
 * Created by Livia H. R. Scopel on 13/07/2024
 * Arquivo cliente1.c
 */

#include "tHash.h"

int main(int argc, char **argv)
{
    FILE *fp;
    Hash tabela;
    char s[NUMEROPALAVRAS];
    if (argc != 2)
    {
        printf("Arquivo de entrada nao fornecido.\n");
        return 0;
    }
    /* abre arquivo para leitura */
    fp = fopen(argv[1], "rt");
    if (fp == NULL)
    {
        printf("Erro na abertura do arquivo.\n");
        return 0;
    }
    /* conta ocorrência das palavras */
    Inicializa(tabela);
    while (LePalavra(fp, s))
    {
        tPalavra *p = Acessa(tabela, s);
        Incrementa(p);
    }
    /* Imprime ordenado */
    Imprime(tabela);
    return 0;
}