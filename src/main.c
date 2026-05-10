/*
  DeportesMAD (Deportes MADrid)
*/

/* Cabecera */

// Librerías básicas
#include "../include/lector.h"
#include "../include/busqueda.h"
#include "../include/listas.h"
#include "config.h"

// Librerías para codificación UTF-8 en Windows
#ifdef _WIN32
#include <windows.h>
#endif
#include <locale.h>

// Funciones internas a main.c
void limpiar_buffer();
void menu_1(linea* datos, unsigned int tamano);

/* Función main() */

int main()
{
  // Activar el modo UTF-8 de la consola de Windows y establecer el idioma en español
  #ifdef _WIN32
  SetConsoleOutputCP(65001);
  #endif
  setlocale(LC_ALL, "es_ES.UTF-8"); 

  // Se abre el archivo CSV. Escribir *ruta_al_CSV como:
  // - RUTA_DATASET: Ruta según la compilación de CMake, varía según el ordenador así que hay que compilar
  //   para poder ejecutar el binario. Véase include/config.h.in
  // - "../ruta/personalizada/dataset.csv": Ruta personaliazda DESDE DONDE SE EJECUTE EL BINARIO.
  unsigned int tamano;
  const char *ruta_al_CSV = RUTA_DATASET;
  printf("Abriendo archivo... \nRuta provista: %s\n", ruta_al_CSV);
  linea *datos = csv_a_actividades(ruta_al_CSV, &tamano);

  // Contemplar errores a la hora de abrir el archivo
  if (datos == NULL) {
    fprintf(stderr, "Error: No se ha podido abrir el archivo.\n"
            "Posibles soluciones:\n"
            "editar main.c > const char *ruta_al_CSV\n"
            "Ejecutar el programa desde el directorio en el que está (debería ser bin/<Carpeta del OS>/).\n"
            "Cerrando programa...\n");
    return -1;
  }

  printf("\n*  DeportesMAD (Deportes MADrid) \n*  Bienvenido/a.\n");

  char opcion = '\0';

  // Bucle principal de la aplicación
  while (opcion != '0') {

    // Menú principal
    opcion = '\0';
    printf("\n===== Menú principal\n"
           "* Elija una opción:\n"
           "[1] Información sobre centros y actividades.\n"
           "[2] Búsqueda de actividades con plazas disponibles.\n"
           "[3] Salir (o Ctrl+C).\n"
           ":: ");
    opcion = getchar(); limpiar_buffer();

    // Selección de opciones
    switch (opcion) {

      // Información sobre centros y actividades
      case '1':
        menu_1(datos, tamano);
        break;

      // Búsqueda de actividades con plazas disponibles
      case '2':
        printf("* Escoja un centro.\n");
        char *centro_elegido = elegir_centro(datos, tamano);
        actividades_libres(datos, tamano, centro_elegido);

        limpiar_buffer();

        free(centro_elegido);
        break;
      
      // Salir del programa
      case '3':
        opcion = '0';
        printf("\nSesión terminada.\n");
        break;

      // Contemplar opción no válida
      default:
        printf("\n* Opción inválida.\n");
    }
  }

  free(datos);

  return 0;
}

// Limpiar stdin tras usar getchar() o scanf(). Asegura que la próxima lectura sea correcta.
void limpiar_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Opciones del menú Información sobre centros y actividades
void menu_1(linea* datos, unsigned int tamano)
{
  // Menú inicial
  printf("\n[1] Buscar centros que ofrezcan una actividad.\n"
         "[2] Ver actividades disponibles en un centro.\n"
         "[3] Actividad más popular en un centro.\n"
         ":: ");
  char opcion = getchar(); limpiar_buffer();

  // Selección de opciones
  switch (opcion) {

    // Buscar centros que ofrezcan una actividad
    case '1':
      unsigned int tamano_array_centros;
      char buffer[MAX_LEN_LONG];

      // Se toma por teclado la palabra clave
      printf("\n* Introduzca una palabra clave para la búsqueda (EN MINÚSCULA): ");
      if (scanf("%[^\n]", buffer) == 0) {
        printf("Error leyendo la entrada.");
        return;
      }
      limpiar_buffer();

      // Se buscan los centros con actividades que contengan en el nombre a la palabra clave
      int *resultado_busqueda = centros_con_actividad(datos, tamano, &tamano_array_centros, buffer);

      // Se imprimen los centros encontrados y se contempla que no haya habido resultados
      printf("* Centros con actividades según la búsqueda:\n");
      for (int i = 0; i < tamano_array_centros; i++) {
        printf("-- %s: %s (modalidad: %s)\n", datos[resultado_busqueda[i]].centro, datos[resultado_busqueda[i]].actividad_base, datos[resultado_busqueda[i]].modalidad);
      }
      if (tamano_array_centros == 0) printf("Sin resultados de búsqueda.\n");

      free(resultado_busqueda);
      break;

    // Ver actividades disponibles en un centro
    case '2':
      char *centro_elegido = elegir_centro(datos, tamano);
      lista_actividades_centro(datos, tamano, centro_elegido);

      limpiar_buffer();

      free(centro_elegido);
      break;

    // Actividad más popular en un centro
    case '3':
      char *actividad_popular = actividad_mas_popular(datos, tamano);
      printf("* Actividad más popular del centro: %s\n", actividad_popular);
      limpiar_buffer();
      
      break;
      
    // Contemplar opción no válida
    default:
      printf("\n* Opción inválida, abortando...\n");
  }
}
