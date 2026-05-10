# DeportesMAD
## Información general
Proyecto de informática de 1º de IEIA UPM. Este trabajo está hecho con cariño por el grupo 15 de InfoCerdos. Esta info irá actualizándose según pase el tiempo y avance el profecto (la podéis editar en README.md).
> Para ver información sobre todas las librerías y funciones, se recomienda ver el [readme en include/](include/README.md).
## Descarga
Para utilizar el programa, es necesario descargar el repositorio en su totalidad. Se plantean dos alternativas:
- **Descarga directa**: presionando el botón verde de la parte superior de esta página, donde pone **Código**, y haciendo click en **Descargar ZIP**. Basta con descomprimir el archivo donde se desee.
- **Terminal de Git**: Abrir una terminal en el directorio donde se quiera descargar y escribir
```bash
git clone https://github.com/AndresKovTora/DeportesMAD.git
```
## Ejecutar el programa
### Binarios precompilados
Se dispone en el repositorio `bin/` de binarios precompilados para una ejecución cómoda en [windows](bin/windows-x86) y para distribuciones basadas en [Arch linux](bin/arch-linux) (compilado y ejecutado en [CachyOS](https://cachyos.org/)).
> **NOTA**: Los ejecutables que se dan dependen de la estructura de archivos del repositorio, por lo que si se mueven de carpeta dejarán de funcionar. Es vital no mover ni bin/windows-x86/DeportesMAD-bin.exe (asumiendo que se está en Windows) ni data/dataset.csv.
### Compilar desde código fuente
El proyecto está diseñado para compilarse mediante **CMake**, y no utilizarlo probablemente cause problemas, la compilación depende de CMakesLists.txt. Asumiendo que se disponga de un compilador para C/C++ (como MSVC o [MinGW](https://www.mingw-w64.org/)):
1. Instalación de CMake
Se puede obtener fácilmente desde la [página oficial](https://cmake.org/) o instalándolo con la herramienta `winget`, ejecutando en terminal
```bash
winget install Kitware.CMake
```
2. Compilación
Abriendo una terminal *nueva* donde se haya descargado el repositorio, ejecutar:
```bash
mkdir build
cd build
cmake ..
cmake --build .
```
Esto debería crear todos los archivos que CMake necesita y compilar el programa en base a ello. Según el compilador que se utilice, el ejecutable estará en el repositorio `build/` o tal vez en `build/Debug/`, si se revisan los últimos mensajes de CMake se puede ver dónde se ha guardado el binario.
