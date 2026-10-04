#ifndef COMPLEX2D_H
#define COMPLEX2D_H

class Complex2D {
private:
    double real;
    double imaginary;

public:
    Complex2D();
    Complex2D(double r, double i);
    Complex2D(double value);
    Complex2D(const Complex2D &other);

    double getReal();
    double getImaginary();

    void setReal(double r);
    void setImaginary(double i);

    Complex2D operator+(const Complex2D &other);
    Complex2D operator-(const Complex2D &other);
    Complex2D operator*(const Complex2D &other);
    Complex2D operator/(const Complex2D &other);

    bool operator<(const Complex2D &other);
    bool operator>(const Complex2D &other);
};

#endif