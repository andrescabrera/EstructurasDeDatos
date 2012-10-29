/*
Imprimir un texto caracter a caracter hasta EOF y
mostrarlo invertido en forma recursiva.
*/
#include <stdio.h>
#include <stdlib.h>
void invertir(char c);

int main()
{
    char c;

    c=getchar();
    invertir(c);
    putchar(c);

    return 0;
}

void invertir(char c)
{
    if(c!='\n')
        invertir(c=getchar());

        putchar(c);

}

