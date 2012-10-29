/*
Dada una matriz de nxn.
Calcular la cantidad de multiplos de 4 en forma recursiva.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 4

void cargarm(int [][], int);
void mostrarm(int [][], int);
int calcularf(int [][], int, int);

int main()
{
    int mat[TAM][TAM], multiplos=0, i;
    cargarm(mat, TAM);
    printf("Mostrando matriz: \n");
    mostrarm(mat, TAM);

    for (i=0;i<TAM;i++)
    {
        multiplos=calcularf(mat, i, TAM-1);
        printf("Hubieron %d multiplos de 4 en la fila %d\n", multiplos, i);
    }

    return 0;
}

void cargarm(int mata[][TAM], int n)
{
    int i, j;
    srand((int)time(NULL));

    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
            mata[i][j]=rand()%15;
    }

    return;
}

void mostrarm(int mata[][TAM], int n)
{
    int i, j;
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
            printf("%d | ", mata[i][j]);

        printf("\n");
    }

    return;
}

int calcularf(int mat[TAM][TAM], int i, int n)
{
    if (n<0)
        return 0;
    if (mat[i][n]%4==0)
        return calcularf(mat, i, n-1)+1;
    else
        return calcularf(mat, i, n-1);
}

