/*
********************************************************
Andrés Cabrera - Legajo 53231 - Universidad de Palermo
Guia de Ejercicios de Listas, Colas y Pilas, 2010
********************************************************
Ejercicio nº4 - Práctica 2:
Desarrollar un procedimiento que dado un número M elimine:

a)	El elemento M-ésimo de la lista.
b)	Todos los elementos menores a M.
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
nodo *eliminar(nodo *lista, int m);
nodo *eliminarMenores(nodo *lista, int m);

int main()
{
    nodo *prin;
    prin = (nodo*)malloc(sizeof(nodo));
    crear(prin);
    mostrar(prin);
    int m;
    printf("Ingrese elemento M: ");
    scanf("%d", &m);
    eliminar(prin, m);
    mostrar(prin);
    prin = eliminarMenores(prin, m);
    mostrar(prin);
    return 0;
}

void crear(nodo *lista)
{
    printf("\nIngrese un numero: - 1000 para terminar: ");
    scanf("%d", &lista->num);
    if (lista->num == 1000)
    {
        lista->sig = NULL;
    }
    else
    {
        lista->sig = (nodo*)malloc(sizeof(nodo));
        crear(lista->sig);
    }
}

void mostrar(nodo *lista)
{
    if (lista->sig != NULL)
    {
        printf("\nNum: %d", lista->num);
        mostrar(lista->sig);
    }
}

nodo *eliminar(nodo *lista, int m)
{
    nodo *temp;
    if (m == 0)
    {
        temp = lista->sig;
        free(lista);
        lista = lista->sig;
    }
    else
    {
        int i = 1;
        nodo *c;
        c = lista->sig;
        //si no, busco la posicion
        while (i < m-1 && c != NULL)
        {
            c = c->sig;
            i++;
        }
        temp = c->sig->sig;
        free(c->sig);
        c->sig = temp;
    }
    return lista;
}

nodo *eliminarMenores(nodo *lista, int m)
{
    nodo *c;
    nodo *temp;
    while (lista->num < m)
    {
        temp = lista->sig;
        free(lista);
        lista = temp;
        lista=lista->sig;
    }
    c = lista;
    while (c->sig != NULL)
    {
        if (c->sig->num < m)
        {
            temp = c->sig->sig;
            free(c->sig);
            c->sig = temp;
        }
        c = c->sig;
    }
    return lista;
}
