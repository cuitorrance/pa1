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

  cout << "-----------------------------------" << endl;
  cout << "COUNTING COLLISIONS: " << endl;
  
  //generate first hash function
  vector< vector<int> > hf1 = generateFirstHash(n);
  
  
  //count # of collisions for each of the first level buckets
  vector<int> collisions = countCollisions( n, keys, hf1);

  //PRINT OUT COLLISIONS
  cout << "COLLISIONS: "<< endl;
  for ( int i= 0; i < collisions.size(); i++){
    cout << collisions[i]  << " collsion at index " << i << endl;
  }


  //PRINT OUT FIRST HASH FUNCTION
  cout << "--------------------------------------" << endl;
  cout << "FIRST LEVEL HASH: " <<endl;
  cout << "HF1:" << endl;
  for ( vector<int> i : hf1){
    for ( int j: i){
      cout << j;
    }
    cout << endl;
  }
  
  //intialize first level of hashtable
  vNode empty;
  vector< vNode > v(collisions.size(), empty); 
  this->hashTable = v;

  cout << "------------------------------------" << endl;
  cout << "SECOND LEVEL HASH:" << endl;
  
  //push back number of second buckets
  for (int i = 0; i < collisions.size(); i++){
    this->hashTable[i].hashFunction = generateSecondHash(collisions[i]);

    for ( int j = 0; j < pow( 2 , (  pow(2, ceil(log2(pow(collisions[i], 2))))) ); j++){
      this->hashTable[i].hashTable2.push_back("empty");
    }
      
    //PRINT OUT 2ND LEVEL HASH
    cout << "HF2 for index " << i << ": " << endl;
    for ( vector<int> x : this->hashTable[i].hashFunction ){
      for ( int y: x){
      cout << y;
      }
      cout<< endl;
    }
    cout << endl;
  
  }

  
  cout << "-------------------------------------" << endl;
  cout << "ELEMENTS: " << endl;
  //go through keys
  for ( int i = 0; i < n; i++){
    string s = keys[i];

    //generate key
    vector<int> key = generateKey(s);

    //find first index
    int firstIndex = getIndex(hf1, key);

    int secondIndex = 0;
    if (collisions[firstIndex] != 0){
      //find second index
      secondIndex = getIndex(this->hashTable[firstIndex].hashFunction ,key);
    }

    //testing
    cout << keys[i] << ": inserted at (" << firstIndex << "," << secondIndex << ")"<< endl;

    cout << "KEY: ";
    for ( int i: key){
      cout << i;
    }
    cout << endl << "------------------" << endl;
    
    //insert
    this->hashTable[firstIndex].hashTable2.at(secondIndex) = s;
    
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

    int rows = pow(2, ceil(log2(pow(c, 2))));
    int cols = 64;

    vector< vector<int> > hf(rows, vector<int>(cols));
    
    //srand(time(NULL));
    for ( unsigned int i = 0; i < rows; i++){
      for ( unsigned int j = 0; j < cols; j++){
	hf[i][j] = ( rand() % 2 );
      }
    }    
    return hf; 
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
  vector<int> v;

  for (unsigned i = 0; i < binaryStr.size(); i++){
    if (binaryStr[i] == '0'){
      v.push_back(0);
    }else if (binaryStr[i] == '1'){
      v.push_back(1);
    }
  }

  return v;
  


}
//count number of collisions at each level of first hash                                                                                                                         
vector<int> Dictionary::countCollisions( int n , string *keys, vector< vector<int> > firstHash){

  //make vector to keep count of collisions
  vector<int> collisions(pow(2, ceil(log2(n)) ));
  for ( unsigned int i = 0; i < pow(2, ceil(log2(n))); i++){
    collisions[i] = 0;
  }

  //cout << "Counting collisions at first level..." << endl;
  //count collisions
  for (unsigned int i = 0; i < n; i++){
    vector<int> key = generateKey( keys[i] );
    int index = getIndex( firstHash, key);
    cout << keys[i] << " mapped to index " << index << endl;
    collisions[index] +=1;
  }
  
  //correct collision count
  int i = 0;
  for (int n : collisions){
    if ( n != 0){
      collisions[i] -= 1;
    }
    i++;
  }

  return collisions;
}

//get index by multiplying hashfunction and key
int Dictionary::getIndex( vector< vector<int> > a, vector<int> b){

  //if (a[0].size() != b.size()){
  //cout << "MATRIX ERROR" << endl;
  //}
  //cout << "hf size = " << a.size() << "x" << a[0].size() << endl;
  //cout << "key size = " << b.size() << "x" << 1 << endl;
  
  vector<int> result(a.size());

  for ( unsigned int i = 0; i < a.size(); i++){
      int rowSum = 0;
      for ( unsigned int j = 0; j < a[i].size(); j++){
	//cout << rowSum << endl;
        rowSum += ( a[i][j] * b[j] );
      }
      result.push_back(rowSum % 2);
      rowSum = 0;
    }

    //convert binary vector to decimal value

    //cout << "CONVERTING BINARY" << endl;
    int sumValue = 0;
    for ( unsigned int i = 0, j = result.size() ; i < result.size(); i++){
      //cout << result[i] << "*" << "(2^" << j-1 << ")" << endl;
      sumValue += (pow(2, j-1) * result[i]);
      j--;
    }
    return sumValue;
}

//print hashtable
void Dictionary::printDict(){
  for ( unsigned int i = 0; this->hashTable.size();i++){
    for ( unsigned int j = 0; this->hashTable[i].hashTable2.size() ;j++){
      cout <<  hashTable[i].hashTable2[j] << "|";
    }
    cout << endl;
  }
}
