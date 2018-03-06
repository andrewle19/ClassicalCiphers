//
//  Hill.hpp
//  ClassicalCiphers
//
//  Created by Andrew Le on 3/4/18.
//  Copyright © 2018 Andrew Le. All rights reserved.
//

#ifndef HILL_H
#define HILL_H

#include <string>
#include <iostream>
#include <vector>
#include "CipherInterface.h"
using namespace std;

class Hill : public CipherInterface {
    // private members
private:
    int key[2][2];
public:
    // default constructor of Ceasar
    Hill();

    /**
     * Sets the key to use
     * @param hkey - the key to use
     * @return - True if the key is valid and False otherwise
     */
    bool setKey(const string &hkey);

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

    // makes sure the plain text is even
    string preparePlainText(const string &plaintext);

    // take the inverse of the key for Decryption
    void inverseKey();

    // calculate determinate for decryption
    int calculateDeterminateInverse();
    /* The protected members */
protected:

};

#endif /* Hill_hpp */
