#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <windows.h>
#include "functions.h"

void flush_input() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}
