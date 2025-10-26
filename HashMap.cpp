#include "../include/HashMap.h"  
#include <iostream>
using namespace std;

// Function: checks if the key exists in the hash map
bool HashMap::contains(const string& key) {
    // Loop through all stored keys
    for (int i = 0; i < (int)keys.size(); i++) {
        // If the key at index i matches the given key, return true
        if (keys[i] == key)
            return true;
    }
    // If the loop finishes without finding the key, return false
    return false;
}

// Function: returns the value associated with a given key
string HashMap::get(const string& key) {
    // Loop through all keys to find a match
    for (int i = 0; i < (int)keys.size(); i++) {
        if (keys[i] == key)
            // Return the corresponding value from the same index
                return values[i];
    }
    // If the key is not found, return an empty string
    return "";
}

// Function: inserts or updates a key-value pair
void HashMap::put(const string& key, const string& value) {
    // Loop through existing keys to check if the key already exists
    for (int i = 0; i < (int)keys.size(); i++) {
        if (keys[i] == key) {
            // If key exists, update its value and return (no duplicate keys)
            values[i] = value;
            return;
        }
    }
    // If key does not exist, add it at the end of the vectors
    keys.push_back(key);
    values.push_back(value);
}
