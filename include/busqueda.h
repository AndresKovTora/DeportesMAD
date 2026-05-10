/*

  busqueda.h
  Librería encargada de extraer información con un enfoque algo distinto que `listas.h`, más centrado en
  devolver datos utilizables que en la tarea de listarlos.

*/

#ifndef _STRING_H
#include <string.h>
#endif

#ifndef _STDIO_H
#include <stdio.h>
#endif

#ifndef _CTYPE_H
#include <ctype.h>
#endif

#ifndef LECTOR_H
#include "lector.h"
#endif

#ifndef BUSQUEDA_H
#define BUSQUEDA_H

/* Definición de macros */

#define TAMANO_ARRAY_ACTIVIDADES 200
#define TAMANO_ARRAY_CENTROS 50

/* Definición de funciones */

// Obtiene un array con todos los nombres de las acividades.
int* array_actividades(linea* datos, unsigned int tamano_datos, unsigned int* ultimo_indice_actividades);

// Devuelve un array de los índices de los elementos de `linea* datos` que contienen centros con una actividad que contiene una palabra clave.
int* centros_con_actividad(linea* datos, unsigned int tamano_datos, unsigned int* tamano_array_centros, char* palabra_clave);

#endif
