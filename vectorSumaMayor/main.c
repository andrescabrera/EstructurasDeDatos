#include <stdio.h>
#include <stdlib.h>
#define TAM 5

int vectorESuma(int A[], int n);
int vectorEMayor(int A[], int n, int mayor);

int main()
{
int resul, may;
int V[TAM]={6,2,10,4,20};

resul=vectorESuma(V, TAM-1);
printf("res vale: %d\n",resul);

may=vectorEMayor(V,TAM-1,V[TAM-1]);
printf("el mayor es: %d",may);

return EXIT_SUCCESS;
}

int vectorESuma(int A[], int n)
{
    int resultado;

    if(n==0)
        resultado=A[0];
    else
        resultado=A[n]+vectorESuma(A, (n-1));

    return resultado;
}

int vectorEMayor(int A[], int n, int mayor)
{
int prox;

if(n!=0)
{
prox=vectorEMayor(A, (n-1), A[n-1]);
if(mayor < prox)
    mayor=prox;

return mayor;
}
else
if(mayor<A[n]) mayor=A[n];

return mayor;
}
