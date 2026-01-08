#include <stddef.h>

void func_to_array(char **array, void (*f)(char *)) {
    if (!array || !f) return;
    for (int i = 0; array[i] != NULL; i++) {
        f(array[i]);
    }
}
