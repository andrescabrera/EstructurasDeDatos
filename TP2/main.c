//Andrés Cabrera - Trabajo Práctico 2 - Ejercicio 1
#include <stdio.h>
#include <stdlib.h>

int main()
{
int c,cont=0,aux;
c=getchar();
   while(c==' '){
     putchar(c);
     c=getchar();
   }
aux=c;
putchar(c);
   while(c!=EOF){

      c=getchar();
      if(c!=EOF){
             if(c==aux){

             putchar('=');
             cont++;
             }
       putchar(c);
       aux=c;

       }
   }

printf("\nHay %d letras consecutivas iguales",cont);
return EXIT_SUCCESS;
}
