#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo{
    char seccion[20];
    float saldo;
    struct nodo *sig;
}nodo;

void crear(nodo *registro);
void mostrar(nodo *registro);
nodo *localiza (nodo *registro);
nodo *eliminar(nodo *primero);

int main()
{
    nodo *prin;
    prin=malloc(sizeof(nodo));
    crear((nodo*)prin);
    mostrar(prin);
    prin=eliminar((nodo*)prin);
    mostrar(prin);

    return EXIT_SUCCESS;
}

void crear(nodo *registro)
{
    // Ingreso datos
    printf("Ingresar seccion (FIN para terminar): ");
    scanf(" %s", registro->seccion);

    if ((strcmp(registro->seccion, "FIN"))==0)
        registro->sig=NULL;
    else
    {
        //termino de ingresar datos
        printf("Ingresar saldo: ");
        scanf("%f", &registro->saldo);
        //creo nuevo nodo
        registro->sig=malloc(sizeof(nodo));
        crear ((nodo*)registro->sig);
    }
    return;
}

void mostrar(nodo *registro)
{
    if (registro->sig != NULL)
    {
        printf("%s ",registro->seccion);
        printf("%.2f | ", registro->saldo);
        mostrar(registro->sig);
    }
    printf("\n");

    return;
}

//LOCALIZA
{
nodo *localiza (nodo *registro)


}

//ELIMINAR
nodo *eliminar(nodo *primero)
{
nodo *localiza(nodo*);
nodo *marca;
nodo *temp;

if (primero->saldo>20)
{
temp=primero->sig;
free(primero);
primero=temp;
}
else
{
while(primero->sig!=NULL){
    if (registro->sig->saldo>20)

    else
        if (primero->sig->sig!=NULL)
            return	localiza (primero->sig);
        else
            return NULL;
    }
}
return primero;
}
