/*
Andr�s Cabrera - Estructura de Datos y Algoritmos - Trabajo Pr�ctico 3 - Ejercicio 1

Cargar  vector con  n elementos enteros  y calcular la suma de sus elementos en forma recursiva
*/
#include <stdio.h>
#include <stdlib.h>

void cargar(int vec[], int cont, int n);
void mostrar(int vec[], int cont, int n);
int suma(int vec[], int n);
int main()
{
    int n;
    int total;
    do
    {
        printf("Ingrese cantidad de elementos del vector: ");
        scanf("%d", &n);
    }
    while (n<=0);
    int vec[n];

    cargar(vec, 0, n);
    mostrar(vec, 0, n);

    total=suma(vec, n-1);
    printf("\nLa suma de los elementos del vector es: %d", total);

    return EXIT_SUCCESS;
}

void cargar(int vec[], int cont, int n)
{
    if (cont<n)
    {
        printf("\nIngrese numero para pos. %d: ", cont);
        scanf("%d", &vec[cont]);
        cargar(vec, cont+1, n);
    }
}

void mostrar(int vec[], int cont, int n)
{
    if (cont<n)
    {
        printf(" %d |", vec[cont]);
        mostrar(vec, cont+1, n);
    }
}

int suma(int vec[], int n)
{
    if (n==0)
        return vec[0];

    return (vec[n] + suma(vec, n-1));
}
