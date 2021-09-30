#include <iostream>

#include "big_integer_lib/BigInteger.h"
#include "big_integer_lib/EquationsParser.h"
#include <gtest/gtest.h>


TEST(Constructor, Test1) {
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

    ASSERT_EQ(a.to_string(), "1000000000000000000000");
    ASSERT_EQ(b.to_string(), "123456789101112131415");
    ASSERT_EQ(c.to_string(), "-123456789101112131415");
    ASSERT_EQ(d.to_string(), "-1000000000000000000000");
    ASSERT_EQ(e, 0);

    ASSERT_EQ(f.to_string(), "2147483647");
    ASSERT_EQ(g.to_string(), "-2147483648");

    ASSERT_EQ(h.to_string(), "9223372036854775807");
    ASSERT_EQ(i.to_string(), "-9223372036854775808");

    ASSERT_EQ(j.to_string(), "9223372036854775807");
    ASSERT_EQ(k.to_string(), "-9223372036854775808");

    ASSERT_EQ(l.to_string(), "4294967295");
    ASSERT_EQ(m.to_string(), "18446744073709551615");
    ASSERT_EQ(n.to_string(), "18446744073709551615");
}

TEST(Addition, Test1) {
    BigInteger a("1000000000000000000000");
    BigInteger b("123456789101112131415");
    BigInteger c("-123456789101112131415");
    BigInteger d("-1000000000000000000000");

    ASSERT_EQ((a + b).to_string(), "1123456789101112131415");
    ASSERT_EQ((a + b + c).to_string(), "1000000000000000000000");
    ASSERT_EQ(b + c, 0);

    ASSERT_EQ((a + INT_MAX).to_string(), "1000000000002147483647");
    ASSERT_EQ((a + LONG_MAX).to_string(), "1009223372036854775807");
    ASSERT_EQ((a + LONG_LONG_MAX).to_string(), "1009223372036854775807");

    ASSERT_EQ((d + INT_MIN).to_string(), "-1000000000002147483648");
    ASSERT_EQ((d + LONG_MIN).to_string(), "-1009223372036854775808");
    ASSERT_EQ((d + LONG_LONG_MIN).to_string(), "-1009223372036854775808");

    ++a;
    ASSERT_EQ((a).to_string(), "1000000000000000000001");
    ++d;
    ASSERT_EQ((d).to_string(), "-999999999999999999999");

    a += LONG_LONG_MAX;
    ASSERT_EQ((a).to_string(), "1009223372036854775808");
    d += LONG_LONG_MIN;
    ASSERT_EQ((d).to_string(), "-1009223372036854775807");
}

TEST(Substruction, Test1) {
    BigInteger a("1000000000000000000000");
    BigInteger b("123456789101112131415");
    BigInteger c("-123456789101112131415");
    BigInteger d("-1000000000000000000000");

    ASSERT_EQ((a - c).to_string(), "1123456789101112131415");
    ASSERT_EQ((a - b - c).to_string(), "1000000000000000000000");
    ASSERT_EQ((a - d).to_string(), "2000000000000000000000");

    ASSERT_EQ((a - INT_MIN).to_string(), "1000000000002147483648");
    ASSERT_EQ((a - LONG_MIN).to_string(), "1009223372036854775808");
    ASSERT_EQ((a - LONG_LONG_MIN).to_string(), "1009223372036854775808");

    ASSERT_EQ((d - INT_MAX).to_string(), "-1000000000002147483647");
    ASSERT_EQ((d - LONG_MAX).to_string(), "-1009223372036854775807");
    ASSERT_EQ((d - LONG_LONG_MAX).to_string(), "-1009223372036854775807");

    --a;
    ASSERT_EQ((a).to_string(), "999999999999999999999");
    --d;
    ASSERT_EQ((d).to_string(), "-1000000000000000000001");

    a -= LONG_LONG_MIN;
    ASSERT_EQ((a).to_string(), "1009223372036854775807");
    d -= LONG_LONG_MAX;
    ASSERT_EQ((d).to_string(), "-1009223372036854775808");
}

