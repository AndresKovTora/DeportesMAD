/*

  Librería búsqueda
  Librería encargada de extraer información particularmente tediosa a partir de los datos procesados, como
  centros que cuentan con un tipo de actividad (véase que en el [CSV](../data/dataset.csv) cada polideportivo
  llama de una forma a una misma actividad).

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
#define TAMANO_ARRAY_ACTIVIDADES 200
#define TAMANO_ARRAY_CENTROS 50

/* Definición de funciones */

int* array_actividades(linea* datos, unsigned int tamano_datos, unsigned int* ultimo_indice_actividades);

int* centros_con_actividad(linea* datos, unsigned int tamano_datos, unsigned int* tamano_array_centros, char* palabra_clave);

#endif
