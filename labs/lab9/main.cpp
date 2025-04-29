#include "linkedlist.h"

int main() {
    LinkedList list;

    //calling all the functions

    list.SERVER_buildCircularLinkedList();

    list.SERVER_printLinkedList();

    list.CLIENT_printLinkedList();

    list.SERVER_deleteCircularLinkedList();

    list.CLIENT_printLinkedList();

    return 0;
}
