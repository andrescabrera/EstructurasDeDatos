#include <stdio.h>
#include <stdlib.h>

int main()
{
int c;

c=getchar();

while(c==' '){
    putchar(c);
    c=getchar();
}

while(c!=EOF){
if(c=='v'){
    c=getchar();
    if(c=='l'){
        putchar('b');
    }else
        if(c!=EOF&&c!=' ') putchar('v');

    putchar(c);
}

while(c==' '){
    putchar(c);
    c=getchar();
}
}


return EXIT_SUCCESS;
}
