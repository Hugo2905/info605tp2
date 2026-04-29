// dijkstra.c
#include <stdio.h>
#include <stdbool.h>
#include "graphe.h"

void dijkstra(Graphe g, int depart) {
    int n = nbSommets(g);
    int dist[n];
    bool visite[n];

    // Initialisation
    for (int i = 0; i < n; i++) {
        dist[i] = INFINI;
        visite[i] = false;
    }
    dist[depart] = 0;

    // Boucle principale
    for (int count = 0; count < n - 1; count++) {
        int min = INFINI, u = -1;

        // Trouver le sommet avec la distance minimale non visité
        for (int v = 0; v < n; v++)
            if (!visite[v] && dist[v] <= min) {
                min = dist[v];
                u = v;
            }

        // Si aucun sommet n'est accessible
        if (u == -1) break;
        visite[u] = true; // Marquer le sommet comme visité

        // Relâchement (Update des distances des voisins)
        for (int v = 0; v < n; v++) {
            int poids = getPoids(g, u, v);
            // Si le sommet v n'est pas visité, il y a un arc de u à v, et le chemin de u à v est plus court que le chemin actuel
            if (!visite[v] && poids != INFINI && dist[u] != INFINI 
                && dist[u] + poids < dist[v]) {
                dist[v] = dist[u] + poids;
            }
        }
    }

    // Affichage des résultats
    printf("Distances depuis le sommet %d :\n", depart);
    for (int i = 0; i < n; i++) printf("Sommet %d : %d\n", i, dist[i]);
}