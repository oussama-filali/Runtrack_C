#include <stdio.h>
#include <stdlib.h>

char **split(const char *str, const char *delim);
void free_split(char **split_str);

int main() {
    char *str = "Hello,how,are,you,today";
    char *delim = ",";
    char **result = split(str, delim);

    if (result) {
        for (int i = 0; result[i] != NULL; i++) {
            printf("[%d]: %s\n", i, result[i]);
        }
        free_split(result);
    }

    return 0;
}
