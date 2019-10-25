// Implement Dictionary methods.
#include "Dictionary.h"
#include <string>
#include <iostream>
using namespace std;

void Dictionary::bulkInsert(int n, string *keys) {
  for ( int i = 0; i < n; i++){
    linearInsert( *(keys + i) );
  }
}

void Dictionary::insert(string key) {

  long long int index = hashOne(key);

  //collision aka vector is not empty
  if ( this->hashTable.at(index).empty() ){
    
    //hash again
    long long int indexTwo = hashTwo(key);
    this->hashTable.at(index).at(indexTwo) = key; 
    
  //no collision aka vector is empty
  }else{
    
    //insert at first position of vector
    this->hashTable.at(index).at(0) = key;
  }
}

void Dictionary::linearInsert(string key){
  
}

void Dictionary::remove(string key) {
// TODO:: Write this.

}

bool Dictionary::find(string key) {
// TODO:: Write this.

    return false;
}

long long int Dictionary::hashOne(const string &s){
    long long int hash_value = 0;
    
    return hash_value;
}

long long int Dictionary::hashTwo(const string &s){
    long long int hash_value = 0;

    return hash_value;

}
void Dictionary::printDict(){
  for ( vector< vector<string> >::size_type i = 0; i < this->hashTable.size(); i++){
    for (vector< vector<string> >::size_type j = 0; j < this->hashTable[i].size(); j++){
      cout << this->hashTable[i][j] << " - ";
    }
    cout << endl;
  }
}
