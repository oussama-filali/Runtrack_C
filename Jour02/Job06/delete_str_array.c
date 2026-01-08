#include <stdlib.h>

void delete_str_array(char ***array_ptr) {
    if (!array_ptr || !*array_ptr) return;

    char **array = *array_ptr;
    for (int i = 0; array[i] != NULL; i++) {
        free(array[i]);
    }
    free(array);
    *array_ptr = NULL;
}
