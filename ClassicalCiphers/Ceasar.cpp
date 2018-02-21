//
//  Ceasar.cpp
//  ClassicalCiphers
//
//  Created by Andrew Le on 2/21/18.
//  Copyright © 2018 Andrew Le. All rights reserved.
//

#include "Ceasar.h"

// default constructor
Ceasar::Ceasar(){
    int key = 0;
}

// sets the key to use
// input: key- int key to use for shifts
// output: false or true when set
bool Ceasar::setKey(int ckey){
    if(key > 0){
        key = ckey;
        return true;
    }
    else {
        return false;
    }
}

string Ceasar::encrypt(const string &plaintext){
    string ciphertext;
    // traverse text
    for (int i=0;i< plaintext.length();i++){
        // Encrypt Uppercase letters
        if (isupper(plaintext[i])) { ciphertext += char(int(plaintext[i]+key-'A')%26 +'A'); }
        // Encrypt Lowercase letters
        else{ ciphertext += char(int(plaintext[i]+key-'a')%26+'a'); }
    }
    return ciphertext;
}


string Ceasar::decrypt(const string &ciphertext){
    string plaintext;
    for (int i=0;i< ciphertext.length();i++){
        //decrypt upper case
        if (isupper(ciphertext[i])) { plaintext += char(int(ciphertext[i]-key-'A')%26 +'A'); }
        // decrypt Lowercase letters
        else{ plaintext += char(int(ciphertext[i]-key-'a')%26+'a'); }
    }
    return plaintext;
}
