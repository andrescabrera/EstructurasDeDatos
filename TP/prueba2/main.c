#include <stdio.h>
#include <stdlib.h>

int cargar(int a[], int b[]);
void mostrar (int a[], int tam);
int generarc (int a[], int b[], int c[], int tama, int tamb);
void desplazar (int a[], int tam);
void primin (int b[], int tam);

int main()
{
    int a[10], b[10], c[10], contb, p;
    contb=cargar(a, b);
    printf ("\n el vector a es ");
    mostrar (a, 10);
    printf("\n el vector b es ");
    mostrar(b, contb);
    p=generarc(a, b, c, 10, contb);
    printf ("\n el vector c es ");
    mostrar(c, p);
    desplazar(a, 10);
    printf ("\n el vector desplazado es ");
    mostrar (a, 10);
    primin(b, contb);

    return EXIT_SUCCESS;
}

int cargar(int a[], int b[])
{

    int conta=0,contb=0, num;

    while (conta<10)
    {
        printf ("\n ingrse numero ");
        scanf ("%d", &num);
        if (num%3==0 && num%2!=0)
        {
            a[conta]=num;
            conta++;
        }

        if (num%5==0 && contb<10)
        {
            b[contb]=num;
            contb++;
        }
    }

    return contb;
}

void mostrar (int a[], int tam)
{
    int i;

    for (i=0; i<tam; i++)
        printf ("\n el numero en la posicion %d es %d ", i, a[i]);
    return;
}

int generarc (int a[], int b[], int c[], int tama, int tamb)
{
    int i, p=0, j;
    for (i=0; i<tama; i++)
    {
        for (j=0; j<tamb; j++)
        {
            if (a[i]==b[j])
            {
                c[p]=a[i];
                p++;
            }
        }
    }
    return p;
}

void desplazar (int a[], int tam)
{
    int i;
    for (i=tam; i>3; i--)
        a[i]=a[i-2];

    a[2]=a[2]+5;
    a[3]=a[3]+5;
    return;
}

void primin (int b[], int tam)
{
    int i, min=b[0], minpos=0;
    for (i=1; i<tam; i++)
    {
        if(min>b[i])
        {
            min=b[i];
            minpos=i;
        }
    }

    minpos++;
    while (b[minpos]<min)
    {

    minpos++;
    }

    printf("El primer elemento mayor al minimo es %d", b[minpos]);

    printf ("\n el minimo es %d ", min);
    return;
}


