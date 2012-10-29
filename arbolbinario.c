#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct arbol
{
	int dato;
	struct arbol *izq;
	struct arbol *der;
} treenode;

void crear (treenode **hoja);
void insertar(treenode **hoja, int elem);
void mostrar (treenode *hoja);

int main ()
{

	printf ("arboles\n");
	treenode* arbol = NULL;

	crear (&arbol);
	printf ("**************\n");
	printf ("mostrar arbol\n");
	printf ("***************\n");

	mostrar (arbol);


	return 0;
}
void crear (treenode **hoja)
{
	int numero;

	printf ("ingrese numero:\t");
	scanf ("%d", &numero);

	while (numero != -1)
	{
		insertar (&(*hoja), numero);
		printf ("ingrese numero:\t");
		scanf ("%d", &numero);
	}
}

void insertar (treenode **hoja, int elem)
{
	//int numero=elem;
     
	if (elem == -1)
		return;

	if (*hoja == NULL)
	{
	//creo la hoja vacia
		(*hoja) = (treenode*) malloc (sizeof (treenode));
		(*hoja) -> dato = elem;
		(*hoja) -> der = NULL;
		(*hoja) -> izq = NULL;
	}
	else
	{
		if (elem >= (*hoja) -> dato)
			{
            //printf("\n %d", elem);
			//printf("\n");
			insertar (&(*hoja) -> der, elem);
            }
		if (elem <(*hoja) -> dato)
		
			insertar (&(*hoja) -> izq, elem);
	}
}

void mostrar (treenode *hoja)
{
	if (hoja != NULL)
	{	
	    mostrar (hoja -> izq);
		printf ("%d ", hoja -> dato);
		mostrar (hoja -> der);
     }
	 }


