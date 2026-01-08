#include <stdio.h>

char to_lower(char c) {
    if (is_upper(c)) {
        return c + ('a' - 'A');
    }
    return c;
}