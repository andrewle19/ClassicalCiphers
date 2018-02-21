//
//  Ceasar.hpp
//  ClassicalCiphers
//
//  Created by Andrew Le on 2/21/18.
//  Copyright © 2018 Andrew Le. All rights reserved.
//

#ifndef CEASAR_H
#define CEASAR_H

#include <string>
#include "CipherInterface.h"
using namespace std;

class Ceasar : public CipherInterface {
    // private members
private:
    int key;
public:
    // default constructor of Ceasar
    Ceasar();
    
    /**
     * Sets the key to use
     * @param ckey - the key to use
     * @return - True if the key is valid and False otherwise
     */
    bool setKey(int ckey);
    
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
    
    /* The protected members */
protected:
    
};


#endif /* Ceasar_h */
