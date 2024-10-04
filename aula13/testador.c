#include "tArvoreBB.h"

int main()
{
    tArvore *a = CriaArvore(10, NULL, NULL);

    ImprimeArvore(a);
    printf("\n");

    a = InsereElementoArvore(a, 8);

    ImprimeArvore(a);
    printf("\n");

    a = InsereElementoArvore(a, 11);

    ImprimeArvore(a);
    printf("\n");

    a = InsereElementoArvore(a, 5);

    ImprimeArvore(a);
    printf("\n");

    a = InsereElementoArvore(a, 9);

    ImprimeArvore(a);
    printf("\n");

    a = InsereElementoArvore(a, 15);

    ImprimeArvore(a);
    printf("\n");

    a = RetiraElementoArvore(a, 10);

    ImprimeArvore(a);
    printf("\n");

    LiberaArvore(a);

    return 0;
}