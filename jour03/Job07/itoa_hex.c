#include <stdlib.h>

char *itoa_hex(int n) {
    // Treat as unsigned for hex representation (standard behavior for hex dump)
    unsigned int num = (unsigned int)n;
    
    // Calculate length
    int len = 0;
    unsigned int temp = num;
    if (temp == 0) {
        len = 1;
    } else {
        while (temp != 0) {
            temp /= 16;
            len++;
        }
    }

    char *str = (char *)malloc((len + 1) * sizeof(char));
    if (!str) return NULL;

    str[len] = '\0';
    
    // Fill backwards
    if (num == 0) {
        str[0] = '0';
        return str;
    }

    char *base = "0123456789ABCDEF";
    int i = len - 1;
    while (num != 0) {
        str[i] = base[num % 16];
        num /= 16;
        i--;
    }
    
    return str;
}
