//Andrés Cabrera - Trabajo Práctico 2 - Ejercicio 2
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int cont=1,c, veces=0,aux;

	printf("\nIngrese  un texto caracter a caracter. Termina con EOF\n");
	c=getchar();
	while (c==' ')
	{
		putchar(c);
		c=getchar();
	}
	aux=c;
      putchar(c);
      c=getchar();
      while (c!=EOF)
	{	//Pase los blancos y entré: ya estoy dentro de una palabra.

		while (c!=EOF &&c!=' ')
		{
			putchar(c); //lo muestro
			if(c==aux)
                     cont++;
                   c=getchar();
		}
		//fin de palabra. Me fijo si habia mas de una letra igual ala primera.
		if (cont>1)
		{
			veces++;
			cont=0;
			}
		//paso los espacios en blanco que hubiera.
		while (c==' ')
		{
			putchar(c);
			c=getchar();
		}
	}
	printf("\nHabía %d palabras CON MAS DE UNA VEZ LA PRIMERA LETRA.",veces);

	return EXIT_SUCCESS;
}
