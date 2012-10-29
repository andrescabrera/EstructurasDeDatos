/*
Ejercicio nº1
Cargar una lista con nombre y sueldo. Mostrarla
1)Cargar una segunda lista con números enteros repetidos. Mostrarla.
2)Eliminar de la primera lista las posiciones indicadas por cada nodo de la segunda lista. Mostrarla.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista1
{
    char nom[20];
    float sueldo;
    struct lista1 * sig;
} nodo1;

typedef struct lista2
{
    int num;
    struct lista2 * sig;
} nodo2;

void cargar1(nodo1 *p1);
void mostrar1(nodo1 *p1);
void cargar2(nodo2 *p2);
void mostrar2(nodo2 *p2);
nodo1 *eliminar1(nodo1 *p1, nodo2 *p2);

int main()
{
    nodo1 *p1;
    nodo2 *p2;
    p1 = (nodo1*)malloc(sizeof(nodo1));
    p2 = (nodo2*)malloc(sizeof(nodo2));
    cargar1(p1);
    printf("\nLista1:\n");
    mostrar1(p1);
    cargar2(p2);
    printf("\nLista2:\n");
    mostrar2(p2);
    printf("\nEliminando las posiciones indicadas en la lista 2, de la 1\n");
    p1=eliminar1(p1, p2);
    printf("\nLista3:\n");
    mostrar1(p1);
    return 0;
}

void cargar1(nodo1 *p1)
{
    printf("Ingrese Nombre (FIN para terminar): ");
    scanf("%s", p1->nom);

    if (strcmp (p1->nom,"FIN")==0)
        p1->sig=NULL;
    else
    {
        printf("Ingrese Sueldo: ");
        scanf("%f", &p1->sueldo);
        p1->sig=(nodo1*)malloc(sizeof(nodo1));
        cargar1(p1->sig);
    }
}
void mostrar1(nodo1 *p1)
{
    if (p1->sig != NULL)
    {
        printf("\n Nombre= %s, Sueldo= %f", p1->nom, p1->sueldo);
        mostrar1(p1->sig);
    }
    return;
}

void cargar2(nodo2 *p2)
{
    printf("\nIngrese un numero entero (pueden repetirse - 0 para terminar): ");
    scanf("%d", &p2->num);

    if (p2->num ==0)
        p2->sig = NULL;
    else
    {
        p2->sig = (nodo2*)malloc(sizeof(nodo2));
        cargar2(p2->sig);
    }

    return;
}
void mostrar2(nodo2 *p2)
{
    if (p2->sig != NULL)
    {
        printf("\nn= %d", p2->num);
        mostrar2(p2->sig);
    }

    return;
}


nodo1 *eliminar1(nodo1 *p1, nodo2 *p2)
{
    nodo1 *eliminarpos(nodo1 *, int);
    while (p2->sig!=NULL)
    {
        p1 = eliminarpos(p1, p2->num);
        p2 = p2->sig; //avanzo en p2
    }

    return p1;
}


nodo1 *eliminarpos(nodo1 *p, int objetivo)
{
    nodo1 *aux;
    nodo1 *temp;
    nodo1 *localiza(nodo1 *, int, int);
    //int cont = 1;

    if (objetivo==1)
    {
        temp=p->sig;
        free(p);
        p=temp;
    }
    else
    {

   aux = localiza(p, objetivo, 1);
   /* //De manera iterativa algo así...
        while (cont < objetivo && aux != NULL)
        {
            aux = aux->sig;
            cont++;
        }
        //si no estoy en la ultima posicion (cont < objetivo) minimo me faltaba una...
        if (aux != NULL)
        {
            //estoy en la posicion anterior al objetivo
            temp=aux->sig->sig;
            free (aux->sig);
            aux->sig=temp;
        }
*/
//de forma iterativa
 if (aux != NULL)
        {
            //estoy en la posicion anterior al objetivo
            temp=aux->sig->sig;
            free (aux->sig);
            aux->sig=temp;
        }
    }

    return p;
}

//LOCALIZA
nodo1 *localiza (nodo1 *registro, int objetivo, int num)
//regresa el puntero al nodo anterior al objetivo
{
    if (objetivo == num+1) //+1 porque es uno antes al que tengo que conseguir
        return registro;
    else
        if (registro->sig->sig!=NULL)
            return localiza (registro->sig, objetivo, num+1); //porque voy incrementando
        else
            return NULL;
}
