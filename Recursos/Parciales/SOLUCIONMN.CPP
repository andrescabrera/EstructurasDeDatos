#include <stdio.h>
#include <stdlib.h>
#define TAM 9
void cargar(int x[], int y[], int n, int *tx, int *ty, int c1, int c2);
void mostrar(int x[],int n);
float promedio(int x[], int n);
int menor(int a, int b);
void ordenar(int x[], int n);
void reducir(int x[], int n, int m);
void comunes(int a[], int b[], int n, int *pI, int *pF);
void swap(int *a, int *b);
void
main()
{
int A[TAM], B[TAM];
int tamA, tamB;
int posI, posF;
char m;
cargar(A, B, TAM, &tamA, &tamB, 2, 3);
printf("\nVector con múltiplos de 2");
mostrar(A, tamA);
printf("\nVector con múltiplos de 3");
mostrar(B, tamB);
printf("%.2f y %.2f", promedio(A, tamA), promedio(B, tamB));
m = menor(tamA, tamB);
if (m == tamA)
	reducir(B, tamB, m);
else
	reducir(A, tamA, m);
printf("\nVector con múltiplos de 2");
mostrar(A, m);
printf("\nVector con múltiplos de 3");
mostrar(B, m);
ordenar(A, m);
ordenar(B, m);
printf("\nVector con múltiplos de 2");
mostrar(A, m);
printf("\nVector con múltiplos de 3");
mostrar(B, m);
comunes(A, B, m, &posI, &posF);
if (posI == m)
	printf("\nNo hay elementos comunes");
else
	printf("\nHay elementos comunes desde %d hasta %d", posI, posF);

}
void swap(int *a, int *b)
{
int aux;
aux =*a;
*a = *b;
*b = aux;
}
void cargar(int x[], int y[], int n, int *tx, int *ty, int c1, int c2)
{
int num;
int i, j, k;
j = 0;
k = 0;
for (i = 0; i < n; i++)
{
	printf("Ingrese un número:");
	scanf("%d", &num);
	if (num%c1 == 0)
	{
		x[j] = num;
                j++;
	}
	if (num%c2 == 0)
	{
		y[k] = num;
                k++;
        }
}
*tx = j;
*ty = k;
}
void mostrar(int x[],int n)
{
int i;
for (i = 0; i < n; i++)
	printf("\n(%d) %d", i, x[i]);
}
float promedio(int x[], int n)
{
int i;
float p, acu = 0;
for (i = 0; i < n; i++)
	acu+= x[i];
if (n > 0)
	p = acu/n;
else p = 0;
return p;
}
int menor(int a, int b)
{
int m;
if (a > b) m = b;
else m = a;
return m;
}
void ordenar(int x[], int n)
{
int i, j;
for (i = 0; i < n-1; i++)
	for (j = i + 1; j < n; j++)
		if (x[i] > x[j])
                	swap(&x[i], &x[j]);

}
void comunes(int a[], int b[], int n, int *pI, int *pF)
{
int i;
int j;
*pI = n;
*pF = 0;
for (i = 0; i < n; i++)
	for (j = 0; j <n; j++)
		if (a[i] == b[j])
		{
			if (i < *pI)
				*pI = i;
			if (i > *pF)
                        	*pF = i;
                }


}
void reducir(int x[], int n, int m)
{
int i;
int j;
j = n - m;/*Cantidad de posiciones que se eliminan*/
for (i = 0; i < m; i++)
{
	x[i] = x[j];
        j++;
}
}