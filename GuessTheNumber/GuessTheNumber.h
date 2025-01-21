#ifndef GUESS_THE_NUMBER_H
#define GUESS_THE_NUMBER_H

// Costante per il numero massimo di tentativi
#define MAX_TENTATIVI 10

#include <stdio.h>

// Dichiarazioni delle funzioni
void stampaMessaggioBenvenuto();          // Stampa il messaggio di benvenuto
int generaNumeroCasuale();                // Genera un numero casuale tra 1 e 100
int leggiTentativo();                     // Legge il tentativo dell'utente
void stampaMessaggioFineGioco(int tentativi, int numeroCasuale); // Stampa il messaggio di fine gioco

#endif // GUESS_THE_NUMBER_H