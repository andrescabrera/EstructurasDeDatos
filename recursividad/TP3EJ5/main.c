/*
Andr�s Cabrera - TP Recursividad - Ejercicio 5
Ingresar dos n�meros y calcular el m.c.d. en los mismos en forma recursiva.
*/

#include <stdio.h>
#include <stdlib.h>

static int mcd(int a, int b);

int main()
{
int numa, numb, mcdn;

printf("Ingrese numero: ");
scanf("%d",&numa);
printf("\nIngrese numero: ");
scanf("%d",&numb);

mcdn=mcd(numa, numb);
printf("El maximo comun divisor es %d", mcdn);

return EXIT_SUCCESS;
}

static int mcd(int a, int b)
{
if( a == b || b == 0 )
    return a;
    else
        if(a > b)
            return mcd(b, a-b);
        else
            return mcd(a, b-a);
}


