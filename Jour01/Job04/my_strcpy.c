#include <stdio.h>

char *my_strcpy(char *dest, const char *src) {
    char *ptr = dest;
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return ptr;
}