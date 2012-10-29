/*
Andr�s Cabrera - Ejercicio 3, Trabajo Pr�ctico 2

3. Leer un texto car�cter por car�cter terminando en EOF.
Contar palabras terminadas en �n� y mostrarlas pas�ndolas al plural.
(el cami�n > el camionES)

*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c, ult;

    printf("Ingresar un texto caracter a caracter terminando con EOF.\n");

    c=getchar();

    while(c==' ')
    {
        putchar(c);
        c=getchar();
    }

    while(c!=EOF)
    {
        while(c!=EOF && c!=' ')
        {
            putchar(c);
            ult=c;
            c=getchar();
        }
        if(ult == 'n')
        {
            putchar('E');
            putchar('S');
        }

        while(c==' ')
        {
            putchar(c);
            c=getchar();
        }
    }

    return 0;
}
