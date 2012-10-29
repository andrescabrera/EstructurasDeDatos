/*

Estructura de Datos - Viernes - T. Noche - Andrés Cabrera - Leg. 53231
Ejercicio 1 - Trabajo Práctico 3
1)	Cargar  vector con  n elementos enteros  y calcular la suma de sus elementos en forma recursiva

*/

#include <stdio.h>
#include <stdlib.h>
#define TAM 10

void cargarvector(int [], int);
void mostrarvec(int [], int);
int sumarvec(int vector[], int n, int suma);

int main(){

int veca[TAM];

cargarvector(veca, TAM);
printf("\n");
mostrarvec(veca, TAM);

printf("\nEl total de la suma de los elementos del vector es: %d", sumarvec(veca, TAM-1, 0));

return EXIT_SUCCESS;
}

//funcion cargarvector
void cargarvector(int vector[], int n){

int i;

for(i=0; i<n; i++){
    printf("Ingrese posición %d del vector: ", n);
    scanf("%d", &vector[i]);
    }
}

//funcion mostrarvec
void mostrarvec(int vector[], int n){
    int i;
    for(i=0; i<n; i++)
        printf("%d | ", vector[i]);
}

//funcion sumar de forma recursiva
int sumarvec(int vector[], int n, int suma){
//si ya sume todas las posiciones retorno la suma
    if(n<0)
        return suma;
//sino sigo sumando y restando posiciones
    else{
        suma = suma + vector[n];
        return sumarvec(vector, n-1, suma);
    }
}
