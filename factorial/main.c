#include <stdio.h>
#include <conio.h>

long factorial (int x);

void main ()
{
clrscr();
int n;
long r;
printf ("Ingrese un numero: ");
scanf ("%d",& n);
r=factorial(n);
printf ("%ld", r);
getch();
}

long factorial (int x)
{
if (x==1)
	return 1;
return (x*factorial(x-1));
}
