#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "checkPosNeg.h"

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

void arraySetup(std::vector<int>& arr, int n){
    arr.resize(2 * n);
    for (int i = 0; i < n; i++){
        arr[i] = 1;
    }
    for (int i = n; i < 2*n; i++){
        arr[i] = -1;
    }
}

int posNeg(std::vector<int>& arr, int trials, int n){
    int posNeg = 0;

    // std::cout << "Number of iterations: ";
    // std::cin >> trials;

    // std::cout << "Number of +1's (total length will be doubled): ";
    // std::cin >> n;

    for(int i = 0; i < trials; i++){
        arraySetup(arr, n);
        fisherYatesShuffle(arr);

        if(!non_negative_prefix_sum(arr) && !non_positive_prefix_sum(arr)){
            posNeg++;
        }
    }
    std::cout << "Number of positive and negative prefix sums: " << posNeg;
    std::cout << "\nTotal number of iterations: " << trials;
    std::cout << "\nRatio (pos&neg / trials): " << static_cast<double>(posNeg) / trials << "\n";
    return posNeg;
}