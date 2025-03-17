#include <iostream>
#include <unordered_map>

using namespace std;

int main() {

    unordered_map<char, int> myMap;

    char myChar = 'd';
    int myInt = 4;

    myMap['a'] = 1;
    myMap['b'] = 2;
    myMap['c'] = 3;
    myMap[myChar] = myInt;

    for (auto item: myMap) {
        cout << item.first << " " << item.second << endl;
    }

    myMap['b'] = 14;
    cout << endl;
    for (auto item: myMap) {
        cout << item.first << " " << item.second << endl;
    }

    cout << myMap.contains('b') << endl;\

    return 0;
}