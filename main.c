//Examen opdracht IOT1 - 2025 - Behaald resultaat: 19/20
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define AANTAL 200 // Declareer een constante AANTAL op de waarde 200.

int countInRange(int *value,int min, int max);
void printBinary(unsigned number);

int main(void) {
    //-----------
    // Vraag 1
    //-----------
    // Declareer een constante AANTAL op de waarde 200.
        // Zie boven main

    // Declareer een array van 200 ints, en gebruik de constante AANTAL daarvoor.
    // Initialiseer die array op 200 random nummers in de range [0, 100[ (0 zit er bij, 100 niet).
    int array[AANTAL];
    int i;
    srand(time(0));

    for (i = 0; i < AANTAL; i++)
    {
        array[i] = rand() % 100;
    }

    printf("Testing the array: \n");
    for (i = 0; i < AANTAL; i++)
    {
        printf("%i ", array[i]);
    }
    printf("\n");


    // Schrijf een nieuwe functie 'countInRange()'.
    // De functie telt hoeveel getallen in de array er in een bepaalde range vallen, en returnt die waarde.
    // Die range = [MIN, MAX], dus onder- en bovengrens zitten er bij.

    // Deze functie mag je NIET recursief programmeren.
    // Je geeft als argumenten aan de functie de array en MIN en MAX mee.

    // Beslis zelf welke van deze parameters je by value of by reference meegeeft.
    // Laat uw keuze leiden door een streven naar het gebruik van zo weinig mogelijk geheugen
    // (we gaan dus zo efficient mogelijk om met het beschikbare geheugen).
    // Leg in het licht daarvan uit waarom je hebt gekozen om bepaalde parameters by value of by reference te maken.

    // Print het resultaat.
    #define MIN 0
    #define MAX 50

    //int * values = calloc(AANTAL, sizeof(int));
    int * values = array;

    int amountInRange = countInRange(values,MIN, MAX);
    printf("\nThere are %d numbers in range\n\n", amountInRange);

    //free(values);

    /*
     * Ik heb gekozen om de min en max by value te gebruiken omdat deze vrij weinig geheugen innemen (int = 4bytes) en zo is het eenvoudig
     * met deze waarde te spelen/ te veranderen.
     * Ik had eerst op voorhand geheugen gealoceerd maar dit had geen effect omdat de pointer
     * die naar de array van getallen wijst (by reference) dit niet perse nodig heeft.
     * Deze by reference doen we omdat het zo vrij eenvoudig is om met deze getallen aan te spreken en met te kunnen werken.
     **/




    //-----------
    // Vraag 2
    //-----------

    // 113 decimaal = 0111 0001 binair
    //
    // Schrijf code die de bits op positie 7 en 3 op 1 zet.

    // Print het resultaat

    //Stap1 AND
    //      0111 0001   113 dec
    //      0111 0111   119 dec
    //      ---------
    //      0111 0001   113 dec

    //Stap2 Shift
    //      0001 0001           after lEFT shift 3. (dec 17)
    //      ---------
    //      1000 1000          these are the bits we want to write (dec 136).

    //Stap3 OR
    //      0111 0001
    //      1000 1000
    //      ---------
    //      1111 1001    249 dec

    unsigned short int result = 0;
    result = (113 & 119) | (17 << 3);
    printf("\nThe binairy result is:\n");
    printBinary(result);
    printf("\n");



    //-----------
    // Vraag 3
    //-----------

    // SONGS bestaan uit NOTES, die een noteNumber en noteLength als fields hebben.
    // Hieronder staat code die een eenvoudige manier om songs bij te houden, gebruikt.
    // Zet de code uit commentaar, build en je hebt errors.
    //
    // De code werkt niet omdat de 2 structs (genaamd SONG en NOTE) die er voor nodig zijn nog niet gedefinieerd zijn.
    // Pas nu een soort reverse engineering toe om de code werkend te krijgen, door die 2 structs te definieren.
    //
    // Randinformatie: deze song bevat 10 noten die op een random waarde tussen 0 en 128 geinitialiseerd worden. 0 komt overeen met de laagste noot
    // op een klavier, 128 met de hoogste. De lengte staat op 4, dat is een kwart noot.
    //
    // Je zal ook een variable moeten declareren van de juiste struct.
    //
    // Dit is de verwachte output met random nootwaarden:

    /*
        Song titel: At ease
        BPM: 160
        Eerste 10 noten:
            Nummer:  124, lengte:   4
            Nummer:  122, lengte:   4
            Nummer:    8, lengte:   4
            Nummer:   31, lengte:   4
            Nummer:   78, lengte:   4
            Nummer:   40, lengte:   4
            Nummer:   42, lengte:   4
            Nummer:   35, lengte:   4
            Nummer:   82, lengte:   4
            Nummer:   24, lengte:   4
    */

    #define AANTAL_NOTEN 10

    struct Note
    {
        int noteNumber;
        int noteLength;
    };

    struct Song
    {
        char *title;
        int beatsPerMinute;
        struct Note notes[AANTAL_NOTEN];
    };

    struct Song song;

    song.title = (char *) calloc(100, sizeof(char));
    strcpy(song.title, "At ease");
    song.beatsPerMinute = 160;

    for (int i = 0; i < AANTAL_NOTEN; i++)
    {
        song.notes[i].noteNumber = rand() % 128;
        song.notes[i].noteLength = 4;
    }

    printf("\nSong titel: %s", song.title);
    printf("\nBPM: %d", song.beatsPerMinute);
    printf("\nEerste 10 noten:");
    for (int i=0; i<10; i++)
    {
        printf("\n\tNummer:\t%4d, lengte:\t%d", song.notes[i].noteNumber, song.notes[i].noteLength);
    }

    free(song.title);
    printf("\n\n");

    return 0;
}

int countInRange(int * value,int min, int max) {
    int i;
    int count = 0;
    for (i = 0; i < AANTAL; i++)
    {
        int selectedValue = *value++;
        if (selectedValue>= min && selectedValue <= max) {
            ++count;
        }
    }
    return count;
}

void printBinary(unsigned number)
{
    unsigned i;
    for (i = 128; i > 0; i = i / 2)
    {
        (number & i) ? printf("1") : printf("0");
    }
}