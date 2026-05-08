/*

  Librería búsqueda
  Librería encargada de extraer información particularmente tediosa a partir de los datos procesados, como
  centros que cuentan con un tipo de actividad (véase que en el [CSV](../data/dataset.csv) cada polideportivo
  llama de una forma a una misma actividad).
  Comentarios sobre las funciones en include/busqueda.h

*/

#include "../include/busqueda.h"

int* array_actividades(linea* datos, unsigned int tamano_datos, unsigned int* ultimo_indice_actividades)
{
  int* actividades = calloc(TAMANO_ARRAY_INICIAL, sizeof(int*));
  *ultimo_indice_actividades = 1;

  int i, j, repetido;

  for (i = *ultimo_indice_actividades; i < tamano_datos; i++) {
    repetido = 0;
    for (j = 0; j <= *ultimo_indice_actividades; j++) {
      if (strcmp(datos[i].actividad_base, datos[actividades[j]].actividad_base) == 0) repetido = 1;
    }
    if (repetido != 1) {
      if (*ultimo_indice_actividades <= TAMANO_ARRAY_INICIAL) {
        actividades[*ultimo_indice_actividades] = i;
        (*ultimo_indice_actividades)++;
      } else {
        fprintf(stderr, "array_actividades(): Excedido el límite de tamaño, leídas %d líneas.\n", i);
        fprintf(stderr, "*ultimo_indice_actividades: %d", *ultimo_indice_actividades);
        return NULL;
      }
    }
  }
  printf("array_actividades(): Guardadas %d actividades.\n", (*ultimo_indice_actividades) + 1);

  return actividades;
}
