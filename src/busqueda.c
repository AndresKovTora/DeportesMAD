/*

  busqueda.h
  Librería encargada de extraer información con un enfoque algo distinto que `listas.h`, más centrado en
  devolver datos utilizables que en la tarea de listarlos.

*/

#include "../include/busqueda.h"

/* Definición de funciones */

// Obtiene un array con todos los nombres de las acividades. Devuelve los índices de `linea* datos` que
// contienen a los nombres, en datos[actividades[i]].actividad_base, i = {1, ... ,tamano_datos}.
int* array_actividades(linea* datos, unsigned int tamano_datos, unsigned int* ultimo_indice_actividades)
{
  // Se crea un array y se limpia la memoria
  int* actividades = calloc(TAMANO_ARRAY_ACTIVIDADES, sizeof(int*));

  // Como actividades está limpio, actividades[0] = 0. Entonces, como la primera actividad que se guardará será
  // datos[0].actividad_base, y eso ya se cumple para datos[actividades[0]].actividad_base, se empieza por el
  // índice 1.
  *ultimo_indice_actividades = 1;

  // Se busca a lo largo de todas las líneas
  int i, j, repetido;
  for (i = *ultimo_indice_actividades; i < tamano_datos; i++) {
    repetido = 0;

    // Si la actividad ya se ha guardado, se marca como repetida
    for (j = 0; j <= *ultimo_indice_actividades; j++) {
      if (strcmp(datos[i].actividad_base, datos[actividades[j]].actividad_base) == 0) repetido = 1;
    }

    // Si es una actividad nueva, se guarda. Se toma la precaución de no haber axcedido el límite actividades[]
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

  return actividades;
}

// Devuelve un array de los índices de los elementos de `linea* datos` que contienen centros con una actividad
// que contiene una palabra clave.
int* centros_con_actividad(linea* datos, unsigned int tamano_datos, unsigned int* tamano_array_centros, char* palabra_clave)
{
  // Variables iniciales
  *tamano_array_centros = 0;
  unsigned int ultimo_indice_actividades;
  int *centros = malloc(sizeof(int) * TAMANO_ARRAY_CENTROS);
  int *actividades = array_actividades(datos, tamano_datos, &ultimo_indice_actividades);

  // Match entre las actividades provistas en actividades[] y la palabra clave
  int i;
  char *busqueda;
  for (i = 0; i < ultimo_indice_actividades; i++) {
    busqueda = strstr(datos[actividades[i]].actividad_base, palabra_clave);

    // Si la búsqueda da algún resultado, guardar el índice de `linea* datos`
    if (busqueda != NULL && busqueda != 0) {
      centros[*tamano_array_centros] = actividades[i];
      (*tamano_array_centros)++;
    }
  }

  free(actividades);

  return centros;
}
