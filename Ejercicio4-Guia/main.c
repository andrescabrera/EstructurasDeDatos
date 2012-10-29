/*
Andrés Cabrera - Leg. 53231
Guia de Ejercicios de Listas, Colas y Pilas, Universidad de Palermo.
Dada la siguiente lista  simplemente enlazada que contiene la siguiente información:

DNI: entero positivo de hasta 8 dígitos.
NOMBRE: cadena de 15 caracteres
TIPO DE CUENTA: carácter (C,E,A)
SALDO: real
SIGUIENTE: puntero al próximo elemento de la lista.

Desarrollar un procedimiento que busque en la lista un nodo cuyo DNI sea igual a uno dado. EL mismo devolverá un puntero al nodo hallado o NULL sino existiera tal nodo.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct cuenta
{
    long int dni;
    char nombre[45];
    char tipo;
    float saldo;
    struct cuenta *sig;
} nodo;

void crear(nodo *lista);
void mostrar(nodo *lista);
nodo *localiza(nodo *lista, long int dni_obj);

int main()
{
    nodo *prin;
    prin = (nodo*)malloc(sizeof(nodo));
    crear(prin);
    mostrar(prin);
    long int dni_obj;
    printf("\n\nIngrese un DNI que este buscando: ");
    scanf("%ld", &dni_obj);

    nodo *marca;
    marca = localiza(prin, dni_obj);

    printf("\nEl DNI buscado");
    if(marca == NULL)
        printf(" NO");
    printf(" fue encontrado");
    printf("\nEl dni encontrado es: %ld, nombre: %s", marca->dni, marca->nombre);
    return 0;
}

void crear(nodo *lista)
{
    printf("\nIngrese un DNI - 0 para finalizar: ");
    scanf("%ld", &lista->dni);
    if(lista->dni == 0)
        lista->sig = NULL;
    else
    {
        printf("\nIngrese nombre: ");
        scanf(" %[^\n]", lista->nombre);
        printf("\nIngrese tipo de cuenta: ");
        scanf(" %c", &lista->tipo);
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
        printf("\n%s, %ld\n\t %f, %c", lista->nombre, lista->dni, lista->saldo, lista->tipo);
        mostrar(lista->sig);
    }
}

nodo *localiza(nodo *lista, long int dni_obj)
{
    if(lista->sig == NULL) //caso base
        return NULL;
    else
        if(lista->dni == dni_obj)
            return lista;
        else
            return localiza(lista->sig, dni_obj); //avanzo
}
