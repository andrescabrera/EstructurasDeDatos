/*
Calcular el producto de dos n�meros en forma recursiva
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n1, n2, res;

    printf("Ingrese numero 1: ");
    scanf("%d",&n1);
    printf("\nIngrese n�mero 2: ");
    scanf("%d",&n2);
    res=producto(n1, n2);

    printf("\nEl producto es: %d.", res);

    return 0;
}

int producto(int n1, int n2)
{
    if(n2==1)
        return n1;

    return (producto(n1, n2-1)+n1);
}
