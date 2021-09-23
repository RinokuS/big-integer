#include <iostream>
#include <vector>
#include "BigInteger.h"

std::vector<int> BigInteger::stringToVector(const std::string& string) {
    std::vector<int> result;
    if (string.size() % BASE_LENGTH == 0) {
        result.resize(string.size() / BASE_LENGTH);
    } else {
        result.resize(string.size() / BASE_LENGTH + 1);
    }

    for (long long i = string.size() - 1, j = result.size() - 1; i >= 0; i = i - BASE_LENGTH, --j) {
        if ((i + 1) - BASE_LENGTH <= 0) {
            result[j] = std::stoi(string.substr(0, (i + 1)));
        } else {
            result[j] = std::stoi(string.substr((i + 1) - BASE_LENGTH, BASE_LENGTH));
        }
    }

    return result;
}

BigInteger::BigInteger() {
    // default big integer is zero
    bi_digits.resize(1);
    bi_digits[0] = 0;
    is_positive = true;
}

BigInteger::BigInteger(std::string string) {
    if (string.empty() || (string[0] == '-') && string.size() == 1) {
        throw std::runtime_error("Fatal error. Type creation is impossible. String does not contain number.");
    }

    if (string[0] == '-') {
        string.erase(string.begin());
        is_positive = false;
    } else {
        is_positive = true;
    }

    for (const auto &i: string) {
        // check ASCII symbols
        if (i < 48 || i > 57) {
            throw std::runtime_error("Fatal error. Type creation is impossible. String contain unknown characters.");
        }
    }

    while (string.size() != 1 && string[0] == '0') {
        string.erase(string.begin());
    }
    bi_digits = BigInteger::stringToVector(string);
}

BigInteger::BigInteger(int number) {
    std::string string = std::to_string(number);
    if (string[0] == '-') {
        string.erase(string.begin());
        is_positive = false;
    } else {
        is_positive = true;
    }

    bi_digits = BigInteger::stringToVector(string);
}

BigInteger::BigInteger(unsigned int number) {
    is_positive = true;
    bi_digits = BigInteger::stringToVector(std::to_string(number));
}

BigInteger::BigInteger(long number) {
    std::string string = std::to_string(number);
    if (string[0] == '-') {
        string.erase(string.begin());
        is_positive = false;
    } else {
        is_positive = true;
    }

    bi_digits = BigInteger::stringToVector(string);
}

BigInteger::BigInteger(unsigned long number) {
    is_positive = true;
    bi_digits = BigInteger::stringToVector(std::to_string(number));
}

BigInteger::BigInteger(long long number) {
    std::string string = std::to_string(number);
    if (string[0] == '-') {
        string.erase(string.begin());
        is_positive = false;
    } else {
        is_positive = true;
    }

    bi_digits = BigInteger::stringToVector(string);
}

BigInteger::BigInteger(unsigned long long number) {
    is_positive = true;
    bi_digits = BigInteger::stringToVector(std::to_string(number));
}

/// Method to get string representation of BigInteger number
/// \param number our number
/// \return string representation
std::string BigInteger::to_string(BigInteger number) {
    if (number.bi_digits.size() == 1 && number.bi_digits[0] == 0) {
        return "0";
    }

    std::string result;
    if (!number.is_positive) { // if number is negative - adding minus to the string
        result.append("-");
    }

    result.reserve(number.bi_digits.size() * (BASE_LENGTH - 1));
    result.append(std::to_string(number.bi_digits[0]));

    std::string tmp;
    for (long long i = 1; i < number.bi_digits.size(); ++i) {
        tmp = std::to_string(number.bi_digits[i]);
        tmp.reserve(BASE_LENGTH - tmp.size());

        while (tmp.size() < BASE_LENGTH) {
            tmp.insert(tmp.begin(), '0');
        }

        result.append(tmp);
    }

    return result;
}

std::ostream& operator <<(std::ostream& ostream, const BigInteger& number) {
    std::string str = BigInteger::to_string(number);
    for (const auto &i: str) {
        ostream.put(i);
    }

    return ostream;
}

BigInteger BigInteger::removeLeadingZeroes(BigInteger number) {
    long long zeroes_leading_border = number.bi_digits.size() - 1;
    for (long long i = 0; i < number.bi_digits.size() - 1; ++i) {
        if (number.bi_digits[i] != 0) {
            zeroes_leading_border = i;
            break;
        }
    }

    number.bi_digits.erase(
            number.bi_digits.begin(),
            number.bi_digits.begin() + zeroes_leading_border);
    return number;
}

BigInteger BigInteger::shiftRight(BigInteger number, long long shift_power) {
    number.bi_digits.reserve(shift_power);
    for (long long i = 0; i < shift_power; ++i) {
        number.bi_digits.insert(number.bi_digits.begin(), 0);
    }

    return number;
}
BigInteger BigInteger::shiftLeft(BigInteger number, long long shift_power) {
    if (number == 0) {
        return number;
    }

    number.bi_digits.reserve(shift_power);
    for (long long i = 0; i < shift_power; ++i) {
        number.bi_digits.push_back(0);
    }

    return number;
}

BigInteger BigInteger::abs(BigInteger number_first) {
    number_first.is_positive = true;
    return number_first;
}
bool BigInteger::even(const BigInteger& number) {
    return number.bi_digits[number.bi_digits.size() - 1] % 2 == 0;
}
bool BigInteger::odd(const BigInteger& number) {
    return !BigInteger::even(number);
}
char BigInteger::sign(const BigInteger& number) {
    if (number.is_positive) {
        return '+';
    }

    return '-';
}

