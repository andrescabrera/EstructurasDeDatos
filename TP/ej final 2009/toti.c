#include <stdio.h>
#include <stlib.h>
int cargar (int a[], int b[]);
int main()
{
    int a[10];
    conta=cargar(int a[], int b[]);
    printf ("\n el vector a es ");
    mostrar (a, conta);
    contb=cargar (int a[], int b[])
          printf ("\n el vector b es ");
    mostrar (b, contb);


}

int cargar (int a[], int b[])
{

    int i, conta=0,contb=0, num;

    while (conta<10)
    {
        printf ("\n ingrse numero ");
        scanf ("%d", &num);
        if (num%3==0 && num%2!=0)
        {
            a[conta]=num;
            conta++;
        }

        if (num%5==0)
        {
            b[contb]=num;
            contb++;
        }
    }
    return conta, contb;
}
