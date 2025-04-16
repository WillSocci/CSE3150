#include "bigint.h"
#include <cassert>
#include <iostream>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "/workspaces/CSE3150/include/doctest.h"

using namespace std;
using BigInt = bigint;
using BigFraction = std::pair<BigInt, BigInt>;


//BIgIntFractionCore class containing all functions
class BigIntFractionCore {
public:
    static BigFraction add(const BigFraction& a, const BigFraction& b);
    static BigFraction multiply(const BigFraction& a, const BigFraction& b);
    static BigInt gcd(BigInt a, BigInt b);
};

//add function.  first = numerator second = denominator then add the two fractions together
BigFraction BigIntFractionCore::add(const BigFraction& a, const BigFraction& b) {
    BigInt numerator = BigInt(a.first) * BigInt(b.second) + BigInt(b.first) * BigInt(a.second);
    BigInt denominator = BigInt(a.second) * BigInt(b.second);
    
    BigInt divisor = BigIntFractionCore::gcd(numerator, denominator);
    return {BigInt(numerator) / divisor, BigInt(denominator) / divisor};
}

//multiply the fractions together
BigFraction BigIntFractionCore::multiply(const BigFraction& a, const BigFraction& b) {
    BigInt numerator = BigInt(a.first) * BigInt(b.first);
    BigInt denominator = BigInt(a.second) * BigInt(b.second);
    
    BigInt divisor = BigIntFractionCore::gcd(numerator, denominator);
    return {BigInt(numerator) / divisor, BigInt(denominator) / divisor};
}

//calculates the greatest common denominator
BigInt BigIntFractionCore::gcd(BigInt a, BigInt b) {
    BigInt zero("0");
    while (b != zero) {
        BigInt temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

//test cases 4 different examples of bigInts
TEST_CASE("combining bigint fractions"){
    
    BigFraction f1 = {BigInt("123456789123456789"), BigInt("987654321")};
    BigFraction f2 = {BigInt("112233445566778899"), BigInt("998877665544332211")};
    BigFraction sum1 = BigIntFractionCore::add(f1, f2);
    BigFraction prod1 = BigIntFractionCore::multiply(f1, f2);

    SUBCASE("f1 and f2") {
        CHECK(sum1.first == BigInt("138404297896840929950614079201238"));
        CHECK(sum1.second == BigInt("1107234391161899579409241"));
        CHECK(prod1.first == BigInt("15551044693531749440601704762621"));
        CHECK(prod1.second == BigInt("1107234391161899579409241"));
    }

    BigFraction f3 = {BigInt("637849476"), BigInt("243534525")};
    BigFraction f4 = {BigInt("342135235"), BigInt("432643266")};
    BigFraction sum2 = BigIntFractionCore::add(f3, f4);
    BigFraction prod2 = BigIntFractionCore::multiply(f3, f4);

    SUBCASE("f3 and f4") {
        CHECK(sum2.first == BigInt("119761007484838997"));
        CHECK(sum2.second == BigInt("35121190759919550"));
        CHECK(prod2.first == BigInt("16956548590978"));
        CHECK(prod2.second == BigInt("8186757752895"));
    }

    BigFraction f5 = {BigInt("741385961920"), BigInt("4092037525702")};
    BigFraction f6 = {BigInt("56281943187"), BigInt("1234132452543")};
    BigFraction sum3 = BigIntFractionCore::add(f5, f6);
    BigFraction prod3 = BigIntFractionCore::multiply(f5, f6);

    SUBCASE("f5 and f6") {
        CHECK(sum3.first == BigInt("190879383167652136909139"));
        CHECK(sum3.second == BigInt("841686051248766442960031"));
        CHECK(prod3.first == BigInt("6954440431403464239840"));
        CHECK(prod3.second == BigInt("841686051248766442960031"));
    }

    BigFraction f7 = {BigInt("981273981273981273"), BigInt("123456789123456789")};
    BigFraction f8 = {BigInt("129837129837129837"), BigInt("987654321987654321")};
    BigFraction sum4 = BigIntFractionCore::add(f7, f8);
    BigFraction prod4 = BigIntFractionCore::multiply(f7, f8);

    SUBCASE("f7 and f8") {
        CHECK(sum4.first == BigInt("1106817004051007486"));
        CHECK(sum4.second == BigInt("136986042361108759"));
        CHECK(prod4.first == BigInt("1576058469846518438821"));
        CHECK(prod4.second == BigInt("1508353312438168545349"));
    }
}
