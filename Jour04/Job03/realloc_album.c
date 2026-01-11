#include "../album.h"
#include <stdlib.h>

struct album *realloc_album(struct album *arr, size_t current_size, size_t new_size) {
    struct album *new_arr = NULL;
    if (new_size > 0) {
        new_arr = (struct album *)malloc(new_size * sizeof(struct album));
        if (!new_arr) {
            return NULL;
        }
    }
    if (arr && new_arr) {
        size_t n = current_size < new_size ? current_size : new_size;
        for (size_t i = 0; i < n; ++i) {
            new_arr[i] = arr[i];
        }
    }
    if (arr) {
        free(arr);
    }
    return new_arr;
}
