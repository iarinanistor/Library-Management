#include "entreeSortieLC.h"
#include "biblioLC.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main() {

    Biblio *b = creer_biblio();
    inserer_en_tete(b, 1, "Fram", "Profa");
    inserer_en_tete(b, 2, "Singurpelume", "Hector");
	printf("affichage de la bibliotheque b\n");
    afficher_biblio(b);
    printf("\n");

    Livre *livre1 = recherche_titre(b, "Fram");
    Livre *livre2 = recherche_num(b, 2);
    Livre *livre3 = recherche_num(b, 3);

    printf("recherche par titre : 'Fram' \n");
    if (livre1 != NULL) {
        afficher_livre(livre1);
    } else {
        printf("Livre introuvable.\n");
    }

    printf("recherche par numero : '2' \n");
    if (livre2 != NULL) {
        afficher_livre(livre2);
    } else {
        printf("Livre introuvable.\n");
    }

    printf("recherche par numero : '3' \n");
    if (livre3 != NULL) {
        afficher_livre(livre3);
    } else {
        printf("Livre introuvable.\n");
    }

    printf("\n");
    printf("affichage de b apres l'ajout de deux livres : 'Nou' et 'malade'\n");
    inserer_en_tete(b, 3, "Nou", "Profa");
    inserer_en_tete(b,5,"malade","Profa");
    afficher_biblio(b);
    printf("affichage des ouvrages de l'auteur 'Profa'\n");
    Biblio *res = recherche_bib_auteur(b, "Profa");
    afficher_biblio(res);

    enregistrer_biblio(b, "Exemple");
    printf("\n");

    Biblio *b2 = charger_n_entrees("bib3.txt", 3);
    printf("affichage de la bibliotheque b2\n");
    afficher_biblio(b2);
    suppression_livre(b2, 1, "nou", "eu");
    printf("apres supression du livre de titre 'nou' et auteur 'eu' \n");
    afficher_biblio(b2);

    printf("\n");
    printf("fusion de b et b2\n");
    b = fusion_biblio(b, b2);
    afficher_biblio(b);

    printf("\n");
    printf("ajout des livres '6 malade Profa' et '7 Fram Profa'\n");
    inserer_en_tete(b,6,"malade","Profa");
    inserer_en_tete(b,7,"Fram","Profa");

    printf("affichage de b\n");
    afficher_biblio(b);

    printf("\n");
    Livre *resdup = recherche_dupliques(b);
    printf("affichage des doublons \n");
    while (resdup != NULL) {
        afficher_livre(resdup);
        resdup = resdup->suiv;
    }

    liberer_biblio(b);

    return 0;
}
