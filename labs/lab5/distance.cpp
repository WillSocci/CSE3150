#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include "linkfiles.h"

using namespace std;

double dotProduct(const vector<double>& v1, const vector<double>& v2) {
    double result = 0.0;
    for (size_t i = 0; i < v1.size(); ++i) {
        result += v1[i] * v2[i];
    }
    return result;
}

double magnitude(const vector<double>& v) {
    double sum = 0.0;
    for (double val : v) {
        sum += val * val;
    }
    return sqrt(sum);
}

double cosineDistance(const vector<double>& v1, const vector<double>& v2) {
    double result = 0.0;

    double dot = dotProduct(v1, v2);
    double mag1 = magnitude(v1);
    double mag2 = magnitude(v2);

    if (mag1 == 0 || mag2 == 0) return 0.0;

    double cos = dot / (mag1 * mag2);
    cos = max(-1.0, min(1.0, cos));  //kept returning nan so researched that the result was either above or below -1 1 this was the fix
    result = acos(cos);

    return result;

}