TEST(Less, Test1) {
    BigInteger a("1000000000000000000000");
    BigInteger b("123456789101112131415");
    BigInteger c("-123456789101112131415");
    BigInteger d("-1000000000000000000000");

    ASSERT_FALSE((a < a));
    ASSERT_FALSE((b < b));
    ASSERT_FALSE((c < c));
    ASSERT_FALSE((d < d));

    ASSERT_LE(a, a);
    ASSERT_LE(b, b);
    ASSERT_LE(c, c);
    ASSERT_LE(d, d);

    ASSERT_LT(b, a);
    ASSERT_LE(b, a);

    ASSERT_LT(c, a);
    ASSERT_LE(c, a);
    ASSERT_LT(c, b);
    ASSERT_LE(c, b);

    ASSERT_LT(d, a);
    ASSERT_LE(d, a);
    ASSERT_LT(d, b);
    ASSERT_LE(d, b);

    ASSERT_LT(d, c);
    ASSERT_LE(d, c);

    ASSERT_LT(c, 0);
    ASSERT_LE(c, 0);
    ASSERT_LT(d, 0);
    ASSERT_LE(d, 0);

    ASSERT_LT(BigInteger(INT_MIN), 0);
    ASSERT_LE(BigInteger(INT_MIN), 0);
    ASSERT_LE(BigInteger(INT_MIN), INT_MIN);

    ASSERT_LT(BigInteger(LONG_MIN), 0);
    ASSERT_LE(BigInteger(LONG_MIN), 0);
    ASSERT_LE(BigInteger(LONG_MIN), LONG_MIN);

    ASSERT_LT(BigInteger(LONG_LONG_MIN), 0);
    ASSERT_LE(BigInteger(LONG_LONG_MIN), 0);
    ASSERT_LE(BigInteger(LONG_LONG_MIN), LONG_LONG_MIN);

    ASSERT_LE(BigInteger(0), 0);
}
TEST(Greater, Test1) {
    BigInteger a("1000000000000000000000");
    BigInteger b("123456789101112131415");
    BigInteger c("-123456789101112131415");
    BigInteger d("-1000000000000000000000");

    ASSERT_FALSE((a > a));
    ASSERT_FALSE((b > b));
    ASSERT_FALSE((c > c));
    ASSERT_FALSE((d > d));

    ASSERT_GE(a, a);
    ASSERT_GE(b, b);
    ASSERT_GE(c, c);
    ASSERT_GE(d, d);

    ASSERT_GT(a, b);
    ASSERT_GE(a, b);

    ASSERT_GT(a, c);
    ASSERT_GE(a, c);
    ASSERT_GT(b, c);
    ASSERT_GE(b, c);

    ASSERT_GT(a, d);
    ASSERT_GE(a, d);
    ASSERT_GT(b, d);
    ASSERT_GE(b, d);

    ASSERT_GT(c, d);
    ASSERT_GE(c, d);

    ASSERT_GT(0, c);
    ASSERT_GE(0, c);
    ASSERT_GT(0, d);
    ASSERT_GE(0, d);

    ASSERT_GT(BigInteger(INT_MAX), 0);
    ASSERT_GE(BigInteger(INT_MAX), 0);
    ASSERT_GE(BigInteger(INT_MAX), INT_MAX);

    ASSERT_GT(BigInteger(LONG_MAX), 0);
    ASSERT_GE(BigInteger(LONG_MAX), 0);
    ASSERT_GE(BigInteger(LONG_MAX), LONG_MAX);

    ASSERT_GT(BigInteger(LONG_LONG_MAX), 0);
    ASSERT_GE(BigInteger(LONG_LONG_MAX), 0);
    ASSERT_GE(BigInteger(LONG_LONG_MAX), LONG_LONG_MAX);

    ASSERT_GT(BigInteger(UINT_MAX), 0);
    ASSERT_GE(BigInteger(UINT_MAX), 0);
    ASSERT_GE(BigInteger(UINT_MAX), UINT_MAX);

    ASSERT_GT(BigInteger(ULONG_MAX), 0);
    ASSERT_GE(BigInteger(ULONG_MAX), 0);
    ASSERT_GE(BigInteger(ULONG_MAX), ULONG_MAX);

    ASSERT_GT(BigInteger(ULONG_LONG_MAX), 0);
    ASSERT_GE(BigInteger(ULONG_LONG_MAX), 0);
    ASSERT_GE(BigInteger(ULONG_LONG_MAX), ULONG_LONG_MAX);

    ASSERT_GE(BigInteger(0), 0);
}

TEST(Equal, Test1) {
    BigInteger a("1000000000000000000000");
    BigInteger b("123456789101112131415");
    BigInteger c("-123456789101112131415");
    BigInteger d("-1000000000000000000000");

    ASSERT_FALSE((a != a));
    ASSERT_FALSE((b != b));
    ASSERT_FALSE((c != c));
    ASSERT_FALSE((d != d));

    ASSERT_EQ(a, a);
    ASSERT_EQ(b, b);
    ASSERT_EQ(c, c);
    ASSERT_EQ(d, d);

    ASSERT_EQ(BigInteger(INT_MAX), INT_MAX);
    ASSERT_EQ(BigInteger(INT_MIN), INT_MIN);
    ASSERT_EQ(BigInteger(UINT_MAX), UINT_MAX);

    ASSERT_EQ(BigInteger(LONG_MAX), LONG_MAX);
    ASSERT_EQ(BigInteger(LONG_MIN), LONG_MIN);
    ASSERT_EQ(BigInteger(ULONG_MAX), ULONG_MAX);

    ASSERT_EQ(BigInteger(LONG_LONG_MAX), LONG_LONG_MAX);
    ASSERT_EQ(BigInteger(LONG_LONG_MIN), LONG_LONG_MIN);
    ASSERT_EQ(BigInteger(ULONG_LONG_MAX), ULONG_LONG_MAX);

    ASSERT_EQ(BigInteger(0), 0);
}

