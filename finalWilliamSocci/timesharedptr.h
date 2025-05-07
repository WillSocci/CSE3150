#ifndef TIMEDSHAREDPTR_H
#define TIMEDSHAREDPTR_H

#include <chrono>
#include <iostream>
#include <memory>
#include <thread>

using namespace std;
using namespace chrono;

template<typename T>
class TimedSharedPtr {
private:
    //intializing everything... my count for the timeshared ptr, use_count, starttime, endtime, and the bool status
    T* xPtr;
    int* count;
    steady_clock::time_point start;
    milliseconds end;
    bool* status;

public:
    using Clock = steady_clock;

    //constructor
    TimedSharedPtr(T* ptr = nullptr, int ms = 100): 
        //set ptr, count to 1, start clock, and the status
        xPtr(ptr), 
        count(new int(1)),
        start(Clock::now()),
        end(milliseconds(ms)),
        status(new bool(false))
    {
        //prints the start message if the ptr is set correctly
        if (ptr) {
            cout << "ControlTimedSharedPtr " << ptr << " start: 0 ms" << endl;
        }
    }

    //copy constructor
    TimedSharedPtr(const TimedSharedPtr& other): 
        //copies pointer and everything else
        xPtr(other.xPtr),
        count(other.count),
        start(other.start),
        end(other.end),
        status(other.status)
    {
        //if count was correctly set increment it
        if (count){
            (*count)++;
        }
    }

    //assignment operator... cleans up current object, copies other's data, and increments count
    TimedSharedPtr& operator=(const TimedSharedPtr& other) {
        if (this != &other) {
            cleanup(); //cleans up everything... the functions below
            xPtr = other.xPtr;
            count = other.count;
            start = other.start;
            end = other.end;
            status = other.status;
            
            if (count){
                ++(*count);
            }
        }
        return *this;
    }

    //destructor, calls cleanup after
    ~TimedSharedPtr() {
        cleanup();
    }

    //this is my added feature! it tracks once the ptr beccomes expired
    T* get() {
        //tracks the time that has elapsed
        auto now = Clock::now();
        auto elapsed = duration_cast<milliseconds>(now - start);

        //if time has passed and status is still false... expire it and delete
        if (elapsed > end && !(*status)) {

            *status = true; //changes the status
            delete xPtr; //delete it
            xPtr = nullptr; //set it to nullptr

        }

        //return the original ptr or the nullptr whichever
        return xPtr;
    }

    //returns the number of shared pointers pointing to the same resource
    int use_count() const {
        if (count != nullptr) {
            return *count;
        } else {
            return 0;
        }
    }

private:
    //cleanup... if this is the last shared ptr, delete everything
    void cleanup() {
        if (count && --(*count) == 0) {
            if (!(*status)) {

                //not expired yet... print message and delete pointer
                auto end = Clock::now();
                auto lived = duration_cast<milliseconds>(end - start);
                cout << "ControlTimedSharedPtr " << xPtr << " end: " << lived.count() << " ms" << endl;
                delete xPtr;
                
            } else {
                //already expired... just print that info
                cout << "ControlTimedSharedPtr expired already" << endl;
            }

            //delete the shared resources
            delete count;
            delete status;
        }
    }
};

#endif
