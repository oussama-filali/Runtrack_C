#include <stdio.h>

char *my_strcpy(char *dest, const char *src);

int main() {
    char src[] = "Hello World!";
    char dest[50];

    my_strcpy(dest, src);
    printf("Source: %s\n", src);
    printf("Dest: %s\n", dest);

    return 0;
}
