/*
Andrés Cabrera - Estructura de Datos y Algoritmos - Trabajo Práctico 3 - Ejercicio 2

Cargar  vector con  n elementos enteros  y calcular el promedio  de sus elementos en forma recursiva
*/
#include <stdio.h>
#include <stdlib.h>

void cargar(int vec[], int n, int cont);
void mostrar(int vec[], int n, int cont);
void promedio(int vec[], int n, int *suma, int *cont);

int main()
{
    int n;
    do
    {
        printf("Ingrese tamano del vector: ");
        scanf("%d", &n);
    }
    while (n<=0);

    int vec[n];

    cargar(vec, n, 0);
    mostrar(vec, n, 0);
    int suma=0, cont=0;
    promedio(vec, n, &suma, &cont);

return EXIT_SUCCESS;
}

void mostrar(int vec[], int n, int cont)
{
    if (cont<n)
    {
        printf(" %d |", vec[cont]);
        mostrar(vec, n, cont+1);
    }
}

void cargar(int vec[], int n, int cont)
{
    if (cont<n)
    {
        printf("\nIngrese posicion %d: ", cont);
        scanf("%d", &vec[cont]);
        cargar(vec, n, cont+1);
    }
}

void promedio(int vec[], int n, int *suma, int *cont)
{
    if (*cont == n)
    {
        float prom = (float) *suma / ((*cont));
        printf("\n Promedio: %.2f", prom);
    }
    else
    {
        *suma = *suma + vec[(*cont)];
        *cont+=1;
        printf("\n cont vale: %d, suma vale %d", *cont, *suma);
        promedio(vec, n, suma, cont);
    }
return;
}

