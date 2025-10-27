#ifndef TRIE_H
#define TRIE_H

#include <string>
#include <vector>
using namespace std;

// Node in the Reversed Trie
class TrieNode {
public:
    struct Child {
        string label;   // part of domain ("com", "google", etc.)
        TrieNode* next;
    };

    vector<Child> children;
    bool isEnd;
    string rule; // "ALLOW" or "BLOCK"

    TrieNode();
    TrieNode* findChild(const string& label);
    TrieNode* addChild(const string& label);
};

// Reversed Trie class
class ReversedTrie {
private:
    TrieNode* root;
    vector<string> splitAndReverse(const string& domain);

public:
    ReversedTrie();
    void insert(const string& domain, const string& rule);
    string search(const string& domain);
};

#endif
