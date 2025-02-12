/**
 * Examples of using C++ vector showing some helpful methods
 * vector is very similar to Java ArrayList
 * vector is a resizable, dynamic array
 * as you append items to vector, it will resize automatically
 */
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> intVector; // declare a vector to hold ints
    cout << intVector.size() << endl; // the initial size should be zero

    intVector.resize(5);
    cout << intVector.size() << endl; // resize causes strVector to now have 5 ints

    for (size_t i = 0; i < intVector.size(); i++) { // size_t is C++ for unsigned integer
        cout << intVector[i] << endl; // when you resize, everything is set to a default value
    }

    vector<string> stringVector; // declare a vector to hold strings
    cout << stringVector.size() << endl; // again initial size is 0
    stringVector.resize(5);

    for (const auto& str : stringVector) {// this is a ranged-for to iterate over the vector without indexes
                                                    // const auto& means I want a reference (&) to each string (auto) but I don't want to modify the string (const)
        cout << str << endl; // the default value for strings is "" so all the strings are empty
    }

    // now that the vector can store stuff, lets assign some indexes to things
    stringVector[0] = "hello";
    stringVector[1] = "world";
    stringVector[2] = "james";
    stringVector[3] = "is";
    stringVector[4] = "really";

    // stringVector[5] = "smelly"; not an exception, but this did crash my program

    stringVector.push_back("cool"); // push_back() appends to the end of the vector
    for (const auto& str : stringVector) {
        cout << str << endl;
    }

    try { // the at() method will throw an exception, but if you're trying to access out of bounds
        // there is probably another issue with your program
        stringVector.at(6) = "beans";
    } catch (const exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}