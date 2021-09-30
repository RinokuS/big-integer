#pragma once

#include "UnsignedBigInteger.h"

class BigInteger : protected UnsignedBigInteger {
public:
    BigInteger();
    BigInteger(signed int number);
    BigInteger(unsigned int number);
    BigInteger(signed long number);
    BigInteger(unsigned long number);
    BigInteger(signed long long number);
    BigInteger(unsigned long long number);
    BigInteger(const BigInteger& copy);
    explicit BigInteger(const UnsignedBigInteger& copy);
    BigInteger(const std::string& str);

    BigInteger& operator=(const BigInteger& copy);

    friend BigInteger operator+(const BigInteger& a, const BigInteger& b);
    friend BigInteger operator-(const BigInteger& a, const BigInteger& b);
    friend BigInteger operator*(const BigInteger& a, const BigInteger& b);
    friend BigInteger operator/(const BigInteger& a, const BigInteger& b);
    friend BigInteger operator%(const BigInteger& a, const BigInteger& b);

    BigInteger& operator+=(const BigInteger& b);
    BigInteger& operator-=(const BigInteger& b);
    BigInteger& operator*=(const BigInteger& b);
    BigInteger& operator/=(const BigInteger& b);
    BigInteger& operator%=(const BigInteger& b);

    BigInteger operator-();
    BigInteger& operator++() override;
    BigInteger operator++(int);
    BigInteger& operator--() override;
    BigInteger operator--(int);

    friend bool operator<(const BigInteger& a, const BigInteger& b);
    friend bool operator==(const BigInteger& a, const BigInteger& b);
    friend bool operator!=(const BigInteger& a, const BigInteger& b);
    friend bool operator>(const BigInteger& a, const BigInteger& b);
    friend bool operator<=(const BigInteger& a, const BigInteger& b);
    friend bool operator>=(const BigInteger& a, const BigInteger& b);

    friend std::ostream& operator<<(std::ostream& out, const BigInteger& number);
    friend std::istream& operator>>(std::istream& in, BigInteger& number);

    [[nodiscard]] std::string to_string() const override;
    explicit operator bool() const;
    [[nodiscard]] bool isZero() const;
protected:
    bool sign;
};