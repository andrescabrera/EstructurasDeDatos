#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
main()
{
    FILE *fFlota;
    tLista lista;
    fFlota = fopen("flota.txt", "r");
    if (fFlota == NULL)
        fprintf(stderr, "No pudo abrirse archivo flota.");
    else
    {
        lista = cargarLista(fFlota);
        lista = insertarElemento(lista, "AAC123", 0);
        lista = insertarElemento(lista, "AAC123", 3);
        mostrarLista(lista);
	  mostrarMasAntiguos(lista);	
	  lista = eliminarElementos(lista, "TAA000", "WZZ999");
	  mostrarLista(lista);
        liberarLista(&lista);
        fclose(fFlota);
    }
    return EXIT_SUCCESS;
}