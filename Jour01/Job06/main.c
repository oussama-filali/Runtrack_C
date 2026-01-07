#include <stdio.h>

int my_strcmp(const char *s1, const char *s2);

int main() {
    char *s1 = "Hello";
    char *s2 = "Hello";
    char *s3 = "World";
    char *s4 = "Hell";

    printf("strcmp(Hello, Hello) = %d\n", my_strcmp(s1, s2));
    printf("strcmp(Hello, World) = %d\n", my_strcmp(s1, s3));
    printf("strcmp(Hello, Hell) = %d\n", my_strcmp(s1, s4));
    printf("strcmp(Hell, Hello) = %d\n", my_strcmp(s4, s1));

    return 0;
}
