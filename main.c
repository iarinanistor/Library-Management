#include "entreeSortieLC.h"
#include "biblioLC.h"
#include "biblioH.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>


// Fonction pour afficher le menu des actions possibles sur la bibliothèque
void menu() {
    printf("Actions possibles sur la bibliothèque :\n");
    printf("0 - Sortie du programme\n");
    printf("1 - Affichage de la bibliothèque\n");
    printf("2 - Insérer un ouvrage\n");
    printf("3 - Recherche par numero\n");
    printf("4 - Recherche par titre\n");
    printf("5 - Recherche livres d'un auteur\n");
    printf("6 - Supprimer un ouvrage\n");
    printf("7 - Fusionner avec une autre bibliothèque\n");
    printf("8 - Recherche des ouvrages avec plusieurs exemplaires\n");
    printf("9 - Créer une nouvelle bibliothèque\n");
    printf("10 - Libérer la bibliothèque actuelle\n");
    printf("Votre choix : ");
}

// Fonction principale du programme
int main(int argc, char **argv) {
    if (argc != 3) { // Vérifie le nombre d'arguments passés au programme
        printf("Usage: %s <nom_fichier> <nombre_lignes>\n", argv[0]);
        return 1; // Quitte le programme avec un code d'erreur
    }

    char *nomfic = strdup(argv[1]); // Copie le nom du fichier depuis les arguments
    int n = atoi(argv[2]); // Convertit la chaîne en entier pour le nombre de lignes à charger

    Biblio *bib = charger_n_entrees(nomfic, n); // Charge les entrées depuis le fichier dans une bibliothèque

    if (bib == NULL) { // Vérifie si le chargement de la bibliothèque a échoué
        printf("Erreur lors du chargement de la bibliothèque.\n");
        return 1; // Quitte le programme avec un code d'erreur
    }

    enregistrer_biblio(bib, "nouvelle_biblio.txt"); // Enregistre la bibliothèque dans un nouveau fichier

    int choix; // Variable pour stocker le choix de l'utilisateur

    do { 
        menu(); 
        scanf("%d", &choix); // Lit le choix de l'utilisateur

        switch (choix) { // Structure de contrôle pour traiter le choix de l'utilisateur
            case 0: // Cas 0: Sortie du programme
                printf("Sortie du programme.\n");
                break;

            case 1: // Cas 1: Affichage de la bibliothèque
                afficher_biblio(bib);
                break;

            case 2: // Cas 2: Insérer un ouvrage
                {
                    int num;
                    char titre[256];
                    char auteur[256];
                    printf("Veuillez écrire le numéro, le titre et l'auteur de l'ouvrage :\n");
                    if (scanf("%d %s %s", &num, titre, auteur) == 3) {
                        inserer_en_tete(bib, num, titre, auteur);
                        printf("Ajout fait.\n");
                    } else {
                        printf("Erreur de format.\n");
                    }
                }
                break;

            case 3: // Cas 3: Recherche par numéro
                {
                    int numero_recherche;
                    printf("Veuillez entrer le numéro de l'ouvrage à rechercher : ");
                    scanf("%d", &numero_recherche);
                    Livre *ouvrage = recherche_num(bib, numero_recherche);
                    if (ouvrage != NULL) {
                        printf("Livre trouvé :\n");
                        afficher_livre(ouvrage);
                    } else {
                        printf("L'ouvrage avec le numéro %d n'a pas été trouvé.\n", numero_recherche);
                    }
                }
                break;

            case 4: // Cas 4: Recherche par titre
                {
                    char titre_recherche[256];
                    printf("Veuillez entrer le titre de l'ouvrage à rechercher : ");
                    scanf("%s", titre_recherche);
                    Livre *resultat_titre = recherche_titre(bib, titre_recherche);
                    if (resultat_titre != NULL) {
                        printf("Livre trouvé :\n");
                        afficher_livre(resultat_titre);
                    } else {
                        printf("Aucun ouvrage avec le titre '%s' n'a été trouvé.\n", titre_recherche);
                    }
                }
                break;

            case 5: // Cas 5: Recherche livres d'un auteur
                {
                    char auteur_recherche[256];
                    printf("Veuillez entrer le nom de l'auteur : ");
                    scanf("%s", auteur_recherche);
                    Biblio *resultat_auteur = recherche_bib_auteur(bib, auteur_recherche);
                    if (resultat_auteur != NULL) {
                        printf("Livres de l'auteur '%s' :\n", auteur_recherche);
                        afficher_biblio(resultat_auteur);
                    } else {
                        printf("Aucun ouvrage de l'auteur '%s' n'a été trouvé.\n", auteur_recherche);
                    }
                }
                break;

            case 6: // Cas 6: Supprimer un ouvrage
                {
                    int num_suppression;
                    char titre_suppression[256];
                    char auteur_suppression[256];
                    printf("Veuillez entrer le numéro, le titre et l'auteur de l'ouvrage à supprimer : ");
                    if (scanf("%d %s %s", &num_suppression, titre_suppression, auteur_suppression) == 3) {
                        suppression_livre(bib, num_suppression, titre_suppression, auteur_suppression);
                        printf("L'ouvrage avec le numéro %d, le titre '%s' et l'auteur '%s' a été supprimé de la bibliothèque.\n", num_suppression, titre_suppression, auteur_suppression);
                    } else {
                        printf("Erreur de saisie. Veuillez entrer le numéro, le titre et l'auteur de l'ouvrage à supprimer.\n");
                    }
                }
                break;

            case 7: // Cas 7: Fusionner avec une autre bibliothèque
                {
                    char nom_fichier[256];
                    printf("Veuillez entrer le nom du fichier de la deuxième bibliothèque : ");
                    scanf("%s", nom_fichier);
                    
                    Biblio *b2 = charger_n_entrees(nom_fichier, INT_MAX); // Charger la deuxième bibliothèque depuis le fichier
                    
                    if (b2 == NULL) {
                        printf("Erreur lors du chargement de la deuxième bibliothèque.\n");
                        break;
                    }
                    
                    bib = fusion_biblio(bib, b2); // Fusionner la première bibliothèque avec la deuxième
                    liberer_biblio(b2);
                    printf("La fusion avec la deuxième bibliothèque a été effectuée avec succès.\n");
                }
                break; 

            case 8: // Cas 8: Recherche des ouvrages avec plusieurs exemplaires
                {
                    Livre *doublons = recherche_dupliques(bib);
                    if (doublons != NULL) {
                        printf("Ouvrages avec plusieurs exemplaires :\n");
                        while (doublons != NULL) {
                            afficher_livre(doublons);
                            doublons = doublons->suiv;
                        }
                    } else {
                        printf("Aucun ouvrage avec plusieurs exemplaires n'a été trouvé.\n");
                    }
                }
                break;

            case 9: // Cas 9: Créer une nouvelle bibliothèque
                {
                    liberer_biblio(bib); // Libère la mémoire de l'ancienne bibliothèque
                    bib = creer_biblio(); // Crée une nouvelle bibliothèque vide
                    printf("Une nouvelle bibliothèque a été créée.\n");
                }
                break;

            case 10: // Cas 10: Libérer la bibliothèque actuelle
                {
                    liberer_biblio(bib); // Libère la mémoire de la bibliothèque actuelle
                    printf("La bibliothèque actuelle a été libérée.\n");
                }
                break;

            default: // Cas par défaut: Choix invalide
                printf("Choix invalide. Veuillez choisir une action valide.\n");
        }

    } while (choix != 0); // Continue la boucle jusqu'à ce que l'utilisateur choisisse de sortir du programme

    return 0;
}

