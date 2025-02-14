#include <iostream>
#include "checkPosNeg.h"
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "/workspaces/CSE3150/include/doctest.h"

TEST_CASE("checking the creating arraysetup") {
    std::vector<int> arr;
    int n = 2;
    arraySetup(arr, n);

    REQUIRE(arr.size() == 4);
    CHECK(arr == std::vector<int>{1, 1, -1, -1});
}

TEST_CASE("both positive and neg") {
    std::vector<int> arr;
    int trials = 10;
    int n = 1; 

    CHECK(posNeg(arr, trials, n) == 0);
}
TEST_CASE("both positive and neg2") {
    std::vector<int> arr;
    int trials = 100;
    int n = 5; 

    CHECK(posNeg(arr, trials, n) >= 0);
}
TEST_CASE("both positive and neg3") {
    std::vector<int> arr;
    int trials = 1000;
    int n = 10; 

    CHECK(posNeg(arr, trials, n) >= 0);
}
TEST_CASE("both positive and neg4") {
    std::vector<int> arr;
    int trials = 10000;
    int n = 15; 

    CHECK(posNeg(arr, trials, n) >= 0);
}