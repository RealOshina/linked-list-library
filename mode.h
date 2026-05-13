#ifndef MODE_H
#define MODE_H

typedef enum {
    MODE_NORMAL,
    MODE_DEBUG
} Mode;

extern Mode mode;

const char* showMode();
bool checkMode();

#endif