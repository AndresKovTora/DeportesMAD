/*

  DeportesMAD (Deportes MADrid)

*/

// Librerías
#include <stdio.h>
#include "../include/lector.h"

// Función principal
int main()
{
  u_int tamano;
  linea *datos = csv_a_actividades("../data/dataset.csv", &tamano);

  printf("%d", datos[10].hora_fin[0]);

  return 0;
}
