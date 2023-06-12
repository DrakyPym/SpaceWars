cmake_minimum_required(VERSION 3.22.1)

project(SpaceWarsProject)

# Lista de archivos fuente
set(PROYECTO_SOURCES
    src/SpaceWars.c
    src/tools.c
    src/hideShow.c
)

# Crea el ejecutable
add_executable(SpaceWars ${PROYECTO_SOURCES})

# Indica la ruta a los archivos de encabezado (.h)
include_directories(include)

