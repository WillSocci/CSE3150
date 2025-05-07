#include "timesharedptr.h"

struct Node {
    int data;
    Node(int d) : data(d) {}
};

//this is mostly the same as the example in the pdf
//changes I made: changed the sleep_until to sleep_for.  
//Im more familiar with sleep_for so not a big deal allows it to be more consistent
//also I mention below the dummy I learned mix of a couple web searches and basic funcionalities I've learned
int main() {
    TimedSharedPtr<Node> myNode(new Node(7), 100);
    // Node holds data of 7 and expires in 100 milliseconds
    // Note: the 100 is an argument to the TimedSharedPtr constructor
    TimedSharedPtr<Node> myOtherNode = myNode;

    //50milsec
    this_thread::sleep_for(chrono::milliseconds(50));
    cout << "myNode.get() address: <" << myNode.get() << ">" << endl;
    cout << "myNode.use_count(): " << myNode.use_count() << endl;
    cout << "myOtherNode.use_count(): " << myOtherNode.use_count() << endl;

    //25milsec
    this_thread::sleep_for(chrono::milliseconds(25));
    cout << "myNode.get() address: <" << myNode.get() << ">" << endl;

    //75milsec
    this_thread::sleep_for(chrono::milliseconds(75));

    
    cout << "The ptr should have expired: " << endl;
    cout << "myNode.get() address: <" << myNode.get() << ">" << endl;

    cout << "-----------" << endl;

    //this line was tricky and helped me make sure it guarenteed allocation
    //the addresses will now be different no matter what
    int* tester = new int(12345);

    TimedSharedPtr<int> p(new int(42));

    cout << p.get() << endl;
    cout << "p.use_count(): " << p.use_count() << endl;

    TimedSharedPtr<int> q = p;
    cout << "p.use_count(): " << p.use_count() << endl;
    cout << "q.use_count(): " << q.use_count() << endl;

    //deallocate
    delete tester;

    return 0;
}
