#include <stdbool.h>
#include "mode.h"

Mode mode = MODE_NORMAL;

const char* showMode() {
    if (mode == MODE_DEBUG) {
        return "Debug";
    } else {
        return "Normal";
    }
}

bool checkMode() {
    if (mode == MODE_DEBUG) {
        return true;
    } else {
        return false;
    }
}