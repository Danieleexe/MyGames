#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TENTATIVI 10

int main() {
    srand(time(0)); // Inizializza il generatore di numeri casuali
    int numeroCasuale = rand() % 100 + 1; // Genera un numero tra 1 e 100
    int tentativo, tentativi = 0;

    printf("Indovina il numero tra 1 e 100!\n");

    do {
        printf("Inserisci il tuo tentativo: ");
        scanf("%d", &tentativo);
        tentativi++;

        if (tentativo < numeroCasuale) {
            printf("Troppo basso!\n");
        } else if (tentativo > numeroCasuale) {
            printf("Troppo alto!\n");
        } else {
            printf("Hai indovinato in %d tentativi!\n", tentativi);
        }
    } while (tentativo != numeroCasuale);

    return 0;
}