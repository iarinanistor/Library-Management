#include "entreeSortieLC.h" 
#include <stdlib.h> 

// Fonction pour charger les n premières entrées à partir d'un fichier dans une bibliothèque
Biblio* charger_n_entrees(char* nomfic, int n){
    FILE *f = fopen(nomfic,"r"); // Ouvre le fichier en mode lecture

    // Vérifie si l'ouverture a réussi
    if (f == NULL) {
        printf("Erreur ouverture %s\n", nomfic);
        return NULL;
    }

    Biblio *b = creer_biblio(); // Crée une nouvelle bibliothèque vide
    int num;
    char titre[100];
    char auteur[100];
    char buffer[256];
    fgets(buffer, 256, f); // Lit la première ligne du fichier

    int i = 0;
    while (i < n) { // Boucle pour lire les n premières lignes du fichier
        sscanf(buffer, " %d %s %s", &num, titre, auteur); // Lit les informations du livre depuis le buffer
        inserer_en_tete(b, num, titre, auteur); 
        fgets(buffer, 256, f); // Lit la ligne suivante du fichier
        i++;
    }

    fclose(f); // Ferme le fichier
    return b; 
}

// Fonction pour enregistrer tous les livres d'une bibliothèque dans un fichier
void enregistrer_biblio(Biblio *b, char* nomfic){
    FILE *f = fopen(nomfic, "w"); // Ouvre le fichier en mode écriture

    // Vérifie si l'ouverture a réussi
    if (f == NULL) {
        printf("Erreur ouverture %s\n", nomfic);
        return;
    }

    Livre *l = b->L; // Pointeur pour parcourir les livres de la bibliothèque

    // Boucle pour parcourir tous les livres de la bibliothèque et les écrire dans le fichier
    while (l) {
        fprintf(f, "%d %s %s\n", l->num, l->titre, l->auteur); // Écrit les informations du livre dans le fichier
        l = l->suiv; 
    }

    fclose(f); // Ferme le fichier
} 


