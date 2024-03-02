#include "entreeSortieLC.h"
#include "biblioLC.h"
#include "entreeSortieH.h"
#include "biblioH.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


int main() {
    // Charger les données dans les deux structures de données
    BiblioH *bib_hashmap = charger_n_entreesH("GdeBiblio.txt", 7, 10);
    Biblio *bib_liste = charger_n_entrees("GdeBiblio.txt", 7);
    
    // Afficher les bibliothèques chargées
    printf("Bibliothèque avec HashMap:\n");
    afficher_biblioH(bib_hashmap);
    printf("\nBibliothèque avec Liste Chainée:\n");
    afficher_biblio(bib_liste);
    printf("\n");

    // Question 1 : Mesurer les temps de recherche pour chaque structure de données
    printf("Recherche d'un élément:\n");
    clock_t temps_initial_liste, temps_final_liste, temps_initial_hashmap, temps_final_hashmap;
    double temps_cpu_liste, temps_cpu_hashmap;
    
    // Recherche du livre numéro 5 (présent) et 9 (absent) pour chaque structure de données
    printf("\tcas 1 : élément présent\n");
    temps_initial_liste = clock();
    recherche_num(bib_liste, 5);
    temps_final_liste = clock();
    temps_cpu_liste = ((double)(temps_final_liste - temps_initial_liste)) / CLOCKS_PER_SEC;
    printf("liste: %.9f\n", temps_cpu_liste);
    
    temps_initial_hashmap = clock();
    recherche_numH(bib_hashmap, 5);
    temps_final_hashmap = clock();
    temps_cpu_hashmap = ((double)(temps_final_hashmap - temps_initial_hashmap)) / CLOCKS_PER_SEC;
    printf("hashmap: %.9f\n", temps_cpu_hashmap);
    
    printf("\tcas 2 : élément absent\n");
    temps_initial_liste = clock();
    recherche_num(bib_liste, 9);
    temps_final_liste = clock();
    temps_cpu_liste = ((double)(temps_final_liste - temps_initial_liste)) / CLOCKS_PER_SEC;
    printf("liste: %.9f\n", temps_cpu_liste);
    
    temps_initial_hashmap = clock();
    recherche_numH(bib_hashmap, 9);
    temps_final_hashmap = clock();
    temps_cpu_hashmap = ((double)(temps_final_hashmap - temps_initial_hashmap)) / CLOCKS_PER_SEC;
    printf("hashmap: %.9f\n", temps_cpu_hashmap);

    // Libérer la mémoire allouée pour les deux structures de données
    liberer_biblio(bib_liste);
    liberer_biblioH(bib_hashmap);

    // Question 2 : Mesurer les temps de recherche pour chaque structure de données avec une bibliothèque plus grande
    bib_hashmap = charger_n_entreesH("GdeBiblio.txt", 100, 100);    
    bib_liste = charger_n_entrees("GdeBiblio.txt", 100);
    
    printf("\tcas 1 : élément présent\n");
    temps_initial_liste = clock();
    recherche_num(bib_liste, 5);
    temps_final_liste = clock();
    temps_cpu_liste = ((double)(temps_final_liste - temps_initial_liste)) / CLOCKS_PER_SEC;
    printf("liste: %.9f\n", temps_cpu_liste);
    
    temps_initial_hashmap = clock();
    recherche_numH(bib_hashmap, 5);
    temps_final_hashmap = clock();
    temps_cpu_hashmap = ((double)(temps_final_hashmap - temps_initial_hashmap)) / CLOCKS_PER_SEC;
    printf("hashmap: %.9f\n", temps_cpu_hashmap);
    
    printf("\tcas 2 : élément absent\n");
    temps_initial_liste = clock();
    recherche_num(bib_liste, 9);
    temps_final_liste = clock();
    temps_cpu_liste = ((double)(temps_final_liste - temps_initial_liste)) / CLOCKS_PER_SEC;
    printf("liste: %.9f\n", temps_cpu_liste);
    
    temps_initial_hashmap = clock();
    recherche_numH(bib_hashmap, 9);
    temps_final_hashmap = clock();
    temps_cpu_hashmap = ((double)(temps_final_hashmap - temps_initial_hashmap)) / CLOCKS_PER_SEC;
    printf("hashmap: %.9f\n", temps_cpu_hashmap);
    
    liberer_biblio(bib_liste);
    liberer_biblioH(bib_hashmap);
    
    return 0;
}

