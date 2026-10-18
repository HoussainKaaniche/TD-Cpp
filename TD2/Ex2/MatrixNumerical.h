#ifndef MATRIXNUMERICAL_H
#define MATRIXNUMERICAL_H

#include "MatrixBase.h"
#include <stdexcept>

// Annonces avant utilisation
template <class T>
class MatrixNumerical;

template <class T>
MatrixNumerical<T> getCoFactor(
    const MatrixNumerical<T>& matrice,
    size_t ligne,
    size_t colonne
);

template <class T>
class MatrixNumerical : public MatrixBase<T> {
public:
    MatrixNumerical() : MatrixBase<T>() {
    }

    MatrixNumerical(size_t lignes, size_t colonnes)
        : MatrixBase<T>(lignes, colonnes) {
    }

    double getDeterminant() const {
        if (this->rows != this->cols) {
            throw std::invalid_argument("Matrice non carree");
        }

        if (this->rows == 0) {
            return 1;
        }

        if (this->rows == 1) {
            return this->data[0][0];
        }

        double determinant = 0;
        int signe = 1;

        for (size_t j = 0; j < this->cols; j++) {
            MatrixNumerical<T> petite = getCoFactor(*this, 0, j);

            determinant += signe * this->data[0][j]
                           * petite.getDeterminant();

            signe = -signe;
        }

        return determinant;
    }

    MatrixNumerical<T> operator+(const MatrixNumerical<T>& autre) const {
        if (this->rows != autre.rows || this->cols != autre.cols) {
            throw std::invalid_argument("Dimensions differentes");
        }

        MatrixNumerical<T> resultat(this->rows, this->cols);

        for (size_t i = 0; i < this->rows; i++) {
            for (size_t j = 0; j < this->cols; j++) {
                resultat.addElement(
                    i, j, this->data[i][j] + autre.data[i][j]
                );
            }
        }

        return resultat;
    }

    MatrixNumerical<T> operator-(const MatrixNumerical<T>& autre) const {
        if (this->rows != autre.rows || this->cols != autre.cols) {
            throw std::invalid_argument("Dimensions differentes");
        }

        MatrixNumerical<T> resultat(this->rows, this->cols);

        for (size_t i = 0; i < this->rows; i++) {
            for (size_t j = 0; j < this->cols; j++) {
                resultat.addElement(
                    i, j, this->data[i][j] - autre.data[i][j]
                );
            }
        }

        return resultat;
    }

    MatrixNumerical<T> operator*(const MatrixNumerical<T>& autre) const {
        if (this->cols != autre.rows) {
            throw std::invalid_argument("Dimensions incompatibles");
        }

        MatrixNumerical<T> resultat(this->rows, autre.cols);

        for (size_t i = 0; i < this->rows; i++) {
            for (size_t j = 0; j < autre.cols; j++) {
                T somme = 0;

                for (size_t k = 0; k < this->cols; k++) {
                    somme += this->data[i][k] * autre.data[k][j];
                }

                resultat.addElement(i, j, somme);
            }
        }

        return resultat;
    }

    MatrixNumerical<double> getInverse() const {
        if (this->rows == 0) {
            throw std::invalid_argument("Matrice vide");
        }

        double determinant = getDeterminant();

        if (determinant == 0) {
            throw std::invalid_argument("Matrice non inversible");
        }

        MatrixNumerical<double> resultat(this->rows, this->cols);

        for (size_t i = 0; i < this->rows; i++) {
            for (size_t j = 0; j < this->cols; j++) {
                MatrixNumerical<T> petite = getCoFactor(*this, i, j);

                double cofacteur = petite.getDeterminant();

                if ((i + j) % 2 == 1) {
                    cofacteur = -cofacteur;
                }

                // Transposer les cofacteurs et diviser par le determinant
                resultat.addElement(j, i, cofacteur / determinant);
            }
        }

        return resultat;
    }

    // Division : A / B = A * inverse(B)
    MatrixNumerical<double> operator/(const MatrixNumerical<T>& autre) const {
        MatrixNumerical<double> copie(this->rows, this->cols);

        for (size_t i = 0; i < this->rows; i++) {
            for (size_t j = 0; j < this->cols; j++) {
                copie.addElement(i, j, this->data[i][j]);
            }
        }

        return copie * autre.getInverse();
    }

    static MatrixNumerical<T> getIdentity(int taille) {
        if (taille < 0) {
            throw std::invalid_argument("Taille negative");
        }

        MatrixNumerical<T> resultat(taille, taille);

        for (int i = 0; i < taille; i++) {
            resultat.addElement(i, i, 1);
        }

        return resultat;
    }
};

// Construire un mineur en supprimant une ligne et une colonne
template <class T>
MatrixNumerical<T> getCoFactor(
    const MatrixNumerical<T>& matrice,
    size_t ligne,
    size_t colonne
) {
    if (ligne >= matrice.getRows() || colonne >= matrice.getCols()) {
        throw std::out_of_range("Indice invalide");
    }

    MatrixNumerical<T> petite(
        matrice.getRows() - 1,
        matrice.getCols() - 1
    );

    size_t nouvelleLigne = 0;

    for (size_t i = 0; i < matrice.getRows(); i++) {
        if (i != ligne) {
            size_t nouvelleColonne = 0;

            for (size_t j = 0; j < matrice.getCols(); j++) {
                if (j != colonne) {
                    petite.addElement(
                        nouvelleLigne,
                        nouvelleColonne,
                        matrice.getElement(i, j)
                    );

                    nouvelleColonne++;
                }
            }

            nouvelleLigne++;
        }
    }

    return petite;
}

#endif