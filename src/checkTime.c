#define _POSIX_C_SOURCE 199309L
#include "checkTime.h"
#include <time.h>

double checkTime(){
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec + ts.tv_nsec / 1e9;
}