#include <iostream>

#include "LinkedList.h"

using namespace std;

int main() {

    LinkedList ll, ll_1;

    cout << ll_1 << endl;

    ll.insertAtBeginning(-1);
    ll.insertAtBeginning(+1);
    ll.insertAtBeginning(-1);

    cout << ll << endl;

    ll.insertAtEnd(-44);

    cout << "-------------" << endl;

    Node * ptr_last = ll.getLastElement();

    cout << *ptr_last << endl;

    ll.pointerJumping();

    cout << "-------------" << endl;

    ll_1.insertAtBeginning(1);
    ll_1.insertAtBeginning(-1);
    ll_1.insertAtBeginning(1);
    cout << ll_1 << endl;
    ll_1.deleteNode(-1);
    cout << ll_1 << endl;

    LinkedList ll_2 = ll_1;
    ll_1.deleteNode(-1);

    cout << "-------------" << endl;


    return 0;
}