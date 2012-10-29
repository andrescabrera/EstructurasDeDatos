#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define CANT	8
#define TOPE	45
void cargar(int [], int n, int top);
void mostrar(int [], int n);
void ordenar(int [], int n);
void pasarHM(int, int*, int*);
void extremos(int [], int n, int *inf, int *sup, int desde, int hasta);
int eliminar(int orig[], int n, int desde, int hasta, int nuevo[]);
void swap(int *a, int *b);
int
main()
{
int minutos[CANT];
int h, m;
int a, b;
int nuevo[CANT];
int tam;
clrscr();
cargar(minutos, CANT, TOPE);
printf("Vector original:\n");
mostrar(minutos, CANT);
ordenar(minutos, CANT);
printf("Vector ordenado:\n");
mostrar(minutos, CANT);
pasarHM(minutos[0], &h, &m);
printf("\n%d equivale a %d:%d", minutos[0], h, m);
extremos(minutos, CANT, &a, &b, 3*60, 4*60);
printf("\nInteresan las posiciones %d - %d", a, b);
tam = eliminar(minutos, CANT, a, b, nuevo);
if (tam > 0)
{
	printf("Vector original con menos elementos:\n");
	mostrar(minutos, CANT-tam);
	printf("Vector nuevo:\n");
	mostrar(nuevo, tam);
}else
	printf("\nNo pudo eliminarse nada");
getch();
return EXIT_SUCCESS;
}
void cargar(int vec[], int n, int top)
{
int i;
for (i = 0; i < n; i++)
{
	do
	{
		printf("Valor %d:", i);
		scanf("%d", &vec[i]);
	}while(vec[i] <top);
}
}
void mostrar(int vec[], int n)
{
int i;
for(i = 0;i < n; i++)
	printf("\n(%d) %d", i, vec[i]);
}
void swap(int *a, int *b)
{
int aux;
aux = *a;
*a = *b;
*b = aux;
}
void ordenar(int vec[], int n)
{
int i, j;
for (i = 0; i < n-1; i++)
	for(j = i+1; j < n; j++)
		if (vec[i] > vec[j])
			swap(&vec[i], &vec[j]);
}
void pasarHM(int todos, int *h, int *m)
{
	(*h)= todos/60;
	(*m)= todos%60;
}
void extremos(int vec[], int n, int *inf, int *sup, int desde, int hasta)
{
	int i;
	i = 0;
	/*busco el primer valor en el intervalo*/
	while(i < n && vec[i]<desde)
		i++;
	if (i!=n)
		(*inf)=i;
	while(i < n && vec[i]<=hasta)
		i++;
	if (i<n)
		(*sup)=i-1;

}
int eliminar(int orig[], int n, int desde, int hasta, int nuevo[])
{
int i, j, k;
for (i = desde +1, j = hasta, k=0; i < hasta && j < n; i++)
{
	nuevo[k] = orig[i];
	k++;
	orig[i] = orig[j];

}
return k;
}
