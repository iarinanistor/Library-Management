#include "entreeSortieH.h"
#include "biblioH.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main() {
    int m = 100;

    BiblioH *b = creer_biblioH(m);
    insererH(b, 1, "Fram", "Profa");
    insererH(b, 2, "Singurpelume", "Hector");
    printf("affichage de la bibliotheque b\n");
    afficher_biblioH(b);
    printf("\n");

    LivreH *livre1 = recherche_titreH(b, "Fram");
    LivreH *livre2 = recherche_numH(b, 2);
    LivreH *livre3 = recherche_numH(b, 3);

    printf("recherche par titre : 'Fram' \n");
    if (livre1 != NULL) {
        afficher_livreH(livre1);
    } else {
        printf("Livre introuvable.\n");
    }

    printf("recherche par numero : '2' \n");
    if (livre2 != NULL) {
        afficher_livreH(livre2);
    } else {
        printf("Livre introuvable.\n");
    }

    printf("recherche par numero : '3' \n");
    if (livre3 != NULL) {
        afficher_livreH(livre3);
    } else {
        printf("Livre introuvable.\n");
    }

    printf("\n");
    printf("affichage de b apres l'ajout de deux livres : 'Nou' et 'malade'\n");
    insererH(b, 3, "Nou", "Profa");
    insererH(b,5,"malade","Profa");
    afficher_biblioH(b);
    printf("affichage des ouvrages de l'auteur 'Profa'\n");
    LivreH *res = recherche_bib_auteurH(b, "Profa");
    while (res != NULL) {
        afficher_livreH(res);
        res = res->suivant;
    }

    enregistrer_biblioH(b, "Exemple1");
    printf("\n");

    BiblioH *b2 = charger_n_entreesH("bib4.txt", 3, m);
    printf("affichage de la bibliotheque b2\n");
    afficher_biblioH(b2);
    suppression_livreH(b2, 1, "nou", "eu");
    printf("apres supression du livre de titre 'nou' et auteur 'eu' \n");
    afficher_biblioH(b2);

    printf("\n");
    printf("fusion de b et b2\n");
    b = fusion_bibH(b, b2);
    afficher_biblioH(b);

    printf("\n");
    printf("ajout des livres '6 malade Profa' et '7 Fram Profa'\n");
    insererH(b,6,"malade","Profa");
    insererH(b,7,"Fram","Profa");

    printf("affichage de b\n");
    afficher_biblioH(b);

    printf("\n");
    LivreH *resdup = recherche_dupliquesH(b);
    printf("affichage des doublons \n");
    while (resdup != NULL) {
        afficher_livreH(resdup);
        resdup = resdup->suivant;
    }

    liberer_biblioH(b);

    return 0;
}
