#include "Categorias.h"
#ifndef JUEGOS_H_INCLUDED
#define JUEGOS_H_INCLUDED

typedef struct
{
    int codigo;
    char descripcion[51];
    float importe;

    int idCategoria;

}eJuego;


#endif // JUEGOS_H_INCLUDED
int buscarJuego(eJuego juegos[],int tamjue,int idJuego);
void mostrarJuego(eJuego unJuego,eCategoria categorias[],int tamcat);
int mostrarJuegos(eJuego juegos[],int tamjue,eCategoria categorias[],int tamcat);
int cargarDescripcionJuego (eJuego juegos[], int tamjue, char descripcion[],int id);
int cargarImporteJuego(eJuego juegos[],int tamjue,float* importe,int id);
int cargarCategoriaJuego(eCategoria categorias[], int tamcat,eJuego juegos[],int tamjue,char categoria[],int id);


