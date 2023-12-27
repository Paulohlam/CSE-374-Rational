// Rational.cpp
// Author: Paul Lam
// CSE374, HW7
// Implements Rational.h
// Copyright 2023 Paul Lam

#include <cstdlib>
#include "Rational.h"

namespace Rational374 {

int gcd(int a, int b);

// Constructors
// Constructors
Rational::Rational(int n, int d) {
  if(n == 0) {
		numer_ = 0;
		denom_ = 1;
    
	} else if (d == 0) {
    numer_ = 1;
    denom_ = 0;
  } else {
    numer_ = n;
    denom_ = d;
  }
}

Rational::Rational() : numer_(0), denom_(1) {}

Rational::Rational(int n) : numer_(n), denom_(1) {}

// Accessors
int Rational::n() const {
  return numer_;
}

int Rational::d() const {
  return denom_;
}

// Arithmetic operations
Rational Rational::plus(Rational other) const {
  int den = denom_ * other.d();
  int num = (numer_ * other.d()) + (other.n() * denom_);
  int gcd_num = gcd(abs(num), abs(den));

  num = num / gcd_num;
  den = den / gcd_num;

  if (den < 0) {
    num = -1 * num;
  }

  return Rational(num, abs(den));
}

Rational Rational::minus(Rational other) const {
  return plus(Rational(-1 * other.n(), other.d()));
}

Rational Rational::times(Rational other) const {
  int num = numer_ * other.n();
  int den = denom_ * other.d();
  int gcd_num = gcd(abs(num), abs(den));

  num = num / gcd_num;
  den = den / gcd_num;

  if (den < 0) {
    num = -1 * num;
  }

  return Rational(num, abs(den));
}

Rational Rational::div(Rational other) const {
  if (other.d() == 0) {
    return Rational(numer_ >= 0 ? 1 : -1, 0);  // Return a rational with 1/0 to represent division by zero
  } else if (numer_ == 0) {
    return Rational(0, 1);  // Return 0/1 for division when the dividend is zero
  } else {
    return times(Rational(other.d(), other.n()));
  }
}



// gcd (greatest common divisor) function
int gcd(int a, int b) {
  if (a == 0) {
    return b;
  } else if (b == 0) {
    return a;
  }

  while (b != 0) {
    int temp = b;
    b = a % b;
    a = temp;
  }

  return a;
}

}  // namespace Rational374
