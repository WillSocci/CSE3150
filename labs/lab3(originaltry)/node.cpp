#ifndef NODE_H
#define NODE_H

#include <iostream>

struct Node {
    int data;
    Node* next;

    Node(int val): data(val), next(nullptr) {}

    Node(const Node& other): data(other.data), next(nullptr) {
        if (other.next) {
            next = new Node(*other.next);
        }
    }

    ~Node() {}
};

#endif
