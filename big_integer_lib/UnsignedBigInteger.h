#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

class UnsignedBigInteger {
public:
    UnsignedBigInteger();
    explicit UnsignedBigInteger(signed int number);
    explicit UnsignedBigInteger(unsigned int number);
    explicit UnsignedBigInteger(signed long number);
    explicit UnsignedBigInteger(unsigned long number);
    explicit UnsignedBigInteger(signed long long number);
    explicit UnsignedBigInteger(unsigned long long number);
    UnsignedBigInteger(const UnsignedBigInteger& copy);
    explicit UnsignedBigInteger(const std::string& str);

    ~UnsignedBigInteger();

    class divide_by_zero : public std::exception {
        virtual const char* what() const noexcept {
            return "Division by zero";
        }
    };

    friend bool operator<(const UnsignedBigInteger& a, const UnsignedBigInteger& b);
    friend bool operator==(const UnsignedBigInteger& a, const UnsignedBigInteger& b);
    friend bool operator!=(const UnsignedBigInteger& a, const UnsignedBigInteger& b);
    friend bool operator>(const UnsignedBigInteger& a, const UnsignedBigInteger& b);
    friend bool operator<=(const UnsignedBigInteger& a, const UnsignedBigInteger& b);
    friend bool operator>=(const UnsignedBigInteger& a, const UnsignedBigInteger& b);

    UnsignedBigInteger& operator=(const UnsignedBigInteger& copy);
    friend UnsignedBigInteger operator+(const UnsignedBigInteger& a, const UnsignedBigInteger& b);
    friend UnsignedBigInteger operator-(const UnsignedBigInteger& a, const UnsignedBigInteger& b);

    UnsignedBigInteger& operator+=(const UnsignedBigInteger& b);
    UnsignedBigInteger& operator-=(const UnsignedBigInteger& b);

    virtual const UnsignedBigInteger& operator++();
    UnsignedBigInteger operator++(int);
    virtual const UnsignedBigInteger& operator--();
    UnsignedBigInteger operator--(int);

    friend std::ostream& operator<<(std::ostream& out, const UnsignedBigInteger& number);
    friend std::istream& operator>>(std::istream& in, UnsignedBigInteger& number);

    [[nodiscard]] virtual std::string to_string() const;
    explicit operator bool();

protected:
    std::vector<char> digits;
};
