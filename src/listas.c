/*
  listas.c
  Esta es la librería destinada a todas las funciones que se encargan de crear listas a partir de los datos
*/

#include "../include/listas.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

    // Comparar el 'centro_actual' con los ya guardados
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

    // Si no era repetido, guardarlo en la posición libre encontrada
    if (repetido == 0) {
      strcpy(centros[posCentros], centro_actual);
    }
  }

  // Imprimir todos los centros únicos
  for (unsigned int z = 0; z < 100; z++) {
    if (strcmp(centros[z], "0") == 0) {
      break;
    }
    printf("%s\n", centros[z]);
  }
}

char* elegir_centro(linea *datos, unsigned int tamano)
{
  int i = 0, j = 0, existe = 0, centro_valido = 0;
  char *centro_elegido = malloc(100 * sizeof(char));

  while (centro_valido == 0) {
    //Esto muestra todos los centros
    printf("Centros disponibles:\n");
    for (i = 0; i < tamano; i++){
      existe = 0;
      for (j = 0; j < i && existe == 0; j++){
        //Si el centro ya ha sido mostrado, no lo mostramos de nuevo
        if (strcmp(datos[i].centro, datos[j].centro) == 0){
          existe = 1;
        }
      }
      //Si el centro no ha sido mostrado, lo mostramos
      if (existe == 0){
        printf("%s\n", datos[i].centro);
      }
    }

    //Esto pide al usuario que elija un centro
    printf("Elige un centro:\n ");
    scanf("%s", centro_elegido);

    //Esto comprueba que el centro elegido es válido
    centro_valido = 0;
    for (i = 0; i < tamano && centro_valido == 0; i++){
      if (strcmp(centro_elegido, datos[i].centro) == 0){
        centro_valido = 1;
      }
    }
    if (centro_valido == 0){
      printf("Centro no válido. Por favor, elige un centro de la lista.\n");
    }
  }
  return centro_elegido;
}