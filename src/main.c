/*
  DeportesMAD (Deportes MADrid)
*/

#include <stdio.h>
#include <stdlib.h>
#include "lector.h"
#include "config.h"
#include "listas.h"

int main()
{
  unsigned int tamano;
  const char *ruta_al_CSV = RUTA_DATASET;
  linea *datos = csv_a_actividades(ruta_al_CSV, &tamano);

  if (datos == NULL) {
    printf("Error al cargar el dataset.\n");
    return 1;
  }

  // Prueba de lista_centros (mía)
  printf("\n=== Lista de centros unicos ===\n");
  lista_centros(datos, tamano);

  // Prueba de actividad concreta (de Andres)
  printf("\nActividad de la linea 10: %s\n", datos[10].actividad_base);

  // Prueba de elegir_centro (de Andres)
  char *centro_elegido = elegir_centro(datos, tamano);
  printf("\nHas elegido: %s\n", centro_elegido);

  free(datos);
  free(centro_elegido);
  return 0;
}