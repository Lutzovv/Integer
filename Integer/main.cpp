#include <iostream> 

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
        return units_ > other.units_ ? other.units_ - units_ : units_ - other.units_;
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
                units_ = units_ - other.units_;
            }
            else {
                units_ = units_ - other.units_;
            }
        }
        else {
            if (units_ > other.units_) {
                units_ = units_ + other.units_;
            }
            else {
                sign_ = other.sign_;
                units_ = units_ + other.units_;
            }
        }
    }


    void operator*=(Integer other) {
        units_ = units_ * other.getUnits();
    }


    void operator/=(Integer other) {
        units_ = units_ / other.getUnits();
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

private:
    bool sign_;
    unsigned units_;
};

int main() {
    int aa = 29, bb = 30;
    Integer a = aa, b = bb, c;
    
    a -= b;
    std::cout << aa - bb << "\n";
    std::cout << a.getSign() << " " << a.getUnits();

    return 0;
}