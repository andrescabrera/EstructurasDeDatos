/*
Andrés Cabrera - Estruc. de Datos y Algoritmos - Miercoles Turno Tarde-
1)	Dada la siguiente estructura:

                  Nombre
                 Edad
                Materias Cursadas
               Materias Aprobadas

     Crear y mostrar la lista. Generar un archivo con aquellas personas que tengan un 60% de materias aprobadas.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista
{
    char nombre[20];
    int edad;
    int materias_Aprobadas;
    int materias_Cursadas;
    struct lista *sig;
}nodo;

void crear(nodo *registro);
void mostrar(nodo *registro);
float promedio(int a, int b);
void archivar(FILE *pt, nodo *registro);

int main()
{
    FILE *punfile;
    nodo *prin; //puntero al principio de la lista
    prin=(nodo *)malloc(sizeof(nodo));
    crear(prin);
    printf("\n");
    mostrar(prin);
    printf("\n");
    if((punfile=fopen("c:\\materias.txt","w"))==NULL)
        printf("No se pudo abrir el archivo");
        else
            archivar(punfile, prin);
            fclose(punfile);

    return EXIT_SUCCESS;
}


void crear (nodo *registro)
{
    printf ("Nombre (escribir ""FIN"" para terminar): ");
    scanf ("%s",registro->nombre);
    if (strcmp(registro->nombre,"FIN")==0) //si cambia se convierte en 1
        registro->sig=NULL;
    else
    {
        printf("\nIngrese edad: ");
        scanf("%d", &registro->edad);
        printf("\nIngrese materias aprobadas: ");
        scanf("%d", &registro->materias_Aprobadas);
        printf("\nIngrese materias cursadas: ");
        scanf("%d", &registro->materias_Cursadas);

        registro->sig=(nodo*)malloc(sizeof(nodo));
        crear(registro->sig);
    }

    return;
}

void mostrar (nodo *registro)
{
    if (registro->sig != NULL)
    {
        printf ("Nombre: %s, Edad: %d\n",registro->nombre, registro->edad);
        printf("Materias Aprobadas: %d, Materias Cursadas: %d\n", registro->materias_Aprobadas, registro->materias_Cursadas);
        mostrar (registro->sig);
    }
    return;
}

void archivar(FILE *pt, nodo *registro)
{

            if(registro->sig!=NULL)
            {
                if((promedio(registro->materias_Aprobadas, registro->materias_Cursadas)) >= 60)
                    fprintf(pt,"%s %d %d %d ",registro->nombre, registro->edad, registro->materias_Aprobadas, registro->materias_Cursadas);
                archivar(pt, registro->sig);
            }
}

float promedio(int a, int b)
{
    float prom;
    if(b>0)
    {
        prom=(float)a*100/b;
        return prom;
    }
    else
        return 0;
}
