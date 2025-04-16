#include "bigint.h"
#include <iostream>
#include <chrono>
#include <utility>

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

//calculate the greatest common denominator
BigInt BigIntFractionCore::gcd(BigInt a, BigInt b) {
    BigInt zero("0");
    while (b != zero) {
        BigInt temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

//calculates the duration of the functions
template<typename Func>
long long timeFunction(Func f) {
    auto start = chrono::high_resolution_clock::now();
    f();
    auto end = chrono::high_resolution_clock::now();
    return chrono::duration_cast<chrono::microseconds>(end - start).count();
}

//This is the main... it allows us to enter the bigints and it prints the result
int main() {
    BigFraction f1 = {BigInt("123456789123456789"), BigInt("987654321")};
    BigFraction f2 = {BigInt("112233445566778899"), BigInt("998877665544332211")};

    auto duration = timeFunction([&]() {
        BigFraction sum = BigIntFractionCore::add(f1, f2);
        cout << "Sum: " << sum.first << " / " << sum.second << endl;
    });
    cout << "Addition took " << duration << " microseconds.\n";

    duration = timeFunction([&]() {
        BigFraction prod = BigIntFractionCore::multiply(f1, f2);
        cout << "Product: " << prod.first << " / " << prod.second << endl;
    });
    cout << "Multiplication took " << duration << " microseconds.\n";

    return 0;
}