#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "/workspaces/CSE3150/include/doctest.h"
#include "timesharedptr.h"

class MyClass {
public:
    int val;
    MyClass(int v): val(v) {}
};

TEST_CASE("Testing the timesharedptr.h checking cases") {

    SUBCASE("create a timeshraredptr and then make sure it acts the way it should throughout (stays 42)") {
        TimedSharedPtr<MyClass> ptr(new MyClass(42), 100); //100ms
        CHECK(ptr.get() != nullptr);
        CHECK(ptr.get()->val == 42); //check the val
    }

    SUBCASE("make sure it expires") {
        TimedSharedPtr<MyClass> ptr(new MyClass(99), 100); //100ms
        this_thread::sleep_for(150ms); //wait for longer than above
        CHECK(ptr.get() == nullptr); //should be expired
    }

    SUBCASE("make sure use_count functions correctly... increments when it should") {
        TimedSharedPtr<MyClass> ptr1(new MyClass(10), 500); //create ptr
        TimedSharedPtr<MyClass> ptr2 = ptr1; //copy it
        CHECK(ptr1.use_count() == 2); //check use count for both
        CHECK(ptr2.use_count() == 2);
    }

    SUBCASE("cleanup should work accordingly with everything else") {
        TimedSharedPtr<MyClass> ptr1(new MyClass(20), 500); //create ptr
        TimedSharedPtr<MyClass> ptr2;
        ptr2 = ptr1; //assign it
        CHECK(ptr1.use_count() == 2); //both should share ownership for both pointers
        CHECK(ptr2.use_count() == 2);
    }

    SUBCASE("make sure destructer is working") {
        {
            TimedSharedPtr<MyClass> x(new MyClass(5), 100); //100ms
            this_thread::sleep_for(150ms); //wait to expire
            x.get(); //make it expire
            //"expired already"
        }
        CHECK(true); //if it output then good
    }
}
