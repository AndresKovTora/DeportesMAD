# Carpeta include
Aquí van todos los archivos *Header*, es decir, los archivos tipo `librería.h`, archivos que contienen las declaraciones de las funciones que utilizamos en otros archivos cuando hacemos
```c
#include "include/librería.h"
```
## Librería lector
### Estructuras
#### Linea
La estructura actividad contiene la información relativa a una actividad que ocurre a una hora, en un centro, con un tipo, etc, es decir, a cada una de las líneas del CSV que se proporciona [aquí](../data/dataset.csv). Es la base de todo el programa, todos los datos estarán en un array de estructuras **línea**.

### Funciones
```c
linea *csv_a_actividades(char *ruta_al_CSV, u_int *tamano);
```
Encargada de tomar el [archivo CSV](../data/dataset.csv) y convertirlo al array de estructuras de tipo línea mencionado en [[#Linea]].

```c
int contar_lineas(FILE *archivo);
```
Función interna a `lector.c` usada por `csv_a_actividades`, que cuenta las líneas del [CSV](../data/dataset.csv) para saber el tamaño en memoria que habrá que reservar.
