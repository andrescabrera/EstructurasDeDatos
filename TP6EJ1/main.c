/*
Trabajo Práctico 6 - Estructura de Datos y Algoritmos - Viernes Turno Noche
Andres Cabrera - Leg. 53231
a) Cargar una lista  con la siguiente estructura:
       Int n1
       Int n2
       Sig : Puntero.

La carga finaliza con n1=n2=0. Mostrarla

b) Agregar un nodo (uno sólo) detrás del primer nodo donde n1-n2 < 0 con los valores n1, n1

c) Agregar detrás de cada nodo cuya diferencia es menor a 0 la cantidad de nodos necesarios hasta llegar a n2, n2:

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int n1;
    int n2;
    struct nodo *sig;
}nodo;

void crear (nodo *pt);
void mostrar(nodo *pt);
void insertar(nodo *pt);
void volverainsertar(nodo *pt);

int main()
{
    nodo *prin;
    prin=malloc(sizeof(nodo));
    crear((nodo*)prin);
    mostrar(prin);
    insertar((nodo*)prin);
    mostrar(prin);
    volverainsertar((nodo*)prin);
    mostrar(prin);

    return EXIT_SUCCESS;
}

void crear(nodo *registro)
{
    // Ingreso datos
    printf("Ingresar n1: ");
    scanf("%d", &registro->n1);
    printf("Ingresar n2: ");
    scanf("%d", &registro->n2);

    if (registro->n1==0&&registro->n2==0)
        registro->sig=NULL;
    else
    {
        registro->sig=malloc(sizeof(nodo));
        crear ((nodo*)registro->sig);
    }
    return;
}

void mostrar(nodo *registro)
{
    if (registro->sig !=NULL)
    {
        printf("%d | ",registro->n1);
        printf("%d\n",registro->n2);
        mostrar(registro->sig);
    }
    printf("\n");
    return;
}

void insertar(nodo *registro)
{
    nodo *nuevoregistro;

    if(registro->sig==NULL)
    {
        printf("\nNo se encuentra en la lista.");
    }
    else
    {
        if((registro->n1-registro->n2)<0)
        {
            nuevoregistro=malloc(sizeof(nodo));
            nuevoregistro->n1=registro->n1;
            nuevoregistro->n2=registro->n1;
            nuevoregistro->sig=registro->sig;
            registro->sig=nuevoregistro;
        }
        else
            insertar((nodo*)registro->sig);
    }
}

void volverainsertar(nodo *registro)
{
    nodo *nuevoregistro;

    if(registro->sig!=NULL)
    {
        if((registro->n1-registro->n2)<0)
        {
            nuevoregistro=malloc(sizeof(nodo));
            nuevoregistro->n1=registro->n1+1;
            nuevoregistro->n2=registro->n2;
            nuevoregistro->sig=registro->sig;
            registro->sig=nuevoregistro;
        }
        volverainsertar((nodo*)registro->sig);
    }
}
