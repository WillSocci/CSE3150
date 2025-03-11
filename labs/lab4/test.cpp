#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "/workspaces/CSE3150/include/doctest.h"
#include "LinkedList.h"

TEST_CASE("LinkedList") {
    LinkedList ll;

    SUBCASE("Move Constructor") {
        ll.insertAtEnd(1);
        ll.insertAtEnd(2);
        ll.insertAtEnd(3);
        LinkedList movedList = std::move(ll);
        CHECK(movedList.root->data == 1);
        CHECK(movedList.root->next->data == 2);
        CHECK(movedList.root->next->next->data == 3);
        CHECK(ll.root == nullptr);
    }

    SUBCASE("Move Assignment Operator") {
        ll.insertAtEnd(1);
        ll.insertAtEnd(2);
        ll.insertAtEnd(3);
        LinkedList ll2;
        ll2.insertAtEnd(5);
        ll2.insertAtEnd(10);

        LinkedList ll3;
        ll3 = std::move(ll2);
        CHECK(ll3.root->data == 5);
        CHECK(ll3.root->next->data == 10);
        CHECK(ll2.root == nullptr);
    }
    
    SUBCASE("insert and print") {
        ll.insertAtEnd(1);
        ll.insertAtEnd(2);
        ll.insertAtEnd(3);
        CHECK(ll.root->data == 1);
        CHECK(ll.root->next->data == 2);
        CHECK(ll.root->next->next->data == 3);
    }

    SUBCASE("copy constructor") {
        ll.insertAtEnd(5);
        ll.insertAtEnd(10);
        LinkedList copyList = ll;
        CHECK(copyList.root->data == 5);
        CHECK(copyList.root->next->data == 10);
    }

    SUBCASE("delete") {
        ll.insertAtEnd(1);
        ll.insertAtEnd(2);
        ll.insertAtEnd(3);
        ll.deleteNode(1);
        CHECK(ll.root->next->data == 3);
    }

    SUBCASE("checking prefix sum") {
        ll.insertAtEnd(1);
        ll.insertAtEnd(-1);
        ll.insertAtEnd(2);
        CHECK(ll.checkPrefixSum() == true);
        
        ll.insertAtEnd(-5);
        CHECK(ll.checkPrefixSum() == false);
    }

    SUBCASE("pointer jumper") {
        ll.insertAtEnd(1);
        ll.insertAtEnd(2);
        ll.pointerJumping();
        CHECK(ll.root->next->data == 2);
    }
}
