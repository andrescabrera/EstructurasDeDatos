#include <stdio.h>
#include <stdlib.h>
void cargar (int a[]);
void mostrar (int a[], int max);
int generar (int a[], int b[], int tam);
int generarc (int a[], int b[], int c[], int tama, int tamb);
int main()
{
    int a[10], b[10], c[10], j, p;
    cargar(a);
    printf ("\n el vector a es ");
    mostrar (a, 10);
    j=generar(a, b, 10);
    if (j==0)
        printf ("\n no existe vector b ");
    else
    {
        printf ("\n el vector b es ");
        mostrar (b, j);
    }
    p=generarc (a, b, c, 10, j);
    if (p==0)
        printf ("\n no existe vector c ");
    else
    {
        printf("p es %d", p);
        system("PAUSE");
        printf ("\n el vector c es ");
        mostrar (c, p);
    }
    return EXIT_SUCCESS;
}

void cargar (int a[])
{
    int i;
    for (i=0; i<10; i++)
    {
        do
        {
            printf ("\n ingrese numero para posicion %d", i);
            scanf ("%d", &a[i]);
        }
        while (a[i]%2==0 || a[i]%3!=0);
    }

    return;
}

void mostrar (int a[], int max)
{
    int i;
    for (i=0; i<max; i++)
        printf ("\n el numero en la posicion %d es %d ", i, a[i]);
    return;
}

int generar (int a[], int b[], int tam)
{
    int i, j=0;
    for (i=0; i<tam; i++)
    {
        if (a[i]%5==0)
        {
            b[j]=a[i];
            j++;
        }
    }
    return j;
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





