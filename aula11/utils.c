// Created by Livia H. R. Scopel on 20/06/2024

#include "utils.h"

void bubbleSort(int vetor[], int n)
{
    int aux;
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n-1; j++)
        {
            if (vetor[i] > vetor[j])
            {
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
        }
    }
}

void quickSort(int vetor[], int n)
{
    if (n <= 1)
        return;
    else
    {
        int x = vetor[0];
        int a = 1;
        int b = n-1;
        do {
            while (a < n && vetor[a] <= x)
                a++;
            while (vetor[b] > x)
                b--;
            if (a < b) {
                int temp = vetor[a];
                vetor[a] = vetor[b];
                vetor[b] = temp;
                a++;
                b--;
            }
        }
        while (a <= b);
        vetor[0] = vetor[b];
        vetor[b] = x;

        quickSort(vetor, b);
        quickSort(&vetor[a], n-a);
    }
}

int linearSearch(int vetor[], int n, int elem)
{
    for (int i = 0; i < n; i++)
    {
        if (vetor[i] == elem)
        {
            return i;
        }
    }
    return -1;
}

int binarySearch(int vetor[], int n, int elem)
{
    int inicio = 0;
    int fim = n-1;
    int meio;

    while (inicio <= fim)
    {
        meio = (inicio + fim) / 2;
        if (elem < vetor[meio])
            fim = meio - 1;
        else if (elem > vetor[meio])
            inicio = meio + 1;
        else
            return meio;
    }
    return -1;
}