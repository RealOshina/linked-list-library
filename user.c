#include <stdlib.h>
#include "user.h"

const char* getUsername() {
    #ifdef _WIN32
        return getenv("USERNAME");
    #elif __linux__
        return getenv("USER");
    #else
        return "user";
    #endif
}