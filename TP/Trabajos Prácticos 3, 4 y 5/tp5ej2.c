/*
Estructura de Datos y Algoritmos - Viernes Turno Noche
Trabajo Práctico 5, Ejercicio 2 - Andres Cabrera - Legajo 53231
2)	Generar una archivo con los siguientes campos:

Nombre, edad y sueldo

Luego crear una lista con aquellas personas cuya edad supera los 20 años y el sueldo es inferior a $2000. Mostrarla
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista
{
    char nombre[20];
    int edad;
    float sueldo;
    struct nodo *sig;
}nodo;

void generararchivo(FILE *punfile);
void leerarchivo(nodo *registro, FILE *punfile);
void mostrar(nodo *registro);

int main()
{
    FILE *punfile;

    generararchivo(punfile);


    nodo *prin;
    prin=malloc(sizeof(nodo));

    leerarchivo((nodo*)prin, punfile);

    mostrar(prin);

    return EXIT_SUCCESS;
}

//funcion para crear estructura desde el archivo
void leerarchivo(nodo *registro, FILE *punfile)
{
    if ((punfile=fopen("c:estructura.dat","r"))==NULL)
	printf("\n Error: No pude abrir el archivo!");
	else
	{
	    char nombre[20];
        int edad;
        float sueldo;
        while (!feof(punfile))
        {
            //leo el archivo
            fscanf(punfile, "%s %d %f", nombre, &edad, &sueldo);

            if(edad>20 && sueldo < 2000)
            {
                strcpy(registro->nombre, nombre);
                registro->edad=edad;
                registro->sueldo=sueldo;
                if(!feof(punfile)) //feo. ¿? para que no se repita el ultimo.
                {
                    registro->sig=malloc(sizeof(nodo));
                    registro=(nodo*)registro->sig;
                }
            }
        }
        //FEOF entonces llegue a lo ultimo que debía cargar
        registro->sig=NULL;
        fclose(punfile);
	}
}

//funcion para mostrar estructura
void mostrar(nodo *registro)
{
//veo si llegué al final de la lista
    if (registro->sig !=NULL)
    {
        //imprimo nodo
        printf ("Nombre: %s | ",registro->nombre);
        printf("Edad: %d | ", registro->edad);
        printf("Sueldo: %.2f\n", registro->sueldo);
        //voy al siguiente
        mostrar((nodo*)registro->sig);
    }
    return;
}


//Funcion para cargar el archivo con datos
void generararchivo(FILE *punfile){

char nombre[20];
int edad;
float sueldo;

if((punfile=fopen("c:estructura.dat", "w"))==NULL)
    printf("Error: No se pudo abrir el archivo!");
    else
    {
        //ingreso el primero nombre, fuera del bucle
        printf("Ingrese nombre (FIN para terminar): ");
        scanf("%s", nombre);
        //mientras nombre no sea fin continuo generando archivo
        while(strcmp(nombre,"FIN")!=0)
        {
        printf("\nIngrese edad: ");
        scanf("%d", &edad);
        printf("\nIngrese sueldo: ");
        scanf("%f", &sueldo);
        fprintf(punfile, "%s %d %.2f\n", nombre, edad, sueldo);
        printf("\nIngrese nombre (FIN para terminar): ");
        scanf("%s", nombre);
        }

    fclose(punfile);
    }
}
