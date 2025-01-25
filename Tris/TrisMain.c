/*
* Author: Daniele
 * Date: 25/01/2025
*/

#include "Tris.h"
#include <stdio.h>

#include "Tris.h"

int main() {
 char griglia[RIGHE][COLONNE];
 char giocatoreCorrente = GIOCATORE1;
 int vittoria = 0;
 int modalita, difficolta = FACILE;
 int punteggioGiocatore1 = 0, punteggioGiocatore2 = 0, pareggi = 0;
 char continua;

 mostraBenvenuto();
 mostraRegole();

 modalita = scegliModalita();
 if (modalita == 2) {
  difficolta = scegliDifficolta();
 }

 do {
  inizializzaGriglia(griglia);
  stampaGriglia(griglia);

  while (1) {
   if (giocatoreCorrente == GIOCATORE1) {
    mossaGiocatore(griglia, giocatoreCorrente);
   } else {
    if (modalita == 1) {
     mossaGiocatore(griglia, giocatoreCorrente);
    } else {
     mossaComputer(griglia, giocatoreCorrente, difficolta);
    }
   }

   stampaGriglia(griglia);

   if (controllaVittoria(griglia, giocatoreCorrente)) {
    if (giocatoreCorrente == GIOCATORE1) {
     punteggioGiocatore1++;
     printf("Giocatore 1 (X) ha vinto!\n");
    } else {
     punteggioGiocatore2++;
     printf("Giocatore 2 (O) ha vinto!\n");
    }
    break;
   }

   if (grigliaPiena(griglia)) {
    pareggi++;
    printf("Pareggio!\n");
    break;
   }

   // Cambia giocatore
   giocatoreCorrente = (giocatoreCorrente == GIOCATORE1) ? GIOCATORE2 : GIOCATORE1;
  }

  mostraPunteggio(punteggioGiocatore1, punteggioGiocatore2, pareggi);
  continua = giocaDiNuovo();
 } while (continua == 's' || continua == 'S');

 printf("Grazie per aver giocato!\n");
 return 0;
}