#include "choseDifficulty.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *choseDifficulty(void){
    const char *easyPrac[] = {
        "the quick brown fox jumps over the lazy dog",
        "sixty zippers were quickly picked from the woven jute bag",
        "my girl wove six dozen plaid jackets before she quit",
        "brown jars prevented the mixture from freezing too quickly",
        "we promptly judged antique ivory buckles for the next prize",
        "farmer jack realized that big yellow quilts were expensive",
        "when zombies arrive quickly fax judge pat",
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

    return chosenSen;
}