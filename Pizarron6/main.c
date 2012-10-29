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
int calcularm(int [][], int, int, int, int);

int main()
{
    int mat[TAM][TAM], multiplos;
    cargarm(mat, TAM);
    printf("Mostrando matriz: \n");
    mostrarm(mat, TAM);
    multiplos=calcularm(mat, TAM-1, 0, 0, 0);
    printf("Hubieron %d multiplos de 4 en la matriz", multiplos);
    return 0;
}

void cargarm(int mata[][TAM], int n)
{
    int i, j;
    srand((int)time(NULL));

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            mata[i][j]=rand()%9;
    }

return;
}

void mostrarm(int mata[][TAM], int n)
{
    int i, j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%d | ", mata[i][j]);

            printf("\n");
    }

    return;
}

int calcularm(int mata[][TAM], int n, int x, int y, int nmult)
{
    if(mata[x][y]%4==0)
        nmult++;

    if(x==n&&y==n)
        return nmult;

    if(x==n)
    {
        x=0;
        y++;
    }
    else
        x++;

    return calcularm(mata, n, x, y, nmult);
}

