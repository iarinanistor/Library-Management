#ifndef ENTREESORTIEH_h
#define ENTREESORTIEH_h

#include <stdio.h>
#include "biblioH.h" 

// Déclaration des fonctions pour charger les entrées depuis un fichier et enregistrer une bibliothèque de hachage dans un fichier
BiblioH* charger_n_entreesH(char* nomfic, int n, int m);
void enregistrer_biblioH(BiblioH *b, char* nomfic);

#endif 

