# Carpeta include
Aquí van todos los archivos *Header*, es decir, los archivos tipo `librería.h`, archivos que contienen las declaraciones de las funciones que utilizamos en otros archivos cuando hacemos
```c
#include "include/librería.h"
```
## Librería lector
Librería encargada de procesar el [archivo CSV](../data/dataset.csv) y transformarlo en estructuras utilizables en C.
### Estructuras
#### Linea
La estructura actividad contiene la información relativa a una actividad que ocurre a una hora, en un centro, con un tipo, etc, es decir, a cada una de las líneas del CSV que se proporciona [aquí](../data/dataset.csv). Es la base de todo el programa, todos los datos estarán en un array de estructuras **línea**.

### Funciones
```c
linea *csv_a_actividades(char *ruta_al_CSV, u_int *tamano);
```
Encargada de tomar el [archivo CSV](../data/dataset.csv) y convertirlo al array de estructuras de tipo línea mencionado en [Lector > Estructuras > Línea](#Linea).

```c
int contar_lineas(FILE *archivo);
```
Función interna a [lector.c](../src/lector.c) usada por `csv_a_actividades`, que cuenta las líneas del [CSV](../data/dataset.csv) para saber el tamaño en memoria que habrá que reservar.

## Librería listas
Librería contenedora de las funciones para listar distintas características, como los polideportivos disponibles, las actividades que ofrece un polideportivo, etc.
### Funciones

```c
void lista_centros(linea *datos, unsigned int tamano);
```
Print de todos y cada uno de los centros disponibles.

```c
char* elegir_centro(linea *datos, unsigned int tamano);
```
Elección de un centro disponible. Permite también contemplar la opción de haber escogido un centro inexistente o mal escrito.
**Return**: La función devuelve el string del nombre del centro escogido (un puntero al primer caracter).
**Uso**: Véase `actividades_libres`.

```c
void actividades_libres(linea *datos, unsigned int tamano, char* centro_seleccionado);
```
Búsqueda y print de actividades con sitio disponible en un centro dado. `centro_seleccionado` viene dado por la función `elegir_centro`.

```c
void lista_actividades_centro(linea *datos, unsigned int tamano, char* centro_seleccionado);
```
Listado de todas las actividades disponibles en un sólo centro.

```c
char* actividad_mas_popular(linea *datos, unsigned int tamano);
```
Búsqueda y print de la actividad más popular del centro, según el criterio de la proporción de todas las veces que se da la actividad que esta está llena.


## Librería búsqueda
Librería encargada de extraer información con un enfoque algo distinto que `listas.h`, más centrado en devolver datos utilizables que en la tarea de listarlos.

### Funciones
```c
int* array_actividades(linea* datos, unsigned int tamano_datos, unsigned int* ultimo_indice_actividades);
```
Devuelve un array de los números de línea del [CSV](../data/dataset.csv) (en realidad del vector de [estructuras](#Linea)) que contienen los nombres de actividades, sin repetir nombres.

```c
int* centros_con_actividad(linea* datos, unsigned int tamano_datos, unsigned int* tamano_array_centros, char* palabra_clave);
```
Refina el array de números de línea devuelto por `array_actividades` y guarda aquellos que contengaun una actividad con un nombre relacionado al criterio de búsqueda provisto.

## config.h.in
Archivo de configuración utilizado por CMake para crear la ruta absoluta al [dataset.csv](../data/dataset.csv) en cada ordenador en el que se compila. Este enfoque es tal vez poco portable, tal vez se cambie a futuro.
