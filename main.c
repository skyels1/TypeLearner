#include <stdio.h>
#include <string.h>

int main() {
    char foxS[] = "the quick brown fox jumps over the lazy dog";
    size_t length = strlen(foxS);
    char typed[] = "the quick brown fox jimps over the lszy dog"; // two wrong characters to test

    /* i dont want to type every test right now
    char typed[length + 1];
    scanf("%[^\n]s", typed);
    printf("%s\n", typed);
*/
    
    for(int i = 0; i<length; i++){
        char character = foxS[i];
        char typedCharacter = typed[i];
        //printf("char at  pos.%zu, is: %c.\n",i,character);
        //printf("char at  pos.%zu, is: %c.\n",i,typedCharacter);

        if(typedCharacter==character){

            printf("they are the same\n");
        }
        else{
            printf("they are different\n");
        }
    }

    //printf("Length of string is %zu.\n", length);
    return 0;
}