#include <stdio.h>
#include <string.h>

int main() {
    char myString[] = "the quick brown fox jumps over the lazy dog";
    size_t length = strlen(myString);

    printf("Length of string is %zu.\n", length);
    return 0;
}