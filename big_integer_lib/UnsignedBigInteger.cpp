#include "UnsignedBigInteger.h"

UnsignedBigInteger::UnsignedBigInteger() {
    digits.push_back('0');
}
UnsignedBigInteger::UnsignedBigInteger(int number) {
    std::string str_from_number = std::to_string(number);

    if (number < 0) {
        for (int i = str_from_number.length() - 1; i > 0; --i) {
            digits.push_back(str_from_number[i]);
        }
    } else {
        for (int i = str_from_number.length() - 1; i >= 0; --i) {
            digits.push_back(str_from_number[i]);
        }
    }
}
UnsignedBigInteger::UnsignedBigInteger(unsigned int number) {
    std::string str_from_number = std::to_string(number);

    for (int i = str_from_number.length() - 1; i >= 0; --i) {
        digits.push_back(str_from_number[i]);
    }
}
UnsignedBigInteger::UnsignedBigInteger(long number) {
    std::string str_from_number = std::to_string(number);

    if (number < 0) {
        for (int i = str_from_number.length() - 1; i > 0; --i) {
            digits.push_back(str_from_number[i]);
        }
    } else {
        for (int i = str_from_number.length() - 1; i >= 0; --i) {
            digits.push_back(str_from_number[i]);
        }
    }
}
UnsignedBigInteger::UnsignedBigInteger(unsigned long number) {
    std::string str_from_number = std::to_string(number);

    for (int i = str_from_number.length() - 1; i >= 0; --i) {
        digits.push_back(str_from_number[i]);
    }
}
UnsignedBigInteger::UnsignedBigInteger(long long number) {
    std::string str_from_number = std::to_string(number);

    if (number < 0) {
        for (int i = str_from_number.length() - 1; i > 0; --i) {
            digits.push_back(str_from_number[i]);
        }
    } else {
        for (int i = str_from_number.length() - 1; i >= 0; --i) {
            digits.push_back(str_from_number[i]);
        }
    }
}
UnsignedBigInteger::UnsignedBigInteger(unsigned long long number) {
    std::string str_from_number = std::to_string(number);

    for (int i = str_from_number.length() - 1; i >= 0; --i) {
        digits.push_back(str_from_number[i]);
    }
}
UnsignedBigInteger::UnsignedBigInteger(const UnsignedBigInteger& copy) {
    for (char digit : copy.digits) {
        digits.push_back(digit);
    }
}
UnsignedBigInteger::UnsignedBigInteger(const std::string& str) {
    std::istringstream iss(str);
    iss >> *this;
}

UnsignedBigInteger::~UnsignedBigInteger() {
    digits.clear();
}

UnsignedBigInteger& UnsignedBigInteger::operator=(const UnsignedBigInteger& copy) {
    digits.clear();
    for (char digit : copy.digits) {
        digits.push_back(digit);
    }

    return *this;
}

std::ostream& operator<<(std::ostream& out, const UnsignedBigInteger& number) {
    out << number.to_string();
    return out;
}

std::istream& operator>>(std::istream& in, UnsignedBigInteger& number) {
    char digit = in.get();
    number.digits.clear();

    if (digit < 48 || digit > 57) {
        number.digits.push_back('0');
        return in;
    }

    while ((digit = in.get()) >= 48 && digit <= 57) {
        number.digits.push_back(digit);
    }

    return in;
}

std::string UnsignedBigInteger::to_string() const {
    std::string buf;
    for (auto i = digits.rbegin(); i < digits.rend(); ++i) {
        buf += *i;
    }

    return buf;
}

UnsignedBigInteger::operator bool() {
    if (digits.size() == 1 && digits[0] == '0') {
        return false;
    }

    return true;
}

const UnsignedBigInteger& UnsignedBigInteger::operator++() {
    int i = 0;
    while (digits[i] == '9') {
        digits[i] = '0';
        ++i;
        if (i >= digits.size()) {
            digits.push_back('1');
            return *this;
        }
    }
    ++digits[i];
    return *this;
}

UnsignedBigInteger UnsignedBigInteger::operator++(int) {
    UnsignedBigInteger buf(*this);
    int i = 0;
    while (digits[i] == '9') {
        digits[i] = '0';
        ++i;
        if (i >= digits.size()) {
            digits.push_back('1');
            return buf;
        }
    }
    ++digits[i];
    return buf;
}

const UnsignedBigInteger& UnsignedBigInteger::operator--() {
    int i = 0;
    if (digits.size() == 1 && digits[i] == '0') {
        return *this;
    }
    while (digits[i] == '0') {
        digits[i] = '9';
        ++i;
    }

    if (digits[i] == '1' && digits.size() != 1) {
        digits.pop_back();
    } else {
        --digits[i];
    }
    return *this;
}

UnsignedBigInteger UnsignedBigInteger::operator--(int) {
    UnsignedBigInteger buf(*this);
    int i = 0;

    if (digits.size() == 1 && digits[i] == '0') {
        return buf;
    }
    while (digits[i] == '0') {
        digits[i] = '9';
        ++i;
    }

    if (digits[i] == '1' && digits.size() != 1) {
        digits.pop_back();
    } else {
        --digits[i];
    }
    return buf;
}

