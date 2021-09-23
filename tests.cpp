#include <iostream>
#include <cassert>
#include "big_integer_lib/BigInteger.h"

void testBIConstructor() {
    BigInteger a("1000000000000000000000");
    BigInteger b("123456789101112131415");
    BigInteger c("-123456789101112131415");
    BigInteger d("-1000000000000000000000");
    BigInteger e(0);

    BigInteger f(INT_MAX);
    BigInteger g(INT_MIN);

    BigInteger h(LONG_MAX);
    BigInteger i(LONG_MIN);

    BigInteger j(LONG_LONG_MAX);
    BigInteger k(LONG_LONG_MIN);

    BigInteger l(UINT_MAX);
    BigInteger m(ULONG_MAX);
    BigInteger n(ULONG_LONG_MAX);

    assert(BigInteger::to_string(a) == "1000000000000000000000");
    assert(BigInteger::to_string(b) == "123456789101112131415");
    assert(BigInteger::to_string(c) == "-123456789101112131415");
    assert(BigInteger::to_string(d) == "-1000000000000000000000");
    assert(e == 0);

    assert(BigInteger::to_string(f) == "2147483647");
    assert(BigInteger::to_string(g) == "-2147483648");

    assert(BigInteger::to_string(h) == "9223372036854775807");
    assert(BigInteger::to_string(i) == "-9223372036854775808");

    assert(BigInteger::to_string(j) == "9223372036854775807");
    assert(BigInteger::to_string(k) == "-9223372036854775808");

    assert(BigInteger::to_string(l) == "4294967295");
    assert(BigInteger::to_string(m) == "18446744073709551615");
    assert(BigInteger::to_string(n) == "18446744073709551615");
}

void testBIAddition() {
    BigInteger a("1000000000000000000000");
    BigInteger b("123456789101112131415");
    BigInteger c("-123456789101112131415");
    BigInteger d("-1000000000000000000000");

    assert(BigInteger::to_string(a + b) == "1123456789101112131415");
    assert(BigInteger::to_string(a + b + c) == "1000000000000000000000");
    assert(b + c == 0);

    assert(BigInteger::to_string(a + INT_MAX) == "1000000000002147483647");
    assert(BigInteger::to_string(a + LONG_MAX) == "1009223372036854775807");
    assert(BigInteger::to_string(a + LONG_LONG_MAX) == "1009223372036854775807");

    assert(BigInteger::to_string(d + INT_MIN) == "-1000000000002147483648");
    assert(BigInteger::to_string(d + LONG_MIN) == "-1009223372036854775808");
    assert(BigInteger::to_string(d + LONG_LONG_MIN) == "-1009223372036854775808");

    ++a;
    assert(BigInteger::to_string(a) == "1000000000000000000001");
    ++d;
    assert(BigInteger::to_string(d) == "-999999999999999999999");

    a += LONG_LONG_MAX;
    assert(BigInteger::to_string(a) == "1009223372036854775808");
    d += LONG_LONG_MIN;
    assert(BigInteger::to_string(d) == "-1009223372036854775807");
}

void testBISubtraction() {
    BigInteger a("1000000000000000000000");
    BigInteger b("123456789101112131415");
    BigInteger c("-123456789101112131415");
    BigInteger d("-1000000000000000000000");

    assert(BigInteger::to_string(a - c) == "1123456789101112131415");
    assert(BigInteger::to_string(a - b - c) == "1000000000000000000000");
    assert(BigInteger::to_string(a - d) == "2000000000000000000000");

    assert(BigInteger::to_string(a - INT_MIN) == "1000000000002147483648");
    assert(BigInteger::to_string(a - LONG_MIN) == "1009223372036854775808");
    assert(BigInteger::to_string(a - LONG_LONG_MIN) == "1009223372036854775808");

    assert(BigInteger::to_string(d - INT_MAX) == "-1000000000002147483647");
    assert(BigInteger::to_string(d - LONG_MAX) == "-1009223372036854775807");
    assert(BigInteger::to_string(d - LONG_LONG_MAX) == "-1009223372036854775807");

    --a;
    assert(BigInteger::to_string(a) == "999999999999999999999");
    --d;
    assert(BigInteger::to_string(d) == "-1000000000000000000001");

    a -= LONG_LONG_MIN;
    assert(BigInteger::to_string(a) == "1009223372036854775807");
    d -= LONG_LONG_MAX;
    assert(BigInteger::to_string(d) == "-1009223372036854775808");
}

