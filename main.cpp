#include "include/Trie.h"
#include "include/HashMap.h"
#include "include/AVLTree.h"
#include <iostream>
using namespace std;

int main() {
    ReversedTrie trie;
    HashMap cache;
    AVLTree tree;

    trie.insert("google.com", "ALLOW");
    trie.insert("mail.google.com", "BLOCK");
    trie.insert("onion", "BLOCK");

    string domain = "mail.google.com";
    string result = trie.search(domain);
    cache.put(domain, result);
    tree.insert({domain, result});
    cout << "[Lookup] " << domain << " -> " << result << endl;

    domain = "news.google.com";
    result = trie.search(domain);
    cache.put(domain, result);
    tree.insert({domain, result});
    cout << "[Lookup] " << domain << " -> " << result << endl;

    cout << endl;
    tree.printInorder();
}
