#include "rational.hpp"

Rational::Rational(const char* str) {
	const char* symbol = std::strchr(str, '/');
	if (symbol != nullptr) {
		numerator_ = std::atoi(std::string(str, symbol - str).c_str());
		denominator_ = std::atoi(symbol + 1);
		if (numerator_.getSign() == denominator_.getSign()) {
			sign_ = false;
			numerator_.setSign(false);
			denominator_.setSign(false);
		}
		else {
			sign_ = true;
			numerator_.setSign(false);
			denominator_.setSign(false);
		}
	}
}


Rational::Rational(Integer numerator, Integer denominator) {
	numerator_ = numerator;
	denominator_ = denominator;

	if (numerator.getSign() == denominator.getSign()) {
		sign_ = false;
		numerator_.setSign(false);
		denominator_.setSign(false);
	}
	else {
		sign_ = true;
		numerator_.setSign(false);
		denominator_.setSign(false);
	}
}


void Rational::setNumerator(Integer numerator) {
	numerator_ = numerator;
}


void Rational::setDenominator(Integer denominator) {
	denominator_ = denominator;
}


void Rational::setSign(bool sign) {
	sign_ = sign;
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


bool Rational::getSign() const {
	return sign_;
}


bool Rational::isRationalReciprocal(Rational other) const {
	return ((numerator_ == other.denominator_) && (denominator_ == other.numerator_));
}


Rational Rational::getReducingRational() const {
	Integer nod = numerator_.findNOD(denominator_);
	return Rational(numerator_ / nod, denominator_ / nod);
}


void Rational::reducingRational() {
	Integer nod = numerator_.findNOD(denominator_);
	numerator_ /= nod;
	denominator_ /= nod;
}


void Rational::ractoinReplacement() {
	Integer temp = denominator_;
	denominator_ = numerator_;
	numerator_ = temp;	
}


Rational Rational::operator+(const Rational other) const {

	Rational result, num1 = *this, num2 = other;
	Integer temp, nok = denominator_.findNOK(other.denominator_);
	num1.numerator_ = (nok / num1.denominator_) * num1.numerator_;
	num2.numerator_ = (nok / num2.denominator_) * num2.numerator_;
	temp = num1.numerator_ + num2.numerator_;

	return Rational(temp, nok);
}


std::ostream& operator<<(std::ostream& out, const Rational& obj) {
	if (obj.sign_ == true) {
		return out << "-(" << obj.numerator_ << "/" << obj.denominator_ << ")";
	}
	return out << obj.numerator_ << "/" << obj.denominator_;
}