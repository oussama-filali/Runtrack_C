#include <stdio.h>

void func_to_array(char **array, void (*f)(char *));

void my_putstr(char *str) {
    if (str) printf("%s\n", str);
}

int main() {
    char *arr[] = {"Hello", "World", "C", "Programming", NULL};
    func_to_array(arr, my_putstr);
    return 0;
}
