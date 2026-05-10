/*

  listas.h
  Esta es la librería destinada a todas las funciones que se encargan de crear listas a partir de los
  datos que hemos recopilado en lector.h.

*/

#ifndef _STDLIB_H
#include <stdlib.h>
#endif

#ifndef _STDIO_H
#include <stdio.h>
#endif

#ifndef _STRING_H
#include <string.h>
#endif

#ifndef LECTOR_H
#include "lector.h"
#endif

#ifndef LISTAS_H
#define LISTAS_H


/* Definición de funciones */

// Listar todos los centros que hay
void lista_centros(linea *datos, unsigned int tamano);

// Obtener un string con el nombre de un centro seleccionado existente.
char* elegir_centro(linea *datos, unsigned int tamano);

// Listar las actividades con plazas libres en un centro.
void actividades_libres(linea *datos, unsigned int tamano, char* centro_seleccionado);

// Lista de todas las actividades de un centro.
void lista_actividades_centro(linea *datos, unsigned int tamano, char* centro_seleccionado);

// Encuentra la actividad más popular de un centro (la propia función pide la búsqueda del centro,
// no lo requiere como parámetro).
char* actividad_mas_popular(linea *datos, unsigned int tamano);

#endif
