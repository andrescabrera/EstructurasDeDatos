#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct cola {
             int data;
     struct cola *sig;
                    } nodo;
void mostrar(nodo *);
int sacar(nodo **, nodo **);
void agregar(nodo **, nodo **, int);
int menu();

void main()
 {
nodo *cabeza=NULL, *fin=NULL;
int op, valor, x;
do {
op=menu();
switch(op) 
   {
  case 1: printf("ingrese un valor: ");
	  scanf("%d", &valor);
	  agregar(&cabeza, &fin, valor);
	  printf("\n");
	  mostrar(cabeza);
	  continue;
  case 2: if (cabeza == NULL)
                     printf("\n VACIA!\n");
            	  else {
	           x=sacar(&cabeza, &fin);
               	   printf("\n el valor eliminado es %d\n", x);
               	       }
          mostrar(cabeza);
	  continue;
  case 3: printf("\nFin proceso\n");
	  continue;
     }
  } while (op != 3);
return;
}

int menu()
 {
int op;
printf("1. Agregar\n");
printf("2. Sacar\n");
printf("3. Fin\n");
do {
  printf("\n Opcion: ");
  scanf("%d", &op);
  if (op<1 || op>3)
              printf("ERROR!\n");
   } while (op<1 || op>3);
return op;
 }

void agregar(nodo **cabeza, nodo **fin, int valor)
 {
nodo *nuevo;
nuevo=(nodo *)malloc(sizeof(nodo));
if (nuevo != NULL)
     {
      nuevo->data=valor;
      nuevo->sig=NULL;
      if (*cabeza == NULL)
               *cabeza=nuevo;
            else
               (*fin)->sig=nuevo;
      *fin=nuevo;
      }
    else
       printf("NO MEMORY!\n");
return;
}

int sacar(nodo **cabeza, nodo **fin)
 {
  int valor;
  nodo *temp;
  valor=(*cabeza)->data;
  temp=*cabeza;
  *cabeza=(*cabeza)->sig;
  if (*cabeza == NULL) 
          *fin=NULL;
  free(temp);
return valor;
}

void mostrar(nodo *cola)
 {
   lo tratamos como una lista
}