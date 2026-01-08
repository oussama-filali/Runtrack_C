#include <stdio.h>

int my_sqrt(int n);

int main() {
    printf("my_sqrt(4) = %d\n", my_sqrt(4));
    printf("my_sqrt(9) = %d\n", my_sqrt(9));
    printf("my_sqrt(16) = %d\n", my_sqrt(16));
    printf("my_sqrt(1) = %d\n", my_sqrt(1));
    printf("my_sqrt(0) = %d\n", my_sqrt(0));
    printf("my_sqrt(2) = %d\n", my_sqrt(2));
    printf("my_sqrt(81) = %d\n", my_sqrt(81));
    printf("my_sqrt(-5) = %d\n", my_sqrt(-5));
    return 0;
}
