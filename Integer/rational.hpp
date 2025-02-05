#ifndef _RATIONAL_HPP_
#define _RATIONAL_HPP_

#include "integer.hpp"
#include "cstdlib"

class Rational {
public:
	Rational() : Rational(0, 0, false, false) {}
	Rational(Integer numerator, Integer denominator);
	Rational(
		int numerator, 
		int denominator, 
		bool signNumerator, 
		bool signDenominator) : 
		numerator_(numerator), 
		denominator_(denominator), 
		signNumerator_(signNumerator), 
		signDenominator_(signDenominator) {};
	Rational(unsigned numerator, 
		unsigned denominator, 
		bool signNumerator, 
		bool signDenominator) : 
		numerator_(numerator), 
		denominator_(denominator), 
		signNumerator_(signNumerator), 
		signDenominator_(signDenominator) {};
	Rational(const char* str);


	void setNumerator(Integer numerator);
	void setDenominator(Integer denominator);
	void setSignNumerator(bool sign);
	void setSignDenominator(bool sign);


	Integer getNumerator() const;
	Integer getDenominator() const;
	bool getSignNumerator() const;
	bool getSignDenominator() const;

	bool properFraction() const;
	bool isRationalPositive() const;


	bool isRationalReciprocal(Rational other) const;
	Rational getReducingRational() const;
	void reducingRational();
	void ractoinReplacement();


	Rational operator+(const Rational other) const;


	friend std::ostream& operator<<(std::ostream& out, const Rational& obj);

private:
	Integer numerator_;
	Integer denominator_;
	bool signNumerator_;
	bool signDenominator_;

};

#endif // _RATIONAL_HPP_
