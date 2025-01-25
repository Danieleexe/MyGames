/*
* Author: Daniele
 * Date: 25/01/2025
*/

#include "Tris.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> // Per la sleep() del computer

// Inizializza la griglia con spazi vuoti
void inizializzaGriglia(char griglia[RIGHE][COLONNE]) {
    for (int i = 0; i < RIGHE; i++) {
        for (int j = 0; j < COLONNE; j++) {
            griglia[i][j] = VUOTO;
        }
    }
}

// Stampa la griglia con bordi ASCII
void stampaGriglia(char griglia[RIGHE][COLONNE]) {
    printf("\n");
    printf(" %c | %c | %c \n", griglia[0][0], griglia[0][1], griglia[0][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", griglia[1][0], griglia[1][1], griglia[1][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", griglia[2][0], griglia[2][1], griglia[2][2]);
    printf("\n");
}

// Controlla se una mossa è valida
int mossaValida(int cella, char griglia[RIGHE][COLONNE]) {
    if (cella < 0 || cella > 8) return 0; // Fuori intervallo
    int riga = cella / 3;
    int colonna = cella % 3;
    return (griglia[riga][colonna] == VUOTO);
}

// Controlla se un giocatore ha vinto
int controllaVittoria(char griglia[RIGHE][COLONNE], char simbolo) {
    // Controlla righe e colonne
    for (int i = 0; i < RIGHE; i++) {
        if (griglia[i][0] == simbolo && griglia[i][1] == simbolo && griglia[i][2] == simbolo) return 1;
        if (griglia[0][i] == simbolo && griglia[1][i] == simbolo && griglia[2][i] == simbolo) return 1;
    }
    // Controlla diagonali
    if (griglia[0][0] == simbolo && griglia[1][1] == simbolo && griglia[2][2] == simbolo) return 1;
    if (griglia[0][2] == simbolo && griglia[1][1] == simbolo && griglia[2][0] == simbolo) return 1;
    return 0;
}

// Controlla se la griglia è piena
int grigliaPiena(char griglia[RIGHE][COLONNE]) {
    for (int i = 0; i < RIGHE; i++) {
        for (int j = 0; j < COLONNE; j++) {
            if (griglia[i][j] == VUOTO) return 0;
        }
    }
    return 1;
}

// Gestisce la mossa del giocatore umano
void mossaGiocatore(char griglia[RIGHE][COLONNE], char simbolo) {
    int cella;
    do {
        printf("Inserisci il numero della cella (0-8): ");
        scanf("%d", &cella);
        if (!mossaValida(cella, griglia)) {
            printf("Mossa non valida! Riprova.\n");
        }
    } while (!mossaValida(cella, griglia));

    int riga = cella / 3;
    int colonna = cella % 3;
    griglia[riga][colonna] = simbolo;
}

// Gestisce la mossa del computer (con difficoltà)
void mossaComputer(char griglia[RIGHE][COLONNE], char simbolo, int difficolta) {
    printf("Il computer sta pensando...\n");
    sleep(3); // Ritardo di 3 secondi

    if (difficolta == FACILE) {
        // Modalità facile: mossa casuale
        int cella;
        do {
            cella = rand() % 9;
        } while (!mossaValida(cella, griglia));
        int riga = cella / 3;
        int colonna = cella % 3;
        griglia[riga][colonna] = simbolo;
        printf("Il computer ha giocato in %d\n", cella);
    } else if (difficolta == MEDIO) {
        // Modalità medio: cerca di vincere o bloccare il giocatore
        char avversario = (simbolo == GIOCATORE1) ? GIOCATORE2 : GIOCATORE1;
        int cella = -1;

        // Cerca una mossa vincente
        for (int i = 0; i < 9; i++) {
            if (mossaValida(i, griglia)) {
                int riga = i / 3;
                int colonna = i % 3;
                griglia[riga][colonna] = simbolo;
                if (controllaVittoria(griglia, simbolo)) {
                    griglia[riga][colonna] = VUOTO;
                    cella = i;
                    break;
                }
                griglia[riga][colonna] = VUOTO;
            }
        }

        // Se non trova una mossa vincente, cerca di bloccare il giocatore
        if (cella == -1) {
            for (int i = 0; i < 9; i++) {
                if (mossaValida(i, griglia)) {
                    int riga = i / 3;
                    int colonna = i % 3;
                    griglia[riga][colonna] = avversario;
                    if (controllaVittoria(griglia, avversario)) {
                        griglia[riga][colonna] = VUOTO;
                        cella = i;
                        break;
                    }
                    griglia[riga][colonna] = VUOTO;
                }
            }
        }

        // Se non trova nulla, fa una mossa casuale
        if (cella == -1) {
            do {
                cella = rand() % 9;
            } while (!mossaValida(cella, griglia));
        }

        int riga = cella / 3;
        int colonna = cella % 3;
        griglia[riga][colonna] = simbolo;
        printf("Il computer ha giocato in %d\n", cella);
    }
}

// Mostra un messaggio di benvenuto
void mostraBenvenuto() {
    printf("************************************\n");
    printf("* Benvenuto nel gioco del Tris!   *\n");
    printf("************************************\n");
}

// Mostra le regole del gioco
void mostraRegole() {
    printf("\nRegole del gioco:\n");
    printf("- Il gioco si svolge su una griglia 3x3.\n");
    printf("- Ogni giocatore sceglie una cella inserendo un numero da 0 a 8.\n");
    printf("- Vince chi allinea tre simboli (X o O) in una riga, colonna o diagonale.\n");
    printf("- Se la griglia e' piena e nessuno ha vinto, e' pareggio.\n");
    printf("\nEcco la griglia con i numeri delle celle:\n");
    printf(" 0 | 1 | 2 \n");
    printf("---+---+---\n");
    printf(" 3 | 4 | 5 \n");
    printf("---+---+---\n");
    printf(" 6 | 7 | 8 \n");
    printf("\n");
}

// Scegli la modalità di gioco
int scegliModalita() {
    int scelta;
    do {
        printf("Scegli la modalita' di gioco:\n");
        printf("1. Giocatore vs Giocatore\n");
        printf("2. Giocatore vs Computer\n");
        printf("Scelta: ");
        scanf("%d", &scelta);
    } while (scelta != 1 && scelta != 2);
    return scelta;
}

// Scegli la difficoltà del computer
int scegliDifficolta() {
    int scelta;
    do {
        printf("Scegli la difficolta' del computer:\n");
        printf("1. Facile\n");
        printf("2. Medio\n");
        printf("Scelta: ");
        scanf("%d", &scelta);
    } while (scelta < 1 || scelta > 2);
    return scelta;
}

// Mostra il punteggio
void mostraPunteggio(int punteggioGiocatore1, int punteggioGiocatore2, int pareggi) {
    printf("\nPunteggio:\n");
    printf("Giocatore 1 (X): %d\n", punteggioGiocatore1);
    printf("Giocatore 2 (O): %d\n", punteggioGiocatore2);
    printf("Pareggi: %d\n", pareggi);
    printf("\n");
}

// Chiede all'utente se vuole giocare di nuovo
char giocaDiNuovo() {
    char scelta;
    printf("Vuoi giocare di nuovo? (s/n): ");
    scanf(" %c", &scelta);
    return scelta;
}