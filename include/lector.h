/*
  lector.h
  Esta es la librería destinada a todas las funciones que se encargan de leer el .csv que nos han dado.
*/

#ifndef _STDLIB_H
#include <stdlib.h>
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
  char *nombre;
  int plazasTotales;
  int plazasOcupadas;
  fecha fecha; 
  char *modalidad;
  char *tipo;
} actividad;

// Polideportivo.
// Información relativa a un polideportivo. Un polideportivo contiene una serie de actividades.
typedef struct
{
  char *nombre;
  actividad actividades[];
} polideportivo;


/* Definición de funciones */


#endif
