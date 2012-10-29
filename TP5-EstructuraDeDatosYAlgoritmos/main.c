/*1) Dada la siguiente estructura:       Oskarina González, legajo: 65762. Curso Viernes Noche.
Nombre y Apellido
Nro Legajo
Materias Cursadas
Materias Aprobadas
Crear y mostrar la lista. Generar un archivo con aquellas personas que tengan un 40% de materias aprobadas.*/


#include<stdio.h>
#include<stdlib.h>
#include <string.h>



typedef struct alumno{
	char nombre [8];
	char apellido [10];
	int legajo;
	int materiasCursadas;
	int materiasAprobadas;

	struct alumno *sig;
	 }nodo;

void crear (nodo *pt);
void mostrar(nodo *pt);

int main()
{

    return 0;
}
