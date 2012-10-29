/*
Andrés Cabrera - Trabajo Práctico 4 - Archivos - Ejercicio 2
Generar un archivo con el block de notas con nombre y edad (por lo menos que contenga 4 registros).
Escribir el código en C para leer y mostrar dicho archivo.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 6

// int contar(FILE *punfile);
void mostrar(char nombres[][], int edades[], int n);
void leer(FILE *punfile, int edades[], char nombres[][]);

int main()
{
    FILE *punfile;
    int n=6;
    //n=contar(punfile);

    char nombres[n][20];
    int edades[n];

    leer(punfile, edades, nombres);
    mostrar(nombres, edades, n);

    return EXIT_SUCCESS;
}

/*
int contar(FILE *punfile)
{
    int cont=0;
    if ((punfile=fopen("c:\\nombredad.txt","r"))==NULL)
        printf("No se pudo abrir el archivo...");
    else
    {
        while( !feof(punfile) ) //no funciona...¿?
        {
            cont++;
        }
    }
    fclose(punfile);

    return cont;
}
*/

void leer(FILE *punfile, int edades[], char nombres[][20])
{
    int i=0;
    if ((punfile=fopen("c:\\nombredad.txt","r"))==NULL)
        printf("No se pudo abrir el archivo...");
    else
    {
        while (!feof(punfile))
        {
            fscanf(punfile,"%s %d\n", nombres[i], &edades[i]);
            i++;
        }
    }

    fclose(punfile);

    return;
}

void mostrar(char nombres[][20], int edades[], int n)
{
    int i;
    printf("\n");
    for (i=0;i<n;i++)
        printf("nombre: %s, edad: %d\n", nombres[i], edades[i]);

    return;
}

