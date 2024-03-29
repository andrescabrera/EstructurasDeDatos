/*
Andr�s Cabrera -
Cargar una matriz de n filas y n columnas en forma recursiva. Generar un archivo con aquellos n�meros m�ltiplos de 3 y de 7.
Mostrar dicho archivo.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 6

void mostrar(int mata[][], int n, int fila, int col);
void cargar(int mata[][], int n, int fila, int col);
void multiplos(int mata[][], int n, int fila, int col, int cond1, int cond2, FILE *punfile);
void leer(FILE *punfile);

int main()
{
    int n;
    FILE *punfile;

    do
    {
        printf("Ingrese orden de la matriz: ");
        scanf("%d", &n);
    }
    while (n<1||n>TAM);

    int mata[n][n], fila=n, col=n;

    srand((int)time(NULL));
    cargar(mata, n, fila, col);
    fila=0;
    col=0;
    mostrar(mata, n, fila, col);
    if ((punfile=fopen("c:\\multiplos.txt","w"))==NULL)
        printf("\n No se puede Abrir!!");
    else
        multiplos(mata, n, fila, col, 3, 7, punfile);
    fclose(punfile);
    if ((punfile=fopen("c:\\multiplos.txt","r"))==NULL)
        printf("No se pudo abrir el archivo...");
    else
    {
        printf("\n\n\n");
        leer(punfile);
    }
    fclose(punfile);
    return EXIT_SUCCESS;
}

void cargar(int mata[][TAM], int n, int fila, int col)
{

    mata[fila][col]=rand()%200; //tiene que ir por fuera para q se cargue el primero!!!!!!!!
    if (fila!=0 || col!=0)
    {
        if (col>0)
            cargar(mata, n, fila, col-1);
        else
            if (fila>0)
                cargar(mata, n, fila-1, n);
    }

    return;
}

void mostrar(int mata[][TAM], int n, int fila, int col)
{
    printf(" %d |", mata[fila][col]); //tiene que estar afuera para mostrar nxn
    if (fila!=n || col!=n)
    {
        if (col!=n)
            mostrar(mata, n, fila, col+1);
        else
            if (fila!=n)
            {
                printf("\n");
                mostrar(mata, n, fila+1, col-col);
            }
    }

    return;
}

void multiplos(int mata[][TAM], int n, int fila, int col, int cond1, int cond2, FILE *punfile)
{
    int aux = mata[fila][col];
    if (aux%cond2==0 || aux%cond2==0)
        fprintf(punfile, "%d\n", aux);

    if (fila!=n || col!=n)
    {
        if (col!=n)
            multiplos(mata, n, fila, col+1, cond1, cond2, punfile);
        else
            if (fila!=n)
                multiplos(mata, n, fila+1, col-col, cond1, cond2, punfile);
    }
    return;
}

void leer(FILE *punfile)
{
    int aux;
    if (!feof(punfile))
    {
        fscanf(punfile,"%d\n", &aux);
        printf("%d | ", aux);
        leer(punfile);
    }
}

