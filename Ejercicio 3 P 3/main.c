#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int num;
    struct lista *sig;
}nodo;

void mostrar(nodo *lista);
void crear(nodo *lista);
void concatenar(nodo *listaA, nodo *listaB, nodo *listaConcatenada);

int main()
{
    nodo *listaA;
    listaA = (nodo*)malloc(sizeof(nodo));
    nodo *listaB;
    listaB = (nodo*)malloc(sizeof(nodo));
    crear(listaA);
    mostrar(listaA);
    crear(listaB);
    mostrar(listaB);
    nodo *listaC;
    listaC = (nodo*)malloc(sizeof(nodo));
    concatenar(listaA, listaB, listaC);
    mostrar(listaC);

    return 0;
}

void mostrar(nodo *lista)
{
    nodo *c = lista;
    while (c->sig != NULL)
    {
        printf("%d\n", c->num);
        c = c->sig;
    }
}

void crear(nodo *lista)
{
    printf("\nIngrese un numero: - 1000 para terminar: ");
    scanf("%d", &lista->num);
    if(lista->num == 1000)
        lista->sig = NULL;
    else
    {
        lista->sig = (nodo*)malloc(sizeof(nodo));
        crear(lista->sig);
    }
}

void concatenar(nodo *listaA, nodo *listaB, nodo *listaConcatenada)
{
    nodo *tempC = listaConcatenada;
    nodo *temp = listaA;
    while(temp->sig)
    {
        tempC->num = temp->num;
        tempC->sig = (nodo*)malloc(sizeof(nodo));
        tempC = tempC->sig;
        temp = temp->sig;
    }
    temp = listaB;
    while(temp->sig)
    {
        tempC->num = temp->num;
        tempC->sig = (nodo*)malloc(sizeof(nodo));
        tempC = tempC->sig;
        temp = temp->sig;
    }
    //free(tempC);
    tempC->sig = NULL;
}

