#include<stdio.h>
#include<stdlib.h>
#include <string.h>



typedef struct lista
{
    char elem [20];
    struct lista *sig;
} nodo;

void crear (nodo *pt);
void mostrar(nodo *pt);

int main()
{
    nodo *prin;
    int op;
    prin=(nodo *)malloc(sizeof(nodo));
    crear(prin);
    mostrar (prin);
    return 0;
}

void crear (nodo *registro)
{
// Ingresar el dato

    if (strcmp (registro->elem,"FIN")==0) //si cambia se convierte en 1
        registro->sig=NULL;
    else
    {


        registro->sig=(nodo*)malloc(sizeof(nodo));
        crear (registro->sig);


    }
    return;
}

void mostrar (nodo *registro)
{
    if (registro->sig !=NULL)
    {
        printf ("%s\n",registro->elem);
        mostrar (registro->sig);
    }
    return;
}
