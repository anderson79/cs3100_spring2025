/**
 * ArrayList.h
 * This is the header file for ArrayList
 * ArrayList is a list/dynamic array
 *
 */

#ifndef ARRAYLIST_H
#define ARRAYLIST_H
#include <optional>
#include <string>
#include <ostream>

using namespace std;

class ArrayList {
    public:

    static constexpr size_t INITIAL_ALLOCATED_SIZE = 4;

    string* dataArray; // I renamed this from theArray
    size_t listLength;
    size_t allocatedSize;

    // "empty" constructor
    // you can pass in a desired initial capacity, or else
    // it will be set to the default INITIAL_ALLOCATED_SIZE
    ArrayList(size_t initialSize = INITIAL_ALLOCATED_SIZE);

    // destructor
    ~ArrayList();

    // copy constructor
    ArrayList(const ArrayList& other);

    // add the item to the end of the list
    // list needs to dynamically grow
    void append(string item);

    // helper methods to resize our dataArray
    // one does the resize, the other just copies dataArray
    void resizeArray(double resizeFactor);
    string* copyArray(size_t newSize, const string* copyFrom) const;

    // accessor methods
    // at returns optional<string>, if index is out of bounds returns nullopt
    optional<string> at(size_t index) const;
    // operator[] returns a reference to the string, it is modifiable
    string& operator[](size_t index) const;

};

// overload for << so we can output to cout nicely
ostream& operator<<(ostream& os, const ArrayList& arrayList);


#endif //ARRAYLIST_H
