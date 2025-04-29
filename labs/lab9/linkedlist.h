#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <memory>
#include <string>

//node for the name next and next weak
struct Node {

    std::string name;
    std::shared_ptr<Node> next;
    std::weak_ptr<Node> nextWeak;

    Node(const std::string& name) : name(name) {}
};

//linkedlist class ready to go
class LinkedList {
public:

    void SERVER_buildCircularLinkedList();
    void SERVER_printLinkedList();
    void SERVER_deleteCircularLinkedList();
    void CLIENT_printLinkedList();

private:

    std::shared_ptr<Node> head;
    
};

#endif
