//
// Created by drink on 2/5/2025.
//

#include "ArrayList.h"

ArrayList::ArrayList(size_t initialSize ) {
    dataArray = new string[4];
    listLength = 0;
    allocatedSize = 4;
}

ArrayList::~ArrayList() {
    delete[] dataArray;
}

ArrayList::ArrayList(const ArrayList& other) {
    listLength = other.listLength;
    allocatedSize = other.allocatedSize;
    dataArray = copyArray(allocatedSize, other.dataArray);
}

void ArrayList::append(string item) {
    if (listLength >= allocatedSize) {
        resizeArray(2.0);
    }
    dataArray[listLength] = item;
    listLength++;
}

void ArrayList::resizeArray(double resizeFactor) {
    string* newArray = copyArray(listLength * resizeFactor, dataArray);
    delete[] dataArray;
    dataArray = newArray;
    allocatedSize = listLength * resizeFactor;
}

string* ArrayList::copyArray(size_t newSize, const string* copyFrom) const {
    string* newArray = new string[newSize];
    for (int i = 0; i < listLength; i++) {
        newArray[i] = copyFrom[i];
    }
    return newArray;
}

string& ArrayList::operator[](size_t index) {
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