// Implement Dictionary methods.
#include "Dictionary.h"
#include <string>
using namespace std;

void Dictionary::bulkInsert(int n, string *keys) {
  
}

void Dictionary::insert(string key) {

  long long index = hashOne(key);

  //collision aka vector is not empty
  if ( this.hashTable.at(index).empty() ){

    //hash again
    long long indexTwo = hashTwo(key);
    this.hashTable.at(index).at(indexTwo) = key; 
    
  //no collision aka vector is empty
  }else{
    
    //insert at first position of vector
    this.hashTable.at(index).at(0) = key;
  }

  
}

void Dictionary::remove(string key) {
// TODO:: Write this.

}

bool Dictionary::find(string key) {
// TODO:: Write this.

    return false;
}

long long hashOne(string const &s){
    long long hash_value = 0;
    
    return hash_value;
}

long long hashTwo(string const &s){
  long long hash_value = 0;

  return hash_value;
}
