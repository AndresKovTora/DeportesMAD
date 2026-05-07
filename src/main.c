/*
  DeportesMAD (Deportes MADrid)
*/

#include <stdio.h>
#include <stdlib.h>
#include "lector.h"
#include "config.h"
#include "listas.h"

int main()
{
  unsigned int tamano;
  const char *ruta_al_CSV = RUTA_DATASET;
  linea *datos = csv_a_actividades(ruta_al_CSV, &tamano);

  if (datos == NULL) {
    printf("Error al cargar el dataset.\n");
    return 1;
  }

  printf("¿Que vas a querer hacer? Escriba el numero correspondiente: /n");
  printf("1 ) Hacer una reserva en una actividad. /n 2 ) Descubrir actividades.)");
  scanf("%d", &opcion);

  if (opcion == 1) {
    elegir_centro(datos, tamano);

    actividades_libres(datos, tamano, centro_elegido);

    return 0;
  }

  else if (opcion == 2) {
    printf("¿Quieres descubrir por centro o por actividad? Escriba el numero correspondiente: /n");
    printf("1 ) Descubrir por centro. /n 2 ) Descubrir por actividad.)");
    scanf("%d", &descubrir);

    if (descubrir == 1) {
      elegir_centro(datos, tamano); 

      lista_actividades_centro(datos, tamano, centro_elegido);
    } else if (descubrir == 2) {
      
    }
  }

    else {
      printf("Opcion no valida. Vuelva a intentarlo.\n");

      return -1;
    }
  else {
    printf("Opcion no valida. Vuelva a intentarlo.\n");

    return -1; 
  }


  // Prueba de lista_centros 
  printf("\n=== Lista de centros unicos ===\n");
  lista_centros(datos, tamano);

  // Prueba de actividad concreta
  printf("\nActividad de la linea 10: %s\n", datos[10].actividad_base);

  // Prueba de elegir_centro 
  char *centro_elegido = elegir_centro(datos, tamano);
  printf("\nHas elegido: %s\n", centro_elegido);

  //Prueba de actividades libres en el centro elegido
  actividades_libres(datos, tamano, centro_elegido);

  // Prueba Actividades en un centro concreto
  printf("\n=== Actividades en el centro elegido ===\n");
  lista_actividades_centro(datos, tamano, centro_elegido);

  free(datos);
  free(centro_elegido);

  return 0;
}