/*
1 contar cuantas vocales tiene la frase.
2 contar cuantos blancos tiene la frase
3 contar cuantas veces aparece el grupo 'ta' en la frase
4 contar cuantas palabras terminan en s
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
int c, cont=0, aux;

c=getchar();

while(c!=EOF)
{
aux=c;
putchar(c);
c=getchar();
    if(c==' ' && aux=='s') cont++;
}

printf("Hubieron %d palabras terminadas en s",cont);

return EXIT_SUCCESS;
}
