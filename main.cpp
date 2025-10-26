#include "include/Trie.h"      
#include "include/HashMap.h"   
#include "include/AVLTree.h"   
#include <iostream>
using namespace std;

int main() {
    // Create instances of each data structure
    ReversedTrie trie;  // domain classification (ALLOW/BLOCK)
    HashMap cache;      // caching domain lookup results
    AVLTree tree;       // storing results in sorted order

    // Step 1: Insert domain rules into the Trie
    trie.insert("google.com", "ALLOW");       
    trie.insert("mail.google.com", "BLOCK");  
    trie.insert("onion", "BLOCK");            

    // Step 2: Perform first lookup
    string domain = "mail.google.com";    
    string result = trie.search(domain);  // Search the Trie for this domain’s rule
    cache.put(domain, result);            // store result in cache (HashMap)
    tree.insert({domain, result});        // Insert (domain, result) pair into AVL tree

    
    cout << "[Lookup] " << domain << " -> " << result << endl;

    // Step 3: Perform second lookup
    domain = "news.google.com";           
    result = trie.search(domain);         // Search again in the Trie
    cache.put(domain, result);            // store result in cache 
    tree.insert({domain, result});        // Insert (domain, result) pair into AVL tree
    cout << "[Lookup] " << domain << " -> " << result << endl;

    cout << endl;

    // Step 4: Print all entries stored in AVL tree in sorted order
    tree.printInorder();

}
