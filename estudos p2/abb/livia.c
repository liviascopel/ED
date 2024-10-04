
#include "utils.h"

int main()
{
    tArvore *a = criaArvoreVazia();

    a = insereElemento(a, 10);
    a = insereElemento(a, 7);
    a = insereElemento(a, 4);
    a = insereElemento(a, 6);
    a = insereElemento(a, 1);
    a = insereElemento(a, 8);

    imprimeArvore(a);

    a = retiraElemento(a, 10);

    imprimeArvore(a);

    liberaArvore(a);

    return 0;
}