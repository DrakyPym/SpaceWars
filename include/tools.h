#ifndef TOOLS_H
#define TOOLS_H

#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

void position(int x, int y);
char getkey();

#endif