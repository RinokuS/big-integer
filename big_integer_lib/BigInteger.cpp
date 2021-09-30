#include "BigInteger.h"

BigInteger::BigInteger() {
    sign = true;
}
BigInteger::BigInteger(int number) : UnsignedBigInteger(number) {
    sign = number >= 0;
}
BigInteger::BigInteger(unsigned int number) : UnsignedBigInteger(number) {
    sign = true;
}
BigInteger::BigInteger(long number) : UnsignedBigInteger(number) {
    sign = number >= 0;
}
BigInteger::BigInteger(unsigned long number) : UnsignedBigInteger(number) {
    sign = true;
}
BigInteger::BigInteger(long long number) : UnsignedBigInteger(number) {
    sign = number >= 0;
}
BigInteger::BigInteger(unsigned long long number) : UnsignedBigInteger(number) {
    sign = true;
}
BigInteger::BigInteger(const BigInteger& copy) : UnsignedBigInteger(copy) {
    sign = copy.sign;
}
BigInteger::BigInteger(const UnsignedBigInteger& copy) : UnsignedBigInteger(copy) {
    sign = true;
}
BigInteger::BigInteger(const std::string& str) {
    std::istringstream iss(str);
    iss >> *this;
}

BigInteger& BigInteger::operator=(const BigInteger& copy) {
    digits.clear();
    for (char digit : copy.digits) {
        digits.push_back(digit);
    }

    sign = copy.sign;

    return *this;
}

std::string BigInteger::to_string() const {
    std::string buf;
    buf = UnsignedBigInteger::to_string();

    if (!sign)
        buf = '-' + buf;

    return buf;
}

std::ostream& operator<<(std::ostream& os, const BigInteger& number) {
    os << number.to_string();
    return os;
}

std::istream& operator>>(std::istream& in, BigInteger& number) {
    char digit = in.get();
    number.digits.clear();

    if (digit == '-') {
        number.sign = false;
        digit = in.get();
        number.digits.push_back(digit);
        if (digit == '0') {
            number.sign = true;
            return in;
        }
    } else if (digit == '+') {
        number.sign = true;
        digit = in.get();
        number.digits.push_back(digit);
        if (digit == '0') {
            number.sign = true;
            return in;
        }
    } else if (digit >= '1' && digit <= '9') {
        number.sign = true;
        number.digits.push_back(digit);
    } else {
        number.digits.push_back('0');
        number.sign = true;
        return in;
    }

    while ((digit = in.get()) >= '0' && digit <= '9') {
        number.digits.push_back(digit);
    }

    std::reverse(number.digits.begin(), number.digits.end());

    return in;
}

BigInteger::operator bool() const {
    return !(isZero());
}

BigInteger BigInteger::operator-() {
    BigInteger buf(*this);
    buf.sign ^= true;
    return buf;
}

BigInteger& BigInteger::operator++() {
    if (sign) {
        UnsignedBigInteger::operator++();
        return *this;
    }

    UnsignedBigInteger::operator--();
    if (isZero())
        sign = true;

    return *this;
}

BigInteger BigInteger::operator++(int) {
    BigInteger buf(*this);

    if (sign) {
        UnsignedBigInteger::operator++();
        return buf;
    }

    UnsignedBigInteger::operator--();
    if (isZero())
        sign = true;

    return buf;
}

BigInteger& BigInteger::operator--() {
    if (!sign) {
        UnsignedBigInteger::operator++();
        return *this;
    }

    if (isZero()) {
        digits[0] = '1';
        sign = false;
        return *this;
    }

    UnsignedBigInteger::operator--();
    return *this;
}

BigInteger BigInteger::operator--(int) {
    BigInteger buf(*this);

    if (!sign) {
        UnsignedBigInteger::operator++();
        return buf;
    }

    if (isZero()) {
        digits[0] = '1';
        sign = false;
        return buf;
    }

    UnsignedBigInteger::operator--();
    return buf;
}

