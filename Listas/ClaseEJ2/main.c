#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista
{
    char nom[15];
    int edad;
    float sueldo;
    struct lista *sig;
}nodo;

void crear(nodo *, FILE *punfile);
void mostrar();

int main()
{
FILE *punfile;
nodo *prin; //defino puntero a lista

prin=(nodo *)malloc(sizeof(nodo)); //inicializo punt. a lista
crear(prin, punfile);

return EXIT_SUCCESS;
}

void crear (nodo *registro){
FILE *punfile;
if((punfile=fopen("f:lista.dat","w"))==NULL)
    printf("No se pudo abrir el archivo!");
    else
    {
    printf("Ingrese nombre: (""FIN"" para terminar): ");
    scanf("%s",registro->nom);
    while(strcmp(registro->nom,"FIN")==0)
        {
        printf("\nIngrese Edad: ");
        scanf("%d",&registro->edad);
        printf("\nIngrese Sueldo: ");
        scanf("%f",&registro->sueldo);
        fprintf(punfile,"%s %d %.2f\n",registro->nom,registro->edad,registro->sueldo);
        registro->sig=(nodo *)malloc(sizeof(nodo));
        registro=registro->sig;
        printf("Ingrese nombre: (""FIN"" para terminar): ");
        scanf("%s",registro->nom);
        }
        registro->sig=NULL;
    }

fclose(punfile);
return;
}
/*
void mostrar()
{
FILE *punfile;

printf("Leyendo desde archivo...");
if((punfile=fopen("e:\clientes.dat","r"))==NULL)
    printf("\nNo se pudo abrir el archivo!");
    else
    {
        while(!feof(punfile))
        {
	    fscanf(punfile,"%s  %d  %f\n", registro->nom, &registro->edad, &registro->sueldo);
	    printf("Nombre: %s | Edad: %d | Sueldo: %.2f\n", registro->nom, registro->edad, registro->sueldo);
        }
	}
fclose(punfile);

return;
}
*/
