/*
  listas.c
  Esta es la librería destinada a todas las funciones que se encargan de crear listas a partir de los datos que hemos recopilado en lector.h.
*/

#include "../include/listas.h"
#include <stdio.h>
#include <string.h>

void lista_centros(linea *datos, unsigned int tamano)
{
  //Variables
  int repetido, comparar;
  unsigned int posCentros;
  char centro_actual[MAX_LEN_LONG];
  char centros[100][MAX_LEN_LONG];

  // Llenar todos los espacios de centros[] con 0 para poder detectar espacios vacíos
  for (unsigned int m = 0; m < 100; m++) {
    strcpy(centros[m], "0");
  }

  // Leer los centros de cada línea del CSV
  for (unsigned int i = 0; i < tamano; i++) {
    strcpy(centro_actual, datos[i].centro);
    repetido = 0;

    // Comparar el 'centro_actual' con los ya guardados, donde si llegamos a una posición vacía '0'
    // se hace break para escribir. Utilizamos una variable auxiliar 'repetido' para comprobar si
    // el 'centro_actual' ya esta escrito.
    for (posCentros = 0; posCentros < 100; posCentros++) {
      if (strcmp(centros[posCentros], "0") == 0) {
        break;
      }
      comparar = strcmp(centro_actual, centros[posCentros]);
      if (comparar == 0) {
        repetido = 1;
        break;
      }
    }

    // Si 'centro_actual' no era repetido, se guardardá en la posición libre encontrada
    if (repetido == 0) {
      strcpy(centros[posCentros], centro_actual);
    }
  }

  // Imprimir los centros guardados
  for (unsigned int z = 0; z < 100; z++) {
    if (strcmp(centros[z], "0") == 0) {
      break;
    }
    printf("%s\n", centros[z]);
  }
}