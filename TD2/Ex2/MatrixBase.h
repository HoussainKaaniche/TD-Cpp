#ifndef MATRIXBASE_H
#define MATRIXBASE_H

#include <iostream>
#include <vector>

template <class T>
class MatrixBase {
protected:
    std::vector<std::vector<T>> data;
    size_t rows;
    size_t cols;

public:
    MatrixBase() {
        rows = 0;
        cols = 0;
    }

    MatrixBase(size_t lignes, size_t colonnes) {
        rows = lignes;
        cols = colonnes;

        data.resize(rows);

        for (size_t i = 0; i < rows; i++) {
            data[i].resize(cols);
        }
    }

    void addElement(size_t ligne, size_t colonne, T valeur) {
        data.at(ligne).at(colonne) = valeur;
    }

    T getElement(size_t ligne, size_t colonne) const {
        return data.at(ligne).at(colonne);
    }

    size_t getRows() const {
        return rows;
    }

    size_t getCols() const {
        return cols;
    }

    void Display() const {
        for (size_t i = 0; i < rows; i++) {
            for (size_t j = 0; j < cols; j++) {
                std::cout << data[i][j] << "\t";
            }

            std::cout << std::endl;
        }
    }
};

#endif