bool operator<(const BigInteger& a, const BigInteger& b){
    if (a.sign == 1 && b.sign == 1) {
        return (UnsignedBigInteger)a < (UnsignedBigInteger)b;
    } else if (a.sign == 0 && b.sign == 0) {
        return (UnsignedBigInteger)b < (UnsignedBigInteger)a;
    } else {
        return a.sign < b.sign;
    }
}

bool operator==(const BigInteger& a, const BigInteger& b) {
    return !(a < b) && !(b < a);
}

bool operator!=(const BigInteger& a, const BigInteger& b) {
    return !(a == b);
}

bool operator>(const BigInteger& a, const BigInteger& b) {
    return (a >= b) && (a != b);
}

bool operator<=(const BigInteger& a, const BigInteger& b) {
    return (a < b) || (a == b);
}

bool operator>=(const BigInteger& a, const BigInteger& b) {
    return !(a < b);
}

BigInteger operator+(const BigInteger& a, const BigInteger& b) {
    BigInteger newNumber;

    if (a.sign == b.sign) {
        UnsignedBigInteger buf = a;
        buf.operator+=(b);
        newNumber = (BigInteger)buf;
        newNumber.sign = a.sign;
        return newNumber;
    }

    if ((UnsignedBigInteger)a < (UnsignedBigInteger)b) { //a<b
        newNumber = (BigInteger)((UnsignedBigInteger)b - (UnsignedBigInteger)a);
        newNumber.sign = b.sign;
        return newNumber;
    }

    if ( (UnsignedBigInteger)a > (UnsignedBigInteger)b) {
        newNumber = (BigInteger)((UnsignedBigInteger)a - (UnsignedBigInteger)b);
        newNumber.sign = a.sign;
        return newNumber;
    }

    return newNumber;
}

BigInteger& BigInteger::operator+=(const BigInteger& b) {
    if (sign == b.sign) {
        UnsignedBigInteger::operator+=(b);
        return *this;
    }

    if ((UnsignedBigInteger)*this >= (UnsignedBigInteger) b) {
        UnsignedBigInteger::operator-=(b);

        if (isZero())
            sign = true;

        return *this;
    } else {
        digits = ((BigInteger)((UnsignedBigInteger)b - (UnsignedBigInteger) *this)).digits;
        sign = b.sign;
        return *this;
    }
}

BigInteger operator-(const BigInteger& a, const BigInteger& b) {
    BigInteger newNum = b;
    newNum.sign ^= true;
    newNum += a;
    return newNum;
}

BigInteger& BigInteger::operator-=(const BigInteger& b) {
    sign ^= true;
    operator+=(b);
    sign ^= true;
    return *this;
}

BigInteger operator*(const BigInteger& a, const BigInteger& b) {
    BigInteger newNum = (BigInteger)((UnsignedBigInteger)a * (UnsignedBigInteger)b);
    if (newNum.isZero()) {
        return newNum;
    }
    newNum.sign = !(a.sign ^ b.sign);
    return newNum;
}

BigInteger& BigInteger::operator*=(const BigInteger& b) {
    UnsignedBigInteger::operator*=(b);
    if (isZero()) {
        sign = true;
        return *this;
    }
    sign = !(sign ^ b.sign);
    return *this;
}

BigInteger operator/(const BigInteger& a, const BigInteger& b) {
    BigInteger newNum = (BigInteger)((UnsignedBigInteger) a / (UnsignedBigInteger) b);
    if (newNum.isZero()) {
        return newNum;
    }
    newNum.sign = !(a.sign ^ b.sign);
    return newNum;
}

BigInteger& BigInteger::operator/=(const BigInteger& b) {
    UnsignedBigInteger::operator/=(b);
    if (isZero()) {
        sign = true;
        return *this;
    }
    sign = !(sign ^ b.sign);
    return *this;
}

bool BigInteger::isZero() const {
    return digits.size() == 1 && digits[0] == '0';
}

BigInteger operator%(const BigInteger& a, const BigInteger& b) {
    BigInteger newNum = a - a / b * b; //operator-(operator/(b).operator*(b));
    return newNum;
}

BigInteger& BigInteger::operator%=(const BigInteger& b) {
    operator-=(*this / b * b);  //operator/(b).operator*(b));
    return *this;
}