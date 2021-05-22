#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


#ifndef GET_H_INCLUDED
#define GET_H_INCLUDED



#endif // GET_H_INCLUDED




int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getCaracter(char *pResultado, char* mensaje, char* mensajeError, char minimo, char maximo,int reintentos );
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);

int utn_getNombre(char* pResultado, char* mensaje, char* mensajeError, int sizeNombre, int reintentos);
