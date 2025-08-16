#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "checkSpace.h"
#include "checkTime.h"
#include "choseDifficulty.h"

int main() {
    const char *chosenSen = choseDifficulty();
    size_t length = strlen(chosenSen);
    int correctChar = 0;
    int wordCount = 0;
    int insideWord = 0;

    printf("Type what is shown below:\n\n");
    printf("%s\n\n", chosenSen);

    // flush the buffer from the held \n
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    double start = checkTime();

    char typed[length + 2];
    fgets(typed, length + 2, stdin);
    typed[strcspn(typed, "\n")] = 0;

    double end = checkTime();

    // loop to check if the typed string is the same as what is given and for the amount of words
    for(int i = 0; i<length; i++){
        char character = chosenSen[i];
        char typedCharacter = typed[i];

        if(!checkSpace(character)) {
            if(!insideWord){
                wordCount++;
                insideWord = 1;
            } 
        } else {
                insideWord = 0;
        }

        if(typedCharacter==character){

            correctChar++;
        }
    }
    double elapsed = end - start;

    printf("\nYou took %.2f seconds.\n", elapsed);

    //printf("\nword count is: %i\n", wordCount);

    float WPM = ((wordCount * 60) / (double)elapsed);
   
    // calculate the acc
    float acc = ((double)correctChar/(double)length);
    // print stats
    float accWPM = WPM * acc;
    printf("\nWPM is: %.2f\n", accWPM);
    printf("\naccuracy is: %.2f%%\n", acc * 100);
    printf("\nWPM without mistakes is: %.2f\n", WPM);

    return 0;
}