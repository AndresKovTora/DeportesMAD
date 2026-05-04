/*

  DeportesMAD (Deportes MADrid)

*/

// Librerías
#include <stdio.h>
#include "../include/lector.h"

// Función principal
int main()
{
  unsigned int tamano;
  linea *datos = csv_a_actividades("../data/dataset.csv", &tamano);

  printf("%s", datos[10].actividad_base);

  free(datos);
  
  return 0;
}
