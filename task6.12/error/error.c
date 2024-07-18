#include "error.h"

void error(char errorname[] ) {
    printf("\033[0;31mERROR: %s\033[0m\n", errorname);
    exit(1);
}
