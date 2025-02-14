#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "/workspaces/CSE3150/include/doctest.h"

void fisherYatesShuffle(std::vector<int>& arr) {
    int size = arr.size();

    for (int i = size - 1; i > 0; --i) {
        int j = std::rand() % (i + 1);
        std::swap(arr[i], arr[j]);
    }
}

bool non_negative_prefix_sum(const std::vector<int>& arr) {
    int sum = 0;

    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];
        if (sum < 0){ 
            return false;
        }
    }
    return true;
}

bool non_positive_prefix_sum(const std::vector<int>& arr) {
    int sum = 0;
    for (int i = 0; i < arr.size(); i++) {

        sum += arr[i];
        if (sum > 0) {
            return false;
        }
    }
    return true;
}

bool balanceCheck(const std::vector<int>& arr) {
    int sum = 0;
    bool nonNegCheck = true;

    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];

        if (sum < 0) {
            nonNegCheck = false;
            break;
        }
    }
    return nonNegCheck == true && sum == 0;
}

TEST_CASE("non-negative") {
    std::vector<int> lst0 = {1, 1, -1, -1};
    std::vector<int> lst1 = {1, -1, 1, -1};
    std::vector<int> lst2 = {-1, -1, 1, 1};
    std::vector<int> lst3 = {-1, 1, -1, 1};

    CHECK(non_negative_prefix_sum(lst0) == true);
    CHECK(non_negative_prefix_sum(lst1) == true);
    CHECK(non_negative_prefix_sum(lst2) == false);
    CHECK(non_negative_prefix_sum(lst3) == false);
}

TEST_CASE("non-positive") {
    std::vector<int> lst0 = {-1, 1, -1, 1};
    std::vector<int> lst1 = {-1, 1, 1, -1};
    std::vector<int> lst2 = {-1, -1, 1, 1};

    CHECK(non_positive_prefix_sum(lst0) == true);
    CHECK(non_positive_prefix_sum(lst1) == false);
    CHECK(non_positive_prefix_sum(lst2) == true);
}

TEST_CASE("balanced") {
    std::vector<int> lst0 = {1, -1, 1, -1};
    std::vector<int> lst1 = {1, -1, -1, 1};
    std::vector<int> lst2 = {1, 1, -1, -1};

    CHECK(balanceCheck(lst0) == true);
    CHECK(balanceCheck(lst1) == false);
    CHECK(balanceCheck(lst2) == true);
}
