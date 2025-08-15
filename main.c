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
        "when zombies arrive quickly fax Judge pat",
        "how vexingly quick daft zebras jump",
        "fake bugs put in wax jonquils drive him crazy",
        "the five boxing wizards jump quickly",
        "waxy and quivering jocks fumble the pizza"
    };
    const char *midPrac[] = {
        "the summer sun drifted slowly across the open field where tall grass swayed in the gentle wind and the distant sound of a river echoed softly through the valley while a few birds circled lazily above looking for their next meal in the shimmering heat",
        "a small wooden boat rested near the shore of the quiet lake while ripples formed from the gentle breeze and fish darted just below the surface as dragonflies danced above the water and tall reeds leaned over like curious sentinels watching the calm afternoon pass",
        "the narrow dirt path wound through the forest where moss covered the roots and sunlight broke through the canopy in shifting golden patches as squirrels leapt between branches and a cool earthy smell filled the air hinting at the rain that had fallen earlier",
        "in the middle of the meadow wildflowers bloomed in a patchwork of colors and bees hummed busily between them while a distant hill cast a long shadow across the grass and a single oak tree stood tall against the horizon marking the edge of the land"
    };
    const char *hardPrac[] = {
        "The curious cat jumped over the tall wooden fence without making a sound.",
        "Despite the heavy rain, the children continued playing outside with laughter and joy.",
        "She carefully packed her suitcase, making sure not to forget her passport or phone charger.",
        "When the sun finally set, the sky turned shades of orange, pink, and purple.",
        "After finishing the book, he realized he had been completely absorbed for hours.",
        "The baker decorated the cake with delicate flowers and intricate icing patterns.",
        "Although he was tired, he stayed up late to finish the report before the deadline.",
        "The old library smelled of dust and leather, a comforting scent for book lovers.",
        "As the train approached, passengers hurried to find their seats and secure their luggage.",
        "During the storm, lightning illuminated the landscape, revealing distant hills and trees."
    };
    int selection;
    const char **difficulty;
    int totalSentences;
    printf("chose a difficulty (1 = easy, 2 = medium, 3 = hard)\n");
    scanf("%d", &selection);
    if(selection == 1){
        difficulty = easyPrac;
        totalSentences = sizeof(easyPrac) / sizeof(easyPrac[0]);
    }
    else if(selection == 2){
        difficulty = midPrac;
        totalSentences = sizeof(midPrac) / sizeof(midPrac[0]);
    }
    else if(selection == 3){
        difficulty = hardPrac;
        totalSentences = sizeof(hardPrac) / sizeof(hardPrac[0]);
    }
    else {
        printf("incorrect selection. default is easy.\n");
        difficulty = easyPrac;
        totalSentences = sizeof(easyPrac) / sizeof(easyPrac[0]);
    }
    srand(time(NULL));
    int index = rand() % totalSentences;
    const char *chosenSen = difficulty[index];
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