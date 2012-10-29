/*
********************************************************
Andrés Cabrera - Legajo 53231 - Universidad de Palermo
Guia de Ejercicios de Listas, Colas y Pilas, 2010
********************************************************
Práctica 2 - Ejercicio nº2:

Dada la estructura del ejercicio anterior,
desarrollar un procedimiento que, dados dos valores P y Q,
elimine todos los elementos de la lista desde P hasta Q inclusive.
Antes posibles errores emitir mensajes aclaratorios.
Nota: P y Q son valores, no punteros.

*/
#include <stdio.h>
#include <stdlib.h>

typedef  struct lista
{
    int num;
    struct lista * sig;
} nodo;

void crear(nodo *lista);
void mostrar(nodo *lista);
void eliminar(nodo *lista, int inicio, int fin);

int main()
{
    nodo *lista;
    int inicio, fin;
    lista = (nodo*)malloc(sizeof(nodo));
    crear(lista);
    mostrar(lista);
    printf("\nIngrese desde donde quiere borrar: ");
    scanf("%d", &inicio);
    printf("\nIngrese hasta donde quiere borrar, inclusive: ");
    scanf("%d", &fin);
    eliminar(lista, inicio, fin);
    mostrar(lista);
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

void eliminar(nodo *lista, int inicio, int fin)
{
    nodo *c;
    nodo *temp;
    c = lista;

    while(c != NULL && c->num != inicio)
        c = c->sig;
    if(c != NULL)
    {
        nodo *in;
        in = c;
        c = c->sig;
        while(c != NULL && c->num != fin)
        {
            //TODO elimino normal
            temp = c->sig;
            free(c);
            c = temp;
        }
        if(c != NULL)
        {
            temp = c->sig;
            free(c);
            c = temp;
        }
        else
            printf("El numero %d no existe, se borro hasta el final", fin);
        in->sig = c;
    }
    else
        printf("No existe el numero %d", inicio);
}
