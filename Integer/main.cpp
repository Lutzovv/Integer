<<<<<<< HEAD
#include "integer.hpp"
=======
#include <iostream> 
#include <string>

class Integer {
public:
    Integer() : Integer(false, 0u) {}
    Integer(bool sign, unsigned units) : sign_(sign), units_(units) {}
    Integer(int number) {
        if (number < 0) {
            sign_ = true;
            units_ = ::abs(number);
        }
        else {
            sign_ = false;
            units_ = static_cast<unsigned>(number);
        }
    }


    void setSign(bool sign) {
        this->sign_ = sign;
    }


    void setUnits(unsigned units) {
        this->units_ = units;
    }


    bool getSign() const {
        return sign_;
    }


    unsigned getUnits() const {
        return units_;
    }


    bool isOdd() const {
        return bool(units_ % 2);
    }


    bool isPositive() const {
        return !sign_;
    }


    bool isSimple() {
        if (units_ < 2) return false;
        for (int i = 2; i <= sqrt(getUnits()); i++) {
            if (getUnits() % i == 0) {
                return false;
            }
        }
        return true;
    }


    unsigned findNOD(Integer other) {
        unsigned a = getUnits();
        unsigned b = other.getUnits();

        while (b != 0) {
            unsigned temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }


    unsigned findNOK(Integer other) {
        return (getUnits() * other.getUnits()) / findNOD(other);
    }


    bool isCoprime(Integer other) {
        return findNOD(other) == 1 ? true : false;
    }


    Integer operator+(const Integer other) const {
        if (sign_ == other.sign_) {
            if (sign_ == false && other.sign_ == false) {
                return units_ + other.units_;
            }
            else {
                return (units_ + other.units_) * -1;
            }
        }
        return units_ > other.units_ ? other.units_ - units_ : (units_ - other.units_) * -1;
    }


    Integer operator-(const Integer other) const {
        if (sign_ == other.sign_) {
            if (sign_ == false && other.sign_ == false) {
                return units_ - other.units_;
            }
            else {
                return (units_ - other.units_) * -1;
            }
        }
        return units_ > other.units_ ? units_ + other.units_ : units_ + other.units_;
    }


    Integer operator*(const Integer other) const {
        if (sign_ == other.sign_) {
            return units_ * other.units_;
        }
        return (units_ * other.units_) * -1;
    }


    Integer operator/(const Integer other) const {
        if (sign_ == other.sign_) {
            return units_ / other.units_;
        }
        return (units_ / other.units_) * -1;
    }


    Integer operator%(const Integer other) const {
        if (sign_ == other.sign_) {
            return units_ % other.units_;
        }
        return (units_ % other.units_) * -1;
    }


    void operator+=(Integer other) {
        if (sign_ == other.sign_) {
            if (sign_ == false && other.sign_ == false) {
                units_ = units_ + other.units_;
            }
            else {
                units_ = units_ + other.units_;
            }
        }
        else {
            if (units_ > other.units_) {
                units_ = units_ - other.units_;
            }
            else {
                sign_ = other.sign_;
                units_ = other.units_ - units_;
            }
        }
    }


    void operator-=(Integer other) {
        if (sign_ == other.sign_) {
            if (sign_ == false && other.sign_ == false) {
                units_ = units_ + other.units_;
            }
            else {
                sign_ = false;
                units_ = other.units_ - units_;
            }
        }
        else {
            if (units_ > other.units_) {
                units_ = units_ + other.units_;
            }
            else {
                units_ = other.units_ + units_;
            }
        }
    }


    void operator*=(Integer other) {
        if (sign_ == other.sign_) {
            units_ = units_ * other.units_;
        }
        else {
            sign_ = true;
            units_ = units_ * other.units_;
        }
    }


    void operator/=(Integer other) {
        if (sign_ == other.sign_) {
            units_ = units_ / other.units_;
        }
        else {
            sign_ = true;
            units_ = units_ / other.units_;
        }
    }


    bool operator==(Integer other) {
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


    bool operator!=(Integer other) {
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


    bool operator>=(Integer other) {
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


    bool operator<=(Integer other) {
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


    bool operator>(Integer other) {
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


    bool operator<(Integer other) {
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


    Integer operator++() {
        if (sign_) {
            if (units_ == -1 || units_ == 0) {
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


    Integer operator++(int) {
        if (sign_) {
            if (units_ == -1 || units_ == 0) {
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


    Integer operator--() {
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


    Integer operator--(int) {
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


    friend std::ostream& operator<<(std::ostream& out, const Integer& obj) {
        char sign = '\0';
        if (obj.sign_ == true) {
            sign = '-';
        }
        return out << sign << obj.units_;
    }


    friend std::istream& operator>>(std::istream& in, Integer& obj) {
        std::string str;
        
        in >> str;
        if (std::stoi(str) < 0) {
            obj.sign_ = true;
        }
        obj.units_ = ::abs(std::stoi(str));

        return in;
    }

private:
    bool sign_;
    unsigned units_;
};
>>>>>>> 1b5d5d23f0c748339f4396ca50e5c006cc70c6b7


class Fraction {
public:



private:
    Integer numerator_;
    Integer denominator_;
    bool sign_;


};


int main() {
<<<<<<< HEAD
    system("chcp 1251>NUL");
    
    Integer a = 5;
    Integer b = 3;
    Integer c = -2;
    Integer d = -4;

    std::cout << 7 % -5 << "\n";
}
=======
    std::cout << "\3\3\3\3\3\3\3\3\3\3\n";
    int aa = -15, bb = 15;
    Integer a = aa, b = bb, C;

    std::cin >> C;
    std::cout << C++;
    

    //a--;
    //std::cout << a.getUnits() << "\n";
    //std::cout << a << "\n";

    /*a /= b;
    std::cout << aa - bb << "\n";
    std::cout << a.getSign() << " " << a.getUnits();*/

    /*if (a != b) {
        std::cout << "==";
    }
    else {
        std::cout << "-";
    }*/



    return 0;
}
>>>>>>> 1b5d5d23f0c748339f4396ca50e5c006cc70c6b7
