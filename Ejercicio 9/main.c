/*
********************************************************
Andrés Cabrera - Legajo 53231 - Universidad de Palermo
Guia de Ejercicios de Listas, Colas y Pilas, 2010
********************************************************
Práctica 2 - Ejercicio nº3:

Desarrollar un procedimiento que permita borrar una lista completa.
Este deberá ser lo más rápido posible.
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
void borrarLista(nodo *lista);
int ListaVacia(nodo *lista);

int main()
{
    nodo *lista;
    lista = (nodo*)malloc(sizeof(nodo));
    crear(lista);
    mostrar(lista);
    borrarLista(lista);
    mostrar(lista);
    return 0;
}

void crear(nodo *lista)
{
    printf("\nIngrese un numero: - 1000 para terminar: ");
    scanf("%d", &lista->num);
    if (lista->num == 1000)
    {
        free(lista);
        lista = NULL;
    }
    else
    {
        lista->sig = (nodo*)malloc(sizeof(nodo));
        crear(lista->sig);
    }
}

void mostrar(nodo *lista)
{
    if (ListaVacia(lista)) printf("Lista vacía\n");
    else
    {
        if (lista)
        {
            printf("\nNum: %d", lista->num);
            mostrar(lista->sig);
        }
    }
}

void borrarLista(nodo *lista)
{
    nodo *temp;
    while (lista)
    {
        temp = lista->sig;
        free(lista);
        lista = temp;
    }
}

int ListaVacia(nodo *lista)
{
    return (lista == NULL);
}



/*
//@author cconclase
void BorrarLista(Lista *lista) {
   pNodo nodo;

   while(*lista) {
      nodo = *lista;
      *lista = nodo->siguiente;
      free(nodo);
   }
}
*/
