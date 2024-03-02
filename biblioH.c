#include "biblioH.h"
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

// Fonction pour calculer la clé à partir du nom de l'auteur
int fonctionClef(char *auteur){
    int len = strlen(auteur);
    int clef = 0;
    for (int i=0;i<strlen(auteur);i++){
        clef += auteur[i];  
    }
    return clef;
}

// Fonction pour créer un nouveau livre avec les informations données
LivreH* creer_livreH(int num,char *titre,char *auteur){
    LivreH *l = malloc(sizeof(LivreH));
    l->clef = fonctionClef(auteur);  // Calculer la clé pour l'auteur du livre
    l->num = num;
    l->titre = strdup(titre); 
    l->auteur = strdup(auteur); 
    l->suivant = NULL;  
    return l;
}

// Fonction pour libérer la mémoire allouée à un livre
void liberer_livreH(LivreH *l){
    free(l->titre); 
    free(l->auteur); 
    free(l);
}

// Fonction pour créer une nouvelle bibliothèque avec une taille donnée
BiblioH* creer_biblioH(int m){
    BiblioH *b = malloc(sizeof(BiblioH));  
    b->nE = 0;  // Initialiser le nombre d'éléments dans la bibliothèque à 0
    b->m = m;  // Définir la taille de la table de hachage
    b->T = malloc(m*sizeof(LivreH*));  // Allouer de la mémoire pour la table de hachage
    for (int i=0;i<m;i++) {
        b->T[i] = NULL; 
    }
    return b;
}

// Fonction pour libérer la mémoire allouée à une bibliothèque
void liberer_biblioH(BiblioH* b){
    if(b){
        LivreH *tmp;
        LivreH *curr;
        for (int i=0;i<(b->m);i++){
            curr = b->T[i];
            while (curr) {
                tmp = curr->suivant;
                liberer_livreH(curr);  // Libérer la mémoire allouée pour chaque livre dans la liste chaînée
                curr = tmp;
            }
        }
        free(b->T);  // Libérer la mémoire allouée pour la table de hachage
        free(b);  // Libérer la mémoire allouée pour la bibliothèque elle-même
    }
}

// Fonction de hachage pour déterminer l'index dans la table de hachage
int fonctionHachage(int cle, int m){
    float A = (sqrt(5)-1)/2;
    int whole = (int)(cle*A);
    float formula = m*(cle*A-whole);
    return (int)formula;
}

// Fonction pour insérer un livre dans la bibliothèque
void insererH(BiblioH* b,int num,char* titre,char* auteur){
    int i = fonctionHachage(fonctionClef(auteur),b->m);  // Calculer l'index dans la table de hachage
    LivreH *l = creer_livreH(num,titre,auteur);
    if (l){
        l->suivant = b->T[i];  // Insérer le livre au début de la liste chaînée à cet index
        b->T[i] = l; 
        b->nE++;
    }
}

// Fonction pour afficher les informations d'un livre
void afficher_livreH(LivreH *l){
    if (l){
        printf(" %d %s %s\n",l->num,l->titre,l->auteur); 
    }
}

// Fonction pour afficher tous les livres dans la bibliothèque
void afficher_biblioH(BiblioH *b){
    if (b){
        for (int i=0;i<(b->m);i++){
            LivreH *tmp = b->T[i];
            while (tmp) {
                afficher_livreH(tmp);  // Afficher chaque livre dans la liste chaînée à cet index
                tmp = tmp->suivant;
            }
        }
    }
}

// Fonction pour rechercher un livre par numéro dans la bibliothèque
LivreH* recherche_numH(BiblioH *b,int num){
    if (b){
        LivreH *tmp;
        for (int i=0;i<(b->m);i++){
            LivreH *tmp = b->T[i];
            while (tmp) {
                if (tmp->num == num) return tmp;  // Retourner le livre si le numéro correspond
                tmp = tmp->suivant;
            }
        }
    }
    return NULL;  // Retourner NULL si le livre n'est pas trouvé
}

