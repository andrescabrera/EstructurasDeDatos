/*
********************************************************
Andrés Cabrera - Legajo 53231 - Universidad de Palermo
Guia de Ejercicios de Listas, Colas y Pilas, 2010
********************************************************
Ejercicio nº7: - Practica 2
Dadas dos listas con la estructura del ejercicio nº1,
intercalar los elementos de la segunda lista en la primera respetando el orden.
*/

#include <stdio.h>
#include <stdlib.h>

typedef  struct lista {
    int num;
    struct lista * sig;
} nodo;

void crear(nodo *lista);
void mostrar(nodo *lista);
void insertar(nodo *listaA, int num);
void intercalar(nodo *listaA, nodo *listaB);

int main()
{
    nodo *listaA;
    listaA = (nodo*)malloc(sizeof(nodo));
    crear(listaA);
    printf("\n");
    mostrar(listaA);

    nodo *listaB;
    listaB = (nodo*)malloc(sizeof(nodo));
    crear(listaB);
    printf("\n");
    mostrar(listaB);

    intercalar(listaA, listaB);
    printf("\n");
    mostrar(listaA);

    return 0;
}
void crear(nodo *lista)
{
    printf("\nIngrese un numero: - 1000 para terminar: ");
    scanf("%d", &lista->num);
    if(lista->num == 1000)
        lista->sig = NULL;
    else
    {
        lista->sig = (nodo*)malloc(sizeof(nodo));
        crear(lista->sig);
    }
}

void mostrar(nodo *lista)
{
    if(lista->sig != NULL)
    {
        printf("\nNum: %d", lista->num);
        mostrar(lista->sig);
    }
}

void intercalar(nodo *listaA, nodo *listaB)
{
    nodo *a = listaA;
    nodo *b = listaB;
    while(b->sig)
    {
        insertar(a, b->num);
        if(a->sig->sig)
            a = a->sig->sig;
        b = b->sig;
    }
    a->sig = NULL;
}

void insertar(nodo *listaA, int num)
{
    nodo *nuevo;
    nodo *temp;
    nuevo = (nodo*)malloc(sizeof(nodo));
    nuevo->num = num;
    temp = listaA->sig;
    listaA->sig = nuevo;
    nuevo->sig = temp;
}
