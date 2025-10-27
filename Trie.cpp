#include "../include/Trie.h"
#include <iostream>
using namespace std;

TrieNode::TrieNode() {
    isEnd = false;
    rule = "";
}

TrieNode* TrieNode::findChild(const string& label) {
    for (int i = 0; i < (int)children.size(); i++) {
        if (children[i].label == label)
            return children[i].next;
    }
    return NULL;
}

TrieNode* TrieNode::addChild(const string& label) {
    TrieNode* newNode = new TrieNode();
    Child c;
    c.label = label;
    c.next = newNode;
    children.push_back(c);
    return newNode;
}

ReversedTrie::ReversedTrie() {
    root = new TrieNode();
}

// Split string by '.' and reverse manually
vector<string> ReversedTrie::splitAndReverse(const string& domain) {
    vector<string> parts;
    string temp = "";
    for (int i = 0; i <= (int)domain.size(); i++) {
        if (i == (int)domain.size() || domain[i] == '.') {
            parts.push_back(temp);
            temp = "";
        } else temp += domain[i];
    }

    // reverse manually
    for (int i = 0; i < (int)parts.size() / 2; i++) {
        string tmp = parts[i];
        parts[i] = parts[parts.size() - 1 - i];
        parts[parts.size() - 1 - i] = tmp;
    }
    return parts;
}

void ReversedTrie::insert(const string& domain, const string& rule) {
    vector<string> parts = splitAndReverse(domain);
    TrieNode* node = root;

    for (int i = 0; i < (int)parts.size(); i++) {
        TrieNode* next = node->findChild(parts[i]);
        if (!next) next = node->addChild(parts[i]);
        node = next;
        if (node->rule == "BLOCK") return;
    }

    node->isEnd = true;
    node->rule = rule;
}

string ReversedTrie::search(const string& domain) {
    vector<string> parts = splitAndReverse(domain);
    TrieNode* node = root;
    string lastRule = "BLOCK";

    for (int i = 0; i < (int)parts.size(); i++) {
        TrieNode* next = node->findChild(parts[i]);
        if (!next) break;
        node = next;
        if (node->rule == "BLOCK") return "BLOCK";
        if (node->rule == "ALLOW") lastRule = "ALLOW";
    }
    return lastRule;
}
