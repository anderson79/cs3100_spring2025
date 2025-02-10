//
// Created by drink on 2/5/2025.
//

#include "ArrayList.h"

// the parameter determines the initial size of the array
// create a new array of that size
// listLength initially is zero since there is nothing in the list
ArrayList::ArrayList(size_t initialSize) {
    allocatedSize = initialSize;
    dataArray = new string[allocatedSize];
    listLength = 0;
}

// delete[] is used when deleting an array
ArrayList::~ArrayList() {
    delete[] dataArray;
}

// copy all items from other into this list
ArrayList::ArrayList(const ArrayList& other) {
    listLength = other.listLength;
    allocatedSize = other.allocatedSize;
    dataArray = copyArray(allocatedSize, other.dataArray);
}

// if we are out of space for the list, resize the array to hold 2x more
// set the element at listLength to the item, since listLength - 1 is the last element, listLength is where the next one goes
// increment listLength since we added a new thing
void ArrayList::append(string item) {
    if (listLength >= allocatedSize) {
        resizeArray(2.0);
    }
    dataArray[listLength] = item;
    listLength++;
}

// using the resizeFactor, copy everything from this array into a new one
// delete the old array memory
// set our array to the new array we made
// update the allocatedSize
void ArrayList::resizeArray(double resizeFactor) {
    // doing some weird casts here because the resizeFactor is a double
    // there is a chance we go over the limit of what a size_t can hold
    // but we would probably run out of available memory before that happens
    const auto newSize = static_cast<size_t>(static_cast<double>(allocatedSize) * resizeFactor);
    string* newArray = copyArray(newSize, dataArray);
    delete[] dataArray;
    dataArray = newArray;
    allocatedSize = newSize;
}

string* ArrayList::copyArray(size_t newSize, const string* copyFrom) const {
    auto* newArray = new string[newSize];
    for (int i = 0; i < listLength; i++) {
        newArray[i] = copyFrom[i];
    }
    return newArray;
}

string& ArrayList::operator[](size_t index) const {
    return dataArray[index];
}

optional<string> ArrayList::at(size_t index) const {
    if (index < listLength) {
        return dataArray[index];
    }
    return nullopt;
}

ostream& operator<<(ostream& os, const ArrayList& arrayList) {
    os << "{";
    for (int i = 0; i < arrayList.listLength; i++) {
        os << arrayList.dataArray[i];
        if (i < arrayList.listLength - 1) {
            os << ", ";
        }
    }
    os << "}";
    return os;
}
