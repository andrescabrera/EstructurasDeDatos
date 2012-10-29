#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, max, num;
    printf("Ingresa el numero: ");
    scanf("%d",&num);
    max=num;

    for (i=1;i<10;i++)
    {
        printf("ingrese otro numero: ");
        scanf("%d",&num);
        if (num>max)
        {
            max=num;
        }
    }
    printf("el maximo es %d",max );

    return 0;
}
