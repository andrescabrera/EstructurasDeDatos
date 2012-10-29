/*
Ejercicio nº1:

Desarrollar un procedimiento que permita dado un entero N,
asignar el valor I al elemento N-ésimo desde la parte superior de la pila,
volviendo a dejar los N-1 elementos inferiores donde se encontraban.

Ejercicio nº2:


Desarrollar un procedimiento que permita eliminar el nodo que contenga la información Z de la pila.


Ejercicio nº3:

Desarrollar un procedimiento que permita invertir los elementos de la pila.


*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct pila
{
    int data;
    struct pila *sig;
} nodo;

void agregar(nodo **, int);
int sacar(nodo **);
void mostrar(nodo *);
void sacarHastaN(nodo **prim, int n, int dato);
void eliminarZ(nodo **prim, int n, int z);
void invertir(nodo **prim, int n);
void concatenar(nodo **prim, nodo **prim2, nodo **prim3, int n, int n2);
int noExiste(int vec[], int data, int tamVec);

int menu();

int main()
{
    nodo *stack=NULL;
    nodo *stack2=NULL;
    nodo *stack3=NULL;
    int valor, op, tampila = 0, tampila2 = 0;
    do
    {
        op=menu();
        switch(op)
        {
        case 1:
            printf("ingrese un valor xra pila1: ");
            scanf("%d", &valor);
            agregar(&stack, valor);
            tampila++;
            printf("PILA 1\n");
            mostrar(stack);
            printf("\n");
            break;
        case 2:
            /*if (stack == NULL ) printf("vacio!");
            else
            {*/
                //x=sacar(&stack);
                //sacarHastaN(&stack, 4, 10);
                //eliminarZ(&stack, tampila, 3);
                //invertir(&stack, tampila);
                concatenar(&stack, &stack2, &stack3, tampila, tampila2);
                printf("\n");
                //printf("el valor eliminado es %d\n", x);
           // }
            printf("PILA 3\n");
            mostrar(stack3);
            printf("\n");
            break;
        case 3:
            printf("ingrese un valor xra pila2: ");
            scanf("%d", &valor);
            agregar(&stack2, valor);
            tampila2++;
            printf("PILA 2\n");
            mostrar(stack2);
            printf("\n");
            break;
        case 4:
            printf("fin de proceso\n");
        }
    }
    while(op != 4);
    return 0;
}

int menu()
{
    int op;
    printf("1. Agregar a Pila 1\n");
    printf("2. Operar\n");
    printf("3. Agregar a Pila 3\n");
    printf("4. Fin\n");
    do
    {
        printf("\n Opcion: ");
        scanf("%d", &op);
        if (op<1 || op>4) printf("ERROR!\n");
    }
    while (op<1 || op>4);
    return op;
}

void agregar(nodo **prim, int info)
{
    nodo *nuevo;
    nuevo=(nodo *)malloc(sizeof(nodo));
    if (nuevo != NULL)
    {
        nuevo->data=info;
        nuevo->sig=*prim;
        *prim=nuevo;
    }
    else printf("no hay memoria\n");
    return;
}

int sacar(nodo **prim)
{
    nodo *temp;
    int valor;
    temp=*prim;
    valor=(*prim)->data;
    *prim=(*prim)->sig;
    free(temp);
    return(valor);
}

void mostrar(nodo *prim)
{
    if(prim!=NULL)
    {
        printf("%d\n ",prim->data);
        mostrar(prim->sig);
    }
    return;
}

void sacarHastaN(nodo **prim, int n, int dato)
{
    int i = 0;
    int vec[n];
    while(i < n && *prim)
    {
        vec[i] = sacar(prim);
        i++;
    }
    agregar(prim, dato);
    while(i > 0)
    {
        i--;
        agregar(prim, vec[i]);
    }
}

void eliminarZ(nodo **prim, int n, int z)
{
    int i = 0;
    int x;
    int vec[n];
    while(*prim)
    {
        if((*prim)->data != z)
            vec[i++] = sacar(prim);
        else
            x = sacar(prim);
    }
    printf("saque: %d", x);
    while(i > 0)
    {
        i--;
        agregar(prim, vec[i]);
    }
}

void invertir(nodo **prim, int n)
{
    int i = 0;
    int vec[n];
    while(*prim)
    {
        vec[i] = sacar(prim);
        i++;
    }
    i = 0;
    while(i < n)
    {
        agregar(prim, vec[i]);
        i++;
    }
}
void concatenar(nodo **prim, nodo **prim2, nodo **prim3, int n, int n2)
{
    int i = 0;
    int j = 0;
    int vec1[n];
    int vec2[n2];
    //pila1
    while(*prim)
        vec1[i++] = sacar(prim);
    //pila2
    while(*prim2)
    {
        if(noExiste(vec1, (*prim2)->data, i) == 0)
            vec2[j++] = sacar(prim2);
        else
            sacar(prim2);
    }
    //concateno
    while(j > 0)
        agregar(prim3, vec2[--j]);
    while(i > 0)
        agregar(prim3, vec1[--i]);
}

int noExiste(int vec[], int data, int tamVec)
{
    int i = 0, existe = 0;

    while(i < tamVec)
        if(vec[i++] == data)
            existe = 1;

    return existe;
}

