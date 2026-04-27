#include "graphe.h"
#include <stdio.h>


extern void dijkstra(Graphe g, int depart);

int main() {
    int n = 4;
    Graphe g = creerGraphe(n);
    
    // Exemple : 0 -> 1 (poids 5), 1 -> 2 (poids 3), 0 -> 2 (poids 10)
    ajouterArc(g, 0, 1, 5);
    ajouterArc(g, 1, 2, 3);
    ajouterArc(g, 0, 2, 10);
    
    printf("--- Test de l'algorithme ---\n");
    dijkstra(g, 0);
    
    // Libération de la mémoire (à implémenter dans matrice.c / listes.c)
    // detruireGraphe(g); 

    return 0;
}