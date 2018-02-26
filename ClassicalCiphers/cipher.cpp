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
#include "RowTransposition.h"
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


// function changes string to lowercase
string toLowercaseString(string plain){
    string tolower;
    
    for(int i = 0; i < plain.length(); i++) {
        if(plain[i] < 97) {
            tolower += plain[i] + 32;
        }
        else {
            tolower += plain[i];
        }
    }
    return tolower;
}


int main(int argc, char** argv)
{
	
  
	
	/* Create an instance of the DES cipher */	
	CipherInterface* cipher = NULL; 
    ifstream infile;
    ofstream outfile;
//    /* Error checks */
//    if(!cipher)
//    {
//        fprintf(stderr, "ERROR [%s %s %d]: could not allocate memory\n",
//        __FILE__, __FUNCTION__, __LINE__);
//        exit(-1);
//    }
	
    string key = string(argv[2]);
    // playfair cipher selection
    if(string(argv[1]) == "PLF"){
        // remove the white space
        key = removeSpace(key);
        cipher = new PlayFair();
        if(!static_cast<PlayFair*>(cipher)->setKey(key)){
            cout << "key was not valid" << endl;
        };
        
        if(string(argv[3]) == "ENC"){
        
            infile.open(argv[4]); // open user input file
            if(!infile){
                cout << "No Input File was found" << endl;
                return 1;
            }
            
            // take in the plain text
            string plaintext;
            infile >> plaintext;
            plaintext = toLowercaseString(plaintext);
            cout << plaintext << endl;
            // encrypt ciphertext with playfair cipher
            string ciphertext = static_cast<PlayFair*>(cipher)->encrypt(plaintext);
            outfile.open(argv[5]);
            outfile << ciphertext;
            
            // close files
            outfile.close();
            infile.close();

        }
        
        else if(string(argv[3]) == "DEC") {
           
            infile.open(argv[4]);
            
            if(!infile){
                cout << "Input file was not found" << endl;
                return 1;
            }
            
            string ciphertext;
            infile >> ciphertext;
            ciphertext = toLowercaseString(ciphertext);
            
            outfile.open(argv[4]);
            // decrypt message and output it
            string plaintext = static_cast<PlayFair*>(cipher)->decrypt(ciphertext);
            outfile << plaintext;
            infile.close();
            outfile.close();
        }
        
    }
    // row transposition selection
    else if(string(argv[1]) == "RTS"){
        cipher = new RowTransposition();
        if(!static_cast<RowTransposition*>(cipher)->setKey(key)){
            cout << "Key was not valid" << endl;
            
            return 1;
        };
        
        if(string(argv[3]) == "ENC"){
            infile.open(argv[4]);
            if(!infile){
                cout << "No Input File was found" << endl;
                return 1;
            }
            
            // take in the plain text
            string plaintext;
            infile >> plaintext;
            plaintext = toLowercaseString(plaintext);
            // encrypt ciphertext with playfair cipher
            cout << "Encrypting... " << endl;
            string ciphertext = static_cast<RowTransposition*>(cipher)->encrypt(plaintext);
            cout << "Done" << endl;
            outfile.open(argv[5]);
            outfile << ciphertext;
            
            // close files
            outfile.close();
            infile.close();
            
        }
        
        else if(string(argv[3]) == "DEC") {
            
            infile.open(argv[4]);
            
            if(!infile){
                cout << "Input file was not found" << endl;
                return 1;
            }
            
            string ciphertext;
            infile >> ciphertext;
            ciphertext = toLowercaseString(ciphertext);
            
            outfile.open(argv[5]);
            // decrypt message and output it
            cout << "Decrypting..." << endl;
            string plaintext = static_cast<RowTransposition*>(cipher)->decrypt(ciphertext);
            outfile << plaintext;
            cout << "Done..." << endl;
            infile.close();;
            outfile.close();
        }
        static_cast<RowTransposition*>(cipher)->freeMatrix();
        
    }
    // rail fence selection
    else if(string(argv[1]) == "RFC"){
        
    }
    // Vigenere selection
    else if(string(argv[1]) == "RTS"){
        
    }
    // ceasar selection
    else if(string(argv[1]) == "CES"){
        
        
        cipher = new Ceasar();
        static_cast<Ceasar*>(cipher)->setKey(stoi(key));
        
        if(!static_cast<Ceasar*>(cipher)->setKey(stoi(key))){
            cout << "Key was not valid" << endl;
            
            return 1;
        };
        
        if(string(argv[3]) == "ENC"){
            infile.open(argv[4]);
            if(!infile){
                cout << "No Input File was found" << endl;
                return 1;
            }
            
            // take in the plain text
            string plaintext;
            infile >> plaintext;
            plaintext = toLowercaseString(plaintext);
            // encrypt ciphertext with playfair cipher
            cout << "Encrypting... " << endl;
            string ciphertext = static_cast<Ceasar*>(cipher)->encrypt(plaintext);
            cout << "Done" << endl;
            outfile.open(argv[5]);
            outfile << ciphertext;
            
            // close files
            outfile.close();
            infile.close();
            
        }
        
        else if(string(argv[3]) == "DEC") {
            
            infile.open(argv[4]);
            
            if(!infile){
                cout << "Input file was not found" << endl;
                return 1;
            }
            
            string ciphertext;
            infile >> ciphertext;
            ciphertext = toLowercaseString(ciphertext);
            
            outfile.open(argv[5]);
            // decrypt message and output it
            cout << "Decrypting..." << endl;
            string plaintext = static_cast<Ceasar*>(cipher)->decrypt(ciphertext);
            outfile << plaintext;
            cout << "Done..." << endl;
            infile.close();;
            outfile.close();
        }
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
