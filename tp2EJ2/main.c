/*
Andrés Cabrera - Ejercicio 2, Trabajo Práctico 2

Leer un texto carácter por carácter terminando en EOF.
Reemplazar grupos “y” por “ll”.
(le yovio a la yama que yama le llovio a la llama que llama).

*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c;
    printf("\nIngresar un texto caracter a caracter terminando con EOF.\n");

    //pidolaprimera
    c=getchar();

    //pasoblancos
    while(c==' ')
    {
        putchar(c);
        c=getchar();
    }

    //entro en palabra
    while(c!=EOF)
    {
        if(c=='y')
        {
            putchar('l');
            putchar('l');
        }
        else
            putchar(c);

        c=getchar();

        //pasoblancos
        while(c==' ')
        {
            putchar(c);
            c=getchar();
        }
    }
    return 0;
}
