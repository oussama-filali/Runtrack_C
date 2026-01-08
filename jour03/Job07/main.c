#include <stdio.h>
#include <stdlib.h>

char *itoa_hex(int n);

int main() {
    int tests[] = {0, 10, 16, 255, -1, 42, 12, 100};
    for (int i = 0; i < 8; i++) {
        char *s = itoa_hex(tests[i]);
        printf("itoa_hex(%d) -> %s\n", tests[i], s);
        free(s);
    }
    return 0;
}
