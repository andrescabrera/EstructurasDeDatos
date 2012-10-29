#include <stdio.h>
#include <stdlib.h>
#define TAM 9

void cargar(int x[], int n);
void mostrar(int x[], int n);
void ordenardecreciente(int x[], int n);

int main()
{
    int a[TAM];
    cargar(a, TAM);
    mostrar(a, TAM);
    ordenardecreciente(a, TAM);
    mostrar(a, TAM);

    return EXIT_SUCCESS;
}


void cargar(int x[], int n){
    int i;

    for(i=0;i<n;i++){
        printf("\nIngrese numero: ");
        scanf("%d",&x[i]);
    }

    return;
}

void mostrar(int x[], int n){
    int i;
    printf("\n");
    for(i=0;i<n;i++)
        printf("%d | ", x[i]);
}
void ordenardecreciente(int x[], int n){
    int i, j, aux;

    for(i=0;i<n-1;i++){
     for(j=i+1;j<n;j++){
         if(x[i]<x[j]){
             aux=x[i];
             x[i]=x[j];
             x[j]=aux;
         }
     }
    }

 return;
}
