#include <stdio.h>

int char_is_digit(char c);
int str_is_digit(char const *str);

int main()
{
    char c = '5';
    char c2 = 'a';
    char *str1 = "12345";
    char *str2 = "123a5";

    printf("'%c' uses digit? %d\n", c, char_is_digit(c));
    printf("'%c' uses digit? %d\n", c2, char_is_digit(c2));
    
    printf("'%s' is all digits? %d\n", str1, str_is_digit(str1));
    printf("'%s' is all digits? %d\n", str2, str_is_digit(str2));

    return 0;
}
