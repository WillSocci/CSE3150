#include "linkedlist.h"

void LinkedList::SERVER_buildCircularLinkedList() {
    //makes shared node for every ptr
    std::shared_ptr<Node> zero = std::make_shared<Node>("zero");
    std::shared_ptr<Node> one = std::make_shared<Node>("one");
    std::shared_ptr<Node> two = std::make_shared<Node>("two");
    std::shared_ptr<Node> three = std::make_shared<Node>("three");
    std::shared_ptr<Node> four = std::make_shared<Node>("four");
    std::shared_ptr<Node> five = std::make_shared<Node>("five");

    //everythign needed to finish a full cycle
    zero->next = one;
    one->next = two;
    two->next = three;
    three->next = four;
    four->next = five;
    five->next = zero;

    //store weak_ptr version
    zero->nextWeak = one;
    one->nextWeak = two;
    two->nextWeak = three;
    three->nextWeak = four;
    four->nextWeak = five;
    five->nextWeak = zero;

    head = zero;
}

//print the server linkedlist function
void LinkedList::SERVER_printLinkedList() {

    //beginning
    std::shared_ptr<Node> curr = head;
    std::cout << "Step 2 Server Printed:" << std::endl;

    //server prints the list of shared_ptrs
    for (int i = 0; i < 6 && curr; ++i) {

        std::cout << "[" << curr->name << "]: use_count: " << curr.use_count()
                  << " address: " << curr.get()
                  << " next (from shared_ptr): " << curr->next.get()
                  << std::endl;

        curr = curr->next;
    }
}

//print the client linkedlist function
void LinkedList::CLIENT_printLinkedList() {

    //beginning
    std::shared_ptr<Node> curr = head;
    std::cout << "Step 3 Client Printed:" << std::endl;

    //prints the clients weak_ptrs
    for (int i = 0; i < 6 && curr; ++i) {

        std::shared_ptr<Node> nextNode = curr->nextWeak.lock();
        std::cout << "[" << curr->name << "]: use_count: " << curr.use_count()
                  << " address: " << curr.get()
                  << " next (from weak_ptr): " << nextNode.get()
                  << std::endl;

        curr = nextNode;
    }
}

//delete the linked list
void LinkedList::SERVER_deleteCircularLinkedList() {

    std::cout << "Step 4 Deleting shared_ptrs:" << std::endl;
    head = nullptr;

}
