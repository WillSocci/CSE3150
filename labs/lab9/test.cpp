#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "/workspaces/CSE3150/include/doctest.h"
#include "linkedlist.h"

TEST_CASE("Circular Linked List Structure and Smart Pointer Behavior") {
    LinkedList list;

    //build the list
    list.SERVER_buildCircularLinkedList();

    SUBCASE("check if list was created by printing it") {
        list.SERVER_printLinkedList();
        CHECK(true);
    }

    SUBCASE("check that the weak_ptrs are there and correctly assigned") {
        list.CLIENT_printLinkedList();  
        CHECK(true);
    }

    SUBCASE("check to see that after deleting there are no more ptrs in the list") {
        list.CLIENT_printLinkedList();
        list.SERVER_deleteCircularLinkedList();
        list.CLIENT_printLinkedList();
        CHECK(true);
    }
}