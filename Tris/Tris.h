/*
* Author: Daniele
 * Date: 25/01/2025
*/

#ifndef TRIS_H
#define TRIS_H

// Costanti per le dimensioni della griglia
#define RIGHE 3
#define COLONNE 3

// Simboli per i giocatori
#define VUOTO ' '
#define GIOCATORE1 'X'
#define GIOCATORE2 'O'

// Difficoltà dell'IA
#define FACILE 1
#define MEDIO 2

// Dichiarazioni delle funzioni
void inizializzaGriglia(char griglia[RIGHE][COLONNE]);
void stampaGriglia(char griglia[RIGHE][COLONNE]);
int mossaValida(int cella, char griglia[RIGHE][COLONNE]);
int controllaVittoria(char griglia[RIGHE][COLONNE], char simbolo);
int grigliaPiena(char griglia[RIGHE][COLONNE]);
void mossaGiocatore(char griglia[RIGHE][COLONNE], char simbolo);
void mossaComputer(char griglia[RIGHE][COLONNE], char simbolo, int difficolta);
void mostraBenvenuto();
void mostraRegole();
int scegliModalita();
int scegliDifficolta();
void mostraPunteggio(int punteggioGiocatore1, int punteggioGiocatore2, int pareggi);
char giocaDiNuovo();

#endif