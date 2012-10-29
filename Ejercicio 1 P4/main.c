/*
********************************************************
Andrés Cabrera - Legajo 53231 - Universidad de Palermo
Guia de Ejercicios de Listas, Colas y Pilas, 2010
********************************************************
Listas doblemente enlazadas.

Para los siguientes ejercicios crear una lista doblemente enlazada con la siguiente información:
      ANT: puntero al elemento anterior de la lista
      I: real
      SIG: puntero al próximo elemento de la lista.

Ejercicio nº1 - Práctica 4:
Desarrollar un procedimiento que dado un número P, lo agregue a la lista.
(considerar que la lista está ordenada descendentemente).
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    struct lista *ant;
    struct lista *sig;
    float elem;
}nodo;

nodo *insertarPorCabeza(nodo *reg);
void mostrar(nodo *reg);
nodo *insertarNumero(nodo *reg, int num);
nodo *intercambiarNodos(nodo *reg, int n, int m);

int main()
{
    nodo *lista;
    lista = (nodo*)malloc(sizeof(nodo));
    //Crea la lista, ordenada de forma descendente
    lista->ant = NULL;
    lista->sig = NULL;
    printf("\nIngrese numero: ");
    scanf("%f", &lista->elem);
    lista = insertarPorCabeza(lista);
    printf("\n");
    mostrar(lista);
    /*
    //Insertar Numeros
    lista = insertarNumero(lista, 5);
    printf("\n");
    mostrar(lista);
    */
    lista = intercambiarNodos(lista, 1, 5);
    printf("\nIntercambiados n y m: \n");
    mostrar(lista);
    return 0;
}

nodo *insertarPorCabeza(nodo *reg)
{
    float num;
    printf("\nIngrese numero: ");
    scanf("%f", &num);
    if (num != 1000)
    {
        nodo *nuevo;
        nuevo = (nodo*)malloc(sizeof(nodo));
        nuevo->elem = num;
        nuevo->ant = NULL;
        nuevo->sig = reg;
        reg->ant = nuevo;
        nuevo = insertarPorCabeza(nuevo);
        return nuevo;
    }
    else
        return reg;

}

void mostrar (nodo *reg)
{
    if (reg != NULL)
    {
        printf("\nElem: %.2f", reg->elem);
        if(reg->ant) printf(", su anterior es: %.2f", reg->ant->elem);
        else printf(", y no tiene anterior");
        mostrar(reg->sig);
    }
    return;
}

nodo *insertarNumero(nodo *reg, int num)
{
    nodo *nuevo;
    nuevo = (nodo*)malloc(sizeof(nodo));
    nuevo->elem = num;

    if(num > reg->elem)
    {
        nuevo->ant = NULL;
        nuevo->sig = reg;
        reg->ant = nuevo;
        return nuevo;
    }
    else
    {
        nodo *copia = reg;

        while(copia && num < copia->sig->elem)
                copia = copia->sig;

        nodo *temp = copia->sig;
        nuevo->ant = copia;

        copia->sig = nuevo;
        nuevo->sig = temp;
        nuevo->sig->ant = nuevo;

        return reg;
    }
}

nodo *intercambiarNodos(nodo *reg, int n, int m)
{
    //recorrer hasta m
    nodo *cpFin = reg;
    nodo *cpIni = reg;

    int cont = 1;
    while(cpFin->sig != NULL && cont < m)
    {
        cpFin = cpFin->sig;
        cont++;
    }
    if(cpFin->sig == NULL) printf("\nNo existe la posicion");
    else printf("\ncpFin->elem es: %.2f\n", cpFin->elem);


    return reg;
}
