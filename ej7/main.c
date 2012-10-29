#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c;
    int cont=0;

    printf("Ingrese un texto caracter a caracter terminando con EOF.");
    c=getchar();

    //paso blancos
    while(c==' ')
    {
        putchar(c);
        c=getchar();
    }

    //entro en palabra
    while(c!=EOF)
    {
        if(c=='o')
        {
            putchar(c);
            c=getchar();
            if(c=='n')
            {
                putchar(c);
                c=getchar();
                if(c==' ' || c==EOF)
                    cont++;
            }
        }
        else
        {
            putchar(c);
            c=getchar();
        }



        while(c==' ')
        {
            putchar(c);
            c=getchar();
        }
    }

    printf("Hubieron %d palabras terminadas en on", cont);

    return 0;
}
