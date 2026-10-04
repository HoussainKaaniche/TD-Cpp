#include <iostream>
#include "Complex2D.h"

int main() {
    Complex2D z1(3, 2);
    Complex2D z2(1, 4);

    Complex2D z3 = z1 + z2;

    std::cout << z3.getReal()
              << " + "
              << z3.getImaginary()
              << "i"
              << std::endl;

    return 0;
}