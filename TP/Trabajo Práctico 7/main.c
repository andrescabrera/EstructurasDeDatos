#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista
{
    char seccion[10];
    float saldo;
    struct lista *sig;
}nodo;

void mostrar(nodo *);
void crear(nodo *);
nodo *eliminar(nodo *);

int main()
{
    nodo *prin;
    prin=(nodo *)malloc(sizeof(nodo));
    crear(prin);
    printf("\n");
    mostrar (prin);
    prin=eliminar(prin);
    printf("\n");
    mostrar(prin);

    return 0;
}

void mostrar (nodo *registro)
{
    if (registro->sig !=NULL)
    {
        printf ("s\n", registro->seccion);
        printf(".2f", &registro->saldo);
        mostrar (registro->sig);
    }
    return;
}

void crear (nodo *registro)
{
    printf ("Ingrese sección (escribir ""FIN"" para terminar): ");
    scanf (" %[^\n]", registro->seccion);
    if (strcmp (registro->elem,"FIN")==0) //si cambia se convierte en 1
        registro->sig=NULL;
    else
    {
        printf("Ingrese saldo: ");
        scanf("%f", &registro->saldo);
        registro->sig=(nodo*)malloc(sizeof(nodo));
        crear (registro->sig);
    }
    return;
}


//ELIMINAR
nodo *eliminar(nodo *primero)
{
    nodo *temp;
    nodo *elimina;
    void borra(*nodo);
    if (primero != NULL)
    {
        if (primero->saldo > 20)
        {
            temp=primero->sig;
            free(primero);
            primero=temp;
        }

        temp=primero;
        borra(temp);
    }
    else
        printf("No está cargada la lista");

    return primero;
}

void borra(*registro)
{
    if (registro->sig != NULL)
    {
        if (registro->sig->saldo > 20)
        {
            temp=registro->sig;
            free(registro);
            registro=temp;
        }
        borra(registro->sig);
    }
    return;
}
