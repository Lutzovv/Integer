#ifndef _RATIONAL_HPP_
#define RATIONAL_HPP_

#include "integer.hpp"

class Rational {
public:
	Rational() = default;
	Rational(Integer numerator, Integer denominator) : numerator_(numerator), denominator_(denominator) {};

	void setNumerator(Integer numerator);
	void setDenominator(Integer denominator);


	Integer getNumerator();
	Integer getDenominator();




private:
	Integer numerator_;
	Integer denominator_;

};

#endif // _RATIONAL_HPP_
