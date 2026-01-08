#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void delete_str_array(char ***array_ptr);

int main() {
    char **arr = malloc(3 * sizeof(char *));
    arr[0] = strdup("Hello");
    arr[1] = strdup("World");
    arr[2] = NULL;

    printf("Array address before: %p\n", (void *)arr);
    delete_str_array(&arr);
    printf("Array address after: %p\n", (void *)arr);

    return 0;
}
