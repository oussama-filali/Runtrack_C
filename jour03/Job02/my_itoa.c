#include <stdlib.h>

char *my_itoa(int n) {
    int len = 0;
    int is_neg = 0;
    unsigned int num;

    if (n == 0) {
        len = 1;
        num = 0;
    } else {
        if (n < 0) {
            is_neg = 1;
            // Handle INT_MIN by casting to unsigned before negation if needed, 
            // but negation of INT_MIN is undefined in signed int.
            // Safe way: cast to unsigned, then negate.
            num = (unsigned int)n; 
            num = -num; 
            len++; // For the '-' sign
        } else {
            num = (unsigned int)n;
        }

        unsigned int temp = num;
        while (temp != 0) {
            temp /= 10;
            len++;
        }
    }

    char *str = (char *)malloc((len + 1) * sizeof(char));
    if (!str) return NULL;

    str[len] = '\0';
    
    // Fill backwards
    int i = len - 1;
    if (num == 0) {
        str[0] = '0';
        return str;
    }

    while (num != 0) {
        str[i] = (num % 10) + '0';
        num /= 10;
        i--;
    }

    if (is_neg) {
        str[0] = '-';
    }

    return str;
}
