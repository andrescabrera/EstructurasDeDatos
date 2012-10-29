# include<stdio.h>
# include<conio.h>
# include<stdlib.h>

typedef struct arbol
{
  int mat;
  struct arbol *der;
  struct arbol *izq;
}nodoarbol;

void mostrar (nodoarbol *r);
nodoarbol *crearnodo(int m);
void insertar (nodoarbol **raiz, int nuevodato);



void main()
{
nodoarbol *r;
int num ;
printf ("ingrese numero");
   scanf("%d",&num);

while (num!=0){

   insertar(&r,num);
   printf ("ingrese numero");
   scanf("%d",&num);
   }
mostrar(r);
}

nodoarbol *crearnodo(int m)
{
nodoarbol *t;
t=(nodoarbol *)malloc(sizeof(nodoarbol));
t->mat=m;
t->der=NULL;
t->izq=NULL;
return t;
}

void insertar (nodoarbol **raiz, int nuevodato)
{
if (!*raiz)
   *raiz=crearnodo(nuevodato);
else
   if (nuevodato < (*raiz)->mat)
   insertar( &(*raiz)->izq, nuevodato);
   else
   if (nuevodato > (*raiz)->mat)
   insertar( &(*raiz)->der, nuevodato);

return;
}

void mostrar (nodoarbol *r)
{
 if (r!=NULL)
 {
   mostrar(r->izq);
   printf("%d\n",r->mat);
   mostrar(r->der);
 }
}





