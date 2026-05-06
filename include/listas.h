/*

  listas.h
  Esta es la librería destinada a todas las funciones que se encargan de crear listas a partir de los
  datos que hemos recopilado en lector.h.

*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lector.h"

#ifndef LISTAS_H
#define LISTAS_H


/* Definición de funciones */

//lista de todos los centros que hay
void lista_centros(linea *datos, unsigned int tamano);
char* elegir_centro(linea *datos, unsigned int tamano);
void lista_actividades_centro(linea *datos, unsigned int tamano, char* centro_seleccionado);
#endif
