#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <conio.h>


typedef struct lista
{
    char elem [20];
    struct lista *sig;
}nodo;

void crear (nodo *pt);
nodo *insertar(nodo *pt);
nodo *eliminar(nodo *pt);
void mostrar(nodo *pt);


void main()
{
    clrscr();
    nodo *prin;//puntero al principio de la lista
    int op;
    prin=(nodo *)malloc(sizeof(nodo));
    crear(prin);
    mostrar (prin);
    prin=insertar(prin);
    mostrar(prin);
    prin=eliminar (prin);
    mostrar(prin);
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

//INSERTAR
nodo *insertar (nodo*primero)
{
    nodo *localiza (nodo*,char[]);
    nodo *nuevoregistro;
    nodo *marca;//puntero al nodo anterior
    char nuevodato [20];
    char objetivo [20];
    printf ("\nNuevo dato:");
    scanf (" %[^\n]",nuevodato);
    printf ("Colocar adelante de (escribir FIN si es el ultimo):");
    scanf (" %[^\n]",objetivo);
    if (strcmp (primero->elem,objetivo)==0)
    {
        //es el primero de la lista
        nuevoregistro=(nodo*)malloc(sizeof(nodo));
        strcpy (nuevoregistro->elem,nuevodato);
        nuevoregistro->sig=primero;
        primero=nuevoregistro;
    }
    else //localiza el nodo precedente
    {
        marca=localiza (primero,objetivo);
        if (marca==NULL)
            printf ("\nNo se encuentra");
        else
        {
            nuevoregistro=(nodo*)malloc(sizeof(nodo));
            strcpy (nuevoregistro->elem,nuevodato);
            nuevoregistro->sig=marca->sig;
            marca->sig=nuevoregistro;
        }
    }
    return (primero);
}

//LOCALIZA
nodo *localiza (nodo *registro,char objetivo[])
//regresa el puntero al nodo anterior al objetivo
{
    if (strcmp(registro->sig->elem,objetivo)==0)
        return registro;
    else
        if (registro->sig->sig!=NULL)
            return	localiza (registro->sig,objetivo);
        else
            return NULL;

}

ELIMINAR
nodo *eliminar(nodo *primero)
{
    nodo *localiza(nodo*, char[]);
    nodo *marca;
    nodo *temp;
    char  objetivo  [20];
    printf ("dato a borrar");
    scanf (" %[^\n]",objetivo);
    if (strcmp(primero->elem, objetivo)==0)
    {
        temp=primero->sig;
        free(primero);
        primero=temp;
    }
    else
    {
        marca=localiza(primero,objetivo);
        if (marca==NULL)
            printf("no se encuentra");
        else
        {
            temp=marca->sig->sig;
            free (marca->sig);
            marca->sig=temp;
        }
    }
    return primero;
}
