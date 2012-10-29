#include <stdio.h>
#include <stdlib.h>
#define TAM 10

void cargar(int x[], int y[], int n, int c1, int c2, int *ty);
void mostrar(int x[], int n);
void comunes(int x[], int y[], int n, int ty);
void desplazar(int x[], int n);
void minimo(int x[], int n, int *pmay, int *min);
void intercalar(int x[], int y[], int n);

int main()
{
    int x[TAM];
    int y[TAM];
    int tamy;
    int menor = 0, mayor = 0;

    cargar(x, y, TAM, 3, 5, &tamy);
    mostrar(x, TAM);
    mostrar(y, tamy);
    comunes(x, y, TAM, tamy);
    desplazar(x, TAM);
    minimo(y, tamy, &mayor, &menor);
    if(mayor!=0) printf("\nEl minimo es: %d, y el sig. mayor al minimo %d", menor, mayor);
    intercalar(x, TAM);

    return EXIT_SUCCESS;
}

void cargar(int x[], int y[], int n, int c1, int c2, int *ty){
    int num, i = 0, k = 0;

    while(i < n){

        printf("\nIngrese un numero: ");
        scanf("%d", &num);

        if(num%c1 == 0 && num%2 != 0){
        x[i] = num;
        i++;
        }
        if(num%c2 == 0){
        y[k] = num;
        k++;
        }
    }

    *ty = k;
}

void mostrar(int x[], int n){
    int i;
    printf("\n");
    for(i=0 ; i<n ; i++){
        printf("%d | ",x[i]);

 }

}

void comunes(int x[], int y[], int n, int ty){
    int z[n];
    int i, j, k = 0;
    for(i = 0; i < n; i++)
        for(j = 0; j < ty; j++)
            if(x[i]==y[j]){
                z[k]=x[i];
                k++;
            }
    mostrar(z, k);
}

void desplazar(int x[], int n){
 int i;

 for(i=n-1;i>3;i--)
     x[i]=x[i-2];

 x[2]+=5;
 x[3]+=5;

 mostrar(x, n);
}

void minimo(int x[], int n, int *pmay, int *min){
    int i, minimo, pmin = 0, posmay;
    minimo=x[0];
    for(i=1 ; i < n-1; i++){
        if(minimo>x[i]){
            minimo=x[i];
            pmin=i;
        }
    }

    *min=minimo;
    posmay=pmin;
    i=pmin;

    while(posmay==pmin && i<n){
    i++;
        if(x[i]>minimo){
        *pmay=x[i];
        posmay=i;
        }
    }

}

void intercalar(int x[], int y[], int n){
 int i, j=1, z[], k=0;

 for(i=0;i<n;i+2){

        z[i]=x[k];
        z[j]=y[k];
        k++;
        j+2;


 }
mostrar(z, n);
}
