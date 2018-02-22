// Author: Andrew Le
// email: andrewle19@csu.fullerton.edu
// Practice with Classical Ciphers

#include <iostream>
#include <string>
#include "CipherInterface.h"
#include <fstream>
#include <locale>
#include <algorithm>
#include "Ceasar.h"
#include "PlayFair.h"
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
        string key = "royal new zealand navy";
        string plaintext;
        // remove the white space
        key = removeSpace(key);
        
        cipher = new PlayFair();
        static_cast<PlayFair*>(cipher)->setKey(key);
        string ciphertext =" KXJEY UREBE ZWEHE WRYTU HEYFS KREHE GOYFI WTTTU OLKSY CAJPO BOTEI ZONTX BYBNT GONEY CUZWR GDSON SXBOU YWRHE BAAHY USEDQ";
        ciphertext = removeSpace(ciphertext);
        std::transform(ciphertext.begin(),ciphertext.end(),ciphertext.begin(), ::tolower);
        
        cout << ciphertext << endl;
        cout << '\n';
        cout << static_cast<PlayFair*>(cipher)->decrypt(ciphertext) << endl;
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
        
        string plaintext = "Hello World";
        plaintext = removeSpace(plaintext);
        int key = 3;
        cipher = new Ceasar();
        static_cast<Ceasar*>(cipher)->setKey(key);
        string ciphertext = static_cast<Ceasar*>(cipher)->encrypt(plaintext);
        cout << ciphertext << endl;
        cout << static_cast<Ceasar*>(cipher)->decrypt(ciphertext) << endl;
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
