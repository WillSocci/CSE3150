#include <iostream>
#include <chrono>
#include "bigint.h"

using namespace std;
using namespace std::chrono;
using BigInt = bigint;

int main() {
    int int1 = 532617426;
    int int2 = 234536239;

    auto intAdd = high_resolution_clock::now();
    int sumInt = int1 + int2;
    auto intAddOver = high_resolution_clock::now();

    auto intMul = high_resolution_clock::now();
    int prodInt = int1 * int2;
    auto intMulOver = high_resolution_clock::now();

    long long1 = 597234657934597236;
    long long2 = 683958273645902150;

    auto longAdd = high_resolution_clock::now();
    long sumLong = long1 + long2;
    auto longAddOver = high_resolution_clock::now();

    auto longMul = high_resolution_clock::now();
    long prodLong = long1 * long2;
    auto longMulOver = high_resolution_clock::now();

    BigInt bigInt1("72836947523465970423765972364587");
    BigInt bigInt2("2734958924326975072345872839465723");

    auto bigIntAdd = high_resolution_clock::now();
    BigInt sumBigInt = bigInt1 + bigInt2;
    auto bigIntAddOver = high_resolution_clock::now();

    auto bigIntMul = high_resolution_clock::now();
    BigInt prodBigInt = bigInt1 * bigInt2;
    auto bigIntOver = high_resolution_clock::now();

    cout << "Comparing times\n";
    cout << "int addition: " << duration_cast<microseconds>(intAddOver - intAdd).count() << " microseconds\n";
    cout << "int multiplication: " << duration_cast<microseconds>(intMulOver - intMul).count() << " microseconds\n";

    cout << "long addition: " << duration_cast<microseconds>(longAddOver - longAdd).count() << " microseconds\n";
    cout << "long multiplication: " << duration_cast<microseconds>(longMulOver - longMul).count() << " microseconds\n";

    cout << "BigInt addition: " << duration_cast<microseconds>(bigIntAddOver - bigIntAdd).count() << " microseconds\n";
    cout << "BigInt multiplication: " << duration_cast<microseconds>(bigIntOver - bigIntMul).count() << " microseconds\n";

    return 0;
}
