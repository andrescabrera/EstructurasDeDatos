#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int num;
    struct lista *sig;
}nodo;

void crear(nodo *pt);
void mostrar(nodo *pt);
nodo *eliminar(nodo *primero);

int main()
{
    nodo *prin;

    //creo lista
    prin=(nodo *)malloc(sizeof(nodo));
    crear(prin);
    mostrar(prin);
    //elimino
    prin=eliminar (prin);
    printf("\n");
    mostrar(prin);

    return 0;
}

//CREAR
void crear (nodo *registro)
//El argumento apunta al nodo actual
{
    printf ("Numero: (-2 para terminar): ");
    scanf (" %d", &registro->num);
    if (registro->num == -2)
        registro->sig=NULL;
    else
    {
        registro->sig=(nodo*)malloc(sizeof(nodo));
        crear (registro->sig);
    }
    return;
}

//MOSTRAR
void mostrar (nodo *registro)
{
    if (registro->sig != NULL)
    {
        printf ("%d\n", registro->num);
        mostrar (registro->sig);
    }
    return;
}

//ELIMINAR
nodo *eliminar(nodo *primero)
{
    nodo *aux;
    nodo *temp;

    while (primero->num % 2 != 0) //elimino todos los cabeza de lista.
    {
        temp=primero->sig;
        free(primero);
        primero=temp;
    }
    aux = primero;
    while (aux->sig != NULL)
    {
        if (aux->sig->num % 2 != 0)
        {
            temp=aux->sig->sig;
            free (aux->sig);
            aux->sig=temp;
        }
        else //siempre tener cuidado con esto
            aux = aux->sig;
    }

    return primero;
}
