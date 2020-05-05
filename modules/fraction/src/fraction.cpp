// Copyright 2020 Baldin Alexey

#include "include/fraction.h"
#include <string>
#include <iostream>

Fraction::Fraction(const int& nom, const int& den) {
    if (den == 0) {
        denominator_ = 1;
        throw std::string("Denominator can`t be zero. Use denominator = 1");
    } else if (den < 0) {
        nominator_ = -nom;
        denominator_ = -den;
    } else {
        nominator_ = nom;
        denominator_ = den;
    }
}

Fraction::Fraction(const Fraction & f) {
    this->nominator_ = f.getNominator();
    this->denominator_ = f.getDenominator();
}

int Fraction::getNominator() const {
    return nominator_;
}

int Fraction::getDenominator() const {
    if (nominator_ == 0) {
        throw std::string("Nominator = 0. Denominator don`t need.");
    } else {
        return denominator_;
    }
}

void Fraction::setNominator(const int& nom) {
    nominator_ = nom;
}

void Fraction::setDenominator(const int& den) {
    if (den == 0) {
        denominator_ = 1;
        throw std::string("Denominator can`t be zero. Use denominator = 1");
    } else if (den < 0) {
        nominator_ = -nominator_;
        denominator_ = -den;
    } else {
        denominator_ = den;
    }
}

bool Fraction::operator==(const Fraction & f) const {
    Fraction f1(this->getNominator(), this->getDenominator());
    Fraction f2(f.getNominator(), f.getDenominator());

    f1.fractionReduction();
    f2.fractionReduction();

    return f1.getNominator() == f2.getNominator() &&
           f1.getDenominator() == f2.getDenominator();
}

bool Fraction::operator!=(const Fraction & f) const {
    Fraction f1(this->getNominator(), this->getDenominator());
    Fraction f2(f.getNominator(), f.getDenominator());

    f1.fractionReduction();
    f2.fractionReduction();

    return f1.getNominator() != f2.getNominator() ||
           f1.getDenominator() != f2.getDenominator();
}

void Fraction::fractionReduction() {
    int nodND = nod(nominator_, denominator_);

    if (nodND != 1) {
        nominator_ = nominator_ / nodND;
        denominator_ = denominator_ / nodND;
    }
}

Fraction Fraction::operator+(const Fraction & f) const {
    int nom = this->getNominator() * f.getDenominator() +
              this->getDenominator() * f.getNominator();
    int den = this->getDenominator() * f.getDenominator();

    Fraction sum(nom, den);
    sum.fractionReduction();

    return sum;
}

Fraction Fraction::operator-(const Fraction & f) const {
    int nom = this->getNominator() * f.getDenominator() -
        this->getDenominator() * f.getNominator();
    int den = this->getDenominator() * f.getDenominator();

    Fraction dif(nom, den);
    dif.fractionReduction();

    return dif;
}

Fraction Fraction::operator*(const Fraction & f) const {
    int nom = this->getNominator() * f.getNominator();
    int den = this->getDenominator() * f.getDenominator();

    Fraction mult(nom, den);
    mult.fractionReduction();

    return mult;
}

Fraction Fraction::operator/(const Fraction & f) const {
    int nom = this->getNominator() * f.getDenominator();
    int den = this->getDenominator() * f.getNominator();

    Fraction division(nom, den);
    division.fractionReduction();

    return division;
}

Fraction Fraction::operator+(const int & n) const {
    int nom = this->getNominator() + this->getDenominator() * n;

    Fraction sum(nom, this->getDenominator());
    sum.fractionReduction();

    return sum;
}

Fraction Fraction::operator-(const int & n) const {
    int nom = this->getNominator() - this->getDenominator() * n;

    Fraction dif(nom, this->getDenominator());
    dif.fractionReduction();

    return dif;
}

Fraction Fraction::operator*(const int & n) const {
    int nom = this->getNominator() * n;

    Fraction mult(nom, this->getDenominator());
    mult.fractionReduction();

    return mult;
}

Fraction Fraction::operator/(const int & n) const {
    int den = this->getDenominator() * n;

    Fraction division(this->getNominator(), den);
    division.fractionReduction();

    return division;
}

Fraction& Fraction::operator=(const Fraction & f) {
    this->nominator_ = f.getNominator();
    this->denominator_ = f.getDenominator();

    return *this;
}

Fraction::operator double() const {
    return static_cast<double>(nominator_) / denominator_;
}

bool Fraction::operator>(const Fraction & f) {
    double f1 = *this;
    double f2 = f;

    return f1 > f2;
}

bool Fraction::operator>=(const Fraction & f) {
    double f1 = *this;
    double f2 = f;

    return f1 >= f2;
}

bool Fraction::operator<(const Fraction & f) {
    double f1 = *this;
    double f2 = f;

    return f1 < f2;
}

bool Fraction::operator<=(const Fraction & f) {
    double f1 = *this;
    double f2 = f;

    return f1 <= f2;
}

int Fraction::changeDenominator(const int & den) {
    if (denominator_ < den && den % denominator_ == 0) {
        denominator_ = den;
        nominator_ *= (den / denominator_);
    } else if (denominator_ > den && denominator_ % den == 0 &&
               nominator_ % (denominator_ / den) == 0) {
        nominator_ /= denominator_ / den;
        denominator_ = den;
    } else {
        throw std::string("Can`t change denominator for this fraction.");
    }
    return 0;
}

int nod(int a, int b) {
    if (a < 0) {
        a = -a;
    }
    if (b < 0) {
        b = -b;
    }

    while (a && b) {
        if (a >= b) {
            a = a % b;
        } else {
            b = b % a;
        }
    }

    if (a == 0) {
        return b;
    } else {
        return a;
    }
}

Fraction operator+(const int & n, const Fraction & f) {
    return f + n;
}

Fraction operator-(const int & n, const Fraction & f) {
    int nom = f.getDenominator() * n - f.getNominator();

    Fraction dif(nom, f.getDenominator());
    dif.fractionReduction();

    return dif;
}

Fraction operator*(const int & n, const Fraction & f) {
    return f * n;
}

Fraction operator/(const int & n, const Fraction & f) {
    int nom = f.getDenominator() * n;

    Fraction division(nom, f.getNominator());
    division.fractionReduction();

    return division;
}
