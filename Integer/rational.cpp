#include "rational.hpp"

Rational::Rational(const char* str) {
	const char* symbol = std::strchr(str, '/');
	if (symbol != nullptr) {
		numerator_ = std::stoi(std::string(str, symbol - str).c_str());
		denominator_ = std::stoi(symbol + 1);
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


Rational Rational::ractoinReplacement() const {
	Rational temp;
	temp.numerator_ = this->denominator_;
	temp.denominator_ = this->numerator_;
	return temp;
}


Rational Rational::operator+(const Rational other) const {
	Rational num1 = *this;
	Rational num2 = other;

	Integer nok = denominator_.findNOK(num2.denominator_);

	num1.numerator_ = (nok / num1.denominator_) * num1.numerator_;
	num2.numerator_ = (nok / num2.denominator_) * num2.numerator_;

	Integer temp = num1.numerator_ + (num2.sign_ ? num2.numerator_ * -1 : num2.numerator_);

	return Rational(temp, nok);
}


Rational Rational::operator-(const Rational other) const {
	Rational num1 = *this;
	Rational num2 = other;

	Integer nok = denominator_.findNOK(num2.denominator_);

	num1.numerator_ = (nok / num1.denominator_) * num1.numerator_;
	num2.numerator_ = (nok / num2.denominator_) * num2.numerator_;

	if (num1.getSign() == true) {
		num1.sign_ = !sign_;
	}
	else if (num2.getSign() == true) {
		num2.sign_ = !sign_;
	}

	Integer temp = num1.numerator_ - (num2.sign_ ? num2.numerator_ * -1 : num2.numerator_);

	return Rational(temp, nok);
}


Rational Rational::operator*(const Rational other) const {
	Rational result;

	if (this->sign_ != other.sign_) {
		result.sign_ = true;
	}
	result.numerator_ = this->numerator_ * other.numerator_;
	result.denominator_ = this->denominator_ * other.denominator_;

	return result;
}


Rational Rational::operator/(const Rational other) const {
	Rational result = *this * other.ractoinReplacement();
	if (this->sign_ != other.sign_) {
		result.sign_ = true;
	}
	return result;
}


void Rational::operator+=(const Rational other) {
	*this = *this + other;
}


void Rational::operator-=(const Rational other) {
	*this = *this - other;
}


void Rational::operator*=(const Rational other) {
	*this = *this * other;
}


void Rational::operator/=(const Rational other) {
	*this = *this / other;
}


bool Rational::operator==(const Rational other) const {
	if (this->sign_ != other.sign_) {
		if (this->sign_ == true) {
			return false;
		}
		else {
			return true;
		}
	}
	Rational num1 = *this;
	Rational num2 = other;

	Integer nok = denominator_.findNOK(num2.denominator_);

	num1.numerator_ = (nok / num1.denominator_) * num1.numerator_;
	num2.numerator_ = (nok / num2.denominator_) * num2.numerator_;

	return num1.numerator_ == num2.numerator_;
}


bool Rational::operator!=(const Rational other) const {
	return !(*this == other);
}


bool Rational::operator>(const Rational other) const {
	if (this->sign_ != other.sign_) {
		if (this->sign_ == true) {
			return true;
		}
		else {
			return false;
		}
	}

	Rational num1 = *this;
	Rational num2 = other;

	Integer nok = denominator_.findNOK(num2.denominator_);

	num1.numerator_ = (nok / num1.denominator_) * num1.numerator_;
	num2.numerator_ = (nok / num2.denominator_) * num2.numerator_;

	return num1.numerator_ > num2.numerator_;
}


bool Rational::operator<(const Rational other) const {
	return !(*this > other);
}


bool Rational::operator>=(const Rational other) const {
	if (this->sign_ != other.sign_) {
		if (this->sign_ == true) {
			return false;
		}
		else {
			return true;
		}
	}

	Rational num1 = *this;
	Rational num2 = other;

	Integer nok = denominator_.findNOK(num2.denominator_);

	num1.numerator_ = (nok / num1.denominator_) * num1.numerator_;
	num2.numerator_ = (nok / num2.denominator_) * num2.numerator_;

	return num1.numerator_ >= num2.numerator_;
}


bool Rational::operator<=(const Rational other) const {
	if (this->sign_ != other.sign_) {
		if (this->sign_ == true) {
			return true;
		}
		else {
			return false;
		}
	}

	Rational num1 = *this;
	Rational num2 = other;

	Integer nok = denominator_.findNOK(num2.denominator_);

	num1.numerator_ = (nok / num1.denominator_) * num1.numerator_;
	num2.numerator_ = (nok / num2.denominator_) * num2.numerator_;

	return num1.numerator_ <= num2.numerator_;
}


Rational Rational::operator++() {
	this->numerator_++;
	return *this;
}


Rational Rational::operator++(int) {
	Rational temp = *this;
	this->numerator_++;
	return temp;
}


Rational Rational::operator--() {
	this->numerator_--;
	return *this;
}


Rational Rational::operator--(int) {
	Rational temp = *this;
	this->numerator_--;
	return temp;
}


std::istream& operator>>(std::istream& in, Rational& obj) {
	std::string str;
	in >> str;
	obj = Rational(str.c_str());
	return in;
}


std::ostream& operator<<(std::ostream& out, const Rational& obj) {
	if (obj.sign_ == true) {
		return out << "-(" << obj.numerator_ << "/" << obj.denominator_ << ")";
	}
	return out << obj.numerator_ << "/" << obj.denominator_;
}
