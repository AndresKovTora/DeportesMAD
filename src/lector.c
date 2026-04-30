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
  int linea_actual = ftell(archivo), lineas_totales = 0;

  // Saltar la primera línea
  rewind(archivo);
  for (char x; x != '\n'; fscanf(archivo, "%c", &x));

  // Leer número de líneas
  for (char x; x != EOF; fscanf(archivo, "%c", &x)) {
    x == '\n' ? lineas_totales++ : lineas_totales;
  }

  fseek(archivo, linea_actual, SEEK_SET);

  return lineas_totales;
}


linea *csv_a_actividades(char *ruta_al_CSV, u_int *tamano)
{
  // Abrir el archivo
  FILE *archivo; archivo = fopen(ruta_al_CSV, "r");

  // Considerar que si lectura ha sido errónea.
  if (archivo == NULL)
  {
    printf("Ha ocurrido un error al abrir el archivo (dataset.csv).");
    fclose(archivo);
    return NULL;
  }
  // Si la lecutra ha sido correcta, comenzar la lectura del archivo.
  else {
    u_int lineas = contar_lineas(archivo);
    rewind(archivo);
    linea *datos = malloc(sizeof(linea) * lineas);

    for (int i = 0; i < lineas; i++) {
      fscanf(archivo, "%d %d %d %[^ ] %d:%d %d:%d %[^ ] %[^ ] %[^ ] %d %d %d %[^\n]\n",
               &datos[i].anio,
               &datos[i].mes,
               &datos[i].dia,
               datos[i].dia_semana,
               &datos[i].hora_inicio[0],
               &datos[i].hora_inicio[1],
               &datos[i].hora_fin[0],
               &datos[i].hora_fin[1],
               datos[i].actividad_base,
               datos[i].modalidad,
               datos[i].centro,
               &datos[i].plazas,
               &datos[i].ocupadas,
               &datos[i].libres,
               datos[i].tipo_actividad
      );
    }

    fclose(archivo);
    return datos;
  }
}
