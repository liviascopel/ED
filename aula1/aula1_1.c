/*
Elabore um programa que declare 4 variáveis do tipo inteiro e 4 do
tipo ponteiro para inteiro e faça com que as variáveis ponteiro apontem para as variáveis
do tipo inteiro. Coloque comandos que permitam modificar os valores das variáveis inteiras
através das variáveis ponteiro. Faça a simulação passo-a-passo para visualizar o que está
acontecendo em cada linha do programa.
*/

#include <stdio.h>

void modifica_variavel (int *pont, int valor);

int main () {
    int a = 1, b = 2, c = 3, d = 4;
    int substitui_a, substitui_b, substitui_c, substitui_d;
    int *pont_a = &a;
    int *pont_b = &b;
    int *pont_c = &c;
    int *pont_d = &d;

    printf("%d %d %d %d\n", *pont_a, *pont_b, *pont_c, *pont_d);

    printf("Valor para modificar a variavel 'a': ");
    scanf("%d", &substitui_a);
    printf("Valor para modificar a variavel 'b': ");
    scanf("%d", &substitui_b);
    printf("Valor para modificar a variavel 'c': ");
    scanf("%d", &substitui_c);
    printf("Valor para modificar a variavel 'd': ");
    scanf("%d", &substitui_d);

    modifica_variavel(pont_a, substitui_a);
    modifica_variavel(pont_b, substitui_b);
    modifica_variavel(pont_c, substitui_c);
    modifica_variavel(pont_d, substitui_d);

    printf("%d %d %d %d", *pont_a, *pont_b, *pont_c, *pont_d);

    return 0;
}

void modifica_variavel (int *pont, int valor) {
    *pont = valor;
}