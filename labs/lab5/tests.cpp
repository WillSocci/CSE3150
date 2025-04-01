#include "linkfiles.h"
#include <iostream>
#include <cassert>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "/workspaces/CSE3150/include/doctest.h"

TEST_CASE("cosine distance") {
    std::vector<double> v1 = {1.0, 1.0, 1.0};
    std::vector<double> v2 = {1.0, 1.0, 0.0};
    std::vector<double> v3 = {2.0, 2.0, 2.0};
    std::vector<double> v0 = {0.0, 0.0, 0.0};
    std::vector<double> v4 = {4.2, 3.1, 6.8};
    std::vector<double> v5 = {5.2, 5.1, 0.0};
    std::vector<double> v6 = {5.0, 6.9, 3.0};
    std::vector<double> v7 = {5.2, 5.1, 1.0};


    double t1 = cosineDistance(v1, v2);
    double t2 = cosineDistance(v4, v5);
    double t3 = cosineDistance(v5, v7);
    double t4 = cosineDistance(v2, v6);
    double t5 = cosineDistance(v3, v4);

    //the check kept returning failure due to a rounding issue not being able to keep track.
    //  So this makes the search have a range for error
    CHECK(t1 == doctest::Approx(0.61548).epsilon(0.00001));
    CHECK(t2 == doctest::Approx(0.923556).epsilon(0.00001));
    CHECK(t3 == doctest::Approx(0.136443).epsilon(0.00001));
    CHECK(t4 == doctest::Approx(0.372414).epsilon(0.00001));
    CHECK(t5 == doctest::Approx(0.318813).epsilon(0.00001));

    CHECK(cosineDistance(v1, v3) == 0.0);
    CHECK(cosineDistance(v1, v0) == 0.0);
}