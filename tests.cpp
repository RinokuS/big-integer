#include <iostream>
#include <cassert>

#include "big_integer_lib/BigInteger.h"
#include "big_integer_lib/EquationsParser.h"

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

    assert(a.to_string() == "1000000000000000000000");
    assert(b.to_string() == "123456789101112131415");
    assert(c.to_string() == "-123456789101112131415");
    assert(d.to_string() == "-1000000000000000000000");
    assert(e == 0);

    assert(f.to_string() == "2147483647");
    assert(g.to_string() == "-2147483648");

    assert(h.to_string() == "9223372036854775807");
    assert(i.to_string() == "-9223372036854775808");

    assert(j.to_string() == "9223372036854775807");
    assert(k.to_string() == "-9223372036854775808");

    assert(l.to_string() == "4294967295");
    assert(m.to_string() == "18446744073709551615");
    assert(n.to_string() == "18446744073709551615");
}

void testBIAddition() {
    BigInteger a("1000000000000000000000");
    BigInteger b("123456789101112131415");
    BigInteger c("-123456789101112131415");
    BigInteger d("-1000000000000000000000");

    assert((a + b).to_string() == "1123456789101112131415");
    assert((a + b + c).to_string() == "1000000000000000000000");
    assert(b + c == 0);

    assert((a + INT_MAX).to_string() == "1000000000002147483647");
    assert((a + LONG_MAX).to_string() == "1009223372036854775807");
    assert((a + LONG_LONG_MAX).to_string() == "1009223372036854775807");

    assert((d + INT_MIN).to_string() == "-1000000000002147483648");
    assert((d + LONG_MIN).to_string() == "-1009223372036854775808");
    assert((d + LONG_LONG_MIN).to_string() == "-1009223372036854775808");

    ++a;
    assert((a).to_string() == "1000000000000000000001");
    ++d;
    assert((d).to_string() == "-999999999999999999999");

    a += LONG_LONG_MAX;
    assert((a).to_string() == "1009223372036854775808");
    d += LONG_LONG_MIN;
    assert((d).to_string() == "-1009223372036854775807");
}

void testBISubtraction() {
    BigInteger a("1000000000000000000000");
    BigInteger b("123456789101112131415");
    BigInteger c("-123456789101112131415");
    BigInteger d("-1000000000000000000000");

    assert((a - c).to_string() == "1123456789101112131415");
    assert((a - b - c).to_string() == "1000000000000000000000");
    assert((a - d).to_string() == "2000000000000000000000");

    assert((a - INT_MIN).to_string() == "1000000000002147483648");
    assert((a - LONG_MIN).to_string() == "1009223372036854775808");
    assert((a - LONG_LONG_MIN).to_string() == "1009223372036854775808");

    assert((d - INT_MAX).to_string() == "-1000000000002147483647");
    assert((d - LONG_MAX).to_string() == "-1009223372036854775807");
    assert((d - LONG_LONG_MAX).to_string() == "-1009223372036854775807");

    --a;
    assert((a).to_string() == "999999999999999999999");
    --d;
    assert((d).to_string() == "-1000000000000000000001");

    a -= LONG_LONG_MIN;
    assert((a).to_string() == "1009223372036854775807");
    d -= LONG_LONG_MAX;
    assert((d).to_string() == "-1009223372036854775808");
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