// Fonction pour rechercher un livre par titre dans la bibliothèque
LivreH* recherche_titreH(BiblioH *b,char *titre){
    if (b){
        LivreH *tmp;
        for (int i=0;i<(b->m);i++){
            LivreH *tmp = b->T[i];
            while (tmp) {
                if (strcmp(titre,tmp->titre)==0) return tmp;  // Retourner le livre si le titre correspond
                tmp = tmp->suivant;
            }
        }
    }
    return NULL;  // Retourner NULL si le livre n'est pas trouvé
}

LivreH* recherche_bib_auteurH(BiblioH *b,char *auteur){
	int i = fonctionHachage(fonctionClef(auteur),b->m);
	return b->T[i];
}


// Fonction pour supprimer un livre de la bibliothèque
void suppression_livreH(BiblioH *b, int num, char *titre, char *auteur){
    int i = fonctionHachage(fonctionClef(auteur),b->m);  // Calculer l'index dans la table de hachage
    LivreH *curr = b->T[i];  // Pointeur actuel dans la liste chaînée
    LivreH *prec = NULL;  // Pointeur précédent dans la liste chaînée
    if (curr == NULL) return;
    if (curr->num == num && strcmp(curr->titre,titre)==0){  // Si le premier livre correspond aux critères de suppression
        b->T[i] = curr->suivant;  // Mettre à jour le pointeur de la table de hachage à cet index
        liberer_livreH(curr); 
        return ;
    }
    while ((curr->num != num && strcmp(curr->titre,titre)!=0 ) && curr != NULL){  // Parcourir la liste chaînée jusqu'à trouver le livre à supprimer
        prec = curr;
        curr = curr->suivant;
    }
    if (curr) {
        prec->suivant = curr->suivant;  // Mettre à jour les pointeurs précédents et suivants pour sauter le livre à supprimer
        liberer_livreH(curr);  // Libérer la mémoire allouée pour ce livre
        b->nE--; 
    }
    return ;
}

BiblioH *fusion_bibH(BiblioH *b1, BiblioH *b2){
	// Parcourir tous les éléments de la deuxième bibliothèque
    for (int i = 0; i < b2->m; i++) {
        LivreH *current = b2->T[i];
        // Ajouter chaque élément à la première bibliothèque
        while (current != NULL) {
            LivreH *next = current->suivant;
            insererH(b1, current->num, current->titre, current->auteur);
            current = next;
        }
    }
    
    // Libérer la mémoire occupée par la table de hachage de la deuxième bibliothèque
    free(b2->T);
    // Libérer la mémoire occupée par la structure de la deuxième bibliothèque
    free(b2);

	return b1;
}

LivreH* recherche_dupliquesH(BiblioH* b) {
    LivreH* res = NULL;
    LivreH* res_aux = NULL;

    // Parcourir tous les éléments de la table de hachage
    for (int i = 0; i < b->m; i++) {
        LivreH* curr = b->T[i];
        while (curr != NULL) {
            LivreH* inner_curr = b->T[i];
            int occurrences = 0;

            // Parcourir les éléments de la même liste chaînée
            while (inner_curr != NULL) {
                if (curr->num != inner_curr->num && strcmp(curr->titre, inner_curr->titre) == 0 && strcmp(curr->auteur, inner_curr->auteur) == 0) {
                    occurrences++;
                    break;
                }
                inner_curr = inner_curr->suivant;
            }

            // Ajouter au résultat si une occurrence a été trouvée
            if (occurrences > 0) {
                if (!res) {
                    res = creer_livreH(curr->num, curr->titre, curr->auteur);
                    res_aux = res;
                } else {
                    res_aux->suivant = creer_livreH(curr->num, curr->titre, curr->auteur);
                    res_aux = res_aux->suivant;
                }
            }
            curr = curr->suivant;
        }
    }
    return res;
}






