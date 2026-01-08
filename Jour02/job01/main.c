#include <stdio.h>

void divide(int *n);

int main() {
    int val = 42;
    printf("Before divide: %d\n", val);
    divide(&val);
    printf("After divide: %d\n", val);
    return 0;
}
