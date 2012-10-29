/*
********************************************************
Andrés Cabrera - Legajo 53231 - Universidad de Palermo
Guia de Ejercicios de Listas, Colas y Pilas, 2010
********************************************************
Ejercicio nº5:

Dada la siguiente estructura:

Dni (int)
sig (puntero)
Nombre(char )
saldo(float)

a)	Crear y mostrar la lista.  La carga de datos termina con dni=0. La carga de datos se hace en forma ascendente por dni.
b)	Generar otra lista con todos los saldos negativos.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista
{
    long int dni;
    char nombre[45];
    float saldo;
    struct lista *sig;
} nodo;

void crear(nodo *lista);
void mostrar(nodo *lista);
void crearNegativos(nodo *lista, nodo *negativos);

int main()
{
    nodo *prin;
    prin = (nodo*)malloc(sizeof(nodo)); //la lista de dnis
    crear(prin);
    mostrar(prin);

    nodo *negativos; //la lista de dnis con saldo negativo
    negativos = (nodo*)malloc(sizeof(nodo));
    crearNegativos(prin, negativos);
    mostrar(negativos);
    return 0;
}


void crear(nodo *lista)
{
    printf("\nIngrese un DNI - 0 para terminar: ");
    scanf("%ld", &lista->dni);
    if(lista->dni == 0)
        lista->sig = NULL;
    else
    {
        printf("\nIngrese nombre: ");
        scanf(" %[^\n]", lista->nombre);
        printf("\nIngrese saldo: ");
        scanf("%f", &lista->saldo);
        lista->sig = (nodo*)malloc(sizeof(nodo));
        crear(lista->sig);
    }
}

void mostrar(nodo *lista)
{
    if(lista->sig != NULL)
    {
        printf("\n\nDNI: %ld, Nombre: %s\n\tSaldo: %.2f", lista->dni, lista->nombre, lista->saldo);
        mostrar(lista->sig);
    }
}

void crearNegativos(nodo *lista, nodo *negativos)
{
    nodo *c;
    nodo *q;
    c = lista;
    q = negativos;

    while(c != NULL)
    {
        if(c->saldo < 0)
        {
            q->dni = c->dni;
            q->saldo = c->saldo;
            strcpy(q->nombre, c->nombre);

            q->sig = (nodo*)malloc(sizeof(nodo));
            q = q->sig;
        }
        c = c->sig;
    }
    free(q);
    q = NULL;
}
