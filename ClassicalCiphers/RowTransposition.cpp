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

void RowTransposition::initMatrix(const string &plainText) {
    row = round(double(plainText.length())/double(maxKey));
    rowTransMatrix = new char *[row];
    for(int i = 0; i < row; i++){
        rowTransMatrix[i] = new char[maxKey];
    }
    for(int i = 0; i < row; i++){
        for(int j = 0; j < maxKey; j++){
            rowTransMatrix[i][j] = 'x';
            
        }
    }
    
    int count = 0;
    while(count < plainText.length()) {
        for(int i = 0; i < row; i++){
            for(int j = 0; j < maxKey; j++){
                if(isalpha(plainText[count])) {
                    rowTransMatrix[i][j] = plainText[count];
                    count++;
                }
            }
        }
   }
    
}

void RowTransposition::initDecryptionMatrix(const string &ciphertext){
    row = round(double(ciphertext.length()/double(maxKey)));
    int count = 0;
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


bool RowTransposition::setKey(const string &rkey){
    
    for(int i = 0; i < rkey.length(); i++){
        if(rkey[i] != ' ') {
            key.push_back(rkey[i]-'0');
        }
    }
    maxKey = key.at(0);
    for(int i = 0; i < key.size(); i++ ){
        if(key.at(i) > maxKey){
            maxKey = key.at(i);
        }
    }
    
    
    return false;
};



string RowTransposition::encrypt(const string &plaintext){
    initMatrix(plaintext); // inititalize the matrix
    string ciphertext;
    
    for(int j = 0; j < key.size(); j++){
        for(int i = 0; i < row; i++){
            ciphertext += rowTransMatrix[i][key.at(j)-1];
        }
    }
   
    return ciphertext;
};

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
