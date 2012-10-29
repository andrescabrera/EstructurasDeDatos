void mostrarxprecio(nbarrio *barrios)
{
    ninmuebles *i;
    nbarrio *b;
    ninmuebles *aux;
    b = barrios;
    while (b != NULL)
    {
        i = b->inmbar;
        if (i != NULL)
        {
            while (i->sigi != NULL)
            {
                ninmuebles *j;
                j = i->sigi;
                while (j != NULL)
                {
                    if (j->precio < i->precio)
                    {
                        aux = (ninmuebles*)malloc(sizeof(ninmuebles));
                        aux->precio = j->precio;
                        strcpy(aux->direccion, j->direccion);
                        aux->cantamb = j->cantamb;

                        j->precio = i->precio;
                        j->cantamb = i->cantamb;
                        strcpy(j->direccion, i->direccion);

                        i->precio = aux->precio;
                        i->cantamb = aux->cantamb;
                        strcpy(i->direccion, aux->direccion);
                    }
                    j = j->sigi;
                }
                i = i->sigi;
            }
        }

        b = b->sigb;
    }
}
