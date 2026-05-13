#include <stdio.h>
#include <windows.h>
#include "terminal.h"

int getTerminalWidth() {
    CONSOLESCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.srWindow.Right - csbi.srWindow.Left + 1;
}