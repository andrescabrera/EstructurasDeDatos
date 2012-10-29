/*
Javier Amuy - Encontrar edades iguales, contarlas y mostrar el nombre de la(s) persona(s).

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int i,edad,edad2,cont=0;
    char nombre2[30],ganador[30]="Juancho Talarga";
    printf("Ingrese la edad de Juancho Talarga: ");
    scanf("%d",&edad);

    for (i=1;i<5;i++)
    {
        printf("ingresa tu sucio nombre: ");
        scanf(" %[^\n]",nombre2);
        printf("ingrese la otra edad: ");
        scanf("%d",&edad2);
        if (edad==edad2)
        {
            cont++;
            printf("\nel tipo: %s tiene la misma edad que Juancho\n",nombre2);
            if (cont==2)
            {
                strcpy(ganador,nombre2);

            }
        }
    }
    if (cont==0)
    {
        printf("No hay edades iguales");
    }
    else
        printf("Si hubo edades iguales a %d y fueron %d",edad,cont);

    if (strcmp(ganador,"Juancho Talarga")!=0)
    {
        printf("\n%s se gano 1.000.000 de dólares en efectivo \ny un viaje a amsterdam con mucha marimba\n",ganador);
    }

    return EXIT_SUCCESS;

}
