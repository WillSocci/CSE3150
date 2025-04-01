#include "linkfiles.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    //open file
    ifstream file("vectors.txt");
    vector<Vector> vectors;
    
    if (!file) {
        cerr << "file error" << endl;
        return 1;
    }
    
    int id = 0;
    string line;

    //reading through the file
    while (!file.eof()) {

        Vector vec;
        vec.id = id++;
        double val;

        while (file >> val) {
            vec.values.push_back(val);
            if (file.peek() == '\n' || file.peek() == EOF) break;
        }

        if (!vec.values.empty()) vectors.push_back(vec);

    }
    file.close();
    
    //this makes sure every vector is calculating with different vector and every vector
    vector<Distance> distances;
    
    for (size_t i = 0; i < vectors.size(); ++i) {
        for (size_t j = i + 1; j < vectors.size(); ++j) {

            double distance = cosineDistance(vectors[i].values, vectors[j].values);
            distances.emplace_back(vectors[i].id, vectors[j].id, distance);
        }
    }
    
    //sorts the alphas
    sort(distances.begin(), distances.end(), [](Distance a, Distance b) {
        return a.alpha < b.alpha;
    });
    
    //prints
    for (const auto& d : distances) {
        cout << "vectors: " << d.vector1 << "  " << d.vector2
             << "    cos distance: " << d.alpha << endl;
    }
    
    return 0;
}