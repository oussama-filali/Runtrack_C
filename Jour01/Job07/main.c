#include <stdio.h>

char *trim(char *str);

int main() {
    char str[] = "   Hello World!   ";
    printf("Before: '%s'\n", str);
    char *trimmed = trim(str);
    printf("After : '%s'\n", trimmed);
    return 0;
}
