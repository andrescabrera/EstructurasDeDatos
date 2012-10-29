/*
Andrés Cabrera - Legajo 53231

Parcial Estructuras de Datos y Algoritmos
30/4/2010 - Viernes - Turno Noche

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int num;
    struct lista *sig;
}nodo;

void cargar(nodo *registro);
void mostrar(nodo *registro);
void generar(nodo *registro, nodo *nuevalis);
nodo *consec(nodo *registro);
void eliminar(nodo *registro);

int main()
{
    nodo *prin;
    nodo *multtres;

    prin = malloc(sizeof(nodo));
    multtres = malloc(sizeof(nodo));

    cargar((nodo*)prin);
    mostrar(prin);
    printf("\n");

    generar(prin, multtres);
    mostrar(multtres);

//  prin=consec(prin);

    eliminar(prin);
    mostrar(prin);

    return EXIT_SUCCESS;
}

//funcion recursiva cargar
void cargar(nodo *registro)
{
    printf("Ingrese num: ");
    scanf("%d", &registro->num);

    if(registro->num == 1000)
    {
        //cierro la lista
        registro->sig = NULL;
    }
    else
    {
        //creo nuevo nodo
        registro->sig = malloc(sizeof(nodo));
        cargar((nodo*)registro->sig);
    }

    return;
}

void mostrar(nodo *registro)
{
    if(registro->sig != NULL)
    {
        printf(" %d |", registro->num);
        mostrar(registro->sig);
    }

    return;
}

//funcion generar nueva lista con multiplos de 3
void generar(nodo *registro, nodo *nuevalis)
{
    while(registro->sig != NULL)
    {
        //si es multiplo
        if((registro->num%3)==0)
        {
            nuevalis->num = registro->num;
            nuevalis->sig = malloc(sizeof(nodo));
            nuevalis = nuevalis->sig;
        }
        //paso al siguiente nodo de la lista original
        registro = registro->sig;
    }
    nuevalis->sig = NULL;
}

nodo *consec(nodo *registro)
{
    nodo *puntPrevio;
    nodo *puntActual;
    nodo *nuevo;

    int cont;
    //sumo el primer nodo
    cont = registro->num;

    if((registro->sig->num + cont)>20)
    {
        nuevo = malloc(sizeof(nodo));
        nuevo->num = 0;
        nuevo->sig = registro;
        registro = nuevo;
        puntPrevio = registro->sig->sig;
    }
    else
        puntPrevio = registro->sig;

    puntActual = puntPrevio->sig;

    while(puntActual->sig != NULL)
    {
        cont=puntPrevio->num+puntActual->num;
        if(cont > 20)
        {
            nuevo = malloc(sizeof(nodo));
            nuevo->num = 0;
            puntPrevio->sig = nuevo;
            nuevo->sig = puntActual;
        }
        puntPrevio = puntActual->sig;
        puntActual = puntPrevio->sig;
    }

return registro;
}

void eliminar(nodo *registro)
{
    nodo *punActual;
    nodo *punPrevio;
    nodo *temp;

    punPrevio = registro;
    punActual = punPrevio->sig;

    while(punActual->sig->num != 1000)
    {
        //si es menor a diez
        if(punActual->num+punPrevio->num < 10)
        {
            temp=punPrevio->sig->sig;
            free(punPrevio->sig);
            punPrevio->sig=temp;
        }
        //adelanto dos
        punPrevio = punActual->sig;
        punActual = punPrevio->sig;
    }
}




