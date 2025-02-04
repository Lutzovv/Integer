#include "rational.hpp"

Rational::Rational(std::string str) {

}

void Rational::setNumerator(Integer numerator) {
	numerator_ = numerator;
}


void Rational::setDenominator(Integer denominator) {
	denominator_ = denominator;
}


void Rational::setSignNumerator(bool sign) {
	signNumerator_ = sign;
}


void Rational::setSignDenominator(bool sign) {
	signDenominator_ = sign;
}


Integer Rational::getNumerator() const {
	return numerator_;
}


Integer Rational::getDenominator() const {
	return denominator_;
}


bool Rational::properFraction() const {
	return !(numerator_ > denominator_);
}


bool Rational::getSignNumerator() const {
	return signNumerator_;
}


bool Rational::getSignDenominator() const {
	return signDenominator_;
}
 
