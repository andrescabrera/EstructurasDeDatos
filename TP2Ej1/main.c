/*
Andr�s Cabrera - Ejercicio 1, Trabajo Pr�ctico 2

1.	Leer un texto car�cter por car�cter terminando en EOF.
    Contar cu�ntas veces aparecen dos letras iguales.
    Mostrarlas intercal�ndoles el signo �=�.

    Ejemplo: �sooolo see que no see naaddaaa.�
    En 8 oportunidades hay dos letras iguales juntas. �so=o=olo se=e que no se=ena=ad=da=a=a�
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c, ant;
    int cont = 0;

    printf("\nIngresar un texto caracter a caracter terminando con EOF.\n");

    c=getchar();
    while(c==' ')
    {
        putchar(c);
        c=getchar();
    }

    while(c!=EOF)
    {
        ant=c;
        putchar(c);
        c=getchar();
        if(ant == c)
        {
            putchar('=');
            cont++;
        }

        while(c==' ')
        {
            putchar(c);
            c=getchar();
        }
    }
    printf("\nEn %d oportunidades hay dos letras iguales juntas.", cont);

    return 0;
}
