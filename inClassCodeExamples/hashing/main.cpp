/**
 * Examples using the C++ hash objects
 */
#include <iostream>
#include <string>

using namespace std;

int main() {
    auto strHash = hash<string>{}; // strHash is a hash object that hashes strings
                                    // here I'm using the auto keyword, I would limit using auto to
                                    // whenever you're using a C++ feature like hash, string, vector, etc.
                                    // and not when it is your own data type

    size_t jamesHash = strHash("James");
    size_t julietHash = strHash("Juliet");

    cout << jamesHash << endl;
    cout << julietHash << endl;

    // you will really only need to hash strings for our hash table project
    // but hash<T> works for most C++ types
    auto intHash = hash<int>();
    auto doubleHash = hash<double>();
    auto charHash = hash<char>();

    cout << intHash(42) << endl;
    cout << doubleHash(42.0) << endl;
    cout << charHash('Q') << endl;

    // you can also create temp hash objects
    size_t tempHash = hash<string>{}("James");
    cout << tempHash << endl;

    return 0;
}