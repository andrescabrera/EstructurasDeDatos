
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <conio.h>


typedef struct lista
{
    int num;
    struct lista *s;
}nodo;

void crear(nodo*);
void mostrar(nodo*);
void c2(nodo*,nodo*);
nodo*ins(nodo*);

int main()
{
    nodo*p;
    nodo*p2;
    p=(nodo*)malloc(sizeof(nodo));
    p2=(nodo*)malloc(sizeof(nodo));
    printf("\nlista 1\n");
    crear(p);
    mostrar(p);
    printf("\nlista 2\n");
    c2(p,p2);
    mostrar(p2);
    printf("\ninserta y elimina\n");
    p=ins(p);
    mostrar(p);
    return 0;
}

nodo*ins(nodo*reg)
{
    nodo*pun;
    nodo*aux;
    nodo*temp;

    if ((reg->num+reg->s->num)>20)
    {
        aux=(nodo*)malloc(sizeof(nodo));
        aux->num=0;
        aux->s=reg;
        reg=aux;
        pun=reg->s->s;
    }
    else
    {
        if ((reg->num+reg->s->num)<10)//borra
        {
            aux=reg->s->s;
            free(reg->s);
            reg->s=aux;
            pun=reg;
        }
    }
    while (pun->s->s!=NULL)
    {
        if ((pun->s->num+pun->s->s->num)>20)
        {
            aux=(nodo*)malloc(sizeof(nodo));
            aux->num=0;
            aux->s=pun->s;
            pun->s=aux;
            pun=pun->s->s->s;
        }
        else
        {
            if ((pun->s->num+pun->s->s->num)<10)//borra
            {
                aux=pun->s->s->s;
                free(pun->s->s);
                pun->s->s=aux;
                pun=pun->s;
            }
            else
            {
                pun=pun->s->s;
            }
        }
    }
    return reg;
}




void c2(nodo*reg,nodo*r2)
{
    while (reg->s!=NULL)
    {
        if (reg->num%3==0)
        {
            r2->num=reg->num;
            r2->s=(nodo*)malloc(sizeof(nodo));
            r2=r2->s;
        }
        reg=reg->s;
    }
    r2->s=NULL;
    return;
}







void crear(nodo*reg)
{
    printf("ing num: ");
    scanf("%d",&reg->num);
    if (reg->num==1000)
    {
        reg->s=NULL;
    }
    else
    {
        reg->s=(nodo*)malloc(sizeof(nodo));
        crear(reg->s);
    }
    return;
}

void mostrar(nodo*reg)
{
    if (reg->s!=NULL)
    {
        printf("\nmun %d",reg->num);
        mostrar(reg->s);
    }
    return;
}
