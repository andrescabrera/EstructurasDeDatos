#include <stdio.h>
#include <stdlib.h>

int esPar(unsigned n);
int esImpar(unsigned n);

int main(){

    int tipo;
    tipo=esImpar(8);
    printf("el tipo es: %d",tipo);


    return EXIT_SUCCESS;
}


int esPar(unsigned n)
{
    if (n == 0)
        return 1;
    else
        return esImpar(n-1);
}

int esImpar(unsigned n)
{
    if (n == 1)
        return 1;
    else
        return esPar(n-1);
}
