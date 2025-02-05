#include "rational.hpp"

Rational::Rational(const char* str) {
	/*int symbol = str.find("/");
	numerator_ = std::stoi(str.substr(0, symbol));
	denominator_ = std::stoi(str.substr(symbol + 1));
	signNumerator_ = numerator_.getSign();
	signDenominator_ = denominator_.getSign();*/

	const char* symbol = std::strchr(str, '/');
	if (symbol != nullptr) {
		numerator_ = std::atoi(std::string(str, symbol - str).c_str());
		denominator_ = std::atoi(symbol + 1);
		signNumerator_ = numerator_.getSign();
		signDenominator_ = denominator_.getSign();
	}
}


Rational::Rational(Integer numerator, Integer denominator) {
	numerator_ = numerator.getUnits();
	signNumerator_ = numerator.getSign();

	denominator_ = denominator_.getUnits();
	signDenominator_ = denominator_.getSign();
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
 

bool Rational::isRationalPositive() const {
	return signNumerator_ == signDenominator_;
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
	/*
	создаём переменную резалт
	считаем НОК

	*/

	Rational result, num1 = *this, num2 = other;
	Integer temp, nok = denominator_.findNOK(other.denominator_);
	num1.numerator_ = (nok / num1.denominator_) * num1.numerator_;
	num2.numerator_ = (nok / num2.denominator_) * num2.numerator_;
	temp = num1.numerator_ + num2.numerator_;

	return Rational(temp, nok);
}


std::ostream& operator<<(std::ostream& out, const Rational& obj) {
	return out << obj.numerator_ << "/" << obj.denominator_;
}