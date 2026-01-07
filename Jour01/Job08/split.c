#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **split(const char *str, const char *delim) {
    int count = 0;
    char *copy = strdup(str);
    char *tmp = strtok(copy, delim);

    while (tmp != NULL) {
        count++;
        tmp = strtok(NULL, delim);
    }
    free(copy);

    char **result = malloc((count + 1) * sizeof(char *));
    if (!result) return NULL;

    copy = strdup(str);
    tmp = strtok(copy, delim);
    int i = 0;
    while (tmp != NULL) {
        result[i++] = strdup(tmp);
        tmp = strtok(NULL, delim);
    }
    result[i] = NULL;
    free(copy);

    return result;
}

void free_split(char **split_str) {
    if (!split_str) return;
    for (int i = 0; split_str[i] != NULL; i++) {
        free(split_str[i]);
    }
    free(split_str);
}