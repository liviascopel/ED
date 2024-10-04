// Created by Livia H. R. Scopel on 20/06/2024

#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int vetor[], int n); // muito mais lento

void quickSort(int vetor[], int n); // mais rápido

int linearSearch(int vetor[], int n, int elem); // basicamente o mesmo tempo de pesquisa

int binarySearch(int vetor[], int n, int elem);

#endif