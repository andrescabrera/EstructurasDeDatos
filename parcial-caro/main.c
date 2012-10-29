#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int num;
    struct lista *sig;
} nodo;

void cargar(nodo *p);
void mostrar(nodo *p);

nodo *agregar(nodo *p, nodo *m);
//nodo *insertar(nodo *p, int n);

nodo *insertar(nodo *p, nodo *m);
// nodo *eliminar(nodo *p);

int main()
{
    nodo *p1;
    nodo *p2;
    p1 = (nodo*)malloc(sizeof(nodo));
    p2 = (nodo*)malloc(sizeof(nodo));
    cargar(p1);
    printf("\n");
    cargar(p2);
    mostrar(p1);
    printf("\n");
    mostrar(p2);
    p1= agregar(p1, p2);
    printf("\n");
    mostrar(p1);
 //   p1 = eliminar(p1);
  //  printf("\n");
  // mostrar(p1);
    return 0;
}

void cargar(nodo *p)
{
    printf("\nIngrese un numero entero mayor al anterior (-1 para terminar):");
    scanf("%d", &p->num);
    if(p->num == -1)
        p->sig = NULL;
    else
    {
        p->sig = (nodo*)malloc(sizeof(nodo));
        cargar(p->sig);
    }
    return;
}

void mostrar(nodo *p)
{
    if(p->sig != NULL)
    {
        printf("\n%d", p->num);
        mostrar(p->sig);
    }
    return;
}


nodo *agregar(nodo *p, nodo *m)
{
    while(m->sig!=NULL)
    {
        p=insertar(p, m);
        m=m->sig;
    }
    return p;
}

nodo *insertar(nodo *p, nodo *m)
{

    nodo *aux;

    if (p->num >= m->num)
    {
    //    temp=p;
        m->sig=p;
        p=m;
    }
    else
    {
        aux=p;
        while(aux->sig!=NULL)
        {
            if( aux->sig->num >= m->num)
            {
                aux->sig=m;
                m->sig=aux->sig;
            }
            else
                aux=aux->sig;
        }
        if(aux->sig==NULL)
        {
            aux->sig=m;
            m->sig=NULL;
        }
    }

    return p;
}


/*---------------------------------
nodo *agregar(nodo *p, nodo *m)
{
    while(m->sig!=NULL)
    {
        p=insertar(p, m->num);
        m=m->sig;
    }
    return p;
}

nodo *insertar(nodo *p, int n)
{
    nodo *aux;
    nodo *temp;

    if ( p->num >= n)
    {
        temp=(nodo*)malloc(sizeof(nodo));
        temp->num=n;
        temp->sig=p;
        p=temp;
    }
    else
    {
        aux=p;
        while(aux->sig!=NULL)
        {
            if( aux->sig->num >= n)
            {
                temp=(nodo*)malloc(sizeof(nodo));
                temp->num = n;
                temp->sig=aux->sig;
                aux->sig=temp;
            }
            else
                aux=aux->sig;
        }
//       if(aux->sig==NULL)
//       {
        temp=(nodo*)malloc(sizeof(nodo));
        temp->num = n;
        temp->sig=NULL;
        aux->sig=temp;
    }
    return p;
}



nodo *eliminar(nodo *p)
{
    nodo *aux;
    nodo *temp;

    while (p->num%2==0)
    {
        temp=p->sig;
        free(p);
        p=temp;
    }

    aux = p;
    while(aux->sig != NULL)
    {
        if (aux->sig->num%2==0 && aux->sig->sig!=NULL)
        {
            temp = aux->sig->sig;
            free(aux->sig);
            aux->sig=temp;
        }
        else
            aux = aux->sig;
    }

    return p;
}

*/
