#include <stdio.h>

int my_strlen(char const *str);

int main()
{
    char *str = "Hello World!";
    int len = my_strlen(str);
    printf("Length of '%s': %d\n", str, len);
    return 0;
}
