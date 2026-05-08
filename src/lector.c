/*

  lector.c
  Esta es la librería destinada a todas las funciones que se encargan de leer el .csv que nos han dado.
  Todos los comentarios en lector.h

*/

// Includes
#include "../include/lector.h"
#include <stdio.h>
#include <string.h>

// Funciones

int contar_lineas(FILE *archivo)
{
  unsigned int cursor_limpio, lineas_totales = 0;
  char lectura;

  // Saltar la primera línea
  rewind(archivo);
  char x = 0;
  while (x != '\n') fscanf(archivo, "%c", &x);

  // El bucle anterior detiene el cursor en el primer '\n', se añade un caracter a la
  // posición actual para no contar la primera línea del CSV, que contiene títulos.
  // fseek(archivo, 1, SEEK_CUR);
  cursor_limpio = ftell(archivo);
  
  // Leer número de líneas
  while ((lectura = fgetc(archivo)) != EOF) {
    if (lectura == '\n') {
      lineas_totales++;
      printf("\rcontar_lineas(): contadas %d líneas.", lineas_totales);
      fflush(stdout);
    }
  }

  printf("\n");

  fseek(archivo, cursor_limpio, SEEK_SET);

  return lineas_totales;
}


linea *csv_a_actividades(const char* ruta_al_CSV, unsigned int* tamano)
{
  // Abrir el archivo
  FILE *archivo; archivo = fopen(ruta_al_CSV, "r");

  // Considerar que si lectura ha sido errónea.
  if (archivo == NULL)
  {
    perror("csv_a_actividades(): Ha ocurrido un error al abrir el archivo en la ruta.\n");
    fclose(archivo);
    return NULL;
  }
  // Si la lecutra ha sido correcta, comenzar la lectura del archivo.
  else {
    *tamano = contar_lineas(archivo);
    linea *datos = malloc(sizeof(linea) * *tamano + 1);
    int fscanf_return, errores = 0;

    for (unsigned int i = 0; i < *tamano; i++) {
      fscanf_return = fscanf(archivo, "%d %d %d %[^ ] %d:%d %d:%d %[^ ] %[^ ] %[^ ] %d %d %d %[^\n]\n",
        &datos[i].anio, &datos[i].mes, &datos[i].dia,
        datos[i].dia_semana,
        &datos[i].hora_inicio[0], &datos[i].hora_inicio[1],
        &datos[i].hora_fin[0], &datos[i].hora_fin[1],
        datos[i].actividad_base, datos[i].modalidad, datos[i].centro,
        &datos[i].plazas, &datos[i].ocupadas, &datos[i].libres,
        datos[i].tipo_actividad
      );

      if (fscanf_return != 15) {
        printf("\rERROR: Lectura incorrecta en la línea %d.\n", i+1);
        errores++;
      }

      printf("\rcsv_a_actividades(): Leídas %d líneas", i+1);
      fflush(stdout);
    }

    printf(", con %d erróneas.\n", errores);

    fclose(archivo);
    return datos;
  }
}
