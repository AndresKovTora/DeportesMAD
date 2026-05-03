/*
  lector.h
  Esta es la librería destinada a todas las funciones que se encargan de leer el .csv que nos han dado.
*/

#ifndef _STDLIB_H
#include <stdlib.h>
#endif

#ifndef _STDIO_H
#include <stdio.h>
#endif


#ifndef _STRING_H
#include <string.h>
#endif

#ifndef _LECTOR_L
#define _LECTOR_L 1
#define MAX_LEN_SHORT 12
#define MAX_LEN_LONG  48

/* Definición de estructuras */

// Línea.
// Información relativa a una instancia de una actividad, es decir, una actividad, a una hora, en un
// centro, con una modalidad, etc. La información contenida por una estructura de tipo linea es
// equivalente a la escrita en una línea del CSV en data/dataset.csv, de ahí el nombre.
typedef struct
{
  int  anio;
  int  mes;
  int  dia;
  char dia_semana[MAX_LEN_SHORT];
  int  hora_inicio[2];
  int  hora_fin[2];
  char actividad_base[MAX_LEN_LONG];
  char modalidad[MAX_LEN_LONG];
  char centro[MAX_LEN_LONG];
  int  plazas;
  int  ocupadas;
  int  libres;
  char tipo_actividad[MAX_LEN_LONG];
} linea;

/* Definición de funciones */

// Contar número de líneas del archivo.
int contar_lineas(FILE *archivo);

// Lector final. Se le pasa el archivo y devuelve un array de estructuras
linea *csv_a_actividades(char *ruta_al_CSV, u_int *tamano);

#endif
