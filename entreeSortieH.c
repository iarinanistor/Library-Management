#include "entreeSortieH.h"
#include <stdlib.h>

// Fonction pour charger les n premières entrées depuis un fichier dans une bibliothèque de hachage
BiblioH* charger_n_entreesH(char* nomfic, int n, int m){
    // Ouvrir le fichier en mode lecture
	FILE *f = fopen(nomfic,"r");
	
	// Vérifier si l'ouverture a réussi
	if (f == NULL) {
		printf("Erreur ouverture %s\n", nomfic);
		return NULL;
	}
	
	// Créer une nouvelle bibliothèque de hachage
	BiblioH *b = creer_biblioH(m);
	int num;
	char titre[100];
	char auteur[100];
	char buffer[256];
	fgets(buffer, 256, f);
	
	int i = 0;
	while (i < n) {
		sscanf(buffer, " %d %s %s", &num, titre, auteur);
		// Insérer le livre dans la bibliothèque de hachage
		insererH(b, num, titre, auteur);
		fgets(buffer, 256, f);
		i++;
	}
	
	// Fermer le fichier
	fclose(f);
	return b;
}

// Fonction pour enregistrer une bibliothèque de hachage dans un fichier
void enregistrer_biblioH(BiblioH *b, char* nomfic){
	// Ouvrir le fichier en mode écriture
	FILE *f = fopen(nomfic, "w");
	
	// Vérifier si l'ouverture a réussi
	if (f == NULL) {
		printf("Erreur ouverture %s\n", nomfic);
		return;
	}
	
	LivreH *curr;
	
	// Parcourir chaque entrée de la table de hachage
	for (int i = 0; i < (b->m); i++) {
		curr = b->T[i];
		while (curr) {
			// Écrire les informations du livre dans le fichier
			fprintf(f, "%d %s %s\n", curr->num, curr->titre, curr->auteur);
			curr = curr->suivant;
		}
	}
	
	// Fermer le fichier
	fclose(f);
}


