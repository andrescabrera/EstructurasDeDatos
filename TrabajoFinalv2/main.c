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
} nBarrio;

typedef struct inmuebles
{
    char dir [40];
    int cantamb;
    float precio;
    struct inmuebles *sigInm;
} nInm;

int userMenu();
int adminMenu();
int iniciarSesion();
void mostrarxBarrio(nBarrio *);
void mostrarInmuebles(nInm *inm);
void mostrarOrdenada(nBarrio *barrio, char sortorder[]);
void altaBarrio (nBarrio **barrio, char objetivo[]);
nBarrio *bajaBarrio(nBarrio *barrios, char objetivo[]);
void altaInmueble(nBarrio **b, char objetivo[]);
int bajaInmueble(nBarrio *b, char objetivo[]);
int modificarInmueble(nBarrio *b, char objetivo[]);
nBarrio *buscarBarrio(nBarrio *b, char objetivo[]);
int buscarInmueble(nBarrio *b, char objetivo[]);
nInm *localizaInmueble (nInm *registro, char objetivo[]);
void ofertarInmuebles(nInm **cabeza, nInm **fin, char oferta[]);
void quitarOferta(nInm **cabeza, nInm **fin);
void procesarCola(nInm **cabeza, nInm **fin, nBarrio *barrios);
void cargar(nBarrio *barrio,  FILE *i, nBarrio **fin);
void cerrarSesion(nBarrio *barrio, FILE *i);
void cargarOfertas(nInm *inmuebles, nInm **fin, FILE *f);
void descargarOfertas(nInm *inmuebles, FILE *f);

