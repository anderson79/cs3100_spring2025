//
// Created by drink on 2/5/2025.
//

#ifndef ARRAYLIST_H
#define ARRAYLIST_H
#include <optional>
#include <string>
#include <ostream>

using namespace std;

class ArrayList {
    public:
    string* dataArray; // I renamed this from theArray
    static constexpr size_t INITIAL_ALLOCATED_SIZE = 4;
    size_t listLength;
    size_t allocatedSize;

    // "empty" constructor
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
    // operator[] returns a reference to the string, it is modifiable
    string& operator[](size_t index);
    // at returns optional<string>, if index is out of bounds returns nullopt
    optional<string> at(size_t index) const;
};

ostream& operator<<(ostream& os, const ArrayList& arrayList);


#endif //ARRAYLIST_H