UnsignedBigInteger operator+(const UnsignedBigInteger& a, const UnsignedBigInteger& b){
    UnsignedBigInteger newNumber;
    newNumber.digits.clear();
    char dopNumber = 0;
    size_t i = 0;
    for (; i < std::min(a.digits.size(), b.digits.size()); ++i) {
        char buf = (a.digits[i] - '0') + (b.digits[i] - '0') + dopNumber;
        newNumber.digits.push_back(buf % 10 + '0');
        dopNumber = buf / 10;
    }

    while (i < a.digits.size()) {
        char buf = ((a.digits[i] - '0') + dopNumber);
        newNumber.digits.push_back(buf % 10 + '0');
        dopNumber = buf / 10;
        ++i;
    }

    while (i < b.digits.size()) {
        char buf = ((b.digits[i] - '0') + dopNumber);
        newNumber.digits.push_back(buf % 10 + '0');
        dopNumber = buf / 10;
        ++i;
    }

    if (dopNumber != 0)
        newNumber.digits.push_back(dopNumber + '0');

    return newNumber;
}

UnsignedBigInteger& UnsignedBigInteger::operator+=(const UnsignedBigInteger& b) {
    char dopNumber = 0;
    size_t i = 0;
    for (; i < std::min(digits.size(), b.digits.size()); ++i) {
        char buf = (digits[i] - '0') + (b.digits[i] - '0') + dopNumber;
        digits[i] = buf % 10 + '0';
        dopNumber = buf / 10;
    }

    while (i < digits.size()) {
        char buf = ((digits[i] - '0') + dopNumber);
        digits[i] = buf % 10 + '0';
        dopNumber = buf / 10;
        ++i;
    }

    while (i < b.digits.size()) {
        char buf = ((b.digits[i] - '0') + dopNumber);
        digits.push_back(buf % 10 + '0');
        dopNumber = buf / 10;
        ++i;
    }

    if (dopNumber != 0)
        digits.push_back(dopNumber + '0');

    return *this;
}

bool operator<(const UnsignedBigInteger& a, const UnsignedBigInteger& b){
    if (a.digits.size() < b.digits.size())
        return true;

    if (a.digits.size() > b.digits.size())
        return false;

    for (int i = a.digits.size() - 1; i >= 0; --i) {
        if (a.digits[i] != b.digits[i])
            return a.digits[i] < b.digits[i];
    }

    return false;
}

bool operator>=(const UnsignedBigInteger& a, const UnsignedBigInteger& b) {
    return !(a < b);
}

bool operator==(const UnsignedBigInteger& a, const UnsignedBigInteger& b) {
    return !(a < b) && !(b < a);
}

bool operator!=(const UnsignedBigInteger& a, const UnsignedBigInteger& b) {
    return !(a == b);
}

bool operator>(const UnsignedBigInteger& a, const UnsignedBigInteger& b){
    return (a >= b) && (a != b);
}

bool operator<=(const UnsignedBigInteger& a, const UnsignedBigInteger& b) {
    return (a < b) || (a == b);
}

UnsignedBigInteger operator-(const UnsignedBigInteger& a, const UnsignedBigInteger& b) {
    UnsignedBigInteger newNumber;

    if (a <= b)
        return newNumber;
    else
        newNumber.digits.clear();

    size_t i = 0;
    bool nextRank = false;
    for (; i < std::min(a.digits.size(), b.digits.size()); ++i) {
        char buf = b.digits[i] + nextRank;
        if (a.digits[i] < buf) {
            nextRank = true;
            newNumber.digits.push_back((10 - (buf - a.digits[i])) + '0');
        }
        else {
            nextRank = false;
            newNumber.digits.push_back(a.digits[i] - buf + '0');
        }
    }

    while (i < a.digits.size()) {
        if (nextRank) {
            if (a.digits[i] == '0')
                newNumber.digits.push_back('9');
            else {
                newNumber.digits.push_back(a.digits[i] - nextRank);
                nextRank = false;
            }
        }
        else {
            newNumber.digits.push_back(a.digits[i]);
        }

        ++i;
    }

    while (newNumber.digits[newNumber.digits.size() - 1] == '0')
        newNumber.digits.erase(newNumber.digits.end() - 1);

    return newNumber;
}

UnsignedBigInteger& UnsignedBigInteger::operator-=(const UnsignedBigInteger& b) {
    if (*this <= b) {
        digits.clear();
        digits.push_back('0');
        return *this;
    }

    size_t i = 0;
    bool nextRank = false;
    for (; i < std::min(digits.size(), b.digits.size()); ++i) {
        char buf = b.digits[i] + nextRank;
        if (digits[i] < buf) {
            nextRank = true;
            digits[i] = 10 - (buf - digits[i]) + '0';
        }
        else {
            nextRank = false;
            digits[i] = digits[i] - buf + '0';
        }
    }

    while (i < digits.size()) {
        if (nextRank) {
            if (digits[i] == '0')
                digits[i] = '9';
            else {
                digits[i] = digits[i] - nextRank;
                nextRank = false;
            }
        }
        else {
            return *this;
        }
        ++i;
    }

    while (digits[digits.size() - 1] == '0')
        digits.erase(digits.end() - 1);

    return *this;
}
