#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Localidad.h"


int mostrarLocalidades(eLocalidad localidades[],int tamloc)
{
    printf("\n Listado de Localidades\n");
     printf("\n\n");
    printf("  ID         Descripcion\n");

    for(int i=0; i<tamloc; i++)
    {

        mostrarUnaLocalidad(localidades[i]);
    }
    printf("\n\n");
    return 0;
}

int mostrarUnaLocalidad(eLocalidad unaLocalidad)
{
    printf(" %d    %10s\n",unaLocalidad.id, unaLocalidad.descripcion);
    return 0;
}


int buscarLocalidad(eLocalidad localidades[], int tamloc, int idBuscado)
{
    int indice=-1;
    if(localidades!=NULL && tamloc>0)
    {
        for(int i=0; i<tamloc; i++)
        {
            if(idBuscado==localidades[i].id)
            {
                indice=i;
                break;
            }
        }
    }
    return indice;
}
