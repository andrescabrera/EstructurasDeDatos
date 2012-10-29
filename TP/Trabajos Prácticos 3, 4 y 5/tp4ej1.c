/*
Estructura de Datos - Viernes Turno Noche - Andrés Cabrera - Legajo 53231
Trabajo Práctico 4 - Ejercicio 1
1)  Cargar una matriz de n filas y n columnas en forma recursiva. Generar un archivo con aquellos números múltiplos de 3 y de 7. Mostrar dicho archivo.
*/

#include <stdio.h>
#include <stdlib.h>
#define TAM 4

void cargarmat(int mat[][TAM], int n, int i, int j);
void mostrarmat(int mat[][TAM], int n, int i, int j);
void generararchivo(int mat[][TAM], int n);

int main()
{
    int mata[TAM][TAM];

    cargarmat(mata, TAM, 0, 0);
    mostrarmat(mata, TAM, 0, 0);
    generararchivo(mata, TAM);

    return EXIT_SUCCESS;
}

//funcion cargar matriz en forma recursiva
void cargarmat(int mat[][TAM], int n, int i, int j){
//evaluo si llegue al n-esimo elemento de la matriz
    if(i<n)
    {
        printf("Ingrese valor para fila %d col %d: ", i+1, j+1);
        scanf("%d", &mat[i][j]);

    //si llegue a la ultima columna, cambio de fila, sino continuo en la sig columna
        if(j==n-1)
            cargarmat(mat, n, i+1, 0);
        else
            cargarmat(mat, n, i, j+1);
    }
}

//funcion mostrar matriz en forma recursiva
void mostrarmat(int mat[][TAM], int n, int i, int j){
//evaluo si llegue al n-esimo elemento de la matriz
    if(i<n)
    {
        printf(" %d |", mat[i][j]);

    //si llegue a la ultima columna, cambio de fila, sino continuo en la sig columna
        if(j==n-1){

            printf("\n");
            mostrarmat(mat, n, i+1, 0);
        }
        else
            mostrarmat(mat, n, i, j+1);
    }
}

void generararchivo(int mat[][TAM], int n){

FILE *punfile;
int i, j;

if ((punfile=fopen("c:matriz.txt","w"))==NULL)
	printf("\n No pude abrir el archivo!");
	else
	{
	for(i=0;i<n;i++)
	{
        for(j=0;j<n;j++)
        {
            if(mat[i][j]%3==0 || mat[i][j]%7==0)
                fprintf(punfile, "%d | ", mat[i][j]);
            else
                fprintf(punfile, "   | ");
        }
        fprintf(punfile, "\n");
	}
    }

fclose(punfile);

}

