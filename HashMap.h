#ifndef HASH_MAP_H
#define HASH_MAP_H

#include <string>
#include <vector>
using namespace std;

// Simple hashmap using vectors (no STL maps)
class HashMap {
private:
    vector<string> keys;
    vector<string> values;

public:
    bool contains(const string& key);
    string get(const string& key);
    void put(const string& key, const string& value);
};

#endif
