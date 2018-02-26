//
//  RowTransposition.hpp
//  ClassicalCiphers
//
//  Created by Andrew Le on 2/25/18.
//  Copyright © 2018 Andrew Le. All rights reserved.
//

#ifndef ROWTRANSPOSITION_H
#define ROWTRANSPOSITION_H


#include <string>
#include "CipherInterface.h"
#include <vector>
#include <stdlib.h>
using namespace std;

class RowTransposition : public CipherInterface {
    // private members
private:
    vector<int> key;
    char **rowTransMatrix;
    int maxKey;
    int row;
public:
    // default constructor of Ceasar
    RowTransposition();
    
    /**
     * Sets the key to use
     * @param rkey - the key to use
     * @return - True if the key is valid and False otherwise
     */
    bool setKey(const string &rkey);
    
    /**
     * Encrypts a plaintext string
     * @param plaintext - the plaintext string
     * @return - the encrypted ciphertext string
     */
    string encrypt(const string &plaintext);
    
    /**
     * Decrypts a string of ciphertext
     * @param ciphertext - the ciphertext
     * @return - the plaintext
     */
    string decrypt(const string &ciphertext);
    
    // initializes the Row Trans Matrix with plaintext
    void initMatrix(const string &plainText);
    
    // initializes the row trans matrix with ciphertext
    void initDecryptionMatrix(const string &ciphertext);
    
    // Free up memory used from matrix
    void freeMatrix();
    
    /* The protected members */
protected:
    
};


#endif /* RowTransposition_hpp */
