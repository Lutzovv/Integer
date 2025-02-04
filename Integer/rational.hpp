#ifndef _RATIONAL_HPP_
#define _RATIONAL_HPP_

#include "integer.hpp"

class Rational {
public:
	Rational() : Rational(0, 0) {}
	Rational(Integer numerator, Integer denominator) : numerator_(numerator), denominator_(denominator) {};
	Rational(int numerator, int denominator) : numerator_(numerator), denominator_(denominator) {};
	Rational(unsigned numerator, unsigned denominator) : numerator_(numerator), denominator_(denominator) {};
	Rational(std::string str);

	void setNumerator(Integer numerator);
	void setDenominator(Integer denominator);
	void setSignNumerator(bool sign);
	void setSignDenominator(bool sign);


	Integer getNumerator() const;
	Integer getDenominator() const;
	bool getSignNumerator() const;
	bool getSignDenominator() const;

	bool properFraction() const;


private:
	Integer numerator_;
	Integer denominator_;
	bool signNumerator_;
	bool signDenominator_;

};

#endif // _RATIONAL_HPP_
