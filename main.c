#include <stdio.h>
#include <string.h>

int main() {
    char foxS[] = "the quick brown fox jumps over the lazy dog";
    size_t length = strlen(foxS);
    

    for(int i = 0; i<length; i++){
        //printf("times looped: %zu.\n", i);

        char character = foxS[i];
        printf("char at %zu, is: %c.\n",i,character);
    }

    printf("Length of string is %zu.\n", length);
    return 0;
}