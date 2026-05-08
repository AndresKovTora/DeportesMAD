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

#ifndef LECTOR_H
#include "lector.h"
#endif

#ifndef BUSQUEDA_H
#define BUSQUEDA_H
#define TAMANO_ARRAY_INICIAL 200

/* Definición de funciones */

int* array_actividades(linea* datos, unsigned int tamano_datos, unsigned int* ultimo_indice_actividades);

#endif
