#include <stddef.h>

int my_strcmp_local(const char *s1, const char *s2) {
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *(unsigned char *)s1 - *(unsigned char *)s2;
}

void sort(char **strs) {
    if (!strs) return;

    int n = 0;
    while (strs[n]) n++;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (my_strcmp_local(strs[j], strs[j + 1]) > 0) {
                char *temp = strs[j];
                strs[j] = strs[j + 1];
                strs[j + 1] = temp;
            }
        }
    }
}
