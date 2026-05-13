#include <stdio.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include "terminal.h"

int getTerminalWidth() {
    struct winsize w;

    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) == 0) {
        //printf("Rows: %d\n", w.ws_row);
        //printf("Columns: %d\n", w.ws_col);
    } else {
        perror("ioctl failed");
    }
    return w.ws_col;
}