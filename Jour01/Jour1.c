#include <ctype.h>
int is_alpha(char c) {
    return 'A' <= c && c <= 'Z';
}       
int is_lower(char c) {
    return 'a' <= c && c <= 'z';
}
int is_upper(char c) {
    return 'A' <= c && c <= 'Z';
}
int is_printable(char c) {
    return 32 <= c && c <= 126;
}
int main() {
    char test_char = 'A';
    if (is_alpha(test_char))
        printf("%c is alphanumeric.\n", test_char);
    if (is_lower(test_char))
        printf("%c is lowercase.\n", test_char);
    if (is_upper(test_char))
        printf("%c is uppercase.\n", test_char);
    if (is_printable(test_char))
        printf("%c is printable.\n", test_char);
    return 0;
}