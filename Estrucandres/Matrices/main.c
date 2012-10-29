#include <stdio.h>
#include <stdlib.h>
#define TAM 5

void cargar(int mat[][], int n);
void mostrar(int mat[][], int n);
int sumafila(int mat[TAM][TAM], int x, int tam);
int maycol(int mat[TAM][TAM], int y, int tam);
void promultmat(int mat[TAM][TAM], int tam, int mult);
void sumdiagprin(int mat[TAM][TAM], int tam);
void elemminfilas(int mat[TAM][TAM], int tam);
int minimofila(int mat[TAM][TAM], int tam, int x);
void mostrardiagsec(int mat[TAM][TAM], int tam);
void debajodiagprin(int mat[TAM][TAM], int tam);
void simetrica(int mat[TAM][TAM], int tam);

int main()
{
int mat[TAM][TAM];
int aux=0, fila=1, col=1, mult=5;

cargar(mat, TAM);
mostrar(mat, TAM);
aux=sumafila(mat, fila, TAM);
printf("La suma de la segunda fila es: %d\n", aux);
aux=maycol(mat, col, TAM);
printf("El mayor elemento de la segunda columna es %d\n", aux);
promultmat(mat, TAM, mult);
sumdiagprin(mat, TAM);
mostrardiagsec(mat, TAM);
debajodiagprin(mat, TAM);
simetrica(mat, tam);

return EXIT_SUCCESS;
}

void cargar(int mat[TAM][TAM], int n){
int i, j;
printf("\n");

 for(i=0;i<n;i++){
    for(j=0;j<n;j++){
    printf("Ingrese numero para %d, %d: ",i,j);
    scanf(" %d", &mat[i][j]);
    }
  }

}

void mostrar(int mat[TAM][TAM], int n){
int i, j;
printf("\n");

for(i=0;i<n;i++){
    for(j=0;j<n;j++) printf("%d \t", mat[i][j]);
    printf("\n");
}
}

int sumafila(int mat[TAM][TAM], int x,  int tam){
int segfila=0, i;

for(i=0;i<tam;i++) segfila+=mat[x][i];

return segfila;
}

int maycol(int mat[TAM][TAM], int y, int tam){
int i, mayelem=mat[0][y];

    for(i=1;i<tam;i++)
        if(mayelem<mat[i][y]) mayelem=mat[i][y];

return mayelem;
}

void promultmat(int mat[TAM][TAM], int tam, int mult){
 int i, j, cont=0;
 float sum=0;
 printf("\n");
 for(i=0;i<tam;i++){
    for(j=0;j<tam;j++){
         if(mat[i][j]%mult==0){
         cont++;
         sum+=mat[i][j];
         }
    }
 }


printf("El promedio de los multiplos de %d es: %f", mult, (sum/cont));
}

void sumdiagprin(int mat[TAM][TAM], int tam){
int i, suma=0;

for(i=0;i<tam;i++) suma+=mat[i][i];

printf("\nLa suma de la diag. principal es: %d", suma);
}

void elemminfilas(int mat[TAM][TAM], int tam){
int i, minfila[TAM]={0};

for(i=0;i<tam;i++){
    minfila[i]=minimofila(mat, tam, i);
    printf("\n El minimo de la fila %d es: %d", i, minfila[i]);
    }
}

int minimofila(int mat[TAM][TAM], int tam, int x){
int i, minimo=mat[x][0];

    for(i=1;i<tam;i++)
        if(minimo<mat[x][i]) minimo=mat[x][i];

return minimo;
}

void mostrardiagsec(int mat[TAM][TAM], int tam){
int i=tam-1, j=0;
printf("\nElementos de la contradiagonal: ");
    for(j=0;j<tam;j++){
        printf(" %d|", mat[i][j]);
        i--;
    }
}

void debajodiagprin(int mat[TAM][TAM], int tam){
int i, j;
printf("\n");

for(i=1;i<tam-1;i++){
    for(j=0;j<tam;j++){
        if(i>j) printf(" %d|", mat[i][j]);
    }
}
}

void simetrica(int mat[TAM][TAM], int tam){
int i, j, cont=0;

for(i=0;i<tam;i++){
    for(j=0;j<tam;j++)
        if(mat[i][j]==mat[j][i]) cont++;
}

if(cont==tam) printf("La matriz es simetrica");
else printf("La Matriz no es simetrica");

}
