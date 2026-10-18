#include "SearchingAlgorithm.h"
#include <cmath>

using namespace std;

// Initialisation des variables partagées entre tous les objets
int SearchingAlgorithm::totalComparisons = 0;
int SearchingAlgorithm::totalSearch = 0;
double SearchingAlgorithm::averageComparisons = 0;

SearchingAlgorithm::SearchingAlgorithm() {
    numberComparisons = 0;
}

SearchingAlgorithm::~SearchingAlgorithm() {
}

void SearchingAlgorithm::displaySearchResults(
    ostream& sortie, int results, int target
) {
    totalComparisons += numberComparisons;
    totalSearch++;

    averageComparisons = (double) totalComparisons / totalSearch;

    sortie << "Valeur cherchee : " << target << endl;
    sortie << "Indice trouve : " << results << endl;
    sortie << "Comparaisons : " << numberComparisons << endl;
    sortie << "Total des comparaisons : " << totalComparisons << endl;
    sortie << "Nombre de recherches : " << totalSearch << endl;
    sortie << "Moyenne : " << averageComparisons << endl;
}


// Recherche case par case
int LinearSearch::search(const vector<int>& tableau, int target) {
    numberComparisons = 0;

    for (int i = 0; i < (int) tableau.size(); i++) {
        numberComparisons++;

        if (tableau[i] == target) {
            return i;
        }
    }

    return -1;
}


// Recherche par blocs, dans un tableau trié
int JumpSearch::search(const vector<int>& tableau, int target) {
    numberComparisons = 0;

    int taille = tableau.size();

    if (taille == 0) {
        return -1;
    }

    int saut = sqrt(taille);
    int debut = 0;
    int fin = saut - 1;

    while (debut < taille) {
        if (fin >= taille) {
            fin = taille - 1;
        }

        numberComparisons++;

        if (tableau[fin] >= target) {
            // Chercher case par case dans ce bloc
            for (int i = debut; i <= fin; i++) {
                numberComparisons++;

                if (tableau[i] == target) {
                    return i;
                }
            }

            return -1;
        }

        debut = fin + 1;
        fin += saut;
    }

    return -1;
}


// Recherche en divisant la zone par deux, dans un tableau trié
int BinarySearch::search(const vector<int>& tableau, int target) {
    numberComparisons = 0;

    int gauche = 0;
    int droite = (int) tableau.size() - 1;

    while (gauche <= droite) {
        int milieu = gauche + (droite - gauche) / 2;

        numberComparisons++;

        if (tableau[milieu] == target) {
            return milieu;
        }

        numberComparisons++;

        if (tableau[milieu] < target) {
            gauche = milieu + 1;
        } else {
            droite = milieu - 1;
        }
    }

    return -1;
}