//
//  Hill.cpp
//  ClassicalCiphers
//
//  Created by Andrew Le on 3/4/18.
//  Copyright © 2018 Andrew Le. All rights reserved.
//

#include "Hill.h"
using namespace std;
Hill::Hill(){};


string Hill::preparePlainText(const string &plaintext){
  return plaintext+'x';
}

// check if the key is valid
// in this case only keys of size 4 are valid because for simplicity reasons
// we used a hill cipher key matrix of size 2x2
bool Hill::setKey(const string &hkey){
  if(hkey.empty() || hkey.length() != 4){
      return false;
  }
  else {
    int count = 0;
    // add the key to hill key subtract 97 because we want letters 0-25
    // rather than ascii values
    for(int i = 0; i < 2; i++){
      for(int j = 0; j < 2; j++){

        key[i][j] = int(hkey[count]-97);
        count++;
      }
    }
      return true;
  }
}

// encrypt plain text into cipher text using hill ciphertext
// plaintext- plaintext to encrypt
string Hill::encrypt(const string &plaintext){
  string plain = plaintext;
  vector<int> cipherMatrix;
  string cipher;

  // if the plain text is uneven
  if(plaintext.length() % 2 != 0){
    string plain = preparePlainText(plaintext);
  }

  // prepare the cipherMatrix so it is from 0-25 instead of ascii values
  // place inside matrix
  for(int i = 0; i < plaintext.length(); i++){
    cipherMatrix.push_back(plain[i]-97);
  }

  // loop through each plain text key evaluating 2 characters at a time
  // then loop through the key matrix;
  // equation to encrypt character is matrix row * ciphermatrix column % 26 + 97
  //. we mod 26 because 26 letters in alphabet, +97 because we use
  for(int i = 0; i < plaintext.length(); i+=2){
    cipher += char((key[0][0]*cipherMatrix[i] + key[0][1]*cipherMatrix[i+1])%26+97);

    cipher += char((key[1][0]*cipherMatrix[i] + key[1][1]*cipherMatrix[i+1])%26+97);
  }

  return cipher;

}

// inverses the 2x2 matrix the lazy way
void Hill::inverseKey(){
  int temp = key[0][0];
  key[0][0] = key[1][1];
  key[1][1] = temp;
  key[0][1] = -1*key[0][1]+26;
  key[1][0] = -1*key[1][0]+26;
}

// Calculate inverse determinate
int Hill::calculateDeterminateInverse(){
  int determinate = key[0][0] * key[1][1] - key[0][1] * key[1][0];
  bool found = false;
  int i = 0;
  while(!found){
    if((determinate * i)%26 == 1){
      found = true;
      return i;
    }
    i++;
  }
  return i;
}

string Hill::decrypt(const string &ciphertext){

  string cipher = ciphertext;
  vector<int> plainMatrix;
  string plain;

  int determinateInverse = calculateDeterminateInverse();
  inverseKey();
  // multiply the determinateInverse with key to make decryption key
  for(int i = 0; i < 2; i++){
    for(int j = 0; j < 2; j++){
      key[i][j] = (key[i][j]*determinateInverse);

    }
  }

  // prepare the cipherMatrix so it is from 0-25 instead of ascii values
  // place inside matrix
  for(int i = 0; i < ciphertext.length(); i++){
    plainMatrix.push_back(cipher[i]-97);
  }

  // loop through each plain text key evaluating 2 characters at a time
  // then loop through the key matrix;
  // equation to encrypt character is matrix row * ciphermatrix column % 26 + 97
  //. we mod 26 because 26 letters in alphabet, +97 because we use
  for(int i = 0; i < ciphertext.length(); i+=2){
    plain += char((key[0][0]*plainMatrix[i] + key[0][1]*plainMatrix[i+1])%26+97);
    plain += char((key[1][0]*plainMatrix[i] + key[1][1]*plainMatrix[i+1])%26+97);
  }


  return plain;
}
