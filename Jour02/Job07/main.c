#include <stdio.h>
#include <stdlib.h>

// Declaration of the function implemented in lowercase.c
char *lowercase(const char *str);

static void my_putchar(char c) {
    putchar(c);
}

static void my_putstr(const char *str) {
    if (!str) return;
    for (int i = 0; str[i]; i++) {
        my_putchar(str[i]);
    }
}

int main(int argc, char **argv) {
    if (argc < 2) return 0;

    for (int i = 1; i < argc; i++) {
        char *res = lowercase(argv[i]);
        if (res) {
            my_putstr(res);
            my_putchar('\n');
            free(res);
        }
    }
    return 0;
}
