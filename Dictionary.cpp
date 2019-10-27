// Implement Dictionary methods.
#include "Dictionary.h"
#include <string>
#include <iostream>
#include <bitset>
#include <math.h>
#include <cmath>
using namespace std;

void Dictionary::bulkInsert(int n, string *keys) {

  //size of first level hash
  int m = pow(2, n);

  //go through keys 
  for (int i = 0; i < n; i++){
    //first level hash
    int firstHash = hashOne(m, *(keys+i) );
    
    
  }
  
  
}

void Dictionary::insert(string key) {

  
}

void Dictionary::remove(string key) {
// TODO:: Write this.

}

bool Dictionary::find(string key) {
// TODO:: Write this.

    return false;
}

int Dictionary::hashOne(int m, const string &s){
    int hash_value = 0;
    int key = getBinaryASCII(s);

    //generate random matrix of ceiling (log_2(m) x 64)
    int rows = ceil( log2(m) * 64 );
    int cols = 64;
    int hFunction [rows][cols];  
    for ( int i = 0; i < rows; i++){
      for ( int j = 0; j < cols; j++){
	
      }
    }
    

    
    return hash_value;
}

int Dictionary::hashTwo(const string &s){
    long long int hash_value = 0;
    
    return hash_value;

}
void Dictionary::printDict(){

}

int Dictionary::getBinaryASCII( const string &s){

  //get last eight characters
  string lastEight = s.substr( s.length()-8 , s.length());

  //convert to binary string
  string binaryStr = "";
  for (char& _char : lastEight) {
	binaryStr +=bitset<8>(_char).to_string();
  }
  
  return stoi(binaryStr);
}

