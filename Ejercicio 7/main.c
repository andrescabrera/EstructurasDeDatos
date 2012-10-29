/*
********************************************************
Andrés Cabrera - Legajo 53231 - Universidad de Palermo
Guia de Ejercicios de Listas, Colas y Pilas, 2010
********************************************************
Práctica 2 - Ejercicio nº1:
Dada la siguiente estructura:

typedef  struct lista {
    int num;
    struct lista * sig;
} nodo;

a) Cargar una lista con números ordenados de menor a mayor y con dos consecutivos cada tanto. La carga termina con número = 1000.
b) Agregar el tercero consecutivo.
c) De dos consecutivos, eliminar el primero.
d) De dos consecutivos, eliminar el segundo.
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
void terceroConsecutivo(nodo *lista);
nodo *eliminarPrimerConsecutivo(nodo *lista);
void eliminarSegundoConsecutivo(nodo *lista);

int main()
{
    nodo *lista;
    lista = (nodo*)malloc(sizeof(nodo));
    crear(lista);
    mostrar(lista);
    terceroConsecutivo(lista);
    printf("\nAgregando en tercer consecutivo\n");
    mostrar(lista);
    //lista = eliminarPrimerConsecutivo(lista);
    //mostrar(lista);
    //eliminarSegundoConsecutivo(lista);
    //mostrar(lista);
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

void terceroConsecutivo(nodo *lista)
{
    nodo *c;
    c = lista;
    int ant = c->num;
    while(c != NULL)
    {
        if(ant == (c->num) - 1)
        {
            //agrego el tercero consecutivo
            nodo *nuevo;
            nuevo = (nodo*)malloc(sizeof(nodo));
            nuevo->num = (c->num) + 1;
            nuevo->sig = c->sig;
            c->sig = nuevo;
            c = c->sig->sig;
        }
        ant = c->num; //antes de avanzar, actualizo el anterior
        c = c->sig;
    }
}

nodo *eliminarPrimerConsecutivo(nodo *lista)
{
    nodo *c;
    nodo *temp;
    if(lista->num == (lista->sig->num)-1)
    {
        temp = lista->sig;
        free(lista);
        lista = temp;
    }
    c = lista;
    while(c->sig->sig != NULL)
    {
        if(c->sig->num == (c->sig->sig->num) - 1)
        {
            temp = c->sig->sig;
            free(c->sig);
            c->sig = temp;
        }
        c = c->sig;
    }
    return lista;
}

void eliminarSegundoConsecutivo(nodo *lista)
{
    nodo *c;
    nodo *temp;
    c = lista;
    while(c->sig != NULL)
    {
        if(c->num == (c->sig->num)-1)
        {
            //TODO elimino el segundo consecutivo
            temp = c->sig->sig;
            free(c->sig);
            c->sig = temp;
        }
        c = c->sig;
    }
}