TEST(EquationParser, Test1) {
    std::string equation = "999*3000+70000000000000000000000*(800+111111111)";

    auto eq = strToExp(equation);
    BigInteger bi = eq->evaluate();
    ASSERT_EQ(bi.to_string(), "7777833770000000000000002997000");
    eq->release();
    delete eq;
}

TEST(Multiply, Test1) {
    int a = 2332;
    int b = 54;
    BigInteger big_value_a = a;
    BigInteger big_value_b = b;
    big_value_a = big_value_a * big_value_b;
    ASSERT_EQ(big_value_a.to_string(), std::to_string(a * b));
}

TEST(MultiplyEq, Test1) {
    int a = 3224;
    int b = 2323;
    BigInteger big_value_a = a;
    BigInteger big_value_b = b;
    big_value_a *= big_value_b;
    ASSERT_EQ(big_value_a.to_string(), std::to_string(a * b));
}

TEST(Divide, Test1) {
    int a = 127456;
    int b = 42;
    BigInteger big_value_a = a;
    BigInteger big_value_b = b;
    big_value_a = big_value_a / big_value_b;
    ASSERT_EQ(big_value_a.to_string(), std::to_string(a / b));
}

TEST(DivideEq, Test1) {
    int a = 127456;
    int b = 42;
    BigInteger big_value_a = a;
    BigInteger big_value_b = b;
    big_value_a /= big_value_b;
    ASSERT_EQ(big_value_a.to_string(), std::to_string(a / b));
}

TEST(DivideZero, Test1) {
    int a = 127456;
    int b = 0;
    BigInteger big_value_a = a;
    BigInteger big_value_b = b;
    ASSERT_THROW(big_value_a / big_value_b, UnsignedBigInteger::divide_by_zero);
}

TEST(DivideEqZero, Test1) {
    int a = 127456;
    int b = 0;
    BigInteger big_value_a = a;
    BigInteger big_value_b = b;
    ASSERT_THROW(big_value_a /= big_value_b, UnsignedBigInteger::divide_by_zero);
}

TEST(Mod, Test1) {
    int a = 4423412;
    int b = -323413;
    BigInteger big_value_a = a;
    BigInteger big_value_b = b;
    big_value_a = big_value_a % big_value_b;
    ASSERT_EQ(big_value_a.to_string(), std::to_string(a % b));
}

TEST(ModEq, Test1) {
    int a = -5;
    int b = 4;
    BigInteger big_value_a = a;
    BigInteger big_value_b = b;
    big_value_a %= big_value_b;
    ASSERT_EQ(big_value_a.to_string(), std::to_string(a % b));
}

TEST(ToAssignment, Test1) {
    int val = 42;
    BigInteger bigint_val = val;
    bigint_val += bigint_val += bigint_val += bigint_val;
    val += val += val += val;

    std::ostringstream oss;
    oss << bigint_val;
    ASSERT_EQ(oss.str(), std::to_string(val));
}

TEST(Arithmetic, Test1) {
    int a = 42;
    int b = 11;
    BigInteger bigint_a = a;
    BigInteger bigint_b = b;

    ++bigint_a -= bigint_b++;
    ++a -= b++;

    bigint_b -= bigint_a *= bigint_a *= bigint_b;
    b -= a *= a *= b;

    bigint_a /= 42;
    a /= 42;

    bigint_a %= 100;
    a %= 100;

    std::ostringstream oss;
    oss << bigint_a << bigint_b;
    ASSERT_EQ(oss.str(), std::to_string(a) + std::to_string(b));
}

TEST(TypeCast, Test1) {
    BigInteger bigint_val = 42;
    ASSERT_TRUE(bool(bigint_val));

    bigint_val = 0;
    ASSERT_FALSE(bool(bigint_val));
}

TEST(InStream, Test1) {
    int value = 42;
    BigInteger bigint_val = value;

    std::istringstream iss(std::to_string(value));
    std::ostringstream oss;
    iss >> bigint_val;
    oss << bigint_val;

    ASSERT_EQ(oss.str(), std::to_string(value));
}

TEST(Comparison, Test1) {
    std::istringstream iss("9325492345983274589758023847509283745827349587212938129"
                           "348762838512387487213648172639471269348172397461297");
    BigInteger a;
    BigInteger b;
    iss >> a >> b;

    std::ostringstream oss;
    oss << (a <= b) << (a >= b) << (a == b) << (a != b) << (a < b) << (a > b);
    ASSERT_EQ(oss.str(), "010101");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
