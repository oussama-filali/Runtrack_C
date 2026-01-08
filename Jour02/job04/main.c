#include <stdio.h>

void sort(char **strs);

int main() {
    char *arr[] = {"Banana", "Apple", "Cherry", "Date", NULL};
    
    printf("Before sort:\n");
    for(int i=0; arr[i]; i++) printf("%s ", arr[i]);
    printf("\n");

    sort(arr);

    printf("After sort:\n");
    for(int i=0; arr[i]; i++) printf("%s ", arr[i]);
    printf("\n");

    return 0;
}
