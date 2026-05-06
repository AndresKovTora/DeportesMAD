/*

  Librería búsqueda
  Librería encargada de extraer información particularmente tediosa a partir de los datos procesados, como
  centros que cuentan con un tipo de actividad (véase que en el [CSV](../data/dataset.csv) cada polideportivo
  llama de una forma a una misma actividad).
  Comentarios sobre las funciones en include/busqueda.h

*/

#include "../include/busqueda.h"

centro *array_centros(linea *datos, unsigned int tamano_de_datos, unsigned int *tamano_array_centros)
{
  char nombre_centro[MAX_LEN_LONG];
  *tamano_array_centros = 32;

  centro *centros = malloc(sizeof(centro) * *tamano_array_centros);

  int i, j = 0;
  for (i = 0; i < tamano_de_datos; i++) {
    for (j = 0; j >= 0 && j < *tamano_array_centros; j++) {
      datos[i].centro == centros[j].centro ? j = -1 : j;
    }
    if (j >= 0) {
      
    }
  }

  return centros;
}
