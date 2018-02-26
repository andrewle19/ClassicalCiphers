//
//  RowTransposition.cpp
//  ClassicalCiphers
//
//  Created by Andrew Le on 2/25/18.
//  Copyright © 2018 Andrew Le. All rights reserved.
//

#include "RowTransposition.h"
#include <iostream>
#include <cmath>
using namespace std;

RowTransposition::RowTransposition(){};



// Inititializes the row trans matrix dynamically
// plaintext- string plain text
void RowTransposition::initMatrix(const string &plainText) {
    
    // calculate how many rows the matrix needs

    row = round(double(plainText.length())/double(maxKey));

    rowTransMatrix = new char *[row]; // dynamically allocate the rows
    
    // dynamically allocate the columns
    for(int i = 0; i < row; i++){
        rowTransMatrix[i] = new char[maxKey];
    }
    
    // FILL matrix with xs
    for(int i = 0; i < row; i++){
        for(int j = 0; j < maxKey; j++){
            rowTransMatrix[i][j] = 'x';
            
        }
    }
    
    // insert plaintext into the matrix
    int count = 0;
    // cycle through the whole plaintext
    while(count < plainText.length()) {
        for(int i = 0; i < row; i++){
            for(int j = 0; j < maxKey; j++){
                // check if alpha before adding to matrix
                if(isalpha(plainText[count])) {
                    rowTransMatrix[i][j] = plainText[count];
                    count++;
                }
            }
        }
   }
    
}


// initalizes the row Trans matrix with cipher text dyanamically
// ciphertext-cipher text
void RowTransposition::initDecryptionMatrix(const string &ciphertext){
    
    // calculate the row needed for matrix
    row = round(double(ciphertext.length()/double(maxKey)));
    int count = 0;
    // insert the cipher text into the matrix by cycling through it
    // insert column by column
    while(count < ciphertext.length()){
        for(int i = 0; i < key.size(); i++) {
            for(int j = 0; j < row; j++){
                if(isalpha(ciphertext[count])){
                    rowTransMatrix[j][key.at(i)-1] = ciphertext[count];
                    count++;
                }
            }
        }
    }
}

// set the key and finds the max key for the cipher
bool RowTransposition::setKey(const string &rkey){
   
    if(rkey.empty()){
        return false;
    }
    
    
    // put key into the key vertex
    for(int i = 0; i < rkey.length(); i++){
        if(rkey[i] != ' ') {
            key.push_back(rkey[i]-'0');
        }
    }
    
    // AlSO find out the max key
    maxKey = key.at(0);
    for(int i = 0; i < key.size(); i++ ){
        if(key.at(i) > maxKey){
            maxKey = key.at(i);
        }
    }
    
    
    return true;
};


// Encrypts the plain text and returns ciphertext
// INPUT: plaintext
// OUTPUT: ciphertext
string RowTransposition::encrypt(const string &plaintext){
    initMatrix(plaintext); // inititalize the matrix
    string ciphertext;
    
    // loops through the matrix by using the key to go column by column to create cipher text
    for(int j = 0; j < key.size(); j++){
        for(int i = 0; i < row; i++){
            ciphertext += rowTransMatrix[i][key.at(j)-1];
        }
    }
   
    return ciphertext;
};

// decrypts the cipher text and returns plain text
// INPUT: ciphertext
// OUTPUT: plaintext
string RowTransposition::decrypt(const string &ciphertext){
    string plaintext;
    initDecryptionMatrix(ciphertext);
    
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < maxKey; j++){
            plaintext += rowTransMatrix[i][j];
        }
    }
    return plaintext;
};

// free up the memory used dyanamically allocated
void RowTransposition::freeMatrix() {
    for(int i = 0; i < row; i++){
        delete [] rowTransMatrix[i];
    }
    delete [] rowTransMatrix;
};

