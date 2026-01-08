// Expose only the lowercase function (no main here)
#include <stdlib.h>

char *lowercase(const char *str) {
    if (!str) return NULL;

    int len = 0;
    while (str[len]) len++;

    char *out = (char *)malloc((len + 1) * sizeof(char));
    if (!out) return NULL;

    for (int i = 0; i < len; i++) {
        char c = str[i];
        if (c >= 'A' && c <= 'Z') {
            out[i] = (char)(c + 32);
        } else {
            out[i] = c;
        }
    }
    out[len] = '\0';
    return out;
}