void testBILess() {
    BigInteger a("1000000000000000000000");
    BigInteger b("123456789101112131415");
    BigInteger c("-123456789101112131415");
    BigInteger d("-1000000000000000000000");

    assert(!(a < a));
    assert(!(b < b));
    assert(!(c < c));
    assert(!(d < d));

    assert(a <= a);
    assert(b <= b);
    assert(c <= c);
    assert(d <= d);

    assert(b < a);
    assert(b <= a);

    assert(c < a);
    assert(c <= a);
    assert(c < b);
    assert(c <= b);

    assert(d < a);
    assert(d <= a);
    assert(d < b);
    assert(d <= b);

    assert(d < c);
    assert(d <= c);

    assert(c < 0);
    assert(c <= 0);
    assert(d < 0);
    assert(d <= 0);

    assert(BigInteger(INT_MIN) < 0);
    assert(BigInteger(INT_MIN) <= 0);
    assert(BigInteger(INT_MIN) <= INT_MIN);

    assert(BigInteger(LONG_MIN) < 0);
    assert(BigInteger(LONG_MIN) <= 0);
    assert(BigInteger(LONG_MIN) <= LONG_MIN);

    assert(BigInteger(LONG_LONG_MIN) < 0);
    assert(BigInteger(LONG_LONG_MIN) <= 0);
    assert(BigInteger(LONG_LONG_MIN) <= LONG_LONG_MIN);

    assert(BigInteger(0) <= 0);
}

void testBIMore() {
    BigInteger a("1000000000000000000000");
    BigInteger b("123456789101112131415");
    BigInteger c("-123456789101112131415");
    BigInteger d("-1000000000000000000000");

    assert(!(a > a));
    assert(!(b > b));
    assert(!(c > c));
    assert(!(d > d));

    assert(a >= a);
    assert(b >= b);
    assert(c >= c);
    assert(d >= d);

    assert(a > b);
    assert(a >= b);

    assert(a > c);
    assert(a >= c);
    assert(b > c);
    assert(b >= c);

    assert(a > d);
    assert(a >= d);
    assert(b > d);
    assert(b >= d);

    assert(c > d);
    assert(c >= d);

    assert(0 > c);
    assert(0 >= c);
    assert(0 > d);
    assert(0 >= d);

    assert(BigInteger(INT_MAX) > 0);
    assert(BigInteger(INT_MAX) >= 0);
    assert(BigInteger(INT_MAX) >= INT_MAX);

    assert(BigInteger(LONG_MAX) > 0);
    assert(BigInteger(LONG_MAX) >= 0);
    assert(BigInteger(LONG_MAX) >= LONG_MAX);

    assert(BigInteger(LONG_LONG_MAX) > 0);
    assert(BigInteger(LONG_LONG_MAX) >= 0);
    assert(BigInteger(LONG_LONG_MAX) >= LONG_LONG_MAX);

    assert(BigInteger(UINT_MAX) > 0);
    assert(BigInteger(UINT_MAX) >= 0);
    assert(BigInteger(UINT_MAX) >= UINT_MAX);

    assert(BigInteger(ULONG_MAX) > 0);
    assert(BigInteger(ULONG_MAX) >= 0);
    assert(BigInteger(ULONG_MAX) >= ULONG_MAX);

    assert(BigInteger(ULONG_LONG_MAX) > 0);
    assert(BigInteger(ULONG_LONG_MAX) >= 0);
    assert(BigInteger(ULONG_LONG_MAX) >= ULONG_LONG_MAX);

    assert(BigInteger(0) >= 0);
}

void testBIEqual() {
    BigInteger a("1000000000000000000000");
    BigInteger b("123456789101112131415");
    BigInteger c("-123456789101112131415");
    BigInteger d("-1000000000000000000000");

    assert(!(a != a));
    assert(!(b != b));
    assert(!(c != c));
    assert(!(d != d));

    assert(a == a);
    assert(b == b);
    assert(c == c);
    assert(d == d);

    assert(BigInteger(INT_MAX) == INT_MAX);
    assert(BigInteger(INT_MIN) == INT_MIN);
    assert(BigInteger(UINT_MAX) == UINT_MAX);

    assert(BigInteger(LONG_MAX) == LONG_MAX);
    assert(BigInteger(LONG_MIN) == LONG_MIN);
    assert(BigInteger(ULONG_MAX) == ULONG_MAX);

    assert(BigInteger(LONG_LONG_MAX) == LONG_LONG_MAX);
    assert(BigInteger(LONG_LONG_MIN) == LONG_LONG_MIN);
    assert(BigInteger(ULONG_LONG_MAX) == ULONG_LONG_MAX);

    assert(BigInteger(0) == 0);
}

int main() {
    testBIConstructor();

    testBIAddition();
    testBISubtraction();

    testBILess();
    testBIMore();
    testBIEqual();

    return 0;
}
