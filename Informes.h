#include "Alquileres.h"
#include "Juegos.h"
#include "Clientes.h"


#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED



#endif // INFORMES_H_INCLUDED
int menu();
int informar(eCliente clientes[],int tamcli,eAlquiler alquileres[],int tamalqui,eJuego juegos[],int tamjue,eCategoria categorias[],int tamcat,eLocalidad localidades[],int tamloc);
int juegoPreferidoDeUnaLocalidad(eCliente clientes[], int tamcli, eLocalidad localidades[], int tamloc, eJuego juegos[], int tamjue, eAlquiler alquileres[], int tamalqui);
int localidadQueMasJugoUnJuego(eCliente clientes[], int tamcli, eLocalidad localidades[], int tamloc, eJuego juegos[], int tamjue, eAlquiler alquileres[], int tamalqui,eCategoria categorias[],int tamcat);
int clientesPorLocalidad(eCliente clientes[], int tamcli, eLocalidad localidades[],int tamloc);
int totalGastoAlquiler (eCliente clientes[],int tamcli,eAlquiler alquileres[],int tamalqui,eJuego juegos[],int tamjue,eCategoria categorias[],int tamcat,eLocalidad localidades[],int tamloc);
int juegosMasAlquiladosPorHombres(eCliente clientes[], int tamcli, eLocalidad localidades[], int tamloc, eJuego juegos[], int tamjue, eAlquiler alquileres[], int tamalqui);
