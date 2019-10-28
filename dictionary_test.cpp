#include "Dictionary.h"
#include <iostream>
using namespace std;

// Driver program
int main()
{
    // Initialize the dictionary.
    Dictionary dict;

    // BulkInsert the keys into the dictionary.
    string strs[] = {"Fred Astaire", "Lauren Bacall", "Brigitte Bardot", "John Belushi", "Ingmar Bergman"};
    int n = 5;

     string strs2[] =
    {
        "Fred Astaire",
        "Lauren Bacall",
        "Brigitte Bardot",
        "Humphrey Bogart",
        "Marlon Brando",
        "Richard Burton",
        "James Cagney",
        "Gary Cooper",
        "Bette Davis",
        "Doris Day",
        "Olivia de Havilland",
        "James Dean"
    };
       int n2 = 12;
    dict.bulkInsert(n2, strs2);
    
    // Insert "Humphrey Bogart" into the dictionary.
    //dict.insert("Humphrey Bogart");

    // Remove "Lauren Bacall" from the dictionary.
    //dict.remove("Lauren Bacall");

    // Find "Fred Astaire" in the dictionary.
    //cout << dict.find("Fred Astaire") << endl;

    // Find "Lauren Bacall" in the dictionary.
    //cout << dict.find("Lauren Bacall") << endl;

    //cout << "----------------" << endl << "HASH TABLE" << endl;
    
    //dict.printDict();
    
    return 0;
}
