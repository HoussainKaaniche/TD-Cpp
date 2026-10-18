#include "SearchingAlgorithm.h"

using namespace std;

int main() {
    vector<int> tableau = {1, 3, 5, 7, 9, 11, 13};
    int target = 9;
    int resultat;

    cout << "--- Recherche lineaire ---" << endl;

    LinearSearch lineaire;
    resultat = lineaire.search(tableau, target);
    lineaire.displaySearchResults(cout, resultat, target);

    cout << "\n--- Recherche par sauts ---" << endl;

    JumpSearch saut;
    resultat = saut.search(tableau, target);
    saut.displaySearchResults(cout, resultat, target);

    cout << "\n--- Recherche binaire ---" << endl;

    BinarySearch binaire;
    resultat = binaire.search(tableau, target);
    binaire.displaySearchResults(cout, resultat, target);

    return 0;
}