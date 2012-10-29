#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int num1;
    int num2;
    int sig;
}nodo;

int main()
{
nodo *prin;
prin=(nodo *)malloc(sizeof(nodo));
crear(prin);
mostrar(prin);
}
