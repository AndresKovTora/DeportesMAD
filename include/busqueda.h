/*

  Librería búsqueda
  Librería encargada de extraer información particularmente tediosa a partir de los datos procesados, como
  centros que cuentan con un tipo de actividad (véase que en el [CSV](../data/dataset.csv) cada polideportivo
  llama de una forma a una misma actividad).

*/

#ifndef LECTOR_H
#include "lector.h"
#endif

#ifndef BUSQUEDA_H
#define BUSQUEDA_H

/* Definición de estructuras */

typedef struct
{
  char centro[32];
} centro;

#endif
