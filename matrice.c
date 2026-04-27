// matrice.c
#include <stdlib.h>
#include "graphe.h"
#define INFINI 999999
struct s_graphe {
    int n;
    int** matrice;
};

Graphe creerGraphe(int nbSommets) {
    Graphe g = malloc(sizeof(struct s_graphe));
    g->n = nbSommets;
    g->matrice = malloc(nbSommets * sizeof(int*));
    for(int i=0; i<nbSommets; i++) {
        g->matrice[i] = malloc(nbSommets * sizeof(int));
        for(int j=0; j<nbSommets; j++) g->matrice[i][j] = (i == j) ? 0 : INFINI;
    }
    return g;
}

void ajouterArc(Graphe g, int src, int dest, int poids) {
    g->matrice[src][dest] = poids;
}

int getPoids(Graphe g, int src, int dest) {
    return g->matrice[src][dest];
}

int nbSommets(Graphe g) { return g->n; }

