/*
Ingresar los n elementos de un vector y calcular la sumatoria
de sus elementos en forma recursiva.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cargar(int [], int n);
int suma(int [], int n);


int main()
{
    int n, mat[20], s;
    printf("ingresar tamaño vector: ");
    scanf("%d",&n);
    cargar(vec, n);
    mostrarm(vec, n);
    s=suma(vec, n);
    printf("%d", s);

    return 0;
}

int cargar(int vec[], int n)
{
    int i;

    srand((int)time(NULL));
    for(i=0;i<n;i++)
        vec[i]=rand();

return 0;
}

int suma(int vec[], int n)
{
    if(n==0)
        return vec[0];

    return suma(vec, n-1)+vec[n];
}
