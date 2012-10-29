/*
********************************************************
Andrés Cabrera - Legajo 53231 - Universidad de Palermo
Guia de Ejercicios de Listas, Colas y Pilas, 2010
********************************************************
Práctica 2 - Ejercicio nº5:
Desarrollar un procedimiento para invertir una lista lineal, es decir, cambiar sus enlaces para que aparezcan en orden inverso.
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
void cambiar(nodo *lista);
void invertir(nodo *lista);

int main()
{
    nodo *lista;
    lista = (nodo*)malloc(sizeof(nodo));
    crear(lista);
    mostrar(lista);
    //cambiar(lista);
    //printf("Lista Intercambiada\n");
    //mostrar(lista);
    invertir(lista);
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

void cambiar(nodo *lista)
{
    int i = 0;
    nodo *q = lista; //posicion 1 en la lista
    nodo *c = q;
    while(i < 3) //encuentro la posicion 5
    {
        c = c->sig;
        i++;
    }

    //intercambio c y q
    nodo *temp;
    temp = q->sig;
    q->sig = c->sig;
    c->sig = temp;
    temp = q->sig->sig;
    q->sig->sig = c->sig->sig;
    c->sig->sig = temp;
}

void invertir(nodo *lista)
{
    nodo *pini = (nodo*)malloc(sizeof(nodo));
    pini->sig = lista;
    nodo *pfin = lista;
    int tamlista = 0;
    int i;
    //TODO recorrer la lista
    while(pfin->sig->sig)
    {
        tamlista++;
        pfin = pfin->sig;
    }
/*
    //INTERCAMBIO PRIMERO Y ULTIMO
    printf("\nIntercambio %d con %d", pini->sig->num, pfin->num);
    nodo *temp;
    temp = pini->sig;
    pini->sig = pfin->sig;
    pfin->sig = temp;
    temp = pini->sig->sig;
    pini->sig->sig = pfin->sig->sig;
    pfin->sig->sig = temp;

    printf("pini->num: %d", pini->num);
    //END INTERCAMBIO
     */
    nodo *aux = pini;
    printf("aux->num: %d", aux->num);
    int mitad = tamlista / 2;

    while(tamlista-1 > mitad)
    {
        printf("ok");
        pfin = lista;
        for(i = 0; i < tamlista-2; i++)
        {
            pfin = pfin->sig;
        }
        tamlista--;
        //intercambiarla
        //printf("\nIntercambio %d con %d", pini->num, pfin->num);
        nodo *temp;
        temp = pini->sig;
        pini->sig = pfin->sig;
        pfin->sig = temp;
        temp = pini->sig->sig;
        pini->sig->sig = pfin->sig->sig;
        pfin->sig->sig = temp;

        pini = pini->sig;
    }
}
