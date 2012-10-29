/*

Estructura de Datos - Viernes - T. Noche - Andrés Cabrera - Leg. 53231
Ejercicio 4 - Trabajo Práctico 3

4)  Cargar una matriz de n filas y n columnas y calcular y mostrar el producto de los elementos de la diagonal principal  en forma recursiva.

*/

#include <stdio.h>
#include <stdlib.h>
#define TAM 4

void cargarmat(int mat[][TAM], int n);
void mostrarmat(int mat[][TAM], int n);
int recorrermat(int mat[][TAM], int n, int i);


int main()
{
    int mata[TAM][TAM];

    cargarmat(mata, TAM);
    mostrarmat(mata, TAM);
    printf("El producto de los elementos de la diag prin es: %d: ", recorrermat(mata, TAM, 0));

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

//recorro matriz de forma recursiva
int recorrermat(int mat[][TAM], int n, int i){

    //evaluo si llegue al n-esimo elemento de la matriz
    if(i == n)
        return mat[i][i];
    else
    //sino llegué multiplico por el siguiente
        return recorrermat(mat, n, i+1) * mat[i][i];
}
