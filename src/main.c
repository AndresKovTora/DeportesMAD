/*

  DeportesMAD (Deportes MADrid)

*/

// Librerías
#include <stdio.h>
#include "lector.h"
#include "config.h"
#include "listas.h"

// Función principal
int main()
{
  unsigned int tamano;
  const char *ruta_al_CSV = RUTA_DATASET;
  linea *datos = csv_a_actividades(ruta_al_CSV, &tamano);

  printf("%s", datos[10].actividad_base);
  char *centro_elegido = elegir_centro(datos, tamano);
  printf("%s", centro_elegido);

  free(datos);
  free(centro_elegido);
  
  return 0;
}
