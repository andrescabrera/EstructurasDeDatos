/*
Andr�s Cabrera - Recursividad  - Ejercicio 3
Cargar una matriz de n filas y n columnas y calcular y mostrar
El elemento m�ximo de cada fila en forma recursiva.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 6

void cargar(int mata[][], int n, int *fila, int *cols);
void mostrar(int mata[][], int n, int *fila, int *cols);
void maximo(int mata[TAM][TAM], int n, int *fila, int *cols);

int main()
{
int fila=0, cols=0;
int n;
do
{
    printf("\nIngrese orden de la matriz a cargar: ");
    scanf("%d", &n);
}while(n<1||n>TAM);

int mata[n][n];
srand((int)time(NULL));
cargar(mata, n, &fila, &cols);
fila=0;
cols=0;
mostrar(mata, n, &fila, &cols);
fila=0;
cols=0;
maximo(mata, n, &fila, &cols);

return EXIT_SUCCESS;
}

void cargar(int mata[TAM][TAM], int n, int *fila, int *cols)
{


if(*cols==n-1 && *fila<n)
{
    mata[*fila][*cols]=rand()%20;
    *cols=0;
    *fila+=1;
    cargar(mata, n, fila ,cols);
}
else
{
    if(*fila<n && *cols<n)
    {
        mata[*fila][*cols]=rand()%20;
        *cols+=1;
        cargar(mata, n, fila, cols);
    }
}

return;
}

void mostrar(int mata[TAM][TAM], int n, int *fila, int *cols)
{
if(*cols==n-1 && *fila<n)
{
    printf("%d | ", mata[*fila][*cols]);
    printf("\n");
    *cols=0;
    *fila+=1;
    mostrar(mata, n, fila ,cols);
}
else
{
    if(*fila<n && *cols<n)
    {
        printf("%d | ", mata[*fila][*cols]);
        *cols+=1;
        mostrar(mata, n, fila, cols);
    }
}
return;
}

void maximo(int mata[TAM][TAM], int n, int *fila, int *cols)
{
static int max;
int aux;
if(*fila==0&&*cols==0) max=0;

if(*cols==n-1 && *fila<n)
{
    aux=mata[*fila][*cols];
    if(max<aux)
        max=aux;

    printf("\nEl maximo de la fila %d es: %d", *cols, max);
    max=0;
    *fila+=1;
    *cols=0;
    maximo(mata, n, fila ,cols);
}
else
{
    if(*fila<n && *cols<n)
    {
        aux=mata[*fila][*cols];
        if(max<aux)
            max=aux;
        *cols+=1;
        maximo(mata, n, fila, cols);
    }
}
return;
}
