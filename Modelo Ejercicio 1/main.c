/*
Ejercicio nº1

     Cargar una lista con nombre y sueldo. Mostrarla
1)	Cargar una segunda lista con números enteros repetidos. Mostrarla.
2)	Eliminar de la primera lista las posiciones indicadas por cada nodo de la segunda lista. Mostrarla.

*/
#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    struct lista *sig;
    float sueldo;
    char nom[45];
}nodo;

int main()
{
    nodo *listaA = (nodo*)malloc(sizeof(nodo));

    return 0;
}


