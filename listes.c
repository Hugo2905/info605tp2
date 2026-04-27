// listes.c
#include <stdlib.h>
#include "graphe.h"

typedef struct Arc {
    int dest, poids;
    struct Arc* suivant;
} Arc;

struct s_graphe {
    int n;
    Arc** listes;
};

Graphe creerGraphe(int nbSommets) {
    Graphe g = malloc(sizeof(struct s_graphe));
    g->n = nbSommets;
    g->listes = calloc(nbSommets, sizeof(Arc*));
    return g;
}

void ajouterArc(Graphe g, int src, int dest, int poids) {
    Arc* nouvelArc = malloc(sizeof(Arc));
    nouvelArc->dest = dest;
    nouvelArc->poids = poids;
    nouvelArc->suivant = g->listes[src];
    g->listes[src] = nouvelArc;
}

int getPoids(Graphe g, int src, int dest) {
    Arc* courant = g->listes[src];
    while(courant) {
        if(courant->dest == dest) return courant->poids;
        courant = courant->suivant;
    }
    return INFINI;
}

int nbSommets(Graphe g) {
    return g->n;
}