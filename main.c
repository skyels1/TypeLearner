#include <stdio.h>
#include <string.h>
#include <time.h>

int main() {
    char foxS[] = "the quick brown fox jumps over the lazy dog";
    size_t length = strlen(foxS);
    int correctChar = 0;
    int wordCount = 0;
    time_t start, end;

    printf("Type what is shown below:\n\n");
    printf("%s\n\n", foxS);

    time(&start);

    char typed[length + 1];
    scanf("%[^\n]", typed);

    time(&end);

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
    wordCount++;
    double deltaTime = difftime(end, start);

    printf("\nYou took %.0f seconds.\n", deltaTime);

    double WPM = ((wordCount * 60) / deltaTime);

    printf("\nWPM is: %.0f\n", WPM);
    // calculate the acc
    float acc = ((double)correctChar/(double)length)*100;
    // print stats
    printf("\nacc is: %.0f%%\n", acc);

    return 0;
}