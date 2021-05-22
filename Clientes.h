#include "Localidad.h"
#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED


typedef struct
{
    int codigo;
    char nombre[51];
    char apellido[51];
    char sexo;
    int telefono;
    int idLocalidad;
    int isEmpty; //0 lleno, 1 vacio
}eCliente;

#endif // CLIENTES_H_INCLUDED

void inicializarClientes(eCliente clientes[], int tamcli);
int altaCliente(eCliente clientes[],int tamcli,int* pId);
int mostrarClientes(eCliente clientes[], int tamcli,eLocalidad localidades[],int tamloc);
void mostrarCliente(eCliente unCliente,eLocalidad localidades[],int tamloc);
int buscarLibre(eCliente clientes[],int tamcli);
//int bajaCliente(eCliente clientes[], int tamcli);

int subMenuModificaciones();
int buscarCliente(eCliente clientes[],int tamcli,int codigoIngresado);
int modificarClientes(eCliente clientes[],int tamcli,eLocalidad localidades[],int tamloc);

int ordenarClientes(eCliente clientes[],int tamcli);
int cargarApellidoCliente(eCliente clientes[],int tamcli,char apellidoCliente[],int id);
