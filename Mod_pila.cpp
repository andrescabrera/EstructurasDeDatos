#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
typedef struct pila {
int data;
struct pila *sig;
} nodo;
void agregar(nodo **, int);
int sacar(nodo **);
void mostrar(nodo *);
int menu();
void main() {
nodo *stack=NULL;
int valor, x, op;
do {
op=menu();
switch(op) {
	case 1: printf("ingrese un valor: ");
		scanf("%d", &valor);
		agregar(&stack, valor);
		printf("PILA\n");
		mostrar(stack);
		break;
	case 2: if (stack == NULL) printf("vacio!");
		else {
		 x=sacar(&stack);
		 printf("\n");
		 printf("el valor eliminado es %d\n", x);
		}
		 printf("PILA\n");

	  mostrar(stack);
	  break;
  case 3: printf("fin de proceso\n");
}
} while(op != 3);
}
int menu() {
int op;
printf("1. Agregar\n");
printf("2. Sacar\n");
printf("3. Fin\n");
do {
printf("\n Opcion: ");
scanf("%d", &op);
if (op<1 || op>3) printf("ERROR!\n");
} while (op<1 || op>3);
return op;
}
void agregar(nodo **prim, int info) {
nodo *nuevo;
nuevo=(nodo *)malloc(sizeof(nodo));
if (nuevo != NULL) {
nuevo->data=info;
nuevo->sig=*prim;
*prim=nuevo;
} else printf("no hay memoria\n");
return;
}
int sacar(nodo **prim) {
nodo *temp;
int valor;
temp=*prim;
valor=(*prim)->data;
*prim=(*prim)->sig;
free(temp);
return(valor);
}
void mostrar(nodo *prim) {
if(prim!=NULL){
									printf("%d\n ",prim->data);
								 mostrar(prim->sig);
									}
                  return;

}
