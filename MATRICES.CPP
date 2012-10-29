#include <stdio.h>
#include <conio.h>

void cargar (int a[5][5],int n);
void mostrar (int a[5][5],int n);
void alterar (int a[5][5], int n);
int maximo (int a[5][5], int n);
int promedio (int a[5][5], int n);
void suma (int a[5][5], int n);

void main ()
{
clrscr();
int a[5][5],n, max, prom;
printf("\n Ingrese dimension");
scanf("%d",&n);
cargar (a,n);
mostrar (a,n);
printf ("\nLa matriz alterada es: \n");
alterar (a,n);
max= maximo (a,n);
printf ("\nEl maximo de la cuarta fila es %d", max);
prom=promedio(a,n);
printf ("\nEl promedio de la tercera columna es %d", prom);
suma (a,n);
getch();
}

void cargar (int a[5] [5], int n)
{
int i, j;
for (j=0; j<n; j++)
	for (i=0; i<n; i++)
		{
		printf ("\nIngrese un elemento: ");
		scanf ("%d",& a[i][j]);
		}
return;
}

void mostrar (int a[5][5], int n)
{
int i, j;
for (j=0; j<n; j++)
	{
	for (i=0; i<n; i++)
		{
		printf (" %d", a[i][j]);
		}
	printf ("\n");
	}
return;
}

void alterar (int a[5][5],int n)
{
int i, j;
for (j=0; j<n; j++)
	{
	for (i=0; i<n; i++)
		{
		printf (" %d", a[j][i]);
		}
	printf ("\n");
	}
return;
}

int maximo (int a[5][5], int n)
{
int i=4, j, max=a[4][0];
	for (j=0; j<n; j++)
		{
		if (a[i][j]>max)
			max=a[i][j];
                }
return max;
}

int promedio (int a[5][5], int n)
{
int i, j=2, suma=0, prom=0;
	for (i=0; i<n; i++)
		suma=suma+a[i][j];
prom=suma/n;
return prom;
}

void suma (int a[5][5],int n)
{
int i, j=0, suma=0;
for (i=0; i<n; i++)
	{
	j++;
	suma=suma+a[i][j];
	}
printf ("\nLa suma es %d", suma);
return;
}