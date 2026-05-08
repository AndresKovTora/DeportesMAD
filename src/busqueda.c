/*

  Librería búsqueda
  Librería encargada de extraer información particularmente tediosa a partir de los datos procesados, como
  centros que cuentan con un tipo de actividad (véase que en el [CSV](../data/dataset.csv) cada polideportivo
  llama de una forma a una misma actividad).
  Comentarios sobre las funciones en include/busqueda.h

*/

#include "../include/busqueda.h"
#include <ctype.h>
#include <string.h>

int* array_actividades(linea* datos, unsigned int tamano_datos, unsigned int* ultimo_indice_actividades)
{
  int* actividades = calloc(TAMANO_ARRAY_ACTIVIDADES, sizeof(int*));
  *ultimo_indice_actividades = 1;

  int i, j, repetido;

  for (i = *ultimo_indice_actividades; i < tamano_datos; i++) {
    repetido = 0;
    for (j = 0; j <= *ultimo_indice_actividades; j++) {
      if (strcmp(datos[i].actividad_base, datos[actividades[j]].actividad_base) == 0) repetido = 1;
    }
    if (repetido != 1) {
      if (*ultimo_indice_actividades <= TAMANO_ARRAY_ACTIVIDADES) {
        actividades[*ultimo_indice_actividades] = i;
        (*ultimo_indice_actividades)++;
      } else {
        fprintf(stderr, "array_actividades(): Excedido el límite de tamaño, leídas %d líneas.\n", i);
        return NULL;
      }
    }
  }
  printf("array_actividades(): Guardadas %d actividades.\n", (*ultimo_indice_actividades) + 1);

  return actividades;
}

int* centros_con_actividad(linea* datos, unsigned int tamano_datos, unsigned int* tamano_array_centros, char* palabra_clave)
{
  *tamano_array_centros = 0;
  unsigned int ultimo_indice_actividades;
  int *centros = malloc(sizeof(int) * TAMANO_ARRAY_CENTROS);
  int *actividades = array_actividades(datos, tamano_datos, &ultimo_indice_actividades);

  int i;
  for (i = 0; i < ultimo_indice_actividades; i++) {
    if (strstr(datos[actividades[i]].actividad_base, palabra_clave) != NULL) {
      centros[*tamano_array_centros] = i;
      (*tamano_array_centros)++;
    }
  }

  free(actividades);

  return centros;
}
