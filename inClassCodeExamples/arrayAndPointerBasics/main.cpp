/*
 * Code from 2nd lecture of week 1
 * Demonstrating fixed size arrays
 * C++ does not prevent you from accessing out of bounds
 * Arrays are really just pointers
 * The variable stores the first address of the memory allocated to the array
 */
#include <iostream>

using namespace std;

int main() {
    // if I don't have std:: in front of cout
    // I need to say 'using namespace std;' like above
    cout << "Hello, World!" << endl;

    int i;
    // if I want my array to be filled with 0's I can do either {0} or {}
    int array[5] = {0};
    int a2[20] = {};

    // fill array with 10, 20...etc
    for (i = 0; i < 5; i++) {
        array[i] = (i + 1) * 10;
    }
    cout << endl;

    // array[-1] is accessing the address of (array - 1)
    array[-1] = 9;
    // different compilers may behave differently, but for gcc
    // setting array[-1] to 9 actually changes a2[19]
    cout << a2[19] << endl;

    // int* means we are declaring a pointer to an integer
    // ptr is a variable
    // in this scenario, &i means "the address of i"
    // we will see & used in other places to mean different things
    // but here it is address of
    int* ptr = &i; // ptr is a pointer to an integer
                // ptr stores the memory address of an integer
                // &i means get the address where i is in memory

    // printing ptr will print the address i is at in memory
    cout << ptr << endl;
    // in this situation, *ptr is used to dereference ptr
    // meaning: go to the memory address stored in ptr and get the value there
    // so, this should print what i is
    cout << *ptr << endl;

    // similarly, we can dereference a pointer and put a value into that address
    *ptr = 10;
    // ptr is pointing to i, so i has been changed to 10 by using *ptr above
    cout << i << endl;

    // array variables are also pointers
    // saying *array means go to the address stored in array and get the value stored there
    // since array stores the address of the first element of the array, *array will get that element
    cout << *array << endl;

    // (array + 1) is saying add 1 to the address stored in array, which is the address of the second element
    // *(array + 1) does the same thing as array[1] does\
    // whenever we use array[i], your program actually does *(array + i)
    cout << *(array + 1) << endl;

    // like I did with ptr, I use * to store something in the array
    *(array + 3) = 100;
    cout << array[3] << endl;
    return 0;
}