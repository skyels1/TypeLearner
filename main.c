#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char foxS[] = "the quick brown fox jumps over the lazy dog";
    size_t length = strlen(foxS);
    char typed[] = "the quick brown fox jimps over the lszy dog"; // two wrong characters to test roughtly 95% acc
    int correctChar = 0;
    int wordCount = 0;
    int WPM = 0;

    printf("Type what is shown below:\n\n");
    printf("%s\n\n", foxS);

    //char typed[length + 1];
    //scanf("%[^\n]s", typed);

    // loop to check if the typed string is the same as what is given and for the amount of words
    for(int i = 0; i<length; i++){
        char character = foxS[i];
        char typedCharacter = typed[i];

        if(character == ' ') {
            wordCount++;
        }

        if(typedCharacter==character){

            correctChar++;
        }
    }
    printf("word count of: %i\n", wordCount + 1);

    printf("\n\nWPM is: %.0f\n", WPM);
    // calculate the acc
    float acc = ((double)correctChar/(double)length)*100;
    // print stats
    printf("\nacc is: %.0f\n", acc);

    return 0;
}