#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, f;
    printf("Ingrese la posición: ");
    scanf("%d",&n);
    f=fibo(n);
    printf("%d",f);

    return 0;
}

int fibo(int n)
{
    if((n==1)||(n==2))
        return 1;

    return fibo(n-1)+fibo(n-2);
}
