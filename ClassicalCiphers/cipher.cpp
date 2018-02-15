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
