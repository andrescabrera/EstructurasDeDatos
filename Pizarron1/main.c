/*
Andrés Cabrera
Ejercicio Pizarron, Clase 19/3
*/

#include <stdio.h>
#include <conio.h>

long factorial (int x);

void main ()
{

int n;
long r;
printf ("Ingrese un numero: ");
scanf ("%d",& n);
r=factorial(n);
printf ("%ld", r);
}

long factorial (int x)
{
if (x==1)
	return 1;

return (x*factorial(x-1));
}
