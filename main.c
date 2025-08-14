#define _POSIX_C_SOURCE 199309L
#include <stdio.h>
#include <string.h>
#include <time.h>

int checkSpace(char c) {
    if(c == ' ' || c == '\t' || c == '\n'){
        return 1;
    } else {
        return 0;
    }
}

double checkTime(){
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec + ts.tv_nsec / 1e9;
}

int main() {
    char foxS[] = "the quick brown fox jumps over the lazy dog";
    size_t length = strlen(foxS);
    int correctChar = 0;
    int wordCount = 0;
    int insideWord = 0;

    printf("Type what is shown below:\n\n");
    printf("%s\n\n", foxS);

    double start = checkTime();

    char typed[length + 1];
    scanf("%[^\n]", typed);

    double end = checkTime();

    // loop to check if the typed string is the same as what is given and for the amount of words
    for(int i = 0; i<length; i++){
        char character = foxS[i];
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

    //printf("\nYou took %.2f seconds.\n", elapsed);

    //printf("\nword count is: %i\n", wordCount);

    float WPM = ((wordCount * 60) / (double)elapsed);

    printf("\nWPM is: %.2f\n", WPM);
    // calculate the acc
    float acc = ((double)correctChar/(double)length)*100;
    // print stats
    printf("\nacc is: %.2f%%\n", acc);

    return 0;
}