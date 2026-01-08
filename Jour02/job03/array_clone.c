#include <stdlib.h>

char *my_strdup_local(const char *src) {
    if (!src) return NULL;
    int len = 0;
    while (src[len]) len++;
    char *dest = (char *)malloc(len + 1);
    if (!dest) return NULL;
    for (int i = 0; i <= len; i++) dest[i] = src[i];
    return dest;
}

char **array_clone(char **strs, int n) {
    if (!strs || n < 0) return NULL;

    int count = 0;
    while (count < n && strs[count] != NULL) {
        count++;
    }

    char **new_array = (char **)malloc((count + 1) * sizeof(char *));
    if (!new_array) return NULL;

    for (int i = 0; i < count; i++) {
        new_array[i] = my_strdup_local(strs[i]);
    }
    new_array[count] = NULL;

    return new_array;
}
