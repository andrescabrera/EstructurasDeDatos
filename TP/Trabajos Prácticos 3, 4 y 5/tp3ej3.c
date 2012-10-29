/*
Estructura de Datos - Viernes - T. Noche - Andrés Cabrera - Leg. 53231
Ejercicio 3 - Trabajo Práctico 3
3)  Cargar una matriz de n filas y n columnas y calcular y mostrar el elemento máximo de cada fila en forma recursiva.
*/

#include <stdio.h>
#include <stdlib.h>
#define TAM 4

void cargarmat(int mat[][TAM], int n);
void mostrarmat(int mat[][TAM], int n);
void buscarmaxmat(int mat[][TAM], int n, int posi);
int recorrerfila(int mat[][TAM], int n, int posj, int fila, int max);

int main()
{
    int mata[TAM][TAM];

    cargarmat(mata, TAM);
    mostrarmat(mata, TAM);
    buscarmaxmat(mata, TAM, 0);

    return EXIT_SUCCESS;
}

void cargarmat(int mat[][TAM], int n){
    int i, j;

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("Ingrese valor para fila %d columna %d: ", i+1, j+1);
            scanf("%d", &mat[i][j]);
        }
    }
}

void mostrarmat(int mat[][TAM], int n){
    int i, j;

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("| %d ", mat[i][j]);
        }
        printf("\n");
    }
}

//recorro columnas
void buscarmaxmat(int mat[][TAM], int n, int posi){
    if(posi>n-1)
    {
        return;
    }
    else{
        //imprimo el maximo de cada fila
        printf("\nEl maximo de la fila %d es: %d", posi+1, recorrerfila(mat, n, 0, posi, mat[posi][0]));
        buscarmaxmat(mat, n, posi+1);
    }
}

//recorro la fila buscando el maximo
int recorrerfila(int mat[][TAM], int n, int posj, int fila, int max){
    if(posj>n-1){
        return max;
    }
    else
    {
        if(max<mat[fila][posj])
            max=mat[fila][posj];

        return recorrerfila(mat, n, posj+1, fila, max);
    }
}
