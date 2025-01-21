/*
 * Author: Daniele
 * Date: 21/01/2025
*/

#include "GuessTheNumber.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

// Funzione per stampare il messaggio di benvenuto
void stampaMessaggioBenvenuto() {
    printf("========================================\n");
    printf("| Benvenuto al gioco 'Indovina il Numero'! |\n");
    printf("========================================\n");
    printf("\n");
    printf("Regole del gioco:\n");
    printf("- Devi indovinare un numero tra 1 e 100.\n");
    printf("- Hai un massimo di %d tentativi.\n", MAX_TENTATIVI);
    printf("\n");
    printf("Iniziamo!\n");
    printf("\n");
}

// Funzione per generare un numero casuale tra 1 e 100
int generaNumeroCasuale() {
    srand(time(0)); // Inizializza il generatore di numeri casuali
    return rand() % 100 + 1; // Genera un numero tra 1 e 100
}

// Funzione per leggere il tentativo dell'utente
int leggiTentativo() {
    int tentativo;
    while (1) {
        printf("Inserisci il tuo tentativo: ");
        if (scanf("%d", &tentativo) == 1) {
            return tentativo;
        } else {
            printf("Input non valido. Per favore, inserisci un numero.\n");
            while (getchar() != '\n'); // Pulisce il buffer di input
        }
    }
}

// Funzione per stampare il messaggio di fine gioco
void stampaMessaggioFineGioco(int tentativi, int numeroCasuale) {
    printf("\n");
    printf("========================================\n");
    if (tentativi <= MAX_TENTATIVI) {
        printf("| Complimenti! Hai indovinato il numero! |\n");
        printf("| Il numero era: %3d                     |\n", numeroCasuale);
        printf("| Tentativi usati: %2d                   |\n", tentativi);
    } else {
        printf("| Hai esaurito i tentativi.              |\n");
        printf("| Il numero corretto era: %3d            |\n", numeroCasuale);
    }
    printf("========================================\n");
    printf("\n");
}