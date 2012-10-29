/*
********************************************************
Andrés Cabrera - Legajo 53231 - Universidad de Palermo
Guia de Ejercicios de Listas, Colas y Pilas, 2010
********************************************************
Ejercicio nº6:

Dada la siguiente estructura:

typedef  struct lista {
        int codmat;
        char nombre 15
        struct lista * sig;
} nodo;

a) Crear y mostrar la lista ( la carga finaliza cuando codmat=0). Se cargan    todos los códigos de materias iguales seguidos y ordenados.
b) Mostrar los alumnos que pertenecen a una materia.
c) Mostrar el código de materia que cuenta con más alumnos.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef  struct lista
{
    int codmat;
    char nombre[15];
    struct lista *sig;
} nodo;

void crear(nodo *);
void mostrar(nodo *);
void mostrarAlumnos(nodo *, int matobj);
int masAlumnos(nodo *);

int main()
{
    int objetivo;
    nodo *prin;
    prin = (nodo*)malloc(sizeof(nodo));
    crear(prin);
    mostrar(prin);

    printf("\n\nIngrese la materia a mostrar los alumnos: ");
    scanf("%d", &objetivo);
    mostrarAlumnos(prin, objetivo);

    printf("\n\nLa materia que tiene mas alumnos es: %d", masAlumnos(prin));
    return 0;
}

void crear(nodo *lista)
{
    printf("\nIngrese un Codigo de Materia - 0 para terminar: ");
    scanf("%d", &lista->codmat);
    if(lista->codmat == 0)
        lista->sig = NULL;
    else
    {
        printf("\nIngrese nombre: ");
        scanf(" %[^\n]", lista->nombre);
        lista->sig = (nodo*)malloc(sizeof(nodo));
        crear(lista->sig);
    }
}

void mostrar(nodo *lista)
{
    if(lista->sig != NULL)
    {
        printf("\nAlumno: %s\n\tCodigo de Materia: %d", lista->nombre, lista->codmat);
        mostrar(lista->sig);
    }
}

void mostrarAlumnos(nodo *lista, int obj)
{
    nodo *c;
    c = lista;
    while(c->codmat != obj)
        c = c->sig;
    while(c->codmat == obj)
    {
        printf("\nAlumno: %s", c->nombre);
        c = c->sig;
    }
}

int masAlumnos(nodo *lista)
{
    nodo *c;
    c = lista;
    int mayorAlumnos = 0; //se almacenan la cantidad mayor de alumnos
    int matMasAlumnos = 0; //codmat con mayor cantidad de alumnos

    int matActual = c->codmat;
    int alumnosActual = 0;

    while(c != NULL)
    {
        if(c->codmat == matActual)
            alumnosActual++;
        else
        {
            if(alumnosActual > mayorAlumnos)
            {
                mayorAlumnos = alumnosActual;
                matMasAlumnos = matActual;
            }
            matActual = c->codmat;
            alumnosActual = 1;
        }
        c = c->sig;
    }

    return matMasAlumnos; //se devuelve 0 si no habian alumnos
}

