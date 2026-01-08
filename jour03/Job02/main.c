#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

char *my_itoa(int n);

int main() {
    int tests[] = {0, 123, -456, 42, -1, 2147483647, INT_MIN};
    int count = sizeof(tests) / sizeof(tests[0]);

    for (int i = 0; i < count; i++) {
        char *s = my_itoa(tests[i]);
        printf("my_itoa(%d) = \"%s\"\n", tests[i], s);
        free(s);
    }
    return 0;
}
