/*
Estructura de Datos - Viernes Turno Noche
Trabajo Práctico 4 - Ejercicio 2
Andrés Cabrera - Legajo 53231
2) Generar un archivo con el block de notas con nombre y edad (por lo menos que contenga 4 registros). Escribir el código en C para leer y mostrar dicho archivo

*/

#include <stdio.h>
#include <stdlib.h>

void leerarchivo();

int main()
{
    leerarchivo();

    return EXIT_SUCCESS;
}

void leerarchivo(){
FILE *punfile;

char nombre[15];
int edad;

if((punfile=fopen("c:registros.dat","r"))==NULL)
    printf("Error: No pude abrir el archivo!");
    else{
        while(!feof(punfile)){
            fscanf(punfile, "%s %d", nombre, &edad);
            printf("Nombre: %s, Edad: %d\n", nombre, edad);
        }
    }
fclose(punfile);
}
