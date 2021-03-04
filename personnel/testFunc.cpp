#include "hash.h"
#include "person.h"

#include <iostream>

using namespace std;

int main()
{
    Hash *h;
    h->insert("G123", person("chow", "chow", "G123", "F123"));
    h->insert("G456", person("lee", "kok", "G456", "F456"));
    cout << *h;
}