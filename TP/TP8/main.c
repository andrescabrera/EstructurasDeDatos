#include <stdio.h>
#include <stdlib.h>

typedef struct Barrio{
    char nombarrio[30];
    struct Inmuebles *BaInm;
    struct Barrio *SigBar;
}nodo;

typedef struct Inmuebles{
    char dir[40];
    int sup;
    int cantamb;
    float precio;
    struct Inmuebles *siglnm;
}mnodo;

int main()
{
    *bprin;
    bprin = malloc(sizeof(nodo*));

    *iprin;
    iprin = malloc(sizeof(mnodo*));

    crear(bprin);
    mostrar(bprin);

    return 0;
}

//CREAR
void crear (nodo *registro)
//El argumento apunta al nodo actual
{
printf("Ingresando nueva propiedad...\n");
printf ("Ingrese nombre del barrio (escribir ""FIN"" para terminar): ");
scanf (" %[^\n]",registro->nombarrio);
if (strcmp (registro->nombarrio,"FIN")==0) //si cambia se convierte en 1
	registro->sig=NULL;
else
	{
    registro->
	registro->sig=(nodo*)malloc(sizeof(nodo));
	crear (registro->sig);
	}
	return;
}
