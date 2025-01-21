#include "GuessTheNumber.h"

int main() {
    int numeroCasuale = generaNumeroCasuale(); // Genera il numero casuale
    int tentativo, tentativi = 0;

    stampaMessaggioBenvenuto(); // Stampa il messaggio di benvenuto

    while (tentativi < MAX_TENTATIVI) {
        printf("----------------------------------------\n");
        printf("Tentativo %d di %d\n", tentativi + 1, MAX_TENTATIVI);
        tentativo = leggiTentativo(); // Legge il tentativo dell'utente
        tentativi++;

        if (tentativo < numeroCasuale) {
            printf("Il numero e' piu' alto!\n");
        } else if (tentativo > numeroCasuale) {
            printf("Il numero e' piu' basso!\n");
        } else {
            break; // L'utente ha indovinato il numero
        }
    }

    stampaMessaggioFineGioco(tentativi, numeroCasuale); // Stampa il messaggio di fine gioco

    return 0;
}