#include "random.h"

// Случайное число типа int.
int randomInt(int from, int to) {
    return rand() % (to - from + 1) + from;
}

// Случайное число типа float.
float randomFloat() {
    return rand() * 1.0 / RAND_MAX;
}
