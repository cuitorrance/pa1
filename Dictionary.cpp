// Implement Dictionary methods.
#include "Dictionary.h"
#include <string>
#include <iostream>
#include <bitset>
#include <math.h>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>  
#include <time.h>

using namespace std;

void Dictionary::bulkInsert(int n, string *keys) {
  
  //generate first hash function
  vector< vector<int> > hf1 = generateFirstHash(n);
  
  //count collisions for each of the first level buckets
  vector<int> collisions = countCollisions( n, keys, hf1);

  //creates second level hash functions 
  addSecondHash( n, collisions);

  //intialize both levels of hashtable
  for ( unsigned int i = 0 ; i < pow(2, log2(n) ); i++){
    for ( unsigned int j = 0; j < pow(2, log2( pow(collisions[i], 2) )); j++){
      hashTable[i].hashTable2[j] = "empty";
    }
  }
  
  //go through keys
  for ( int i = 0; i < n; i++){
    string s = keys[i];

    //generate key
    vector<int> key = generateKey(s);

    //find first index
    int firstIndex = getIndex(hf1, key);

    //find second index
    int secondIndex = getIndex(hashTable[firstIndex].hashFunction ,key);

    //insert
    hashTable[firstIndex].hashTable2[secondIndex] = s;
    
  }
  
}

void Dictionary::insert(string key) {

  
}

void Dictionary::remove(string key) {

}

bool Dictionary::find(string key) {
    return false;
}

//generate first hash function                                                                                                                                                   
vector< vector<int> > Dictionary::generateFirstHash( int n){

    //generate random matrix of ceiling (log_2(m) x 64)                                                                                                                            
    int rows = ceil( log2(n) );
    int cols = 64;

    vector< vector<int> > hf (rows, vector<int>(cols) );
    
    srand(time(NULL));
    for ( unsigned int i = 0; i < rows; i++){
      for ( unsigned int j = 0; j < cols; j++){
	hf[i][j] = ( rand() % 2 );
      }
    }
    
    return hf; 
}

//generate second hash function based on collisions                                                                                                                              
vector< vector<int> > Dictionary::generateSecondHash( int c){
  
    //generate random matrix of ceiling (log_2(m) x 64)                                                                                                                            
    int rows = ceil( log2( pow(c, 2) ) );
    int cols = 64;

    vector< vector<int> > hf(rows, vector<int>(cols));
    
    srand(time(NULL));
    for ( unsigned int i = 0; i < rows; i++){
      for ( unsigned int j = 0; j < cols; j++){
	hf[i][j] = ( rand() % 2 );
      }
    }    
    return hf; 
}

//creates second level hash functions for each first level row
void Dictionary::addSecondHash(int n, vector<int> collisions){
  for (unsigned int i = 0; i < pow( 2, log2(n) );i++){
    hashTable[i].hashFunction = generateSecondHash(collisions[i]);
  }
}

//generate key from string                                                                                                                                                       
vector<int> Dictionary::generateKey( const string &s){

  //get last eight characters                                                                                                                                                      
  string lastEight = s.substr( s.length()-8 , s.length());

  //convert to binary string                                                                                                                                                         
  string binaryStr = "";
  for (char& _char : lastEight) {
        binaryStr += bitset<8>(_char).to_string();
  }

  //put string into vector                                                                                                                                                           
  vector<int> v(binaryStr.size());

  for (unsigned i = 0; i < binaryStr.size(); i++){
    v.push_back( binaryStr[i] - '0' );
  }

  return v;
  


}
//count number of collisions at each level of first hash                                                                                                                         
vector<int> Dictionary::countCollisions( int n , string *keys, vector< vector<int> > firstHash){

  //make vector to keep count of collisions
  vector<int> collisions(pow(2, log2(n)));
  for ( unsigned int i = 0; i < pow(2, log2(n)); i++){
    collisions[i] = 0;
  }

  //count collisions
  for (unsigned int i = 0; i < n; i++){
    vector<int> key = generateKey( keys[i] );
    int index = getIndex( firstHash, key);
    collisions[index] += 1;
  }

  return collisions;
}

//get index by multiplying hashfunction and key
int Dictionary::getIndex( vector< vector<int> > a, vector<int> b){
  
  vector<int> result(a.size());
  
  for ( unsigned int i = 0; i < a.size(); i++){
      int rowSum = 0;
      for ( unsigned int j = 0; j < a[i].size(); j++){
        rowSum += ( a[i][j] * b[j] );
      }
      result.push_back(rowSum % 2);
      rowSum = 0;
    }

    //convert binary vector to decimal value                                                                                                                                        
    int sumValue = 0;
    for ( unsigned int i = 0, j = a.size() ; i < a.size(); i++){
      sumValue += (pow(2, j-1) * result[i]);
      j--;
    }

    return sumValue;
}

//print hashtable
void Dictionary::printDict(){
  for ( unsigned int i = 0; i < hashTable.size();i++){
    for ( unsigned int j = 0; j < hashTable[i].hashTable2.size();j++){
      cout << hashTable[i].hashTable2[j] << " " ;
    }
    cout << endl;
  }

}
