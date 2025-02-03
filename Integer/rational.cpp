#include "rational.hpp"

void Rational::setNumerator(Integer numerator) {
	numerator_ = numerator;
}


void Rational::setDenominator(Integer denominator) {
	denominator_ = denominator;
}


Integer Rational::getNumerator() {
	return numerator_;
}


Integer Rational::getDenominator() {
	return denominator_;
}