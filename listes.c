// listes.c
#include <stdlib.h>
#include "graphe.h"

typedef struct Arc {
    int dest, poids; // Destination et poids de l'arc
    struct Arc* suivant; // Pointeur vers l'arc suivant dans la liste
} Arc;

struct s_graphe {
    int n; // Nombre de sommets
    Arc** listes; // listes[i] = pointeur vers la liste du sommet i
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
    Arc* courant = g->listes[src]; // Parcours de la liste d'adjacence du sommet src
    while(courant) { 
        if(courant->dest == dest) return courant->poids; // Si on trouve le sommet dest dans la liste de src, on retourne son poids
        courant = courant->suivant; // Sinon, on continue à parcourir la liste
    }
    return INFINI;
}

int nbSommets(Graphe g) {
    return g->n;
}