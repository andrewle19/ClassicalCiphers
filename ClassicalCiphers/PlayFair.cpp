//
//  PlayFair.cpp
//  ClassicalCiphers
//
//  Created by Andrew Le on 2/21/18.
//  Copyright © 2018 Andrew Le. All rights reserved.
// 


#include "PlayFair.h"
#include <iostream>
PlayFair::PlayFair(){
    setcount = 0;
    setsize = 25;
    memset(playfairset, 0, 25);
}

// Sets the key with pkey
// checks if the key is valid and if it is intitalizes the playfair matrix with key
bool PlayFair::setKey(string pkey){
    if(pkey.empty()){
        return false;
    }else{
        key = pkey;
        initMatrix();
        return true;
    }
}

// initalize the playfair matrix based on key
void PlayFair::initMatrix(){

    bool found = false;

    // loop through the plain text and insert into set
    for(int i = 0; i < key.length(); i++) {

        found = false; // set default found case to false;

        // loop throught the set to see if the alphabetical character is in the set already
        for(int j = 0; j < setsize; j++) {

            // since j and i are the same set found as true if it is found in the set
            if(key[i] == 'j' || key[i] == 'i'){
                if(playfairset[j] == 'i' || playfairset[j] == 'j'){
                    found = true;
                }
            }
            //  if plain character is found in the set. set found as true
            else if (playfairset[j] == key[i]) {
                found = true;
            }

        }

        // if alphabetical is not found add the plain text alpha to set
        if(!found){
            playfairset[setcount] = key[i];
            setcount++; // increment set count
        }
    }

    // fill in the rest of the alphabetical characters for matrix
    char alpha = 'a';
    while(setcount != setsize){
        found = false;
        // loop throught the set to check if that alpha is being used already
        for(int i = 0; i < setcount; i++) {

            // since i and j are the same if either are found set it as true
            if(alpha == 'i' || alpha == 'j'){
                if(playfairset[i] == 'i' || playfairset[i] == 'j'){
                    found = true;
                }
            }

            //  if plain character is found in the set. set found as true
            if(playfairset[i] == alpha){
                found = true;
            }
        }

        // if alphabetical is not found add the plain text alpha to set
        if(!found){
            playfairset[setcount] = alpha;
            setcount++; // increment set account
        }

        alpha++; // increment the alpha after we check the whole matrix for it
    }


    // INITIALIZE THE PLAYFAIR MATRIX AFTER THE SET IS ready
    int setindex = 0; // start the set index at 0
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            playfairMatrix[i][j] = playfairset[setindex];
            setindex++;
        }
    }
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cout << playfairMatrix[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

// prepares the plain text for playfair cipher
//by separating same characters with xs and making sure sting is even
// input: plain- plain text to insert
// output: returns new string
string PlayFair:: preparePlainText(const string &plaintext){
    string newplain;

    // Preparing the plain text for playfair cipher
    for(int i = 0; i < plaintext.length(); i += 2){

        // add x inbetween same letter characters
        if(plaintext[i] == plaintext[i+1]){
            newplain += plaintext[i];
            newplain += 'x';
            --i;
        } else {
            // checks if next character is an alpha if it is then add both
            if(isalpha(plaintext[i+1])){
                newplain += plaintext[i];
                newplain += plaintext[i+1];
            }
            else {
                newplain += plaintext[i];
            }
        }
    }

    // if its uneven add a character
    if(newplain.length() % 2 != 0) {
        newplain += 'x';
    }

    return newplain;
}


// Takes in two characters finds location in the matrix and returns ciphertext
// output: ciphertext based on the two characters
string PlayFair:: encryptHelper(char firstletter, char secondletter){

    string ciphertext;

    // Finds the location of the two letters
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(firstletter == playfairMatrix[i][j]){
                one.row = i;
                one.col = j;
            } else if(secondletter == playfairMatrix[i][j]){
                two.row = i;
                two.col = j;
            }
        }
    }

    // ENCRYPT THE PLAIN TEXT TO CIPHER TEXT

    // checks if each are in the same column moves down row
    if(one.col == two.col){
        ciphertext += playfairMatrix[(one.row+1)%5][one.col];
        ciphertext += playfairMatrix[(two.row+1)%5][two.col];
    }
    // checks if in same row moves right one column
    else if(one.row == two.row){

        ciphertext += playfairMatrix[one.row][(one.col+1)%5];
        ciphertext += playfairMatrix[two.row][(two.col+1)%5];
    }
    // if not in row or col will swap the two columns but not the rows
    else {
        ciphertext += playfairMatrix[one.row][two.col];
        ciphertext += playfairMatrix[two.row][one.col];
    }

    return ciphertext;
}

