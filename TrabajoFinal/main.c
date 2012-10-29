/*
Andrés Cabrera - Leg. 53231
Estructuras de Datos y Algoritmos - 2010
----------------------------------------
Trabajo Práctico 8
Objetivo:
Programar un sistema de ventas de inmuebles. El sistema contempla la modalidad usuario y la modalidad administrador.

Modo Usuario:
El usuario podrá ver los inmuebles en venta por barrio, por cantidad de ambientes o por el valor de los inmuebles.
El usuario podrá ofertar por un inmueble. Esta oferta irá a una cola de ofertas que luego procesará el administrador.

Modo Administrador:
En esta modalidad, el administrador puede:

•	Dar de alta a un nuevo Barrio
•	Dar de alta a nuevos inmuebles.
•	Dar de baja a un Barrio.
•	Dar de baja a un Inmueble.
•	Podrá  modificar el valor en dólares de un inmueble.
•	Mostrar las ofertas a cada inmueble.
•	Deberá procesar las colas

Codificar en C los menúes correspondientes a cada modalidad..
----------------------------------------------------------------------
Trabajo Práctico 9
La listas del  Trabajo Práctico Final  tienen las  siguientes estructuras:
    Struct Barrio {
             Char nombarrio [30];
             Struct Inmuebles *BaInm;
             Struct Barrio *sigBar;
	}

       Struct Inmuebles {
            Char dir [40];
            Int cantamb;
            Float precio;
            Struct  Inmuebles *sigInm;
            }

Bajar la información de estas listas de uno o dos archivos.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct barrio
{
    char nombarrio [30];
    struct inmuebles *baInm;
    struct barrio *sigBar;
} nodoBarrio;

typedef struct inmuebles
{
    char dir [40];
    int cantamb;
    float precio;
    struct inmuebles *sigInm;
} nodoInmueble;


void altaBarrio();
void bajaBarrio();
void listarInmuebles(nodoBarrio *, char []);
void mostrarInmueblesDelBarrio(nodoInmueble *);
void mostrarBarrios(nodoBarrio *);
void altaInmueble();
void bajaInmueble();
void modificarInmueble();
void procesarColas();
int userMenu();
int adminMenu();
int iniciarSesion();
void cerrarSesion();
void ofertarInmuebles();
void cargar(nodoBarrio *b,  FILE *i);

int main()
{
    int opcion;

    FILE *punfile;
    nodoBarrio *barrios;
    barrios = (nodoBarrio*)malloc(sizeof(nodoBarrio));

    if ((punfile=fopen("archivo.dat","r"))==NULL)
        printf("\n No se puede abrir el archivo!!");
    else
    {
        cargar(barrios, punfile);
        fclose(punfile);

        opcion = iniciarSesion();
        if(opcion == 1)
        {
            do
            {
                opcion = userMenu();
                switch(opcion)
                {
                case 2:
                    ofertarInmuebles();
                    break;
                case 4:
                    listarInmuebles(barrios, "precio");
                    break;
                case 5:
                    listarInmuebles(barrios, "barrio");
                    break;
                case 6:
                    listarInmuebles(barrios, "ambientes");
                    break;
                }

            }
            while(opcion != 3);
        }
        else
        {
            do
            {
                opcion = adminMenu();
                switch(opcion)
                {
                case 1:
                    altaBarrio();
                    break;
                case 2:
                    bajaBarrio();
                    break;
                case 3:
                    altaInmueble();
                    break;
                case 4:
                    bajaInmueble();
                    break;
                case 5:
                    modificarInmueble();
                    break;
                case 6:
                    procesarColas();
                    break;
                }
            }
            while(opcion != 7);
        }
        cerrarSesion();
    }
    return EXIT_SUCCESS;
}

int iniciarSesion ()
{
    int op;
    do
    {
        printf ("\nBienvenido\n--------------\n");
        printf ("\n1 - Ingresar al modo usuario");
        printf ("\n2 - Ingresar al modo administrador");
        printf ("\nSeleccione una opcion: ");

        scanf ("%d",&op);
        if (op<1 || op>2)
        {
            printf("\nERROR: Intente otra vez");
            system("cls");
        }

    }
    while (op<1 || op>2);

    printf ("\n");
    return op;
}

int userMenu()
{
    int op;
    //TODO cls
    //system("cls");
    printf("------------Bienvenido al modo usuario-----------------------");
    do
    {
        printf("\n1 - Ver Inmuebles");
        printf("\n2 - Ofertar Inmuebles");
        printf("\n3 - Cerrar Sesion");
        printf("\nSeleccione una opcion: ");
        scanf("%d", &op);
        if (op<1 || op>3)
        {
            printf("\nERROR: Intente otra vez\n");
            system("pause");
            system("cls");
        }
    }
    while(op<1 || op>3);
    if(op == 1)
    {
        printf("\n\n........Listando los inmuebles........");
        do
        {
            printf("\nSeleccione una opcion:\n\t4- Mostrar por precio\n\t5- Mostrar por Barrio\n\t6- Mostrar por Cantidad de Ambientes\n");
            printf("\n\nSeleccione una opcion: ");
            scanf("%d", &op);
            if(op < 4 || op > 6)
            {
                printf("\nERROR: Ingrese nuevamente\n.");
                system("pause");
                system("cls");
            }
        }
        while(op < 4 || op >6);
    }

    return op;
}

int adminMenu()
{
    int op;
    system("cls");
    printf("------------Bienvenido al modo administrador-----------------");
    do
    {
        printf("\n1 - Dar de alta a un nuevo barrio");
        printf("\n2 - Dar de baja a un barrio.");
        printf("\n3 - Dar de alta inmuebles.");
        printf("\n4 - Dar de baja inmuebles.");
        printf("\n5 - Modificar precios.");
        printf("\n6 - Procesar colas.");
        printf("\n7 - Salir del sistema");
        printf("\n\nSeleccione una opcion: ");
        scanf("%d", &op);
        if (op<1 || op>7)
        {
            printf("\nERROR: Intente otra vez\n");
            system("pause");
            system("cls");
        }

    }
    while(op<1 || op>7);
    return op;
}


void cargar(nodoBarrio *barrio,  FILE *i)
{
    char unstring[40];
    int unentero;
    float unfloat;

    fscanf(i, "%s %d %f", unstring, &unentero, &unfloat); //leo el primer barrio

    while(!feof(i))
    {
        barrio->baInm = (nodoInmueble*)malloc(sizeof(nodoInmueble));
        //guardo el barrio
        strcpy(barrio->nombarrio, unstring);
        //leo el primer inmueble del barrio
        fscanf(i,"%s %d %f", unstring, &unentero, &unfloat);
        do //guardo el primer inmueble del barrio, si tiene otro repite
        {
            strcpy(barrio->baInm->dir, unstring);
            barrio->baInm->cantamb = unentero;
            barrio->baInm->precio = unfloat;
            barrio->baInm->sigInm = (nodoInmueble*)malloc(sizeof(nodoInmueble));
            barrio->baInm = barrio->baInm->sigInm; //avanzo en los inmuebles del barrio
            //vuelvo a pedir
            if(!feof(i))
                fscanf(i,"%s %d %f", unstring, &unentero, &unfloat);
        }
        while(!feof(i) && unentero != 0 && unfloat != 0);
        barrio->baInm = NULL; //cierro la lista de inmuebles del barrio

        barrio->sigBar=(nodoBarrio*)malloc(sizeof(nodoBarrio));
        barrio = barrio->sigBar; //avanzo en barrios
    } //salgo del while principal
    barrio->sigBar=NULL; //entonces cierro la lista de barrios
}

void altaInmueble()
{
    printf("\n\n\tDoy de alta un inmueble\n");
    system("pause");
}
void bajaInmueble()
{
    printf("\n\n\tDoy de baja un inmueble\n");
    system("pause");
}
void modificarInmueble()
{
    printf("\n\n\tCambio el precio de un inmueble\n");
    system("pause");
}
void altaBarrio()
{
    printf("\n\n\tDoy de alta un barrio\n");
    system("pause");
}
void bajaBarrio()
{
    printf("\n\n\tDoy de baja un barrio\n");
    system("pause");
}
void procesarColas()
{
    printf("\n\n\tYo procesar la cola...\n");
    system("pause");
}
void cerrarSesion()
{
    printf("\n\n\tYo cierro el programa, guardando los datos a disco, suerte amigo.\n");
    printf("\n\nSaliendo del sistema!!.\n");
}
void listarInmuebles(nodoBarrio *barrios, char sortorder[20])
{
    printf("\n\n\tYo muestro los inmuebles por: %s\n", sortorder);
    if(strcmp(sortorder, "barrio") == 0)
    {
        mostrarBarrios(barrios);
    }

    system("pause");
}

void mostrarBarrios(nodoBarrio *barrios)
{
    /*nodoBarrio *barrios;
    barrios = aux;*/

    if(barrios->sigBar != NULL)
    {
        printf("El nombre del barrio es: %s\n", barrios->nombarrio);
        //TODO Mostrar Inmuebles del Barrio
        printf("Inmuebles del barrio:\n");
        if(barrios->baInm == NULL)
            printf("\nLa lista de inm es null\n");
        while(barrios->baInm != NULL)
        {
            printf("La direccion del inmueble es: %s, dispone de %d ambientes, y el precio es: %.2f\n", barrios->baInm->dir, barrios->baInm->cantamb, barrios->baInm->precio);
            barrios->baInm = barrios->baInm->sigInm;
        }
        mostrarBarrios(barrios->sigBar);
    }
    return;
}

void ofertarInmuebles()
{
    printf("\n\n\tYo permito que el usuario realice ofertas.\n");
    system("pause");
}
