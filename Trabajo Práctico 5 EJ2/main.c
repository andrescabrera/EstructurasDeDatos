#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista
{
    int edad;
    char nombre[15];
    float sueldo;
    struct lista *sig;
}nodo;

void levantar(nodo *registro, FILE *punfile);
void mostrar(nodo *registro);

int main()
{
    int edad;
    char nombre[15];
    float sueldo;
    nodo *prin;
    FILE *punfile;

    if ((punfile=fopen("c:\\sueldos.txt","w"))==NULL)
        printf("No se pudo abrir el archivo...");
    else
    {
        printf("Ingrese nombre (""FIN"" para terminar): ");
        scanf("%s", nombre);
        while (strcmp(nombre,"FIN")!=0)
        {
            printf("\nIngrese Edad: ");
            scanf("%d", &edad);
            printf("\nIngrese Sueldo: ");
            scanf("%f", &sueldo);
            fprintf(punfile,"%s %d %.2f\n",nombre, edad, sueldo);
            printf("Ingrese nombre (""FIN"" para terminar): ");
            scanf("%s", nombre);
        }
    }
    fclose(punfile);

    if ((punfile=fopen("c:\\sueldos.txt","r"))==NULL)
        printf("No se pudo abrir el archivo...");
    else
    {
        prin=(nodo *)malloc(sizeof(nodo));
        levantar(prin, punfile);
    }
    mostrar(prin);
    fclose(punfile);

    return EXIT_SUCCESS;
}

void levantar(nodo *registro, FILE *punfile)
{
    char nombre[15];
    int edad;
    float sueldo;

    if (!feof(punfile))
    {
        fscanf(punfile,"%s %d %f\n", nombre, &edad, &sueldo);
        if (edad > 20 && sueldo < 2000)
        {
            strcpy(registro->nombre, nombre);
            registro->edad=edad;
            registro->sueldo=sueldo;
            registro->sig=(nodo*)malloc(sizeof(nodo));
            levantar(registro->sig, punfile);
        }
        else
            levantar(registro, punfile);
    }
    else
        registro->sig=NULL;

    return;
}

void mostrar(nodo *registro)
{
    if (registro->sig != NULL)
    {
        printf ("Nombre: %s ", registro->nombre);
        printf("Edad: %d ", registro->edad);
        printf("Sueldo: %.2f\n", registro->sueldo);
        mostrar(registro->sig);
    }

    return;
}
