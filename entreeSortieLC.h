#ifndef ENTREESORTIELC_h
#define ENTREESORTIELC_h

#include <stdio.h> 
#include "biblioLC.h" 

// Fonction pour charger les n premières entrées à partir d'un fichier dans une bibliothèque
Biblio* charger_n_entrees(char* nomfic, int n);

// Fonction pour enregistrer tous les livres d'une bibliothèque dans un fichier
void enregistrer_biblio(Biblio *b, char* nomfic);

#endif

