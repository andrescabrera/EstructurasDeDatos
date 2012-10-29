#include <stdio.h>
#include <stdlib.h>

int main(){
int c, cont=0;

c=getchar();

while(c!=EOF){
putchar(c);
if(c=='t')
{
    c=getchar();
    if(c=='a'){
        putchar(c);
        cont++;
    }
}

c=getchar();
}
printf("Hubieron %d grupos ta",cont);

return EXIT_SUCCESS;
}
