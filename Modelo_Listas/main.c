#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct lista
{
    char elem[20];
    struct lista *sig;
}nodo;
int menu();
void crear (nodo *pt);       //prototipo crear lista
nodo *insertar(nodo *pt);   //prototipo insertar un nodo de una lista
nodo *eliminar(nodo *pt);  //prototipo eliminar un nodo de una lista

void mostrar(nodo *pt);    //prototipo mostra una lista
//PROGRAMA PRINCIPAL
int main()
{

    nodo *prin;//puntero al principio de la lista
    int op;

    do
    {
        op=menu();
        switch (op)
        {
        case 1:
            prin=(nodo *)malloc(sizeof(nodo));
            crear(prin);
            printf("\n");
            mostrar (prin);
            continue;
        case 2:
            prin=insertar(prin);
            printf("\n");
            mostrar(prin);
            continue;
        case 3:
            prin=eliminar (prin);
            printf("\n");
            mostrar(prin);
            continue;
        case 4:
            printf("\nfin de proceso");
        }

    }
    while (op !=4);
    return EXIT_SUCCESS;
}
//MENU PRINCIPAL
int menu (void)
{
    int op;
    do
    {
        printf ("\nMENU PRINCIPAL\n--------------\n");
        printf ("\n1-Crear LISTA");
        printf ("\n2-Agregar un ELEMENTO");
        printf ("\n3-Eliminar un ELEMENTO");
        printf ("\n4-FIN\n");
        printf ("\nSeleccione una opcion: ");

        scanf ("%d",&op);
        if (op<1 || op>4)
            printf("\nERROR: Intente otra vez");

    }
    while (op<1 || op>4);
    printf ("\n");
    return (op);
}
//CREAR
void crear (nodo *registro)
//El argumento apunta al nodo actual
{
    printf ("Dato (escribir ""FIN"" para terminar): ");
    scanf (" %[^\n]",registro->elem);
    if (strcmp (registro->elem,"FIN")==0) //si cambia se convierte en 1
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
    nodo *localiza (nodo*, char[]); //define la funcion localiza dentro de insertar.......... Lindo.
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

//ELIMINAR
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
