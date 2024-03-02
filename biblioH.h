#ifndef BIBLIOH_H 
#define BIBLIOH_H

// Définition de la structure pour un livre
typedef struct livreh{
    int clef;  
    int num; 
    char* titre;
    char* auteur;
    struct livreh* suivant; 
} LivreH;

// Définition de la structure pour une bibliothèque
typedef struct table{
    int nE;
    int m; 
    LivreH **T;
} BiblioH;

// Prototypes de fonctions
int fonctionClef(char *auteur);  // Fonction pour calculer la clé à partir du nom de l'auteur

LivreH* creer_livreH(int num,char *titre,char *auteur);  // Fonction pour créer un nouveau livre

void liberer_livreH(LivreH *l);  // Fonction pour libérer la mémoire allouée à un livre

BiblioH* creer_biblioH(int m);  // Fonction pour créer une nouvelle bibliothèque

void liberer_biblioH(BiblioH* b);  // Fonction pour libérer la mémoire allouée à une bibliothèque

int fonctionHachage(int cle, int m);  // Fonction de hachage pour déterminer l'index dans la table de hachage

void insererH(BiblioH* b,int num,char* titre,char* auteur);  // Fonction pour insérer un livre dans la bibliothèque

void afficher_livreH(LivreH *l);  // Fonction pour afficher les informations d'un livre

void afficher_biblioH(BiblioH *b);  // Fonction pour afficher tous les livres dans la bibliothèque

LivreH* recherche_numH(BiblioH *b,int num);  // Fonction pour rechercher un livre par numéro dans la bibliothèque

LivreH* recherche_titreH(BiblioH *b,char *titre);  // Fonction pour rechercher un livre par titre dans la bibliothèque

LivreH* recherche_bib_auteurH(BiblioH *b,char *auteur);  // Fonction pour rechercher un livre par auteur dans la bibliothèque

void suppression_livreH(BiblioH *b, int num, char *titre, char *auteur);  // Fonction pour supprimer un livre de la bibliothèque

BiblioH *fusion_bibH(BiblioH *b1, BiblioH *b2); // Fonction pour fusionner deux bibliothèques en une seule

LivreH* recherche_dupliquesH(BiblioH* b); // Fonction pour rechercher les doublons dans une bibliothèque
#endif

