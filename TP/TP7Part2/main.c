/*
------------------------------
Estructura de Datos y Algoritmos
Viernes - Turno Noche

Andrés Cabrera - Legajo 53231
Trabajo Práctico 7 Ejericio 2
------------------------------

Dada la siguiente estructura:


          typedef  struct lista {
                                            int num;
                                            struct lista * sig;
                                          } nodo;


        a) Cargar una lista con números ordenados de menor a mayor y con dos consecutivos cada tanto. La carga termina con número = 1000.
        b) Agregar el tercero consecutivo.
        d) De dos consecutivos, eliminar el segundo.

*/

#include <stdio.h>
#include <stdlib.h>


typedef  struct nodo
{
    int num;
    struct nodo * sig;
} nodo;

void mostrar(nodo *registro);
void crear(nodo *registro);
void insertartercero(nodo *registro);
nodo *eliminarprimero(nodo *primero);
void eliminarsegundo(nodo *primero);

int main()
{
    nodo *punt;

    punt=malloc(sizeof(nodo));
    crear((nodo*)punt);
    mostrar(punt);
    printf("\n");
    //insertartercero(punt);
    //punt = eliminarprimero(punt);
    eliminarsegundo(punt);
    mostrar(punt);

    return EXIT_SUCCESS;
}

//Funcion crear lista
void crear(nodo *registro)
{
    // Ingreso datos
    printf("Ingresar numero: ");
    scanf("%d", &registro->num);

    if (registro->num == 1000)
        registro->sig=NULL;
    else
    {
        //creo nuevo nodo
        registro->sig=malloc(sizeof(nodo));
        crear ((nodo*)registro->sig);
    }

    return;
}

void mostrar(nodo *registro)
{
    if (registro->sig!=NULL)
    {
        printf("%d | ", registro->num);
        mostrar(registro->sig);
    }

    return;
}

//Funcion para insertar el tercero consecutivo
void insertartercero(nodo *registro)
{
    nodo *actual;
    nodo *nuevo;
    nodo *anterior;

    anterior = registro->sig;
    actual = anterior->sig;

    while (actual->sig != NULL)
    {

        if ((anterior->num+1) == actual -> num)
        {
            //creo nuevo nodo
            nuevo = malloc(sizeof(nodo));
            nuevo->num = (actual->num+1);
            //adelanto nodo
            anterior = actual;
            actual = anterior->sig;
            //inserto el nodo
            anterior->sig = nuevo;
            nuevo->sig = actual;
        }
        else
        {
            anterior = actual;
            actual = anterior->sig;
        }

    }
}

//Funcion para eliminar el primero consecutivo
nodo* eliminarprimero(nodo *primero)
{
    nodo *actual;
    nodo *anterior;
    nodo *punTemp;
    //elimino el primer nodo
    if ((primero->num+1) == primero->sig->num)
    {
        punTemp=primero->sig;
        free(primero);
        primero=punTemp;
    }

    anterior = primero;
    actual = anterior->sig;

    while (actual->sig != NULL)
    {

        if ((anterior->sig->num+1) == actual->sig->num)
        {
            //elimino el nodo
            punTemp = actual;
            anterior->sig = actual->sig;
            free(punTemp);
        }
        else
        {
            anterior = actual;
            actual = anterior->sig;
        }
    }

    return primero;
}

//Funcion para eliminar el segundo consecutivo
void eliminarsegundo(nodo *primero)
{
    nodo *actual;
    nodo *anterior;
    nodo *punTemp;

    anterior = primero->sig;
    actual = anterior->sig;

    while (actual->sig != NULL)
    {

        if ((anterior->num+1) == actual->num)
        {
            //elimino el nodo
            punTemp = actual;
            anterior->sig = actual->sig;
            free(punTemp);
        }
        else
        {
            anterior = actual;
            actual = anterior->sig;
        }
    }
}
