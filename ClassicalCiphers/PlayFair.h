//
//  PlayFair.hpp
//  ClassicalCiphers
//
//  Created by Andrew Le on 2/21/18.
//  Copyright © 2018 Andrew Le. All rights reserved.
//

#ifndef PLAYFAIR_H
#define PLAYFAIR_H

#include <string>
#include "CipherInterface.h"
using namespace std;

// Struct to store the matrix location of the plain text
struct matrixLocation{
    int row;
    int col;
};

class PlayFair : public CipherInterface {
    // private members:
private:
    string key;
    matrixLocation one;
    matrixLocation two;
    int setsize;
    int setcount;
    char playfairMatrix[5][5]; // matrix of he playfair cipher
    char playfairset[25]; // set that holds unique characters
public:
    // default constructor of Ceasar
    PlayFair();
    
    /**
     * Sets the key to use
     * @param pkey - the key to use
     * @return - True if the key is valid and False otherwise
     */
    bool setKey(string pkey);
    
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
    
    void initMatrix();
    
    // Helper function for main encryption function
    // Input: first letter: first letter to search for, secondletter; 2nd letter to search for
    // OUTPUT: new cipher text for the 2 evaluated characters
    string encryptHelper(char firstletter, char secondletter);
    
    // Helper function for main decrypt function
    // Input: firstletter- first letter to search, secondletter: 2nd letter to search for
    // OUTPUT: new plain text for 2 evaluated characters
    string decryptHelper(char firstletter, char secondletter);
    
    
    string preparePlainText(const string &plaintext);
    
    /* The protected members */
protected:
    
};



#endif /* PlayFair_h */
