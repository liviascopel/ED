/*
Implemente funções em C para cada um dos problemas abaixo (todas as funções devem estar em um único arquivo aula1_2.c). Para cada uma das
funções, implemente uma função main diferente (comente as outras para conseguir rodar):

2.1) Implemente uma função que calcule a área da superfície e o volume de uma esfera de raio r. A área da superfície e o volume são dados,
 respectivamente, por e. Essa função deve obedecer ao seguinte protótipo: void calc_esfera (float r, float* area, float* volume);

2.2) Implemente uma função que calcule as raízes de uma equação do segundo grau, do tipo ax2 + bx + c = 0. Essa função deve obedecer o 
seguinte protótipo: int raizes (float a, float b, float c, float* x1, float* x2);

2.3) Implemente uma função que receba como parâmetro um vetoror de números inteiros (vetor) de tamanho n e retorne quantos números pares 
estão armazenados nesse vetoror. Essa função deve obedecer ao protótipo: int pares (int n, int* vetor);

2.4) Implemente uma função que receba como parâmetro um vetoror de números inteiros (vetor) de tamanho n e inverta a ordem dos elementos 
armazenados nesse mesmo vetoror. Essa função deve obedecer ao protótipo: void inverte (int n, int* vetor);

2.5) Implemente uma função que permita a avaliação de polinômios. Cada polinômio é definido por um vetoror que contém seus coeficientes. 
Por exemplo, o polinômio de grau 2, 3x2 + 2x+ 12, terá um vetoror de coeficientes igual a vetor[] = {12, 2, 3}. A função deve obedecer o 
seguinte protótipo: double avalia (double* poli, int grau, double x), onde poli é o vetoror de coeficientes; grau é o grau do polinômio;
x é o valor da variável.
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.14

// 2.1 ---------------------------------------------------------------------------------


void calc_esfera(float r, float* area, float* volume) {
    *area = 4 * PI * r * r;
    *volume = 4 * PI * r * r * r / 3;
}

// int main () {
//     float r;
//     float area, volume;

//     printf("Raio da esfera: ");
//     scanf("%f", &r);

//     calc_esfera(r, &area, &volume);

//     printf("Volume da esfera: %.2f\n", volume);
//     printf("Area da esfera: %.2f\n", area);

//     return 0;
// } 

// 2.2 ---------------------------------------------------------------------------------

int raizes(float a, float b, float c, float* x1, float* x2) {
    printf("%f %f %f\n", a, b, c);
    float delta = (b * b) - (4 * a * c);
    printf("%f\n", delta);
        
    *x1 = (-b + sqrt(delta)) / (2 * a);
    *x2 = (-b - sqrt(delta)) / (2 * a);

    if (delta < 0)
        return 0;
    if (delta == 0)
        return 1;
    if (delta > 0)
        return 2;

    return -1;
}

// int main () {
//     float a, b, c;
//     float x1, x2;
//     int qtd_raizes;
    
//     printf("Digite os valores de 'a', 'b' e 'c' respectivamente: ");
//     scanf("%f %f %f", &a, &b, &c);

//     qtd_raizes = raizes(a, b, c, &x1, &x2);

//     printf("A equação possui %d raizes\n", qtd_raizes);
//     if (qtd_raizes != 0) {
//         printf("x1 = %.2f\n", x1);
//         printf("x2 = %.2f\n", x2);
//     }

//     return 0;
// 

// 2.3 ---------------------------------------------------------------------------------

int pares (int n, int* vetor) {
    int cont = 0;
    for (int i = 0; i < n; i++) {
        if (vetor[i] % 2 == 0) {
            cont++;
        }
    }
    return cont;
}

// int main () {
//     int qtd;

//     scanf("%d", &qtd);

//     int *vetor = (int*) calloc (1, qtd * sizeof(int));

//     for (int i = 0; i < qtd; i++) {
//         scanf("%d", &vetor[i]);
//     }

//     int qtd_pares = pares(qtd, vetor);
//     printf("Quantidade de numeros pares: %d\n", qtd_pares);

//        free(vetor);

//     return 0;
// }

// 2.4 ---------------------------------------------------------------------------------

void inverte (int n, int* vetor) {
    int* aux = (int*) calloc (1, sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        aux[i] = vetor[i];
    }
    for (int i = 0, j = n-1; i < n, j >= 0 ; i++, j--) {
        vetor[i] = aux[j];
    }
    free(aux);
}

// int main () {
//     int qtd;
//     scanf("%d", &qtd);

//     int* vetor = (int*) calloc (1, qtd * sizeof(int));

//     for (int i = 0; i < qtd; i++) {
//         scanf("%d", &vetor[i]);
//     }

//     inverte(qtd, vetor);

//     for (int i = 0; i < qtd; i++) {
//         printf("%d ", vetor[i]);
//     }

//     free(vetor);

//     return 0;
// }

// 2.5 ---------------------------------------------------------------------------------

double avalia (double* poli, int grau, double x) {
    double soma = 0;
    for(int i = 0; i <= grau; i++) {
        soma = soma + (poli[i] * pow(x, i));
    }
    return soma;
}

// int main () {
//     int qtd;
//     double x;

//     scanf("%d %lf", &qtd, &x);
//     double *vetor = (double*) calloc (1, qtd * sizeof(double));

//     for(int i = 0; i < qtd; i++) {
//         scanf("%lf", &vetor[i]);
//     }

//     double total = avalia(vetor, qtd-1, x);

//     printf("%.2f", total);
//     free(vetor);

//     return 0;
// }