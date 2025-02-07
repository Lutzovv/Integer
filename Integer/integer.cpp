#include "integer.hpp"

Integer::Integer(int number) {
    if (number < 0) {
        sign_ = true;
        units_ = ::abs(number);
    }
    else {
        sign_ = false;
        units_ = static_cast<unsigned>(number);
    }
}


Integer::Integer(std::string str) {
    Integer(std::stoi(str));
}


void Integer::setSign(bool sign) {
    this->sign_ = sign;
}


void Integer::setUnits(unsigned units) {
    this->units_ = units;
}


bool Integer::getSign() const {
    return sign_;
}


unsigned Integer::getUnits() const {
    return units_;
}


bool Integer::isOdd() const {
    return bool(units_ % 2);
}


bool Integer::isPositive() const {
    return !sign_;
}


bool Integer::isSimple() const {
    if (units_ < 2) return false;
    for (int i = 2; i <= sqrt(getUnits()); i++) {
        if (getUnits() % i == 0) {
            return false;
        }
    }
    return true;
}


unsigned Integer::findNOD(Integer other) const {
    unsigned a = getUnits();
    unsigned b = other.getUnits();
    
    while (b != 0) {
        unsigned temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}


unsigned Integer::findNOK(Integer other) const {
    return (getUnits() * other.getUnits()) / findNOD(other);
}


bool Integer::isCoprime(Integer other) const {
    return findNOD(other) == 1 ? true : false;
}


Integer Integer::operator+(const Integer other) const {
    if (sign_ == other.sign_) {
        if (sign_) {
            return (units_ + other.units_) * -1;
        }
        else {
            return (units_ + other.units_);
        }
    }
    else {
        if (units_ > other.units_) {
            return sign_ ? (units_ - other.units_) * -1 : (units_ - other.units_);
        }
        else {
            return other.sign_ ? (other.units_ - units_) * -1 : (other.units_ - units_);
        }
    }
}


Integer Integer::operator-(const Integer other) const {
    if (sign_ == other.sign_) {
        if (sign_) {
            return (units_ - other.units_) * -1;
        }
        else {
            return (units_ - other.units_);
        }
    }
    else {
        if (units_ > other.units_) {
            return sign_ ? (units_ + other.units_) : (units_ + other.units_) * -1;
        }
        else {
            return other.sign_ ? (other.units_ + units_) : (other.units_ + units_) * -1;
        }
    }
}


Integer Integer::operator*(const Integer other) const {
    if (other.units_ == 0) {
        return 0;
    }

    if (sign_ == other.sign_) {
        return units_ * other.units_;
    }
    return (units_ * other.units_) * -1;
}


Integer Integer::operator/(const Integer other) const {
    if (other.units_ == 0) {
        return 0;
    }

    if (sign_ == other.sign_) {
        return units_ / other.units_;
    }
    return (units_ / other.units_) * -1;
}


Integer Integer::operator%(const Integer other) const {
    if (other.units_ == 0) {
        return 0;
    }

    return Integer(((other * (*this / other)) - *this) * -1);
}


void Integer::operator+=(Integer other) {
    *this = *this + other;
}


void Integer::operator-=(Integer other) {
    *this = *this - other;
}


void Integer::operator*=(Integer other) {
    *this = *this * other;
}


void Integer::operator/=(Integer other) {
    *this = *this / other;
}


bool Integer::operator==(const Integer other) const {
    if (!(sign_ && other.sign_)) {
        return units_ == other.units_;
    }
    else if (sign_ == true && other.sign_ == false) {
        return false;
    }
    else if (sign_ == false && other.sign_ == true) {
        return true;
    }
}


bool Integer::operator!=(const Integer other) const {
    if (!(sign_ && other.sign_)) {
        return !(units_ == other.units_);
    }
    else if (sign_ == true && other.sign_ == false) {
        return true;
    }
    else if (sign_ == false && other.sign_ == true) {
        return false;
    }
}


bool Integer::operator>=(const Integer other) const {
    if (!(sign_ && other.sign_)) {
        return units_ >= other.units_;
    }
    else if (sign_ == true && other.sign_ == false) {
        return false;
    }
    else if (sign_ == false && other.sign_ == true) {
        return true;
    }
}


bool Integer::operator<=(const Integer other) const {
    if (!(sign_ && other.sign_)) {
        return units_ <= other.units_;
    }
    else if (sign_ == true && other.sign_ == false) {
        return true;
    }
    else if (sign_ == false && other.sign_ == true) {
        return false;
    }
}


bool Integer::operator>(const Integer other) const {
    if (!(sign_ && other.sign_)) {
        return units_ > other.units_;
    }
    else if (sign_ == true && other.sign_ == false) {
        return false;
    }
    else if (sign_ == false &&
        other.sign_ == true) {
        return true;
    }
}


bool Integer::operator<(const Integer other) const {
    if (!(sign_ && other.sign_)) {
        return !(units_ < other.units_);
    }
    else if (sign_ == true && other.sign_ == false) {
        return true;
    }
    else if (sign_ == false && other.sign_ == true) {
        return false;
    }
}


Integer Integer::operator++() {
    if (sign_) {
        if (units_ == 1 || units_ == 0) {
            sign_ = false;
            units_ -= 1;
        }
        else {
            units_ += 1;
        }
    }
    else {
        units_ += 1;
    }
    return *this;
}


Integer Integer::operator++(int) {
    Integer copy{ *this };
    if (sign_) {
        if (units_ == 1 || units_ == 0) {
            sign_ = false;
            units_ -= 1;
        }
        else {
            units_ += 1;
        }
    }
    else {
        units_ += 1;
    }
    return copy;
}


Integer Integer::operator--() {
    if (!sign_) {
        if (units_ == 1 || units_ == 0) {
            sign_ = true;
            units_ += 1;
        }
        else {
            units_ += 1;
        }
    }
    else {
        units_ += 1;
    }
    return *this;
}


Integer Integer::operator--(int) {
    Integer copy{ *this };
    if (!sign_) {
        if (units_ == 1 || units_ == 0) {
            sign_ = true;
            units_ += 1;
        }
        else {
            units_ += 1;
        }
    }
    else {
        units_ += 1;
    }
    return copy;
}


std::ostream& operator<<(std::ostream& out, const Integer& obj) {
    if (obj.sign_ == true) {
        return out << '-' << obj.units_;
    }
    return out << obj.units_;
}


std::istream& operator>>(std::istream& in, Integer& obj) {
    std::string str;

    in >> str;
    if (std::stoi(str) < 0) {
        obj.sign_ = true;
    }
    obj.units_ = ::abs(std::stoi(str));

    return in;
}
