#include <stdio.h>

int power(int n, int p);

int main() {
    printf("power(2, 3) = %d\n", power(2, 3));
    printf("power(10, 0) = %d\n", power(10, 0));
    printf("power(5, 2) = %d\n", power(5, 2));
    printf("power(2, 4) = %d\n", power(2, 4));
    printf("power(3, -1) = %d\n", power(3, -1));
    return 0;
}
