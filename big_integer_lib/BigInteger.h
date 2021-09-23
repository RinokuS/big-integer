#include <iostream>
#include <vector>


class BigInteger {
public:
    BigInteger();

    BigInteger(std::string string);
    BigInteger(int number);
    BigInteger(unsigned int number);
    BigInteger(long number);
    BigInteger(unsigned long number);
    BigInteger(long long number);
    BigInteger(unsigned long long number);

    static std::string to_string(BigInteger number);

    static BigInteger abs(BigInteger number_first);
    static bool even(const BigInteger& number);
    static bool odd(const BigInteger& number);
    static char sign(const BigInteger& number);

    BigInteger operator +=(BigInteger number);
    BigInteger operator ++();
    BigInteger operator -=(BigInteger number);
    BigInteger operator --();

    friend std::ostream& operator <<(std::ostream& ostream, const BigInteger& number);
    friend bool operator ==(const BigInteger& number_first, const BigInteger& number_second);
    friend bool operator !=(const BigInteger& number_first, const BigInteger& number_second);
    friend bool operator >(BigInteger number_first, BigInteger number_second);
    friend bool operator <(const BigInteger& number_first, const BigInteger& number_second);
    friend bool operator >=(const BigInteger& number_first, const BigInteger& number_second);
    friend bool operator <=(const BigInteger& number_first, const BigInteger& number_second);
    friend BigInteger operator +(BigInteger number_first, BigInteger number_second);
    friend BigInteger operator -(BigInteger number_first, BigInteger number_second);

private:
    static const int BASE = 1'000'000'000;
    static const int BASE_LENGTH = 9;

    std::vector<int> bi_digits;
    bool is_positive;

    static std::vector<int> stringToVector(const std::string& string);
    static BigInteger removeLeadingZeroes(BigInteger number);
    static BigInteger shiftRight(BigInteger number, long long shift_power);
    static BigInteger shiftLeft(BigInteger number, long long shift_power);
};