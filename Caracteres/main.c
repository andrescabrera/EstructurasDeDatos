#include <stdio.h>
#include <stdlib.h>

int main()
{

int c, cont=0;
c=getchar();

while(c!=EOF)
{
    putchar(c);
    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
        cont++;
    c=getchar();
}

printf("Hubo %d vocales",cont);

return EXIT_SUCCESS;
}
