#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int leg;
    int elem;
    struct lista *sig;
}nodo;

void cargar(nodo *pt);
void mostrar(nodo *pt);
void prom(nodo *listaa, nodo *listab);
nodo *eliminar(nodo *primero);

int main()
{
    nodo *lista1;
    nodo *lista2;

    lista1 = (nodo*)malloc(sizeof(nodo*));
    lista2 = (nodo*)malloc(sizeof(nodo*));

    cargar(lista1);
    mostrar(lista1);
    //creo segunda lista
    prom(lista1, lista2);
    printf("\nMostrando lista b");
    mostrar(lista2);
    lista1 = eliminar(lista1);
    mostrar(lista1);
    return 0;
}

void cargar(nodo *pt)
{
    printf("Ingrese un leg (0 para terminar): ");
    scanf("%d", &pt->leg);

    if (pt->leg == 0)
        pt->sig = NULL;
    else
    {
        printf("Ingrese nota: ");
        scanf("%d", &pt->elem);
        pt->sig=(nodo*)malloc(sizeof(nodo));
        cargar(pt->sig);
    }
}

void mostrar(nodo *pt)
{
    if (pt->sig != NULL)
    {
        printf("\nLeg: %d, Elem: %d", pt->leg, pt->elem);
        mostrar(pt->sig);
    }
    return;
}

void prom(nodo *listaa, nodo *listab)
{
    int legactual;
    float notatot = 0;
    int cantnotas = 0;
    float prom;

    //valores para el primer alumno
    legactual = listaa->leg;

    while (listaa->sig != NULL)
    {
        if (legactual == listaa->leg)
        {
            notatot += listaa->elem;
            cantnotas++;
        }
        else
        {
            //calculo el promedio
            prom = (float)notatot / cantnotas;
            //guardo
            listab->leg = legactual;
            listab->elem = prom;
            //cambio de alumno
            listab->sig = (nodo*)malloc(sizeof(nodo));
            listab = listab->sig;
            //reinicio los valores
            legactual = listaa->leg;
            notatot = listaa->elem;
            cantnotas = 1;
        }
        //paso al siguiente nodo
        listaa = listaa->sig;
    }
    prom = (float)notatot / cantnotas;
    listab->leg = legactual;
    listab->elem = prom;
    listab->sig = NULL;
}

//ELIMINAR
nodo *eliminar(nodo *primero)
{
    nodo *aux;
    nodo *temp;

    while (primero->elem < 4)
    {
        temp=primero->sig;
        free(primero);
        primero=temp;
    }
    aux = primero;
    while (aux != NULL)
    {
        if (aux->elem < 4)
        {
            temp=aux->sig->sig;
            free (aux->sig);
            aux->sig=temp;
        }
    }
    return primero;
}
