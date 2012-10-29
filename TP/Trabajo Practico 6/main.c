#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int num1;
    int num2;
    struct lista *sig;
}nodo;

void crear (nodo *pt);
void mostrar(nodo *pt);
nodo *insertar(nodo *pt);

int main()
{
    nodo *prin; //apunta al principio de la lista
    prin=(nodo *)malloc(sizeof(nodo));
    crear(prin);
    mostrar(prin);
    printf("\n");
    prin=insertar(prin);
    mostrar(prin);
    return EXIT_SUCCESS;
}

void crear (nodo *registro)
//El argumento apunta al nodo actual
{
    printf ("\nIngresar num1: ");
    scanf (" %d", &registro->num1);
    printf ("Ingresar num2: ");
    scanf (" %d", &registro->num2);
    if ((registro->num1==0)&&(registro->num2==0)) //veo que sean iguales
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
    printf ("%d ",registro->num1);
    printf (", %d | ",registro->num2);

    if (registro->sig !=NULL)
    {
        mostrar (registro->sig);
    }
    return;
}

//INSERTAR
nodo *insertar (nodo*primero)
{
nodo *localizam (nodo*);
nodo *nuevoregistro;
nodo *marca;

	marca=localizam (primero);
	if (marca==NULL)
		printf ("\nNo se encuentra");
	else
		{
		nuevoregistro=(nodo*)malloc(sizeof(nodo));
		nuevoregistro->num1=marca->num1;
		nuevoregistro->num2=marca->num1;
		nuevoregistro->sig=marca->sig;
		marca->sig=nuevoregistro;
		}
return (primero);
}

//localiza
nodo *localizam (nodo *registro)
{
int aux;
aux=registro->num1-registro->num2;
if (aux<0)
	return registro;
else
	if (registro->sig!=NULL)
                     return	localizam (registro->sig);
	else
		return NULL;

}
