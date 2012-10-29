#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista
{
    char nombre[20];
    int edad;
    int matcurs;
    int matapp;
    struct nodo *sig; /* puntero a siguiente nodo */
}nodo;

void crear(nodo *pt);
void mostrar(nodo *pt);
void generararchivo(nodo *registro);

int main()
{
    nodo *prin;
    prin=malloc(sizeof(nodo));
    crear((nodo*)prin);
    mostrar(prin);
    generararchivo(prin);
    return EXIT_SUCCESS;
}

void crear(nodo *registro)
{
// Ingreso el nombre y evaluo
    printf("Ingres nombre (FIN para terminar):");
    scanf("%s", registro->nombre);
    if (strcmp (registro->nombre,"FIN")==0) //si cambia se convierte en 1
        registro->sig=NULL;
    else
    {
        //Ingreso todos los datos
        printf("Ingrese Edad: ");
        scanf("%d", &registro->edad);
        printf("Ingrese Materias Cursadas: ");
        scanf("%d", &registro->matcurs);
        printf("Ingrese Materias Aprobadas: ");
        scanf("%d", &registro->matapp);
        //asigno memoria y creo nuevo registro
        registro->sig=malloc(sizeof(nodo));
        crear((nodo*)registro->sig);

    }
    return;
}

void mostrar(nodo *registro)
{
//veo si llegué al final de la lista
    if (registro->sig !=NULL)
    {
        //imprimo nodo
        printf ("Nombre: %s | ",registro->nombre);
        printf("Edad: %d | ", registro->edad);
        printf("Materias Cursadas: %d | ", registro->matcurs);
        printf("Materias Aprobadas: %d\n", registro->matapp);
        //voy al siguiente
        mostrar((nodo*)registro->sig);
    }
    return;
}

void generararchivo(nodo *registro)
{
    FILE *punfile;
    int promedio;
    if ((punfile=fopen("c:lista.txt","w"))==NULL)
        printf("\n No pude abrir el archivo!");
    else
    {
        //veo si llegué al final de la lista
        while (registro->sig !=NULL)
        {
            promedio = (float)((registro->matapp*100)/registro->matcurs);
            if(promedio>60)
                fprintf (punfile, "%s %d %d %d\n", registro->nombre, registro->edad, registro->matcurs, registro->matapp);
            //voy al siguiente
            registro=(nodo*)registro->sig;
        }
        fclose(punfile);
        return;
    }
}
