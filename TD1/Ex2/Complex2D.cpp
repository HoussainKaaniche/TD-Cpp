#include "Complex2D.h"

// Constructeurs
Complex2D::Complex2D() {
    real = 0;
    imaginary = 0;
}

Complex2D::Complex2D(double r, double i) {
    real = r;
    imaginary = i;
}

Complex2D::Complex2D(double value) {
    real = value;
    imaginary = value;
}

Complex2D::Complex2D(const Complex2D &other) {
    real = other.real;
    imaginary = other.imaginary;
}

// Getters
double Complex2D::getReal() {
    return real;
}

double Complex2D::getImaginary() {
    return imaginary;
}

// Setters
void Complex2D::setReal(double r) {
    real = r;
}

void Complex2D::setImaginary(double i) {
    imaginary = i;
}

// Opérateurs
Complex2D Complex2D::operator+(const Complex2D &other) {
    return Complex2D(real + other.real, imaginary + other.imaginary);
}

Complex2D Complex2D::operator-(const Complex2D &other) {
    return Complex2D(real - other.real, imaginary - other.imaginary);
}

Complex2D Complex2D::operator*(const Complex2D &other) {
    return Complex2D(
        real * other.real - imaginary * other.imaginary,
        real * other.imaginary + imaginary * other.real
    );
}

Complex2D Complex2D::operator/(const Complex2D &other) {
    double d = other.real * other.real + other.imaginary * other.imaginary;

    return Complex2D(
        (real * other.real + imaginary * other.imaginary) / d,
        (imaginary * other.real - real * other.imaginary) / d
    );
}

bool Complex2D::operator<(const Complex2D &other) {
    return real * real + imaginary * imaginary
         < other.real * other.real + other.imaginary * other.imaginary;
}

bool Complex2D::operator>(const Complex2D &other) {
    return real * real + imaginary * imaginary
         > other.real * other.real + other.imaginary * other.imaginary;
}