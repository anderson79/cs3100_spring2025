//
// Created by drink on 2/5/2025.
//

#include "ArrayList.h"
#include <iostream>

using namespace std;

int main() {
    ArrayList array;

    for (size_t i = 0; i < ArrayList::INITIAL_ALLOCATED_SIZE; i++) {
        array.append(to_string(i));
    }
    array.append("one more thing");
    cout << array << endl;

    ArrayList copy(array);

    array.append("original");
    copy.append("copy");

    array[3] = "original";
    copy[4] = "copy";

    cout <<"array: " << array << endl;
    cout << "copy: " << copy << endl;
}