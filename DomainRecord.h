#ifndef DOMAIN_RECORD_H
#define DOMAIN_RECORD_H

#include <string>
using namespace std;

// Structure for each domain record in the AVL tree
struct DomainRecord {
    string domain;
    string rule; // "ALLOW" or "BLOCK"
};

#endif
