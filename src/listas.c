/*

  listas.c
  Esta es la librería destinada a todas las funciones que se encargan de crear listas a partir de los
  datos que hemos recopilado en lector.h.

*/

#include "../include/listas.h"

char* elegir_centro(linea *datos, unsigned int tamano) 
{
  int i = 0, j = 0, existe = 0, centro_valido = 0;
  char *centro_elegido = malloc(100 * sizeof(char)); // Allocate memory

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