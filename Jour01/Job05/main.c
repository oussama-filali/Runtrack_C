#include <stdio.h>
#include <stdlib.h>

char *my_strdup(const char *src);

int main() {
    char *original = "Hello, world!";
    char *duplicate = my_strdup(original);

    if (duplicate) {
        printf("Original: %s\n", original);
        printf("Duplicate: %s\n", duplicate);
        free(duplicate);
    } else {
        printf("Memory allocation failed\n");
    }

    return 0;
}
