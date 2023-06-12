#ifndef TOOLS_H
#define TOOLS_H

#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <stdbool.h>
#include <sndfile.h>


#define MAX_PATH 4096 // Valor máximo para la ruta

char getkey();
void position(int x, int y);

#endif