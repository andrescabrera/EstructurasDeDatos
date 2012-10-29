#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista{

        int edad;
        char nombre[15];
        int matcur;
        int matap;
        struct lista *sig;

}nodo;

void crear(nodo *registro, FILE *punfile);
void mostrar(nodo *registro);

int main()
{
    FILE *punfile;
    if((punfile=fopen("c:\materias.txt","w"))==NULL)
        printf("No se pudo abrir el archivo...");
    else
    {
    nodo *punpri;
    punpri=(nodo *)malloc(sizeof(nodo));
    crear(punpri, punfile);
    printf("\n");
    mostrar(punpri);
    }

    fclose(punfile);
    return EXIT_SUCCESS;
}

void crear(nodo *registro, FILE *punfile)
{
float porc;
printf("\nIngrese nombre (""FIN"" para terminar): ");
scanf(" %s", registro->nombre);
if(strcmp(registro->nombre,"FIN")==0)
        registro->sig=NULL;
else
    {
    printf("\nIngrese Edad: ");
    scanf("%d", &registro->edad);
    printf("\nIngrese Materias Cursadas: ");
    scanf("%d", &registro->matcur);
    printf("\nIngrese Materias Aprobadas: ");
    scanf("%d", &registro->matap);
    porc=(float)(registro->matcur * 100) / registro->matap;
    if(porc>60)
    {
        fprintf(punfile, "%s %d %d %d\n", registro->nombre, registro->edad, registro->matcur, registro->matap);
    }
    registro->sig=(nodo *)malloc(sizeof(nodo));
    crear(registro->sig, punfile);
    }

return;
}

void mostrar(nodo *registro)
{
if(registro->sig!=NULL)
{
    printf("Nombre: %s | Edad %d | Materias Cursadas: %d | Materias Aprobadas: %d\n", registro->nombre, registro->edad, registro->matcur, registro->matap);
    mostrar(registro->sig);
}
return;
}
