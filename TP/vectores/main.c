//Usando vectores de cadenas de caracteres y vectores de enteros, cargar empleados
//encontrar, contar y mostrar empleados que tienen el mismo sueldo.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define tam 5

int main()
{
    int i, j, cont=0, emple=0;
    float sueldo[tam];
    char nombre[tam][20];

    for (i=0;i<tam;i++)
    {
        printf("Ingrese el nombre de los empleados: ");
        scanf(" %[^\n]", nombre[i]);
        printf("Ingrese el sueldo de %s: ", nombre[i]);
        scanf("%f", &sueldo[i]);
    }

    for (i=0;i<tam;i++)
    {
        printf("\nNombre: %s\t",nombre[i]);
        printf("|\t Sueldo %.2f",sueldo[i]);
    }
    //entro en la persona
    for (i=0;i<tam;i++)
    {
        cont=0;
        //comparacion
        for (j=i+1;j<tam-1;j++)
        {
            if(sueldo[i]==sueldo[j])
            {
                printf("%s tiene el mismo sueldo que %s\n", nombre[j], nombre[i]);
                cont++;

            }
        }
    if(cont!=0)
        emple+=(cont+1);


    }

    if(emple!=0)
        printf("\nHubo %d empleados con el mismo sueldo.", emple);



    return EXIT_SUCCESS;
}

