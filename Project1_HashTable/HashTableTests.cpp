#define RUN_TESTS

#ifdef RUN_TESTS

#include "HashTable.h"

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const string evalName{""};
// for use for grading only
//#define __GRADING

#ifdef GRADING
#include <fstream>
#define OUTSTREAM os
#else
#define OUTSTREAM cout
#endif

#define HT_PRINT(ht) OUTSTREAM << "HashTable contents" << endl; OUTSTREAM << "------------------" << endl; OUTSTREAM << ht1 << endl;

#define HT_INSERT
#define HT_INSERT_DUPLICATE
#define HT_INSERT_FULL
#define HT_REMOVE
#define HT_REMOVE_MISSING
#define HT_INSERT_AFTER_REMOVE
#define HT_CONTAINS
#define HT_CONTAINS_MISSING
#define HT_CONTAINS_AFTER_REMOVE
#define HT_GET
#define HT_GET_MISSING
#define HT_GET_REMOVED
#define HT_GET_AFTER_REMOVE
#define HT_BRACKET_OP_GET
#define HT_BRACKET_OP_SET
#define HT_KEYS
#define HT_ALPHA
#define HT_CAPACITY
#define HT_SIZE


void memoryLeakTest();

// main
int main(int argc, char* argv[]) {
    constexpr size_t MAXHASH = HashTable::DEFAULT_INITIAL_CAPACITY;

#ifdef GRADING
	ofstream OUTSTREAM("evals/" + evalName + "_eval.txt");
	if (!OUTSTREAM.good())
	{
		cout << "Evaluation file failed to open\n";
		exit(1);
	}
    OUTSTREAM << "Grading evaluation for " << evalName << endl << endl;
#endif

    OUTSTREAM << "+==================+" << endl;
    OUTSTREAM << "| HASH TABLE TESTS |" << endl;
    OUTSTREAM << "+==================+" << endl << endl;

    // TEST: HASH TABLE INSERT AND PRINT
    OUTSTREAM << "Testing HashTable creation, insert, print" << endl;
    OUTSTREAM << "=========================================" << endl << endl;

    OUTSTREAM << "Inserting several items into hashtable" << endl;
    OUTSTREAM << "--------------------------------------" << endl;

#ifdef HT_INSERT
    try {
        HashTable ht1;
        bool result;
        size_t index = 1;

        if (!ht1.capacity() == MAXHASH) {
            OUTSTREAM << "Initial capacity incorrect" << endl;
        }

        OUTSTREAM << "Inserting first " << MAXHASH / 2 << " values" << endl;
        OUTSTREAM << "------------------------" << endl;
        for (int index = 1; index <= MAXHASH / 2; index++) {
            result = ht1.insert(to_string(index), index);
            if (result)
                OUTSTREAM << "Inserted <" << index << ", " << index << ">.  " << endl;
            else
                OUTSTREAM << "*** Unable to insert <" << index << ", " << index << "> *** " << __LINE__ << endl;
        }
        OUTSTREAM << endl;

#ifdef HT_PRINT
        HT_PRINT(ht1);
#else
		OUTSTREAM << "***Unable to print HashTable***" << endl << endl;
#endif // HT_PRINT

        OUTSTREAM << "Inserting values with larger keys" << endl;
        OUTSTREAM << "----------------------------------------" << endl;
        for (int i = 111; i <= MAXHASH / 2 * 111; i += 111) {
            result = ht1.insert(to_string(i), i);
            if (result)
                OUTSTREAM << "Inserted <" << i << ", " << i << ">.  " << endl;
            else
                OUTSTREAM << "*** Unable to insert <" << i << ", " << i << "> *** " << __LINE__ << endl;
        }
        OUTSTREAM << endl;

#ifdef HT_PRINT
        HT_PRINT(ht1);
#else
    	OUTSTREAM << "***Unable to print HashTable***" << endl << endl;
#endif // HT_PRINT
    } catch (exception& e) {
        OUTSTREAM << "Exception: " << e.what() << endl << endl;
    }
#else
    OUTSTREAM << "*** DID NOT TEST INSERT ***" << endl
            << endl;
#endif
    // END OF TEST: HASH TABLE INSERT

    // TEST: HASH TABLE INSERT DUPLICATES
    OUTSTREAM << "Inserting duplicate key" << endl;
    OUTSTREAM << "-----------------------" << endl;
#ifdef HT_INSERT_DUPLICATE
    try {
        HashTable ht1;
        bool result;

        for (int i = 1; i <= MAXHASH / 2; i++) {
            result = ht1.insert(to_string(i), i);
            if (!result)
                OUTSTREAM << "*** Unable to insert <" << i << ", " << i << "> *** " << __LINE__ << endl;
        }

        result = ht1.insert(to_string(MAXHASH / 3), MAXHASH / 3);
        if (!result)
            OUTSTREAM << "CORRECT: insert() returned false" << endl << endl;
        else
            OUTSTREAM << "*** ERROR: insert() returned true *** " << __LINE__ << endl << endl;
    } catch (exception& e) {
        OUTSTREAM << "Exception: " << e.what() << endl << endl;
    }
#else
    OUTSTREAM << "*** DID NOT TEST INSERT DUPLICATE ***" << endl
            << endl;
#endif
    // END OF TEST: HASH TABLE INSERT DUPLICATES

    // TEST: HASH TABLE INSERT FULL
    OUTSTREAM << "Testing insert when table is full" << endl;
    OUTSTREAM << "---------------------------------" << endl;
#ifdef HT_INSERT_FULL
    try {
        HashTable ht1;
        bool result;

        for (int i = 1; i <= MAXHASH; i++) {
            result = ht1.insert(to_string(i), i);
            if (!result)
                OUTSTREAM << "*** Unable to insert <" << i << ", " << i << "> *** " << __LINE__ << endl;
            else
                OUTSTREAM << "Inserted <" << i << ", " << i << ">.  " << endl;
        }

        OUTSTREAM << endl << "HashTable now full, attempting to insert more items..." << endl;
        OUTSTREAM << "Testing HashTable resizing" << endl;
        OUTSTREAM << "--------------------------" << endl;

        for (int i = MAXHASH + 1; i <= 2 * MAXHASH; i++) {
            result = ht1.insert(to_string(i), i);
            if (result)
                OUTSTREAM << "Inserted <" << i << ", " << i << ">.  " << endl;
            else
                OUTSTREAM << "*** Unable to insert <" << i << ", " << i << "> *** " << __LINE__ << endl;
        }
        OUTSTREAM << endl;
#ifdef HT_SIZE
        OUTSTREAM << "Reported hash table size is: " << ht1.size() << " versus expected size: " << MAXHASH * 2 << endl;

        if (ht1.size() == 2 * MAXHASH) {
            OUTSTREAM << "CORRECT: hash table successfully resized" << endl << endl;
        } else {
            OUTSTREAM << "ERROR: hash table not correctly resized *** " << __LINE__ << endl << endl;
        }
#endif
#ifdef HT_PRINT
        HT_PRINT(ht1);
#else
        OUTSTREAM << "***Unable to print HashTable***" << endl << endl;
#endif // HT_PRINT
    } catch (exception& e) {
        OUTSTREAM << "Exception: " << e.what() << endl
                << endl;
    }
#else
    OUTSTREAM << "*** DID NOT TEST INSERT FULL ***" << endl
            << endl;
#endif
    // END OF TEST: HASH TABLE INSERT FULL


    // TEST: HASH TABLE REMOVE
    OUTSTREAM << "Testing HashTable::remove()" << endl;
    OUTSTREAM << "===========================" << endl
            << endl;
    OUTSTREAM << "Removing all entries in the table" << endl;
    OUTSTREAM << "---------------------------------" << endl;
#ifdef HT_REMOVE
    try {
        HashTable ht1;
        bool result;

        // fill table with 1 to MAXHASH
        for (int i = 1; i <= MAXHASH; i++) {
            result = ht1.insert(to_string(i), i);
            if (!result)
                OUTSTREAM << "*** Unable to insert <" << i << ", " << i << ">  *** " << __LINE__ << endl;
        }

        // remove 1 to MAXHASH
        bool anyErrors = false;
        for (int i = 1; i <= MAXHASH; i++) {
            result = ht1.remove(to_string(i));
            anyErrors |= !result;
            if (result)
                OUTSTREAM << "Removed entry <" << i << ", " << i << ">" << endl;
            else
                OUTSTREAM << "*** ERROR: Unable to remove entry <" << i << ", " << i << "> *** " << __LINE__ << endl;
        }
        if (anyErrors) {
            OUTSTREAM << "ERROR: Could not remove all items *** " << __LINE__ << endl;
        } else {
            OUTSTREAM << "CORRECT: All items removed" << endl;
        }

        OUTSTREAM << endl;
        OUTSTREAM << "Refilling empty table" << endl;
        OUTSTREAM << "---------------------" << endl;

        bool noErrors = true;
        for (int i = 1; i <= MAXHASH; i++) {
            result = ht1.insert(to_string(i), i);
            if (!result) {
                OUTSTREAM << "*** Unable to insert <" << i << ", " << i << "> *** " << __LINE__ << endl;
                noErrors = false;
            }
        }
        if (noErrors)
            OUTSTREAM << "CORRECT: Successfully inserted new entries" << endl << endl;
        else
            OUTSTREAM << "ERROR: Failed inserting new entries after removing *** " << __LINE__ << endl << endl;
    } catch (exception& e) {
        OUTSTREAM << "Exception: " << e.what() << endl << endl;
    }
#else
    OUTSTREAM << "*** DID NOT TEST REMOVE ***" << endl
            << endl;
#endif
    // END OF TEST: HASH TABLE REMOVE

    // TEST: HASH TABLE REMOVE MISSING
    OUTSTREAM << "Removing missing key: " << (MAXHASH + 5) << endl;
    OUTSTREAM << "------------------------" << endl;
#ifdef HT_REMOVE_MISSING
    try {
        HashTable ht1;
        bool result;

        for (int i = 1; i <= MAXHASH; i++) {
            result = ht1.insert(to_string(i), i);
            if (!result)
                OUTSTREAM << "*** Unable to insert <" << i << ", " << i << "> *** " << __LINE__ << endl;
        }

        result = ht1.remove(to_string(MAXHASH + 5));
        if (!result)
            OUTSTREAM << "CORRECT: remove() returned false" << endl
                    << endl;
        else
            OUTSTREAM << "ERROR: remove() returned true *** " << __LINE__ << endl
                    << endl;
    } catch (exception& e) {
        OUTSTREAM << "Exception: " << e.what() << endl << endl;
    }
#else
    OUTSTREAM << "*** DID NOT TEST REMOVE MISSING ***" << endl
            << endl;
#endif
    // END OF TEST: HASH TABLE REMOVE MISSING


    // TEST: HASH TABLE CONTAINS
    OUTSTREAM << "Testing HashTable::contians()" << endl;
    OUTSTREAM << "-----------------------------" << endl;
#ifdef HT_CONTAINS
    try {
        HashTable ht1;
        bool result;
        for (int i = 1; i <= MAXHASH; i++) {
            result = ht1.insert(to_string(i), i);
            if (!result) {
                OUTSTREAM << "*** Unable to insert <" << i << ", " << i << ">  *** " << __LINE__ << endl;
            }
        }
        result = true;
        bool anyErrors = false;
        for (int i = 1; i <= MAXHASH; i++) {
            result = ht1.contains(to_string(i));
            anyErrors |= !result;
            if (!result) {
                OUTSTREAM << "*** contains() returned false for <" << i << ", " << i << "> *** " << __LINE__ << endl;
            }
        }
        if (anyErrors) {
            OUTSTREAM << "CORRECT: Contains returned true" << endl << endl;
        } else {
            OUTSTREAM << "ERROR: Contains returned false *** " << __LINE__ << endl << endl;
        }
    } catch (exception& e) {
        OUTSTREAM << "Exception: " << e.what() << endl << endl;
    }
#else
    OUTSTREAM << "*** DID NOT TEST CONTAINS ***" << endl << endl;
#endif

    OUTSTREAM << "Testing contains() with missing item" << endl;
    OUTSTREAM << "------------------------" << endl;
#ifdef HT_CONTAINS_MISSING
    try {
        HashTable ht1;
        bool result;
        for (int i = 1; i <= MAXHASH; i++) {
            result = ht1.insert(to_string(i), i);
            if (!result) {
                OUTSTREAM << "*** Unable to insert <" << i << ", " << i << "> *** " << __LINE__ << endl;
            }
        }
        result = ht1.contains(to_string(MAXHASH + 5));
        if (!result) {
            OUTSTREAM << "CORRECT: contains returned false" << endl << endl;
        } else {
            OUTSTREAM << "ERROR: contains returned true *** " << __LINE__ << endl << endl;
        }
    } catch (exception& e) {
        OUTSTREAM << "Exception: " << e.what() << endl << endl;
    }
#else
    OUTSTREAM << "*** DID NOT TEST CONTAINS MISSING ***" << endl << endl;
#endif

    OUTSTREAM << "Testing contains after removing an item" << endl;
    OUTSTREAM << "---------------------------------------" << endl;
#ifdef HT_CONTAINS_AFTER_REMOVE
    try {
        HashTable ht1;
        bool result;
        for (int i = 1; i <= MAXHASH; i++) {
            result = ht1.insert(to_string(i), i);
            if (!result) {
                OUTSTREAM << "*** Unable to insert <" << i << ", " << i << "> *** " << __LINE__ << endl;
            }
        }
        result = ht1.remove(to_string(MAXHASH / 2));
        if (!result) {
            OUTSTREAM << "*** Unable to remove " << MAXHASH / 2 << " *** " << __LINE__ << endl;
        }
        result = ht1.contains(to_string(MAXHASH / 2));
        if (!result) {
            OUTSTREAM << "CORRECT: contains returned false" << endl << endl;
        } else {
            OUTSTREAM << "ERROR: contains returned true *** " << __LINE__ << endl << endl;
        }
    } catch (exception& e) {
        OUTSTREAM << "Exception: " << e.what() << endl << endl;
    }
#else
    OUTSTREAM << "*** DID NOT TEST CONTAINS AFTER REMOVE ***" << endl << endl;
#endif

    // TEST: HASH TABLE get
    OUTSTREAM << "Testing HashTable::get()" << endl;
    OUTSTREAM << "=========================" << endl << endl;
    OUTSTREAM << "Getting value or key in the table: " << MAXHASH / 2 << endl;
    OUTSTREAM << "---------------------------------" << endl;
#ifdef HT_GET
    try {
        HashTable ht1;
        std::optional<int> result;

        for (int i = 1; i <= MAXHASH; i++) {
            result = ht1.insert(to_string(i), i);
            if (!result)
                OUTSTREAM << "*** Unable to insert <" << i << ", " << i << "> *** " << __LINE__ << endl;
        }

        result = ht1.get(to_string(MAXHASH / 2));
        if (result && (result.value() == MAXHASH / 2))
            OUTSTREAM << "CORRECT: found entry " << MAXHASH / 2 << endl << endl;
        else
            OUTSTREAM << "*** ERROR: result was <" << result.has_value() << "> and value was <" << result.value() <<
                    "> *** " << __LINE__ << endl << endl;
    } catch (exception& e) {
        OUTSTREAM << "Exception: " << e.what() << endl << endl;
    }
#else
    OUTSTREAM << "*** DID NOT TEST GET ***" << endl
            << endl;
#endif
    // END OF TEST: HASH TABLE GET

    // TEST: HASH TABLE GET MISSING
    OUTSTREAM << "Testing get() with missing key: " << MAXHASH + 5 << endl;
    OUTSTREAM << "----------------------------------" << endl;
#ifdef HT_GET_MISSING
    try {
        HashTable ht1;
        std::optional<int> result;

        for (int i = 1; i <= MAXHASH; i++) {
            result = ht1.insert(to_string(i), i);
            if (!result)
                OUTSTREAM << "*** Unable to insert <" << i << ", " << i << "> *** " << __LINE__ << endl;
        }

        result = ht1.get(to_string(MAXHASH + 5));
        if (!result)
            OUTSTREAM << "CORRECT: get() returned false" << endl
                    << endl;
        else
            OUTSTREAM << "*** ERROR: result was <" << result.has_value() << "> and value was <" << result.value() <<
                    "> *** " << __LINE__ << endl << endl;
    } catch (exception& e) {
        OUTSTREAM << "Exception: " << e.what() << endl << endl;
    }
#else
    OUTSTREAM << "*** DID NOT TEST GET MISSING ***" << endl << endl;
#endif
    // END OF TEST: HASH TABLE GET MISSING

    // TEST: HASH TABLE GET REMOVED
    OUTSTREAM << "Testing get() with removed key (" << MAXHASH / 2 << ")" << endl;
    OUTSTREAM << "-----------------------------------------" << endl;
#ifdef HT_GET_REMOVED
    try {
        HashTable ht1;
        std::optional<int> result;
        int keyToRemove = MAXHASH / 2;

        for (int i = 1; i <= MAXHASH; i++) {
            result = ht1.insert(to_string(i), i);
            if (!result)
                OUTSTREAM << "*** Unable to insert <" << i << ", " << i << "> *** " << __LINE__ << endl;
        }

        result = ht1.remove(to_string(keyToRemove));
        if (!result)
            OUTSTREAM << "*** ERROR: unable to remove key " << keyToRemove << " *** " << __LINE__ << endl << endl;

        result = ht1.get(to_string(keyToRemove));
        if (!result)
            OUTSTREAM << "CORRECT: get() returned false" << endl << endl;
        else
            OUTSTREAM << "*** ERROR: get returned <" << result.has_value() << "> with value <" << result.value() <<
                    "> *** " << __LINE__ << endl << endl;
    } catch (exception& e) {
        OUTSTREAM << "Exception: " << e.what() << endl << endl;
    }
#else
    OUTSTREAM << "*** DID NOT TEST GET REMOVED ***" << endl << endl;
#endif
    // END OF TEST: HASH TABLE GET REMOVED

    // TEST: HASH TABLE GET AFTER REMOVE
    OUTSTREAM << "Searching for a key in the table (" << MAXHASH - 1 << ") after removing a few keys" << endl;
    OUTSTREAM << "--------------------------------------------------------------" << endl;
#ifdef HT_GET_AFTER_REMOVE
    try {
        HashTable ht1;
        std::optional<int> result;

        for (int i = 1; i <= MAXHASH; i++) {
            result = ht1.insert(to_string(i), i);
            if (!result)
                OUTSTREAM << "*** Unable to insert <" << i << ", " << i << "> *** " << __LINE__ << endl;
        }

        // remove 1/4 of the keys
        for (int i = 1; i <= MAXHASH / 4; i++) {
            if (i != MAXHASH - 1) {
                // make sure we don't remove the key we're going to search for
                result = ht1.remove(to_string(i));
                if (!result)
                    OUTSTREAM << "*** Unable to remove key <" << i << "> *** " << __LINE__ << endl;
            }
        }

        result = ht1.get(to_string(MAXHASH - 1));

        if (result && (result.value() == MAXHASH - 1))
            OUTSTREAM << "CORRECT: found entry " << MAXHASH - 1 << endl << endl;
        else
            OUTSTREAM << "*** ERROR: result was <" << result.has_value() << "> and value was <" << result.value() <<
                    "> *** " << __LINE__ << endl << endl;
    } catch (exception& e) {
        OUTSTREAM << "Exception: " << e.what() << endl << endl;
    }
#else
    OUTSTREAM << "*** DID NOT TEST GET AFTER REMOVE ***" << endl << endl;
#endif
    // END OF TEST: HASH TABLE get AFTER REMOVE

    // TESTING: BRACKET OPERATOR
    OUTSTREAM << "Testing operator[]" << endl;
    OUTSTREAM << "==================" << endl << endl;

    OUTSTREAM << "Testing operator[] to get value" << endl;
    OUTSTREAM << "-------------------------------" << endl;
#ifdef HT_BRACKET_OP_GET
    try {
        HashTable ht1;
        int result;

        for (int i = 1; i <= MAXHASH; i++) {
            result = ht1.insert(to_string(i), i);
            if (!result)
                OUTSTREAM << "*** Unable to insert <" << i << ", " << i << "> *** " << __LINE__ << endl;
        }

        result = ht1[to_string(MAXHASH - 1)];

        if (result == MAXHASH - 1)
            OUTSTREAM << "CORRECT: found entry " << MAXHASH - 1 << endl << endl;
        else
            OUTSTREAM << "*** ERROR: result was <" << result << " *** " << __LINE__ << endl << endl;
    } catch (exception& e) {
        OUTSTREAM << "Exception: " << e.what() << endl << endl;
    }
#else
    OUTSTREAM << "*** DID NOT TEST OPERATOR[] GET ***" << endl << endl;
#endif

    OUTSTREAM << "Testing operator[] to set value" << endl;
    OUTSTREAM << "-------------------------------" << endl;
#ifdef HT_BRACKET_OP_GET
    try {
        HashTable ht1;
        int result;

        for (int i = 1; i <= MAXHASH; i++) {
            result = ht1.insert(to_string(i), i);
            if (!result)
                OUTSTREAM << "*** Unable to insert <" << i << ", " << i << "> *** " << __LINE__ << endl;
        }

        ht1[to_string(MAXHASH - 1)] = 42;

        // once we've updated the value, see that the value was successfully updated
#ifdef HT_BRACKET_OP_GET
        result = ht1[to_string(MAXHASH - 1)];
#elifdef  HT_GET
        auto optResult = ht1.get(to_string(MAXHASH - 1));
        if (optResult) result = optResult.value();
#endif

        if (result == 42)
            OUTSTREAM << "CORRECT: found key " << MAXHASH - 1 << " with new value: " << result << endl << endl;
        else
            OUTSTREAM << "ERROR: result was <" << result << " *** " << __LINE__ << endl << endl;
    } catch (exception& e) {
        OUTSTREAM << "Exception: " << e.what() << endl << endl;
    }
#else
    OUTSTREAM << "*** DID NOT TEST OPERATOR[] GET ***" << endl << endl;
#endif

    // TESTING: HashTable::keys()
    OUTSTREAM << "Testing HashTable::keys()" << endl;
    OUTSTREAM << "-------------------------" << endl;
#ifdef HT_KEYS
    try {
        HashTable ht1;
        bool result;

        for (int i = 1; i <= MAXHASH; i++) {
            result = ht1.insert(to_string(i), i);
            if (!result)
                OUTSTREAM << "*** Unable to insert <" << i << ", " << i << "> *** " << __LINE__ << endl;
        }

        auto keys = ht1.keys();
        bool anyErrors = false;
        for (int i = 1; i <= MAXHASH; i++) {
            auto found = std::find(keys.begin(), keys.end(), to_string(i));
            if (found == keys.end()) {
                anyErrors = true;
                OUTSTREAM << "*** Key <" << i << "> was not found in vector *** " << __LINE__ << endl;
            }
        }
        if (!anyErrors && keys.size() == MAXHASH) {
            OUTSTREAM << "CORRECT: all keys successfully returned" << endl << endl;
        } else {
            OUTSTREAM << "ERROR: either a key missing from result or number of keys doesn't match " << endl;
            OUTSTREAM << "Returned number of keys: " << keys.size() << endl;
            OUTSTREAM << "Expected number of keys: " << MAXHASH << " *** " << __LINE__ << endl << endl;
        }
    } catch (exception& e) {
        OUTSTREAM << "Exception: " << e.what() << endl << endl;
    }
#else
    OUTSTREAM << "*** DID NOT TEST KEYS ***" << endl << endl;
#endif


    // TESTING: HashTable::alpha()
    OUTSTREAM << "Testing HashTable::alpha()" << endl;
    OUTSTREAM << "--------------------------" << endl;
#ifdef HT_ALPHA
    try {
        HashTable ht1;

        if (ht1.alpha() == 0) {
            OUTSTREAM << "CORRECT: alpha for empty table is zero" << endl << endl;
        } else {
            OUTSTREAM << "ERROR: alpha for empty table should be zero *** " << __LINE__ << endl << endl;
        }

        bool result;

        for (int i = 1; i <= MAXHASH / 2; i++) {
            result = ht1.insert(to_string(i), i);
            if (!result)
                OUTSTREAM << "*** Unable to insert <" << i << ", " << i << "> *** " << __LINE__ << endl;
        }
        auto alpha = ht1.alpha();
        OUTSTREAM << "alpha is          " << alpha << endl;
        OUTSTREAM << "alpha should be   " << static_cast<double>(MAXHASH) / 2 / MAXHASH << endl << endl;
    } catch (exception& e) {
        OUTSTREAM << "Exception: " << e.what() << endl << endl;
    }
#else
    OUTSTREAM << "*** DID NOT TEST ALPHA ***" << endl << endl;
#endif

    // TESTING: HashTable::capacity()
    OUTSTREAM << "Testing HashTable::capacity()" << endl;
    OUTSTREAM << "-----------------------------" << endl;
#ifdef HT_CAPACITY
    try {
        HashTable ht1;
        bool result;

        for (int i = 1; i <= MAXHASH / 2; i++) {
            result = ht1.insert(to_string(i), i);
            if (!result)
                OUTSTREAM << "*** Unable to insert <" << i << ", " << i << "> *** " << __LINE__ << endl;
        }

        if (ht1.capacity() == MAXHASH) {
            OUTSTREAM << "CORRECT";
        } else {
            OUTSTREAM << "ERROR";
        }
        OUTSTREAM << ": capacity is " << ht1.capacity() << endl << endl;
        OUTSTREAM << "Adding more so hash table capacity changes" << endl;
        OUTSTREAM << "------------------------------------------" << endl;

        for (int i = (MAXHASH / 2) + 1; i <= (MAXHASH * 2) - 1; i++) {
            result = ht1.insert(to_string(i), i);
            if (!result)
                OUTSTREAM << "*** Unable to insert <" << i << ", " << i << "> *** " << __LINE__ << endl;
        }

        OUTSTREAM << "New hash table capacity:  " << ht1.capacity() << endl;
        OUTSTREAM << "Capacity might be:        " << MAXHASH * 2 << endl << endl;
    } catch (exception& e) {
        OUTSTREAM << "Exception: " << e.what() << endl << endl;
    }
#else
    OUTSTREAM << "*** DID NOT TEST CAPACITY ***" << endl << endl;
#endif


    // TESTING: HashTable::size()
    OUTSTREAM << "Testing HashTable::size()" << endl;
    OUTSTREAM << "-------------------------" << endl;
#ifdef HT_SIZE
    try {
        HashTable ht1;
        bool result;
        for (int i = 1; i <= MAXHASH; i++) {
            result = ht1.insert(to_string(i), i);
            if (!result)
                OUTSTREAM << "*** Unable to insert <" << i << ", " << i << "> *** " << __LINE__ << endl;
            else if (ht1.size() != i) {
                OUTSTREAM << "ERROR: size is " << ht1.size() << endl;
                OUTSTREAM << "ERROR: size should be " << i << " *** " << __LINE__ << endl;
            }
        }
        if (ht1.size() == MAXHASH) {
            OUTSTREAM << "CORRECT: size is " << ht1.size() << endl << endl;
        } else {
            OUTSTREAM << "ERROR: size is " << ht1.size() << " should be " << MAXHASH << " *** " << __LINE__ << endl <<
                    endl;
        }

        OUTSTREAM << "Adding more so hash table size changes" << endl;
        OUTSTREAM << "--------------------------------------" << endl;

        for (int i = MAXHASH + 1; i <= (MAXHASH * 2) - 1; i++) {
            result = ht1.insert(to_string(i), i);
            if (!result)
                OUTSTREAM << "*** Unable to insert <" << i << ", " << i << "> *** " << __LINE__ << endl;
            else if (ht1.size() != i) {
                OUTSTREAM << "ERROR: size is        " << ht1.size() << endl;
                OUTSTREAM << "ERROR: size should be " << i << " *** " << __LINE__ << endl;
            }
        }
        if (ht1.size() == (MAXHASH * 2) - 1) {
            OUTSTREAM << "CORRECT"": after adding more size is " << ht1.size() << endl << endl;
        } else {
            OUTSTREAM << "ERROR"": after adding more size is " << ht1.size() << " *** " << __LINE__ << endl << endl;
        }
    } catch (exception& e) {
        OUTSTREAM << "Exception: " << e.what() << endl << endl;
    }
#else
    OUTSTREAM << "*** DID NOT TEST SIZE ***" << endl << endl;
#endif
}
#endif // RUN_TESTS
