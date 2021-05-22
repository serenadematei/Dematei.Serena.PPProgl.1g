#ifndef LOCALIDAD_H_INCLUDED
#define LOCALIDAD_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[51];


}eLocalidad;

#endif // LOCALIDAD_H_INCLUDED
int mostrarUnaLocalidad(eLocalidad unaLocalidad);
int mostrarLocalidades(eLocalidad localidades[],int tamloc);
int buscarLocalidad(eLocalidad localidades[], int tamloc, int idBuscado);
