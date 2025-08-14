#define _POSIX_C_SOURCE 199309L
#include <stdio.h>
#include <stdlib.h>
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
    const char *easyPrac[] = {
        "the quick brown fox jumps over the lazy dog",
        "sixty zippers were quickly picked from the woven jute bag",
        "my girl wove six dozen plaid jackets before she quit",
        "brown jars prevented the mixture from freezing too quickly",
        "we promptly judged antique ivory buckles for the next prize",
        "farmer Jack realized that big yellow quilts were expensive",
        "when zombies arrive quickly fax Judge pat"
    };
    //char foxS[] = "the quick brown fox jumps over the lazy dog";
    int totalSentences = sizeof(easyPrac) / sizeof(easyPrac[0]);
    srand(time(NULL));

    int index = rand() % totalSentences;

    char *chosen = easyPrac[index];

    size_t length = strlen(chosen);
    int correctChar = 0;
    int wordCount = 0;
    int insideWord = 0;

    printf("Type what is shown below:\n\n");
    printf("%s\n\n", chosen);

    double start = checkTime();

    char typed[length + 1];
    scanf("%[^\n]", typed);

    double end = checkTime();

    // loop to check if the typed string is the same as what is given and for the amount of words
    for(int i = 0; i<length; i++){
        char character = chosen[i];
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