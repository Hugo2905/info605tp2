// graphe.h
#ifndef GRAPHE_H
#define GRAPHE_H

#define INFINI 999999

typedef struct s_graphe* Graphe;

// Création/Destruction
Graphe creerGraphe(int nbSommets);
void detruireGraphe(Graphe g);

// Modification
void ajouterArc(Graphe g, int src, int dest, int poids);

// Consultation
int nbSommets(Graphe g);
int getPoids(Graphe g, int src, int dest); // Retourne INFINI si pas d'arc
int* getSuccesseurs(Graphe g, int v, int* nbSucc);

#endif