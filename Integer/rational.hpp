#ifndef _RATIONAL_HPP_
#define _RATIONAL_HPP_

#include "integer.hpp"
#include "cstdlib"

class Rational {
public:
	Rational() : Rational(0, 0, false) {}
	Rational(Integer numerator, Integer denominator);
	Rational(
		int numerator, 
		int denominator, 
		bool sign) : 
		numerator_(numerator), 
		denominator_(denominator), 
		sign_(sign) {};
	Rational(
		unsigned numerator, 
		unsigned denominator, 
		bool sign) : 
		numerator_(numerator), 
		denominator_(denominator), 
		sign_(sign) {};
	Rational(const char* str);


	void setNumerator(Integer numerator);
	void setDenominator(Integer denominator);
	void setSign(bool sign);


	Integer getNumerator() const;
	Integer getDenominator() const;
	bool getSign() const;

	bool properFraction() const;


	bool isRationalReciprocal(Rational other) const;
	Rational getReducingRational() const;
	void reducingRational();
	Rational ractoinReplacement() const;


	Rational operator+(const Rational other) const;
	Rational operator-(const Rational other) const;
	Rational operator*(const Rational other) const;
	Rational operator/(const Rational other) const;
	void operator+=(const Rational other);
	void operator-=(const Rational other);
	void operator*=(const Rational other);
	void operator/=(const Rational other);
	bool operator==(const Rational other) const;
	bool operator!=(const Rational other) const;
	bool operator>(const Rational other) const;
	bool operator<(const Rational other) const;
	bool operator>=(const Rational other) const;
	bool operator<=(const Rational other) const;
	Rational operator++();
	Rational operator++(int);
	Rational operator--();
	Rational operator--(int);


	friend std::istream& operator>>(std::istream& in, Rational& obj);
	friend std::ostream& operator<<(std::ostream& out, const Rational& obj);

private:
	Integer numerator_;
	Integer denominator_;
	bool sign_;
};

#endif // _RATIONAL_HPP_
