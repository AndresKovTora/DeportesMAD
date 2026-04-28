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

/* Definición de estructuras */

// Fecha.
// Información temporal relativa a una actividad concreta.
typedef struct
{
  int horaInicio;
  int horaFin;
  enum diaSemana {
    lunes, martes, miercoles, jueves, viernes, sabado, domingo
  };
  int diaMes;
  int mes;
  int año;
} fecha;

// Actividad.
// Información de una sola actividad del polideportivo. Cada índice de los arrays siguientes
// hace referencia a una instancia de la actividad, p.ej, la actividad "natación" se da 50 veces en el
// polideportivo X, pues cada uno de los índices de 0 a 49 representa una de las veces que se da natación.
typedef struct
{
  int anio;
  int mes;
  int dia;
  char *dia_semana;
  int hora_inicio[2];
  int hora_fin[2];
  char *actividad_base;
  char *modalidad;
  char *centro;
  int plazas;
  int ocupadas;
  int libres;
  char *tipo_actividad;
} linea;

/* Definición de funciones */

// Contar 

// Lector final. Se le pasa el archivo y devuelve un array de estructuras
linea *csv_a_polideportivos(FILE *archivo, int *tamano);

#endif
