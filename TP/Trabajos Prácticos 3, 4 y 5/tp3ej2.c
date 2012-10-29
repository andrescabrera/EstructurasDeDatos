/*

Estructura de Datos - Viernes - T. Noche - Andrés Cabrera - Leg. 53231
Ejercicio 2 - Trabajo Práctico 3
2)	Cargar  vector con  n elementos enteros  y calcular el promedio  de sus elementos en forma recursiva

*/

#include <stdio.h>
#include <stdlib.h>
#define TAM 10

void cargarvector(int [], int);
void mostrarvec(int [], int);
void calcularprom(int [], int, int, int);

int main(){

int veca[TAM];

cargarvector(veca, TAM);
printf("\n");
mostrarvec(veca, TAM);
printf("\n");
calcularprom(veca, TAM, 0, 0);

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
    for(i=0; i<n; i++){

        printf("%d | ", vector[i]);

    }
}

//funcion calcular promedio de forma recursiva
void calcularprom(int vector[], int n, int suma, int pos)
{
    //si llegue al final calculo el promedio
    if(pos > n-1){
        float prom =(float)suma / n;
        printf("\nEl promedio de la suma de los elementos del vector es %.2f", prom);
    }

    //sino sumo y vuelvo a llamar
    else{
        suma = suma + vector[pos];
        pos++;

        calcularprom(vector, n, suma, pos);
    }
}