int main()
{
    int opcion;
    char objetivo[40];
    FILE *punfile;
    FILE *punofertas;
    nBarrio *fin = NULL;
    nBarrio *barrios = NULL;
    barrios = (nBarrio*)malloc(sizeof(nBarrio));
    nInm *ofertascab=NULL, *ofertasfin=NULL;

    if ((punfile=fopen("archivo.dat","r"))==NULL)
        printf("\n\tERROR: No se puede abrir el archivo de barrios!!\n\n");
    else
    {
        cargar(barrios, punfile, &fin);
        fclose(punfile);
        if ((punofertas=fopen("ofertas.dat", "r"))==NULL)
            printf("\n\tERROR: No se pudo abrir el archivo de ofertas!!\n\n");
        else
        {
            fscanf(punofertas, " "); //TODO q pasa con... !feof ??
            if (!feof(punofertas)) //Si el archivo no esta vacio
            {
                ofertascab = (nInm*)malloc(sizeof(nInm));
                cargarOfertas(ofertascab, &ofertasfin, punofertas);
            }
            else
                printf("\n\tNo hay ofertas pendientes de procesar!!\n\n");
            fclose(punofertas);
        }
        opcion = iniciarSesion();
        if (opcion == 1)
        {
            do
            {
                opcion = userMenu();
                switch (opcion)
                {
                case 2:
                    printf("\nIngrese el inmueble por el que desea ofertar: ");
                    scanf(" %[^\n]", objetivo);
                    if (buscarInmueble(barrios, objetivo))
                    {
                        ofertarInmuebles(&ofertascab, &ofertasfin, objetivo); //si existe lo oferto
                        printf("\n---------------------Listando las ofertas------------------------\n");
                        mostrarInmuebles(ofertascab);
                    }
                    else printf("\n\tNo existe el inmueble por el que desea ofertar!!\n");
                    system("pause");
                    break;
                case 4:
                    mostrarOrdenada(barrios, "precio");
                    break;
                case 5:
                    mostrarxBarrio(barrios);
                    system("pause");
                    break;
                case 6:
                    mostrarOrdenada(barrios, "ambientes");
                    break;
                }
            }
            while (opcion != 3);
        }
        else
        {
            do
            {
                opcion = adminMenu();
                switch (opcion)
                {
                case 1:
                    printf("\nIngrese el nombre del nuevo barrio: ");
                    scanf(" %[^\n]", objetivo);
                    altaBarrio(&barrios, objetivo);
                    mostrarOrdenada(barrios, "barrio");
                    break;
                case 2:
                    printf("\nIngrese el barrio que desea eliminar\n(se eliminaran todos los inmuebles del barrio): ");
                    scanf(" %[^\n]", objetivo);
                    barrios = bajaBarrio(barrios, objetivo);
                    mostrarOrdenada(barrios, "barrio");
                    break;
                case 3:
                    printf("\nIngrese el barrio al que pertenece el inmueble: ");
                    scanf(" %[^\n]", objetivo);
                    altaInmueble(&barrios, objetivo);
                    mostrarOrdenada(barrios, "barrio");
                    break;
                case 4:
                    printf("\nIngrese la direccion del inmueble a borrar: ");
                    scanf(" %[^\n]", objetivo);
                    opcion = bajaInmueble(barrios, objetivo);
                    if (opcion) mostrarxBarrio(barrios);
                    else
                        printf("\nNo se encontro el inmueble indicado\n");
                    break;
                case 5:
                    printf("\nIngrese la direccion del inmueble que desea modificar: ");
                    scanf(" %[^\n]", objetivo);
                    opcion = modificarInmueble(barrios, objetivo);
                    if (opcion == 0)
                        mostrarxBarrio(barrios);
                    else
                        printf("\nNo se encontro el inmueble indicado\n");
                    break;
                case 6:
                    if (ofertascab != NULL)
                    {
                        procesarCola(&ofertascab, &ofertasfin, barrios);
                        printf("\n----------------Ofertas pendientes a procesar----------------\n\n");
                        mostrarInmuebles(ofertascab);
                    }
                    else
                        printf("\n\t\tNo se han realizado ofertas.\n\n");
                    break;
                }
                system("pause");
            }
            while (opcion != 7);
        }
        if ((punfile=fopen("archivo.dat","w"))==NULL)
            printf("\nERROR: No se puede escribir en el archivo!!");
        else
        {
            cerrarSesion(barrios, punfile);
            fclose(punfile);
            if ((punofertas=fopen("ofertas.dat","w"))==NULL)
                printf("\n\tERROR: No se pudo abrir el archivo de ofertas!!\t");
            else
            {
                if (ofertascab != NULL) //TODO condicion para que no descargue
                    descargarOfertas(ofertascab, punofertas);
                else
                    printf("\n\tNo hay ofertas para guardar!. Saliendo...\n");
                fclose(punofertas);
            }
        }
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
            printf("\n\tERROR: Intente otra vez");
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
    system("cls");
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
    while (op<1 || op>3);
    if (op == 1)
    {
        printf("\n\n\n--------------------------------------------------------------\n\t\tListando los inmuebles\n");
        do
        {
            printf("\nSeleccione una opcion:\n");
            printf("\t4- Mostrar por Precio\n");
            printf("\t5- Mostrar por Barrio\n");
            printf("\t6- Mostrar por Cantidad de Ambientes\n");
            printf("\n\nSeleccione una opcion: ");
            scanf("%d", &op);
            if (op < 4 || op > 6)
            {
                printf("\nERROR: Ingrese nuevamente\n.");
                system("pause");
                system("cls");
            }
        }
        while (op < 4 || op >6);
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
    while (op<1 || op>7);
    return op;
}

void cargar(nBarrio *barrios,  FILE *i, nBarrio **fin)
{
    char unstring[40];
    int unentero;
    float unfloat;

    nInm *aux; // IMPORTANTE trabajo con una copia!!
    if (!feof(i))
        fscanf(i, "\n%[^\n] %d %f", unstring, &unentero, &unfloat); //leo el primer barrio

    while (!feof(i))
    {
        strcpy(barrios->nombarrio, unstring);

        fscanf(i, "\n%[^\n] %d %f", unstring, &unentero, &unfloat);
        if(unentero != 0){
        barrios->baInm = (nInm*)malloc(sizeof(nInm));
        aux = barrios->baInm;
        }
        if (feof(i)) //TODO - evitar tener que cargar el ultimo inmueble del ultimo barrio
        {
            strcpy(aux->dir, unstring);
            aux->cantamb = unentero;
            aux->precio = unfloat;
            /*aux->sigInm = (nInm*)malloc(sizeof(nInm));
            aux = aux->sigInm;*/
            aux = NULL; //TODO que onda
        }
        while (!feof(i) && unentero != 0 && unfloat != 0) //leo el resto de los inmuebles
        {
            strcpy(aux->dir, unstring);
            aux->cantamb = unentero;
            aux->precio = unfloat;
            fscanf(i, "\n%[^\n] %d %f", unstring, &unentero, &unfloat); //leo el primer barrio
            if(!feof(i))
            {
                aux->sigInm = (nInm*)malloc(sizeof(nInm));
                aux = aux->sigInm;
            }
        }
        //aux = NULL; //cierro la lista de inmuebles
        *fin = barrios;
        barrios->sigBar=(nBarrio*)malloc(sizeof(nBarrio));
        barrios = barrios->sigBar;
    }
    barrios=NULL; //cierro la lista de barrios
}

void cargarOfertas(nInm *i, nInm **fin, FILE *f)
{
    if (!feof(f))
    {
        fscanf(f, " %[^\n] %d %f", i->dir, &i->cantamb, &i->precio);
        i->sigInm = (nInm*)malloc(sizeof(nInm));
        cargarOfertas(i->sigInm, fin, f);
    }
    else
    {
        *fin = i;
        i->sigInm = NULL;
    }
}

void descargarOfertas(nInm *i, FILE *f)
{
    while (i != NULL)
    {
        fprintf(f, "%s\n%d %.2f", i->dir, i->cantamb, i->precio);
        i = i->sigInm;
        /*if (i->sigInm != NULL)
            fprintf(f, "\n");*/
    }
}

void altaInmueble(nBarrio **b, char objetivo[])
{
    int op;
    nBarrio *marca;
    //si el primero es el barrio que busco, inserto por cabeza de lista
    if (strcmp((*b)->nombarrio, objetivo) == 0)
    {
        nInm *nuevoregistro;
        nuevoregistro = (nInm*)malloc(sizeof(nInm));
        printf("\nIngrese la direccion: ");
        scanf(" %[^\n]", nuevoregistro->dir);
        printf("Ingrese la cantidad de ambientes: ");
        scanf("%d",&nuevoregistro->cantamb);
        printf("Ingrese el precio del inmueble: ");
        scanf("%f", &nuevoregistro->precio);
        printf("\nInserto en el barrio correcto\n");
        nuevoregistro->sigInm = (*b)->baInm;
        (*b)->baInm = nuevoregistro;
    }
    else
    {
        marca = buscarBarrio(*b, objetivo); //buscar me devuelve el barrio anterior
        if (marca == NULL)
        {
            do
            {
                printf("\n%s no existe.\nDesea dar de alta a %s ahora?\n\t 1- Si, 2- No\n", objetivo, objetivo);
                scanf("%d", &op);
                if (op < 1 || op > 2)
                {
                    printf("\n\t\tOpcion Incorrecta. Intente nuevamente.\n");
                    system("pause");
                }
            }
            while (op < 1 || op > 2);
            if (op == 1)
            {
                altaBarrio(b, objetivo);
                altaInmueble(b, objetivo);
            }
        }
        else
        {
            nInm *nuevoregistro;
            nuevoregistro = (nInm*)malloc(sizeof(nInm));
            printf("\nIngrese la direccion: ");
            scanf(" %[^\n]", nuevoregistro->dir);
            printf("Ingrese la cantidad de ambientes: ");
            scanf("%d",&nuevoregistro->cantamb);
            printf("Ingrese el precio del inmueble: ");
            scanf("%f", &nuevoregistro->precio);
            nuevoregistro->sigInm = marca->sigBar->baInm;
            marca->sigBar->baInm = nuevoregistro;
        }
    }
}

void mostrarOrdenada(nBarrio *barrios, char sortorder[40])
{
    printf("\n-----------Lista de inmuebles ordenada por %s--------\n", sortorder);
    nInm *i; //para trabajar en la multilista
    nBarrio *b; //copia de barrio, para iterar y no perder la cabeza
    b = barrios;
    nInm *aux; //temporal para trabajar en las copias
    nInm *nueva; //nueva lista
    nInm *n; //copia de nueva, para no perder la cabeza
    nueva = (nInm*)malloc(sizeof(nInm));
    n = nueva;
    while (b != NULL) //copio la lista
    {
        i = b->baInm;
        if (i != NULL)
        {
            while (i->sigInm != NULL)
            {
                n->precio = i->precio;
                n->cantamb = i->cantamb;
                strcpy(n->dir, i->dir);
                n->sigInm = (nInm*)malloc(sizeof(nInm));
                n = n->sigInm; //avanzo en la nueva lista
                i = i->sigInm; //avanzo en inmuebles
            }
        }
        b = b->sigBar;
    }
    n = NULL;
    //ORDENAR
    i = nueva;
    while (i->sigInm != NULL)
    {
        nInm *j;
        j = i->sigInm;
        while (j->sigInm != NULL)
        {
            int op = 0;
            if (strcmp(sortorder, "precio"))
            {
                if (j->cantamb < i->cantamb) op = 1;
            }
            else
                if (j->precio < i->precio) op = 1;
            if (op)
            {
                aux = (nInm*)malloc(sizeof(nInm)); //j a un aux
                aux->precio = j->precio;
                strcpy(aux->dir, j->dir);
                aux->cantamb = j->cantamb;
                j->precio = i->precio; //i a j
                j->cantamb = i->cantamb;
                strcpy(j->dir, i->dir);
                i->precio = aux->precio; //aux a i
                i->cantamb = aux->cantamb;
                strcpy(i->dir, aux->dir);
            }
            j = j->sigInm;
        }
        i = i->sigInm;
    }
    mostrarInmuebles(nueva);
    system("pause");
}

void mostrarInmuebles(nInm *inm)
{
    nInm *i;
    i = inm;
    while (i != NULL) //TODO si no pregunto por i->sigInm muestra basura cuando muestro la multilista
    {
        printf("\t%s. %d ambientes.\n\tValor: $%.2f\n\n", i->dir, i->cantamb, i->precio);
        i = i->sigInm;
    }
}
int modificarInmueble(nBarrio *b, char objetivo[40])
{
    nInm *aux = NULL;
    if (b->baInm->sigInm != NULL) //si tiene al menos un inmueble, sino paso de barrio
    {
        if (strcmp(b->baInm->dir, objetivo)==0)
        {
            printf("\nIngrese el nuevo precio para %s:", b->baInm->dir);
            scanf("%f", &b->baInm->precio);
        }
        else
        {
            if (b->baInm != NULL)
                aux = localizaInmueble(b->baInm, objetivo);
            if (b->sigBar->sigBar != NULL && aux == NULL)
                return modificarInmueble(b->sigBar, objetivo);
            else
            {
                if (aux == NULL)
                    return 1;
                else
                {
                    printf("\nIngrese el nuevo precio para %s:", aux->sigInm->dir);
                    scanf("%f", &aux->sigInm->precio);
                }
            }
        }
        return 0;
    }
    else
        return modificarInmueble(b->sigBar, objetivo);
}

void altaBarrio (nBarrio **barrio, char objetivo[40])
{
    nBarrio *nuevoregistro;
    nBarrio *existe = NULL;

    if ((*barrio)->sigBar != NULL)
        existe = buscarBarrio(*barrio, objetivo);
    if (existe == NULL)
    {
        nuevoregistro=(nBarrio*)malloc(sizeof(nBarrio));
        strcpy(nuevoregistro->nombarrio, objetivo);
        nuevoregistro->baInm = (nInm*)malloc(sizeof(nInm));
        nuevoregistro->baInm->sigInm = NULL;
        nuevoregistro->sigBar = *barrio;
        *barrio = nuevoregistro;
    }
    else
        printf("\nEl barrio ya existe, no se pudo agregar.\n");
}

nBarrio *buscarBarrio(nBarrio *b, char objetivo[])
{
    if (strcmp(b->sigBar->nombarrio, objetivo) == 0)
        return b;
    else
        if (b->sigBar->sigBar != NULL)
            return buscarBarrio(b->sigBar, objetivo);
        else
            return NULL;
}

int bajaInmueble(nBarrio *b, char objetivo[])
{
    nInm *temp;
    if (strcmp(b->baInm->dir, objetivo)==0) //lo elimino si es el cabeza de lista
    {
        temp=b->baInm->sigInm;
        free(b->baInm);
        b->baInm=temp;
        return 1;
    }
    else
    {
        nInm *aux = NULL;
        if (b->baInm->sigInm != NULL)
            aux = localizaInmueble(b->baInm, objetivo);
        if (b->sigBar->sigBar != NULL && aux == NULL)
            return bajaInmueble(b->sigBar, objetivo);
        else
            if (aux == NULL)
                return 0;
            else
            {
                temp=aux->sigInm->sigInm;
                free (aux->sigInm);
                aux->sigInm=temp;
                return 1;
            }
    }
}

nBarrio *bajaBarrio(nBarrio *barrios, char objetivo[40])
{
    nBarrio *temp;
    nInm *tempInm;
    nInm *aux; //copia para trabajar en la multilista
    nBarrio *b;
    if (barrios->sigBar != NULL)
    {
        if (strcmp(barrios->nombarrio, objetivo) == 0)
        {
            aux = barrios->baInm;
            tempInm = aux;
            while (tempInm != NULL)
            {
                aux = aux->sigInm;
                free(tempInm);
                tempInm = aux;
            }
            temp=barrios->sigBar;
            free(barrios);
            barrios=temp;
        }
        else
        {
            b = buscarBarrio(barrios, objetivo);
            if (b != NULL)
            {
                aux = b->sigBar->baInm;
                tempInm = aux;
                while (tempInm != NULL)
                {
                    aux = aux->sigInm;
                    free(tempInm);
                    tempInm = aux;
                }
                temp=b->sigBar->sigBar;
                free (b->sigBar);
                b->sigBar=temp;
            }
            else
                printf("\n\n\t\tNo existe el barrio.\n\n");
        }
    }
    else
        printf("\nNo hay barrios.\n");

    return barrios;
}
void procesarCola(nInm **cabeza, nInm **fin, nBarrio *barrios)
{
    int noferta = 0;
    int opcion;
    nInm *registro;
    registro = *cabeza;
    system("cls");
    printf("---------------------Procesando las ofertas------------------------\n");
    if (registro->sigInm !=NULL)
    {
        printf ("\n\tOferta %d\n%s.\nPrecio: $%.2f\n", noferta++, registro->dir, registro->precio);
        do
        {
            printf("\nDesea aceptar esta oferta?\n1- Si, 2- No: ");
            scanf("%d", &opcion);
            if (opcion < 1 || opcion > 2)
                printf("\n\tError. Vuelva a ingresar su opcion\n\n");
        }
        while (opcion < 1 || opcion > 2);
        if (opcion == 1)
            bajaInmueble(barrios, registro->dir);

        quitarOferta(cabeza, fin);
    }
    return;
}

void quitarOferta(nInm **cabeza, nInm **fin)
{
    float precio;
    int cantamb;
    char dir[40];
    nInm *temp;
    strcpy(dir, (*cabeza)->dir);
    precio = (*cabeza)->precio;
    cantamb = (*cabeza)->cantamb;
    temp=*cabeza;
    *cabeza=(*cabeza)->sigInm;
    if (*cabeza == NULL)
        *fin=NULL;
    free(temp);
}
void cerrarSesion(nBarrio *barrio, FILE *i)
{
    nInm *b;
    if (barrio->sigBar != NULL)
    {
        fprintf(i, "%s\n0 0", barrio->nombarrio); //imprimo un barrio
        b = barrio->baInm;
        while (b->sigInm != NULL) //imprimo sus inmuebles
        {
            fprintf(i, "\n%s\n%d %.2f", b->dir, b->cantamb, b->precio);
            b = b->sigInm;
        }
        if (barrio->sigBar->sigBar != NULL) fprintf(i, "\n");
        cerrarSesion(barrio->sigBar, i);
    }
    return;
}

void mostrarxBarrio(nBarrio *barrio)
{
    if (barrio->sigBar != NULL)
    {
        printf("________-------=========--------________\nInmuebles de %s\n", barrio->nombarrio);
        mostrarInmuebles(barrio->baInm);
        mostrarxBarrio(barrio->sigBar);
    }
    return;
}

void ofertarInmuebles(nInm **cabeza, nInm **fin, char oferta[40])
{
    nInm *nuevo;
    nuevo=(nInm*)malloc(sizeof(nInm));
    if (nuevo != NULL)
    {
        printf("\n\t\tOfertando por el inmueble: %s", oferta);
        strcpy(nuevo->dir, oferta);
        printf("\nIngrese el precio para su oferta: ");
        scanf("%f", &nuevo->precio);
        nuevo->sigInm = NULL;
        if (*cabeza == NULL)
            *cabeza=nuevo;
        else
            (*fin)->sigInm=nuevo;
        *fin=nuevo;
    }
    else
        printf("ERROR: No hay memoria disponible!\n");
    return;
}

int buscarInmueble(nBarrio *b, char objetivo[])
{
    if (strcmp(b->baInm->dir, objetivo)==0)
        return 1;
    else
    {
        nInm *aux = NULL;
        if (b->baInm->sigInm != NULL)
            aux = localizaInmueble(b->baInm, objetivo);
        if (b->sigBar->sigBar != NULL && aux == NULL)
            return buscarInmueble(b->sigBar, objetivo);
        else
            if (aux == NULL)
                return 0;
            else
                return 1;
    }
}
nInm *localizaInmueble (nInm *registro, char objetivo[])
{
    if (strcmp(registro->sigInm->dir,objetivo)==0)
        return registro;
    else
        if (registro->sigInm->sigInm!=NULL)
            return	localizaInmueble (registro->sigInm, objetivo);
        else
            return NULL;
}
