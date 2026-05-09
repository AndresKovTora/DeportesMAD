/*
  DeportesMAD (Deportes MADrid)
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include "../include/lector.h"
#include "../include/busqueda.h"
#include "config.h"
#include "../include/listas.h"

// Funciones internas a main.c
void limpiar_buffer();

// Función main()
int main()
{
  unsigned int tamano;
  const char *ruta_al_CSV = RUTA_DATASET;
  linea *datos = csv_a_actividades(ruta_al_CSV, &tamano);

  if (datos == NULL) {
    fprintf(stderr, "Error: No se ha podido abrir el archivo. Ruta provista: %s", ruta_al_CSV);
    return -1;
  }

  printf("\n*  DeportesMAD (Deportes MADrid) \n*  Bienvenido/a.\n");

  char opcion = '\0';

  while (opcion != '0') {
    opcion = '\0';
    printf("\n==Menú principal.\n"
           "* Elija una opción:\n"
           "[1] Información sobre centros y actividades.\n"
           "[2] Búsqueda de actividades con plazas disponibles.\n"
           "[3] Salir (o Ctrl+C).\n"
           ":: ");
    opcion = getchar(); limpiar_buffer();

    switch (opcion) {
      case '1':
        printf("\n[1] Buscar centros que ofrezcan una actividad.\n"
               "[2] Buscar actividades disponibles en un centro.\n"
               ":: ");
        opcion = getchar(); limpiar_buffer();

        switch (opcion) {
          case '1':
            printf("");
            unsigned int tamano_array_centros;
            char buffer[MAX_LEN_LONG];

            printf("\n* Introduzca una palabra clave para la búsqueda (EN MINÚSCULA): ");
            if (scanf("%[^\n]", buffer) == 0) {
              printf("Error leyendo la entrada.");
            }
            limpiar_buffer();

            int *resultado_busqueda = centros_con_actividad(datos, tamano, &tamano_array_centros, buffer);

            printf("* Centros con actividades según la búsqueda:\n");

            for (int i = 0; i < tamano_array_centros; i++) {
              printf("- %s: %s\n", datos[resultado_busqueda[i]].centro, datos[resultado_busqueda[i]].actividad_base);
            }
            if (tamano_array_centros == 0) printf("Sin resultados de búsqueda.\n");

            free(resultado_busqueda);
            break;

          case '2':
            printf("* Escoja un centro.\n");
            char *centro_elegido = elegir_centro(datos, tamano);
            actividades_libres(datos, tamano, centro_elegido);

            limpiar_buffer();

            free(centro_elegido);
            break;
            
          default:
            printf("\n* Opción invalida, abortando...\n");
        }

        break;
      
      case '3':
        opcion = '0';
        printf("\nSesión terminada.");
        break;

      default:
        printf("\n* Opción inválida.\n\n");
    }
  }

  free(datos);

  return 0;
}

// Limpiar stdin tras usar getchar() o scanf()
void limpiar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
