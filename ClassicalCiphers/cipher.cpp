// Author: Andrew Le
// email: andrewle19@csu.fullerton.edu
// Practice with Classical Ciphers

#include <iostream>
#include <string>
#include "CipherInterface.h"
#include <fstream>
#include <locale>
using namespace std;

// Function to remove white space from plain text
// Input: plain text
// output: plain text without white space
string removeSpace(string plain){
    
    string noSpacePlain;
    
    // traverse string and add any character that is not a space
    for(int i = 0; i < plain.length(); i++) {
        if(plain[i] != ' ') {
            noSpacePlain += plain[i];
        }
    }

    return noSpacePlain;
}


// Initialize Matrix of the playfair cipher
// Input: key - key to encrypt with, playfairset[] - unique set of characters, setsize - size of set
// playfairMatrix- the matrix u want to initialize
// OUTPUT: NONE:
void initMatrix(string key, char playfairset[],int setsize, char playfairMatrix[][5]) {
    bool found = false;
    int setcount = 0;
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
}



int main(int argc, char** argv)
{
	/**
	 * TODO: Replace the code below	with your code which can SWITCH
	 * between DES and AES and encrypt files. DO NOT FORGET TO PAD
	 * THE LAST BLOCK IF NECESSARY.
	 *
	 * NOTE: due to the incomplete skeleton, the code may crash or
	 * misbehave.
	 */
	
  
	
	/* Create an instance of the DES cipher */	
	CipherInterface* cipher = NULL; 
		
//    /* Error checks */
//    if(!cipher)
//    {
//        fprintf(stderr, "ERROR [%s %s %d]: could not allocate memory\n",
//        __FILE__, __FUNCTION__, __LINE__);
//        exit(-1);
//    }
	
    // playfair cipher selection
    if(string(argv[1]) == "PLF"){
        
        
        string key = "monarchy";
        
        // remove the white space
        key = removeSpace(key);
        
        int setsize = 25;

        char playfairMatrix[5][5]; // matrix of he playfair cipher
        char playfairset[setsize]; // set that holds unique characters
        
        initMatrix(key, playfairset, setsize,playfairMatrix);
        
        
        
        // print the matrix
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 5; j++){
                cout << playfairMatrix[i][j] << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
        
        
        // ENCRYPT A Key
        string plain = "balloonk";
        plain = removeSpace(plain);
        string newplain;
        cout << plain.length() << endl;
        
        // Preparing the plain text for playfair cipher
        for(int i = 0; i < plain.length(); i += 2){
            
            // add x inbetween same letter characters
            if(plain[i] == plain[i+1]){
                newplain += plain[i];
                newplain += 'x';
                --i;
            } else {
                
                if(isalpha(plain[i+1])){
                    newplain += plain[i];
                    newplain += plain[i+1];
                }
                else {
                    newplain += plain[i];
                }
                
            }
        }
       
        // if its uneven add a character
        if(newplain.length()%2 != 0) {
            newplain += 'x';
        }
    
        cout << newplain << endl;
        
        
    }
    // row transposition selection
    else if(string(argv[1]) == "RTS"){
        
    }
    // rail fence selection
    else if(string(argv[1]) == "RFC"){
        
    }
    // Vigenere selection
    else if(string(argv[1]) == "RTS"){
        
    }
    // ceasar selection
    else if(string(argv[1]) == "CES"){
       
        string plain = "Hello World";
        string cipher;
        string decrypt;
        int key = 3;
        
        plain = removeSpace(plain);
        cout << plain << endl;
        // traverse text
        for (int i=0;i< plain.length();i++){
            // Encrypt Uppercase letters
            if (isupper(plain[i])) { cipher += char(int(plain[i]+key-'A')%26 +'A'); }
            // Encrypt Lowercase letters
            else{ cipher += char(int(plain[i]+key-'a')%26+'a'); }
        }
        cout << cipher << endl;
        
        // decrypt cipher text
        for (int i=0;i< plain.length();i++){
            //decrypt upper case
            if (isupper(plain[i])) { decrypt += char(int(cipher[i]-key-'A')%26 +'A'); }
            // decrypt Lowercase letters
            else{ decrypt += char(int(cipher[i]-key-'a')%26+'a'); }
        }
        cout << decrypt << endl;
    
    }
    else {
        
    }
    
    
    
	/* Set the encryption key
	 * A valid key comprises 16 hexidecimal
	 * characters. Below is one example.
	 * Your program should take input from
	 * command line.
	 */
	//cipher->setKey((unsigned char*)"0123456789abcdef");
	
	/* Perform encryption */
	//string cipherText = cipher->encrypt("hello world");
	
	/* Perform decryption */
	//cipher->decrypt(cipherText);	
	
	return 0;
}
