#include <stdio.h>

int my_atoi(char *str);

int main() {
    char *tests[] = {
        "123",
        "-456",
        "   789",
        "  -12",
        "+42",
        "0",
        "  123abc", // Should stop at characters
        NULL
    };

    for (int i = 0; tests[i] != NULL; i++) {
        printf("my_atoi(\"%s\") = %d\n", tests[i], my_atoi(tests[i]));
    }
    return 0;
}
