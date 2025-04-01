#ifndef LINK_FILES_H
#define LINK_FILES_H

#include <vector>
#include <cmath>

struct Vector {
    int id;
    std::vector<double> values;
};

struct Distance {
    int vector1, vector2;
    double alpha;
    Distance(int v1, int v2, double _a) : vector1{v1}, vector2{v2}, alpha{_a} {}
};

double dotProduct(const std::vector<double>& v1, const std::vector<double>& v2);
double magnitude(const std::vector<double>& v);
double cosineDistance(const std::vector<double>& v1, const std::vector<double>& v2);

#endif