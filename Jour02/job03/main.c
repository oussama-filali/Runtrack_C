#include <stdio.h>
#include <stdlib.h>

char **array_clone(char **strs, int n);

int main() {
    char *arr[] = {"Apple", "Banana", "Cherry", NULL};
    char **cloned = array_clone(arr, 2);

    if (cloned) {
        for (int i = 0; cloned[i] != NULL; i++) {
            printf("Cloned[%d]: %s\n", i, cloned[i]);
            free(cloned[i]);
        }
        free(cloned);
    }
    return 0;
}
