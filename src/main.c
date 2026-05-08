/*
  DeportesMAD (Deportes MADrid)
*/

#include <stdio.h>
#include <stdlib.h>
#include "lector.h"
#include "config.h"
#include "busqueda.h"
#include "listas.h"

int main()
{
  unsigned int tamano;
  const char *ruta_al_CSV = RUTA_DATASET;
  linea *datos = csv_a_actividades(ruta_al_CSV, &tamano);

  unsigned int tamano_actividades;
  int *actividades = array_actividades(datos, tamano, &tamano_actividades);

  printf("Todo okei!");

  return 0;
}
