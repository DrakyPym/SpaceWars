#include "tools.h"

void position(int x, int y)
{
    printf("\033[%d;%dH", y, x);
}

char getkey()
{
    char key = '\0';

    struct termios oldTermios, newTermios;
    tcgetattr(STDIN_FILENO, &oldTermios);
    newTermios = oldTermios;
    newTermios.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newTermios);

    int oldFileFlags = fcntl(STDIN_FILENO, F_GETFL);
    fcntl(STDIN_FILENO, F_SETFL, oldFileFlags | O_NONBLOCK);

    int ch = getchar();
    if (ch != EOF)
    {
        key = (char)ch;

        // Verificar si es la tecla Enter
        if (key == '\n')
        {
            key = 'E'; // Utilizamos 'E' como representación de la tecla Enter
        }
        else if (key == '\033')
        {
            // Leer el siguiente carácter para determinar la tecla especial
            key = getchar();

            if (key == '[')
            {
                // Leer el siguiente carácter para identificar la tecla específica
                key = getchar();

                switch (key)
                {
                case 'A':      // Tecla de flecha hacia arriba
                    key = 'U'; // Utilizamos 'U' como representación de la flecha hacia arriba
                    break;
                case 'B':      // Tecla de flecha hacia abajo
                    key = 'D'; // Utilizamos 'D' como representación de la flecha hacia abajo
                    break;
                case 'C':      // Tecla de flecha hacia la derecha
                    key = 'R'; // Utilizamos 'R' como representación de la flecha hacia la derecha
                    break;
                case 'D':      // Tecla de flecha hacia la izquierda
                    key = 'L'; // Utilizamos 'L' como representación de la flecha hacia la izquierda
                    break;
                default:
                    break;
                }
            }
        }
    }

    tcsetattr(STDIN_FILENO, TCSANOW, &oldTermios);
    fcntl(STDIN_FILENO, F_SETFL, oldFileFlags);

    return key;
}

void obtenerTamanoConsola(int *filas, int *columnas){
    struct winsize ws;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);
    *filas = ws.ws_row;
    *columnas = ws.ws_col;
}

void pantallaCompleta(){
    int filas, columnas;
    obtenerTamanoConsola(&filas, &columnas);
    system("xdotool key F11"); // Pone el programa en pantalla completa
    while (filas < 35 || filas > 50){ // Establece un numero de filas y columnas dentro de un intervalo
        obtenerTamanoConsola(&filas, &columnas);
        if (filas < 35)
            system("xdotool key --clearmodifiers Ctrl+minus");
        if (filas > 50)
            system("xdotool key --clearmodifiers Ctrl+plus");
    }
}