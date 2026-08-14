#include <stdio.h>

int main(int argc, char *argv[]) {

    int anzahlZeichen = 0;
    int anzahlWoerter = 0;
    int anzahlZeilen = 0;
 // 
    if(argc != 2) {
        printf("Fehler: Genau ein Dateiname muss angegeben werden.\n");
        return 1;
    }
    FILE *datei; 
// Dateiöffnung
    datei = fopen(argv[1], "r");

    if (datei == NULL) {
        printf("Fehler: Datei kann nicht gefunden werden\n");
        return 1;
    }

    int zeichen;
    int letztesZeichen = EOF;
   
    while ((zeichen = fgetc(datei)) != EOF)
    {
        letztesZeichen = zeichen;
        anzahlZeichen++;
        if (zeichen == '\n')
        {
            anzahlZeilen++;
        }
        
    }
     if (letztesZeichen != EOF && letztesZeichen != '\n')
    {
        anzahlZeilen++;
    }
    char wort[100];
    rewind(datei);

    while (fscanf(datei, "%99s", wort) ==1) {
        anzahlWoerter++;
    }
    printf("Zeichen: %d\n", anzahlZeichen);
    printf("Zeilen: %d\n", anzahlZeilen);
    printf("Wörter: %d\n", anzahlWoerter);
    fclose(datei);
return 0;
}