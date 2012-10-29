/*

Dada la siguiente estructura:


          typedef  struct lista {
                                            int num;
                                            struct lista * sig;
                                          } nodo;


        a) Cargar una lista con números ordenados de menor a mayor y con dos consecutivos cada tanto. La carga termina con número = 1000.
        b) Agregar el tercero consecutivo.
        c) De dos consecutivos, eliminar el primero.
        d) De dos consecutivos, eliminar el segundo.

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int num;
    struct lista *sig;
}nodo;

int main()
{


    return EXIT_SUCCESS;
}

void cargar(nodo *registro)
{
    printf("\nIngresar numero (1000 para terminar): ");
    scanf("%d", &registro->num);
    if(registro->num==1000)
        registro->sig=NULL;
    else
    {
        registro->sig=malloc(sizeof(nodo));
        cargar((nodo*)registro->sig);
    }
    return;
}

void insertar(nodo *prin, ant)
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


