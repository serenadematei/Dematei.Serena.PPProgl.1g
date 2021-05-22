#include "Juegos.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int buscarJuego(eJuego juegos[],int tamjue,int idJuego)
{
    int indice=-1;

     if(juegos!=NULL && tamjue>0)
     {
          for(int i=0; i<tamjue ; i++)
        {
            if(juegos[i].codigo == idJuego)
            {
                indice=i;
                break;
            }


        }
     }


     return indice;
}











int mostrarJuegos(eJuego juegos[],int tamjue,eCategoria categorias[],int tamcat)
{
    int todoOk=0;

    system("cls");
    printf(" LISTA DE JUEGOS\n");
    printf("\n\n");
    printf("ID      Descripcion   Categoria  Precio\n");


    if(juegos!=NULL && tamjue>0)
    {
        for(int i=0; i<tamjue; i++)
        {
            mostrarJuego(juegos[i],categorias,tamcat);
            todoOk=1;
        }

    }


    printf("\n\n");

    return todoOk;
}

void mostrarJuego(eJuego unJuego,eCategoria categorias[],int tamcat)
{
    char descripcionCategoria[51];

    if(cargarDescripcionCategoria(categorias,tamcat,descripcionCategoria,unJuego.idCategoria))
    {
        printf("%d      %10s   %10s   %.2f\n",
               unJuego.codigo,
               unJuego.descripcion,
               descripcionCategoria,
               unJuego.importe);
    }
}






int cargarDescripcionJuego (eJuego juegos[], int tamjue, char descripcion[],int id)
{
    int todoOk=0;


    if(id>=100 && id<=104 && juegos!=NULL && tamjue>0 && descripcion!=NULL)
    {
        for(int i=0; i<tamjue ; i++)
        {
            if(juegos[i].codigo==id)
            {
                strcpy(descripcion, juegos[i].descripcion);
                todoOk=1;
                break;
            }
        }
    }
 return todoOk;
}


int cargarImporteJuego(eJuego juegos[],int tamjue,float* importe,int id)
{
    int todoOk=0;


    if(id>=100 && id<=104 && juegos!=NULL && tamjue>0)
    {
        for(int i=0; i<tamjue ; i++)
        {
            if(juegos[i].codigo==id)
            {

                *importe=juegos[i].importe;
                todoOk=1;
                break;
            }
        }
    }
  return todoOk;
}

int cargarCategoriaJuego(eCategoria categorias[], int tamcat,eJuego juegos[],int tamjue,char categoria[],int id)
{
     int todoOk=0;


    if(id>=100 && id<=104 && juegos!=NULL && tamjue>0 && categoria!=NULL && categorias!=NULL && tamcat>0)
    {
        for(int i=0; i<tamjue ; i++)
        {
            for(int j=0; j<tamcat; j++)
            {
                if(juegos[i].codigo==id && juegos[i].idCategoria==categorias[j].id)
                {
                  strcpy(categoria, categorias[j].descripcion);
                  todoOk=1;
                  break;
                }
            }

        }
    }
 return todoOk;
}


int cargarDescripcionCategoria(eCategoria categorias[],int tamcat,char descripcionCategoria[],int id)
{
    int todoOk=0;


    if(id>=500 && id<=504 && categorias!=NULL && tamcat>0 && descripcionCategoria!=NULL)
    {
        for(int i=0; i<tamcat ; i++)
        {
            if(categorias[i].id==id)
            {
                strcpy(descripcionCategoria, categorias[i].descripcion);
                todoOk=1;
                break;
            }
        }
    }
 return todoOk;
}

