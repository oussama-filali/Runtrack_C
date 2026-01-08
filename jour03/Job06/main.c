#include <unistd.h>

int my_atoi(char *str) {
    int i = 0, res = 0, sign = 1;
    if (str[i] == '-') {
        sign = -1;
        i++;
    }
    while (str[i]) {
        if (str[i] >= '0' && str[i] <= '9') {
            res = res * 10 + (str[i] - '0');
        } else {
            break;
        }
        i++;
    }
    return res * sign;
}

void my_putchar(char c) {
    write(1, &c, 1);
}

void my_putnbr(long long n) {
    if (n < 0) {
        my_putchar('-');
        n = -n;
    }
    if (n >= 10) {
        my_putnbr(n / 10);
    }
    my_putchar((n % 10) + '0');
}

int fibonacci(int n) {
    if (n < 0) return -1; 
    if (n == 0) return 0;
    if (n == 1) return 1;
    
    int a = 0;
    int b = 1;
    for (int i = 2; i <= n; i++) {
        int temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}

int main(int argc, char **argv) {
    if (argc != 2) return 0;

    int n = my_atoi(argv[1]);
    int result = fibonacci(n);
    
    // Result logic differs if negative input? Usually Fib not defined or defined via extension. 
    // Assuming positive index.
    
    my_putnbr(result);
    my_putchar('\n');
    return 0;
}
