#include <stdio.h>
#include <stdlib.h>

int factorial(int n);
void mostrarInvertido(int n);
int main()
{
int n;
n=54321;
printf("El invertido de %d, es: ",n);
mostrarInvertido(n);
printf("\nEl fact. de 4 es %d", factorial(4));

return EXIT_SUCCESS;
}

int factorial(int n)
{
    if(n==0)
        return 1;
    else
        return n*factorial(n-1);
}

void mostrarInvertido(int n)
{
    if(n > 0)
    {
        printf("%d", (n%10));
        mostrarInvertido((n/10));
    }

    return;
}
