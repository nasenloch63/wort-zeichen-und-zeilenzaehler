#include <stdio.h>

int main(int argc, char *argv[]) {

    int anzahlZeichen = 0;
    int anzahlWoerter = 0;
    int anzahlZeilen = 0;

    if(argc != 2) {
        printf("Fehler: Genau ein Dateiname muss angegeben werden.\n");
        return 1;
    }
    FILE *datei;

    datei = fopen(argv[1], "r");

    if (datei == NULL) {
        printf("Fehler: Datei kann nicht geöffnet werden\n");
        return 1;
    }

    int zeichen;

    while ((zeichen = fgetc(datei)) != EOF)
    {
        printf("%c", zeichen);
        anzahlZeichen++;
    }

    printf("Zeichen: %d\n", anzahlZeichen);

return 0;
}