#include "Categorias.h"
#include "Juegos.h"
#include "Clientes.h"
#include "Fecha.h"


#ifndef ALQUILERES_H_INCLUDED
#define ALQUILERES_H_INCLUDED



typedef struct
{
    int codigo;
    int codigoJuego;
    int codigoCliente;
    int isEmpty; //0 lleno 1 vacio
    eFecha fechaIngreso;

}eAlquiler;


void inicializarAlquileres(eAlquiler alquileres[],int tamalqui);
int altaAlquiler(eAlquiler alquileres[],int tamalqui,eCliente clientes[],int tamcli,int*pIdAlquiler,eJuego juegos[],int tamjue,eCategoria categorias[],int tamcat,eLocalidad localidades[],int tamloc);
int buscarLibreAlquiler(eAlquiler alquileres[],int tamalqui);
int mostrarAlquileres(eCliente clientes[], int tamcli, eJuego juegos[], int tamjue, eAlquiler alquileres[], int tamalqui,eCategoria categorias[],int tamcat);
void mostrarAlquiler(eAlquiler unAlquiler,eJuego juegos[],int tamjue,eCliente clientes[],int tamcli,eCategoria categorias[],int tamcat);
int bajaCliente(eCliente clientes[], int tamcli,eAlquiler alquileres[], int tamalqui,eLocalidad localidades[],int tamloc);
int bajaAlquiler(eAlquiler alquileres[], int tamalqui, int codigo);

#endif // ALQUILERES_H_INCLUDED
