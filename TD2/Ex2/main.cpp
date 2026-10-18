#include "MatrixNumerical.h"

using namespace std;

int main() {
    MatrixNumerical<double> a(2, 2);

    a.addElement(0, 0, 4);
    a.addElement(0, 1, 7);
    a.addElement(1, 0, 2);
    a.addElement(1, 1, 6);

    MatrixNumerical<double> b(2, 2);

    b.addElement(0, 0, 1);
    b.addElement(0, 1, 2);
    b.addElement(1, 0, 3);
    b.addElement(1, 1, 4);

    cout << "A :" << endl;
    a.Display();

    cout << "B :" << endl;
    b.Display();

    cout << "Dimensions de A : "
         << a.getRows() << " x " << a.getCols() << endl;

    cout << "Element en (0, 1) : " << a.getElement(0, 1) << endl;

    cout << "\nA + B :" << endl;
    (a + b).Display();

    cout << "\nA - B :" << endl;
    (a - b).Display();

    cout << "\nA * B :" << endl;
    (a * b).Display();

    cout << "\nDeterminant de A : " << a.getDeterminant() << endl;

    cout << "\nInverse de A :" << endl;
    a.getInverse().Display();

    cout << "\nA / B :" << endl;
    (a / b).Display();

    cout << "\nIdentite de taille 3 :" << endl;

    MatrixNumerical<double> identite =
        MatrixNumerical<double>::getIdentity(3);

    identite.Display();

    return 0;
}