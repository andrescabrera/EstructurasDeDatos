#include <stdio.h>
#include <stdlib.h>
typedef struct lista
{
    char nom[15];
    char dni[8];
    char cuenta;
    float saldo;
    struct lista *sig;
}nodo;

void crear(nodo *pt);
void mostrar(nodo *pt);
int buscar(nodo *pt, char dni);

int main()
{
nodo *prin; //defino puntero a lista
prin=(nodo *)malloc

}
