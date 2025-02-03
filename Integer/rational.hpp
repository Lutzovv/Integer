#ifndef _RATIONAL_HPP_
#define RATIONAL_HPP_

#include "integer.hpp"

class Rational {
public:
	Rational() : Rational(0, 0) {}
	Rational(Integer numerator, Integer denominator) : numerator_(numerator), denominator_(denominator) {};
	Rational(int numerator, int denominator) : numerator_(numerator), denominator_(denominator) {};
	Rational(unsigned numerator, unsigned denominator) : numerator_(numerator), denominator_(denominator) {};

	void setNumerator(Integer numerator);
	void setDenominator(Integer denominator);


	Integer getNumerator() const;
	Integer getDenominator() const;

	bool properFraction() const;


private:
	Integer numerator_;
	Integer denominator_;

};

#endif // _RATIONAL_HPP_
