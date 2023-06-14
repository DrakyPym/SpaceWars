#ifndef TOOLS_H
#define TOOLS_H

#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <stdlib.h>

void position(int x, int y);
char getkey();
void obtenerTamanoConsola(int *filas, int *columnas);
void pantallaCompleta();

#endif