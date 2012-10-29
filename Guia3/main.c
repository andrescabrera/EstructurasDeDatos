#include <stdio.h>
#include <stdlib.h>

int main()
{
int c, cont=0, pal=0, aux;

c=getchar();

while(c==' '){
  putchar(c);
  c=getchar();
}

while(c!=EOF){

cont++;
aux=c;
putchar(c);
c=getchar();

    while(c!=EOF&&c!=' '){
    cont++;
    aux=c;
    putchar(c);
    c=getchar();
    }

    if(c==' '&&aux=='s'&&cont>2)
        pal++;

    while(c==' '){
    putchar(c);
    c=getchar();
    }

cont=0;
}

printf("\n%d palabras que terminan en S y tienen mas de 2 letras", pal);

return EXIT_SUCCESS;
}
