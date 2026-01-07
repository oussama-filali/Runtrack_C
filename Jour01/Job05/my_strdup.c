#include <stdlib.h>

char *my_strdup(const char *src) {
    int len = 0;
    const char *temp = src;
    while (*temp++) len++;

    char *dest = (char *)malloc((len + 1) * sizeof(char));
    if (!dest) return NULL;

    char *ptr = dest;
    while (*src) {
        *ptr++ = *src++;
    }
    *ptr = '\0';

    return dest;
}