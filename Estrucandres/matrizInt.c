/*
 * Andrés Cabrera, Ejercicio 1, Cap. 2; Estr. de Datos y Algoritmos. Turno Noche.
 *
 * matrizInt.c
 */
#include <stdio.h>
#include "matrizInt.h"
#include "aleatorio.h"
void mostrarMatrizInt(int A[][COLS], int filas, int cols)
{
	int i, j;
	for (i = 0; i < filas; i++)
	{
		printf("\n");
		for (j = 0; j < cols; j++)
			printf("%d\t", A[i][j]);
	}
	printf("\n");
}
void generarMatrizInt(int A[][COLS], int filas, int cols){
	int i, j;
	for (i = 0; i < filas; i++)
	{
		for (j = 0; j < cols; j++)
			A[i][j] = randInt(VALMIN, VALMAX);
	}
}

void sumarMatrizInt(int A[][COLS], int B[][COLS], int C[][COLS], int filas, int cols){
	int i, j;
	for (i = 0; i < filas; i++)
	{
		for (j = 0; j < cols; j++)
			C[i][j] = A[i][j]+B[i][j];
	}
}

int buscarMenor(int A[][COLS], int filas, int cols, int nmenor)
{
    int i, j, filamenor=0, elemento;
    nmenor=A[0][0];
    for (i = 0; i < filas; i++)
	{
		for (j = 0; j < cols; j++)
		{
		    elemento=A[i][j];
		    if(elemento <= nmenor)
			{
			    nmenor=elemento;
			    filamenor=i;
			}
		}
	}
printf("\nEl menor es: %d\n", nmenor);
return filamenor;
}

void productoMatrices(int A[][COLS], int B[][COLS], int C[][COLS], int n){
int i, j, k;

for(i=0;i<n;i++)
{
    for(j=0;j<n;j++)
    {
    C[i][j]=0;

        for(k=0;k<n;k++)
            C[i][j]=C[i][j]+(A[i][k]*B[k][j]);
    }
}
}

void trasponerMatriz(int A[][COLS], int B[][COLS], int n){
    int i, j;
    for(i=0;i<n;i++)
    {
       for(j=0;j<n;j++)
           B[i][j]=A[j][i];

    }
}

void sumaDiagonalMatriz(int A[][COLS], int n)
{
    int i, suma=0;
    for(i=0;i<n;i++)
        suma+=A[i][i];
printf("La suma de la Diagonal Principal es: %d",suma);
}
