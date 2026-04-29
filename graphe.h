// graphe.h
#ifndef GRAPHE_H
#define GRAPHE_H

#define INFINI 999999

typedef struct s_graphe* Graphe;

// Création/Destruction
Graphe creerGraphe(int nbSommets);

// Modification
void ajouterArc(Graphe g, int src, int dest, int poids);

// Consultation
int nbSommets(Graphe g);
int getPoids(Graphe g, int src, int dest); // Retourne INFINI si pas d'arc

#endif