// decrypts the two inputted character and returns plain text
string PlayFair::decryptHelper(char firstletter, char secondletter){

    string plain;

    // Finds the location of the two letters
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){

            // check if the first or second letter is i or j and find location
            if(firstletter == 'j' || firstletter == 'i'){
                if(playfairMatrix[i][j] == 'i' || playfairMatrix[i][j] == 'j'){
                    one.row = i;
                    one.col = j;
                }
            }
            else if(secondletter == 'j' || secondletter == 'i'){
                if(playfairMatrix[i][j] == 'i' || playfairMatrix[i][j] == 'j'){
                    two.row = i;
                    two.col = j;
                }
            }
            // check for location in playfair matrix
            if(firstletter == playfairMatrix[i][j]){
                    one.row = i;
                    one.col = j;
                } else if(secondletter == playfairMatrix[i][j]){
                    two.row = i;
                    two.col = j;

                }
            }
        }

    // Decrypt THE Cipher TEXT TO plain TEXT

    // checks if each are in the same column moves up a row
    if(one.col == two.col){

      // checks if both locations' row is found at the beginning of setindex
      // If either of them are then we place them at the end of the row
      if(one.row != 0  && two.row != 0){

        plain += playfairMatrix[(one.row-1)%5][one.col];
        plain += playfairMatrix[(two.row-1)%5][two.col];
      }
      else if(one.row == 0){
        plain += playfairMatrix[4][one.col];
        plain += playfairMatrix[(two.row-1)%5][two.col];

      }
      else if(two.row == 0){
        plain += playfairMatrix[(one.row-1)%5][one.col];
        plain += playfairMatrix[4][two.col];
      }


    }
    // checks if in same row moves right one column
    else if(one.row == two.row){

      // checks if both locations' col is found at the beginning of setindex
      // If either of them are then we place them at the end of the col
      if(one.col != 0  && two.col != 0){

        plain += playfairMatrix[one.row][(one.col-1)%5];
        plain += playfairMatrix[two.row][(two.col-1)%5];
      }
      else if(one.col == 0){
        plain += playfairMatrix[one.row][4];
        plain += playfairMatrix[two.row][(two.col-1)%5];
      }
      else if(two.col == 0){
        plain += playfairMatrix[one.row][(one.col-1)%5];
        plain += playfairMatrix[two.row][4];
      }


    }
    // if not in row or col will swap the two columns but not the rows
    else {
        plain += playfairMatrix[one.row][two.col];
        plain += playfairMatrix[two.row][one.col];
    }

    return plain;
}



// Decrypts the cipher using the playfair cipher
// returns plain text
string PlayFair::decrypt(const string &ciphertext){

    string plain;
    for(int i = 0; i < ciphertext.length(); i+=2){
        plain += decryptHelper(ciphertext[i], ciphertext[i+1]);
    }
    return plain;
}


// Encrypts using the playfair cipher
// returns ciphertext
string PlayFair::encrypt(const string &plaintext){

    string ciphertext;
    string plain = preparePlainText(plaintext);
    for(int i = 0; i < plain.length(); i+=2){
        ciphertext += encryptHelper(plain[i], plain[i+1]);
    }
    return ciphertext;
}
