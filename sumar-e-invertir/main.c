#include <stdio.h>
#include <stdlib.h>

int sumarCifras(int n);
void invertirNumero(int n);

int main()
{
    int res;

    res=sumarCifras(4548);
    printf("Res vale: %d\n", res);
    invertirNumero(4548);
    return EXIT_SUCCESS;
}

int sumarCifras(int n)
{
    int resultado;
    if(n>0)
    resultado=((n%10)+(sumarCifras(n/10)));

return resultado;
}

void invertirNumero(int n)
{
    if(n > 0)
    {
        printf("%d", (n%10));
        invertirNumero((n/10));
    }
}
