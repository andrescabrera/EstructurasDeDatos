/*

Estructura de Datos - Viernes - T. Noche - Andr�s Cabrera - Leg. 53231
Ejercicio 5 - Trabajo Pr�ctico 3
5) Ingresar dos n�meros y calcular el m.c.d. en los mismos en forma recursiva.

*/
#include <stdio.h>
#include <stdlib.h>

int mcd(int a, int b);

int main()
{
    int a, b;

    printf("Ingrese a: ");
    scanf("%d",&a);
    printf("Ingrese b: ");
    scanf("%d",&b);

    printf("El MCD es: %d", mcd(a, b));

    return 0;
}

//funcion maximo com�n divisor
int mcd(int a, int b){
    //si B es 0 no necesito continuar
    if(b==0)
        return a;

    else
        return mcd(b, a%b);
}
