//Make the array random
//Then have the nonpositive
//n=25 or 50
// call fisher yatse and then prefix
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

void fisherYatesShuffle(std::vector<int>& arr) {
    int size = arr.size();

    for (int i = size - 1; i > 0; --i) {
        int j = std::rand() % (i + 1);
        std::swap(arr[i], arr[j]);
    }
}

int main(){
    std::srand(std::time(0));
    int n = 50;
    int times = 10000;
    int nonBalancedArr = 0;
    int balancedArr = 0;
    int nonNeg = 0;
    int nonPos = 0;

    for (int i = 0; i < times; i++){
        bool curStatus = true;
        bool nonNegCheck = true;
        bool nonPosCheck = true;
        int sum = 0;

        std::vector<int> arr;
        arr.insert(arr.end(), n, 1);
        arr.insert(arr.end(), n, -1);

        fisherYatesShuffle(arr);

        for (int j = 0; j < 2 * n; j++) {
            sum += arr[j];

            if (sum < 0) {
                nonNegCheck = false;
            }
            if (sum > 0){
                nonPosCheck = false;
            }
        }

        if (nonNegCheck == true && sum == 0) {
            balancedArr++;
        } else {
            nonBalancedArr++;
        }

        if (nonNegCheck == true){
            nonNeg++;
        }
        if (nonPosCheck == true){
            nonPos++;
        }

    }

    std::cout << "Number of trials: " << times << "\nSize of array: " << 2 * n;
    std::cout << "\nThe ratio of Balanced Arr vs Non Balanced: " << balancedArr << " : " << nonBalancedArr;
    std::cout << "\nNumber of Non Negative arrays: " << nonNeg << "\nNumber of Non Positive arrays: " << nonPos;
    std::cout << "\nProportion of non-neg and non-pos vs number of times run: " << static_cast<double>(nonNeg + nonPos) / times << "\n";

    return 0;
}