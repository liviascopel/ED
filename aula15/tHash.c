/*
 * Created by Livia H. R. Scopel on 13/07/2024
 * Arquivo tHash.c
 *
 * Implemente um programa para contar o número de vezes que uma palavra aparece em um arquivo de entrada. Seu programa deve ler um arquivo
 * texto e retornar, no terminal, as palavras seguidas do número de ocorrências dessas palavras no arquivo. Use uma TABELA HASH para manter
 * as palavras e contar o número de ocorrências. Implemente: TadPalavra, TadHash e um cliente.
 */

#include "tHash.h"

void Inicializa(Hash tabela)
{
    int i;
    for (i = 0; i < NUMEROTABELA; i++)
        tabela[i] = NULL;
}

int hash(char *string)
{
    int i;
    int total = 0;
    for (i = 0; string[i] != '\0'; i++)
        total += string[i];
    return total % NUMEROTABELA;
}

void Imprime(Hash tabela)
{
    int i;
    int n;
    tPalavra **vetor;
    
    n = ContaElementos(tabela);

    vetor = CriaVetor(n, tabela);

    qsort(vetor, n, sizeof(tPalavra *), Compara);
    
    for (i = 0; i < n; i++)
        printf("%s = %d\n", RetornaPalavra(vetor[i]), RetornaRepeticoes(vetor[i]));
        
    free(vetor);
}

struct Palavra
{
    char pal[NUMEROPALAVRAS];
    int n;
    tPalavra *prox;
};

int LePalavra(FILE *fp, char *string)
{
    int i = 0;
    int c;
    
    while ((c = fgetc(fp)) != EOF)
    {
        if (isalpha(c))
            break;
    };
    if (c == EOF)
        return 0;
    else
        string[i++] = c;
        
    while (i < NUMEROPALAVRAS - 1 && (c = fgetc(fp)) != EOF && isalpha(c))
        string[i++] = c;
    string[i] = '\0';
    return 1;
}

tPalavra *Acessa(Hash tabela, char *string)
{
    tPalavra *p;
    int h = hash(string);
    for (p = tabela[h]; p != NULL; p = p->prox)
    {
        if (strcmp(p->pal, string) == 0)
            return p;
    }
    
    p = calloc(1, sizeof(tPalavra));
    strcpy(p->pal, string);
    p->n = 0;
    p->prox = tabela[h];
    tabela[h] = p;
    return p;
}

int ContaElementos(Hash tabela)
{
    int i;
    int total = 0;
    tPalavra *p;
    for (i = 0; i < NUMEROTABELA; i++)
    {
        for (p = tabela[i]; p != NULL; p = p->prox)
            total++;
    }
    return total;
}

int Compara(const void *v1, const void *v2)
{
    tPalavra **p1 = (tPalavra **)v1;
    tPalavra **p2 = (tPalavra **)v2;
    if ((*p1)->n > (*p2)->n)
        return -1;
    else if ((*p1)->n < (*p2)->n)
        return 1;
    else
        return strcmp((*p1)->pal, (*p2)->pal);
}

void Incrementa(tPalavra *p)
{
    p->n++;
}

char *RetornaPalavra(tPalavra *vetor)
{
    return vetor->pal;
}

int RetornaRepeticoes(tPalavra *vetor)
{
    return vetor->n;
}

tPalavra **CriaVetor(int n, Hash tabela)

{
    int i, j = 0;
    tPalavra *p;
    tPalavra **vetor = malloc(n * sizeof(tPalavra *));
    
    for (i = 0; i < NUMEROTABELA; i++)
    {
        for (p = tabela[i]; p != NULL; p = p->prox)
            vetor[j++] = p;
    }
    return vetor;
}

