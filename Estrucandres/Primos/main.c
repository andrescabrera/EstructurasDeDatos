//desarrollar un programa que genere un vector con los 15 primeros numeros primos
//PRIMER PARCIAL 30 de Septiembre (Listas)
//SEGUNDO PARCIAL 11 de Noviembre (Arboles binarios)
//las 2 clases sig. los recuperatorios

#include <stdio.h>
#include <stdlib.h>
#define TAM 15

void cargar(int vec[], int tamano);
int candivi(int numero);
void mostrar(int vec[], int n);

int main()
{

int vectp[TAM];

cargar(vectp, TAM);
mostrar(vectp, TAM);

return EXIT_SUCCESS;
}

void cargar(int vec[], int tamano){
int num=2, cant=1;
vec[0]=1;

while(cant<tamano){
    if(candivi(num)==2){
        vec[cant]=num;
        cant++;
    }
    num++;
}
}

int candivi(int numero){
int i, cdivi=1;

for(i=1;i<numero;i++){

    if(numero%i==0){
    cdivi++;
    }
}
return cdivi;
}

void mostrar(int vec[], int n){
int i;
printf("\n");

for(i=0;i<n;i++)
    printf(" %d |",vec[i]);
}
