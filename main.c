#ifdef _WIN32
#include <window.h>
#define SLEEP(ms) Sleep(ms)
#else
#define SLEEP(ms) usleep((ms) * 1000)
#endif

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>

#include "user_input.h"
#include "memory_management.h"
#include "terminal.h"
#include "banner.h"
#include "user.h"
#include "time.h"
#include "mode.h"

#define RED "\x1B[31m"
#define GRN "\x1B[32m"
#define YEL "\x1B[33m"
#define BLU "\x1B[34m"
#define BOLD "\x1B[1;37m"
#define REDBOLD "\x1B[1;31m"
#define GRNBOLD "\x1B[1;32m"
#define YELBOLD "\x1B[1;33m"
#define RESET "\x1B[0m"

#define MENULIST printf(RESET "[1] Insert\n[2] Display List\n[3] Delete\n[4] Search\n[5] Reverse\n[6] Free\n[7] %s Mode\n[8] Exit\n", mode == MODE_DEBUG ? "Normal" : "Debug");
#define MODECONDITION(a) checkMode ? a : (void)0;

//x86_64-w64-mingw32-gcc main.c terminal_window.c memory_management.c user_input.c banner.c user.c time.c mode.c -o main.exe
//gcc main.c terminal_linux.c memory_management.c user_input.c banner.c user.c time.c mode.c -o main

int main() {
    char input[32];
    char choice;

    int terminal_size = getTerminalWidth();

    printCentered(getBanner());

    MODECONDITION(printf(YELBOLD "\nTerminal Width: %d\n" RESET, terminal_size));
    MODECONDITION(printf(YELBOLD "Hour: %d\n" RESET, getHour()))

    printf(BOLD "\nGood %s, %s. What do you want to do today?\n\n", greeting(getHour()),getUsername());
    printf(RESET "Menu List:\n");
    MENULIST;

    printf(RESET "> ");

    while (fgets(input, sizeof(input), stdin)) {
        if (sscanf(input, "%c", &choice) == 1) {
            if (choice == '1') {
                printf("Insert");
            } else if (choice == '2') {
                printf("Display List");
            } else if (choice == '3') {
                printf("Delete");
            } else if (choice == '4') {
                printf("Search");
            } else if (choice == '5') {
                printf("Reverse");
            } else if (choice == '6') {
                printf("Reverse");
            } else if (choice == '7') {
                if (mode == MODE_DEBUG) {
                    mode = MODE_NORMAL;
                } else {
                    mode = MODE_DEBUG;
                }
                printf(GRNBOLD "%s, switched to %s mode.\n\n", getUsername(), showMode());
            } else if (choice == '8') {
                int i;
                char dot[] = "...";
                
                printf("\n");

                for (i = 0; i < 4; i++) {
                    printf(REDBOLD "\rExit%.*s", i, dot);

                    fflush(stdout);
                    SLEEP(500);
                }

                printf("\n");
                exit(0);
            } else {
                printf(REDBOLD "Invalid Input.\n\n");
                (RESET "> ");
            }
        } else {
            printf(REDBOLD "Invalid Input.\n\n");
            printf(RESET "> ");
        }
        printf(RESET "> ");
    }

    return 0;
}