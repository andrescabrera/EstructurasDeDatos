/*
Andrés Cabrera - Ejercicio 3, Trabajo Práctico 2

3. Leer un texto carácter por carácter terminando en EOF.
Contar palabras terminadas en “n” y mostrarlas pasándolas al plural.
(el camión > el camionES)

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
