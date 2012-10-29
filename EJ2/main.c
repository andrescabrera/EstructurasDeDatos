#include<stdio.h>
#include<stdlib.h>
#include <string.h>

//definiciones de tipo
typedef struct lista{
	char nom [20];
	int edad;
	float sueldo;
	struct lista *sig;
	 }nodo;

//prototipos
int menu;
void crear(nodo *pt);
void mostrar(nodo *pt);

//programa principal
int main(){

nodo *prin;

prin=(nodo *)malloc(sizeof(nodo));
crear(prin);
printf("\n");
mostrar(prin);

return EXIT_SUCCESS;
}

//funcion crear
void crear(nodo *registro){
printf("\nIngrese nombre (Escriba ""FIN"" para terminar): ");
scanf("%s", registro->nom);

if(strcmp(registro->nom,"FIN")==0)
    registro->sig=NULL;
else{
    printf("\nIngrese Edad: ");
    scanf(" %d", &registro->edad);
    printf("\nIngrese Sueldo: ");
    scanf(" %f", &registro->sueldo);
    registro->sig = (nodo*)malloc(sizeof(nodo));
    crear(registro->sig);
}

return;
}

//funcion mostrar
void mostrar(nodo *registro)
{
if(registro->sig != NULL)
{
    printf("Nombre: %s | ", registro->nom);
    printf("Edad: %d | ", registro->edad);
    printf("Sueldo: %.2f |", registro->sueldo);
    mostrar(registro->sig);
}
return;
}
