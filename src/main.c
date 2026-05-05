/*

  DeportesMAD (Deportes MADrid)

*/

// Librerías
#include <stdio.h>
#include "lector.h"
#include "config.h"

// Función principal
int main()
{
  unsigned int tamano;
  const char *ruta_al_CSV = RUTA_DATASET;
  linea *datos = csv_a_actividades(ruta_al_CSV, &tamano);

  printf("%s", datos[10].actividad_base);

  free(datos);
  
  return 0;
}
