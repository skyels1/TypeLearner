#include <stdio.h>
#include <string.h>

int main() {
    char foxS[] = "the quick brown fox jumps over the lazy dog";
    size_t length = strlen(foxS);
    char typed[length + 1];
    scanf("%[^\n]s", typed);
    printf("%s\n", typed);
    
/*
    for(int i = 0; i<length; i++){
        char character = foxS[i];
        printf("char at  pos.%zu, is: %c.\n",i,character);
    }
*/
    //printf("Length of string is %zu.\n", length);
    return 0;
}