# Versión mínima de CMake
cmake_minimum_required(VERSION 3.10)

# Ignorar avisos de Windows
if(MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif()

# Activar UTF8 en Windows
if(WIN32)
    add_compile_options(-finput-charset=UTF-8 -fexec-charset=cp1252)
endif()

# Nombre de proyecto
project(DeportesMAD)

# Estándares de C/C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Generar config.h para la ruta al dataset según OS
configure_file(
    "${CMAKE_SOURCE_DIR}/include/config.h.in"
    "${CMAKE_BINARY_DIR}/include/config.h"
)

# Directorio de includes
include_directories(include ${CMAKE_BINARY_DIR}/include)

# Directorio de código fuente
set(SOURCE_FILES src/main.c src/lector.c src/listas.c src/busqueda.c)

# Crear ejecutable
add_executable(DeportesMAD-bin ${SOURCE_FILES})
