# Paramètres du compilateur
CC = gcc
CFLAGS = -Wall -Wextra -std=c99

# Fichiers sources communs
SRC_DIJKSTRA = dijkstra.c
SRC_MAIN = main.c 

# Cibles de sortie
EXE_MATRICE = dijkstra_matrice
EXE_LISTES = dijkstra_listes

# compile les deux versions ---
all: $(EXE_MATRICE) $(EXE_LISTES)

# Compilation de la version Matrice d'Adjacence ---
$(EXE_MATRICE): $(SRC_DIJKSTRA) $(SRC_MAIN) matrice.c
	$(CC) $(CFLAGS) $^ -o $@

# Compilation de la version Listes d'Adjacence ---
$(EXE_LISTES): $(SRC_DIJKSTRA) $(SRC_MAIN) listes.c
	$(CC) $(CFLAGS) $^ -o $@

# Nettoyage des fichiers temporaires ---
clean:
	rm -f $(EXE_MATRICE) $(EXE_LISTES) *.o

# Exécution des tests ---
test: all
	@echo "Exécution avec la Matrice d'Adjacence :"
	./$(EXE_MATRICE)
	@echo "\nExécution avec les Listes d'Adjacence :"
	./$(EXE_LISTES)