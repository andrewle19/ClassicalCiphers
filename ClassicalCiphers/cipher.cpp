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
        
        
        string plain = "hello world";
        // remove the white space
        plain = removeSpace(plain);
        
        bool found; // to check if the alphabetical character is in set
        int setcount = 0;
        int setsize = 25;

        char playfairMatrix[5][5]; // matrix of he playfair cipher
        char playfairset[setsize]; // set that holds unique characters
        
        
        // loop through the plain text and insert into set
        for(int i = 0; i < plain.length(); i++) {
            
            found = false; // set default found case to false;
            
            // loop throught the set to see if the alphabetical character is in the set already
            for(int j = 0; j < setsize; j++) {
                
                // since j and i are the same set found as true if it is found in the set
                if(plain[i] == 'j' || plain[i] == 'i'){
                    if(playfairset[j] == 'i' || playfairset[j] == 'j'){
                        found = true;
                    }
                }
                
                //  if plain character is found in the set. set found as true
                else if (playfairset[j] == plain[i]) {
                    found = true;
                }
                
            }
            
            // if alphabetical is not found add the plain text alpha to set
            if(!found){
                playfairset[setcount] = plain[i];
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
        
        
        
        for(int i = 0; i < setcount; i++){
            cout << playfairset[i] << ' ';
        }
        cout << '\n';
        
        
        
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
