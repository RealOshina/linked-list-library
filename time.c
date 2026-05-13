#include <time.h>
#include "time.h"

int getHour() {
    time_t rawtime = time(NULL);

    struct tm *timeinfo = localtime(&rawtime);

    int hour = timeinfo->tm_hour;

    return hour;
}

const char* greeting(int time)  {
    if (time < 0 || time >= 24) {
        return "Time";
    } else if (time >= 5 && time < 12) {
        return "Morning";
    } else if (time >= 12 && time < 18) {
        return "Afternoon";
    } else if (time >= 18 && time < 21) {
        return "Evening";
    } else if (time <= 21 && time < 5) {
        return "Mood";
    }
}