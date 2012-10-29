#include <stdio.h>
#include <stdlib.h>

int main()
{
int c, cont=0, pal3=0;

c=getchar();
while(c!=EOF){
while(c!=EOF&&c==' ')
{
    putchar(c);
    c=getchar();
}

while(c!=EOF&&c!=' ')
{
    putchar(c);
    cont++;
    c=getchar();
}

if(cont>3) pal3++;
cont=0;

}
printf("Hubieron %d palabras con mas de 3 letras",pal3);
return EXIT_SUCCESS;
}