bool operator ==(const BigInteger& number_first, const BigInteger& number_second) {
    if (number_first.is_positive != number_second.is_positive) {
        return false;
    }
    if (number_first.bi_digits.size() != number_second.bi_digits.size()) {
        return false;
    }

    for (long long i = 0; i < number_first.bi_digits.size(); ++i) {
        if (number_first.bi_digits[i] != number_second.bi_digits[i]) {
            return false;
        }
    }

    return true;
}

bool operator !=(const BigInteger& number_first, const BigInteger& number_second) {
    return !(number_first == number_second);
}

bool operator >(BigInteger number_first, BigInteger number_second) {
    if (number_first == number_second) {
        return false;
    }

    if (!number_first.is_positive || number_second.is_positive) {
        if (number_first.is_positive || !number_second.is_positive) {
            if (!number_first.is_positive && !number_second.is_positive) {
                number_first.is_positive = true;
                number_second.is_positive = true;
                return !(number_first > number_second);
            }
            if (number_first.bi_digits.size() > number_second.bi_digits.size()) {
                return true;
            }
            if (number_first.bi_digits.size() < number_second.bi_digits.size()) {
                return false;
            }

            for (long long numbers_position = 0;
                 numbers_position < number_first.bi_digits.size(); numbers_position = numbers_position + 1) {
                if (number_first.bi_digits[numbers_position] > number_second.bi_digits[numbers_position]) {
                    return true;
                }
                if (number_first.bi_digits[numbers_position] < number_second.bi_digits[numbers_position]) {
                    return false;
                }
            }
            return false;
        } else {
            return false;
        }
    } else {
        return true;
    }
}

bool operator <(const BigInteger& number_first, const BigInteger& number_second) {
    if (number_first != number_second && !(number_first > number_second)) {
        return true;
    }

    return false;
}
bool operator >=(const BigInteger& number_first, const BigInteger& number_second) {
    if (number_first > number_second || number_first == number_second) {
        return true;
    }
    return false;
}
bool operator <=(const BigInteger& number_first, const BigInteger& number_second) {
    if (number_first < number_second || number_first == number_second) {
        return true;
    }
    return false;
}

BigInteger operator +(BigInteger number_first, BigInteger number_second) {
    if (number_first.is_positive && !number_second.is_positive) {
        number_second.is_positive = true;
        return number_first - number_second;
    } else if (!number_first.is_positive && number_second.is_positive) {
        number_first.is_positive = true;
        return number_second - number_first;
    } else if (!number_first.is_positive && !number_second.is_positive) {
        number_second.is_positive = true;
    }

    if (number_first.bi_digits.size() > number_second.bi_digits.size()) {
        number_second = BigInteger::shiftRight(
                number_second,
                number_first.bi_digits.size() - number_second.bi_digits.size());
    } else {
        number_first = BigInteger::shiftRight(
                number_first,
                number_second.bi_digits.size() - number_first.bi_digits.size());
    }

    int sum;
    int in_mind = 0;
    for (long long i = number_first.bi_digits.size() - 1; i >= 0; i = i - 1) {
        sum = number_first.bi_digits[i] + number_second.bi_digits[i] + in_mind;
        in_mind = sum / BigInteger::BASE;
        number_first.bi_digits[i] = sum % BigInteger::BASE;
    }
    if (in_mind != 0) {
        number_first.bi_digits.insert(number_first.bi_digits.begin(), in_mind);
    }

    return number_first;
}

BigInteger BigInteger::operator +=(BigInteger number) {
    return *this = *this + std::move(number);
}
BigInteger BigInteger::operator ++() {
    return *this = *this + 1;
}


BigInteger operator -(BigInteger number_first, BigInteger number_second) {
    if (number_first.is_positive && !number_second.is_positive) {
        number_second.is_positive = true;

        return number_first + number_second;
    } else if (!number_first.is_positive && number_second.is_positive) {
        number_first.is_positive = true;
        BigInteger tmp = number_first + number_second;
        tmp.is_positive = false;

        return tmp;
    } else if (!number_first.is_positive && !number_second.is_positive) {
        number_first.is_positive = true;
        number_second.is_positive = true;
        BigInteger tmp;
        tmp = number_first;
        number_first = number_second;
        number_second = tmp;
    }

    if (number_first < number_second) {
        BigInteger tmp = number_first;
        number_first = number_second;
        number_second = tmp;
        number_first.is_positive = false;
    }

    number_second = BigInteger::shiftRight(
            number_second,
            number_first.bi_digits.size() - number_second.bi_digits.size());
    int different;
    for (long long i = number_first.bi_digits.size() - 1; i >= 0; i = i - 1) {
        different = number_first.bi_digits[i] - number_second.bi_digits[i];
        if (different >= 0) {
            number_first.bi_digits[i] = different;
        } else {
            number_first.bi_digits[i] = different + BigInteger::BASE;
            for (long long j = i - 1;; --j) {
                if (number_first.bi_digits[j] == 0) {
                    number_first.bi_digits[j] = BigInteger::BASE - 1;
                } else {
                    number_first.bi_digits[j] = number_first.bi_digits[j] - 1;
                    break;
                }
            }
        }
    }

    return BigInteger::removeLeadingZeroes(number_first);
}

BigInteger BigInteger::operator -=(BigInteger number) {
    return *this = *this - std::move(number);
}
BigInteger BigInteger::operator --() {
    return *this = *this - 1;
}
