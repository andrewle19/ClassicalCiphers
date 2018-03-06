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
#include "Railfence.h"
#include "Vigenere.h"
#include "Hill.h"
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


    // check arguments if too little or too much
    if(argc != 6){
        cout << "Too little or too many arguments used" << endl;
        cout << "./cipher <CIPHER NAME> <KEY> <ENC/DEC> <INPUTFILE> <OUTPUT FILE>\n";
        return 1;
    }

	/* Create an instance of the DES cipher */
	CipherInterface* cipher = NULL;
    ifstream infile;
    ofstream outfile;

    // get key from arguments
    string key = string(argv[2]);
    // playfair cipher selection
    if(string(argv[1]) == "PLF"){
        // remove the white space
        key = removeSpace(key);
        cipher = new PlayFair();

        // check if key is valid and set it
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
            // encrypt ciphertext with playfair cipher
            cout << "Playfair Encrypting..." << endl;
            string ciphertext = static_cast<PlayFair*>(cipher)->encrypt(plaintext);
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
            string plaintext = static_cast<PlayFair*>(cipher)->decrypt(ciphertext);
            cout << "Done" << endl;
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
            cout << "Row Transposition Encrypting... " << endl;
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
        cipher = new Railfence();
        // remove the white space
        key = removeSpace(key);
        if(!static_cast<Railfence*>(cipher)->setKey(key)){
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
            // encrypt ciphertext with playfair cipher
            cout << "Railfence Encrypting" << endl;
            string ciphertext = static_cast<Railfence*>(cipher)->encrypt(plaintext);
            cout << "Done..." << endl;
            outfile.open(argv[5]);
            outfile << ciphertext;

            // close files
            outfile.close();
            infile.close();

        }

        else if(string(argv[3]) == "DEC") {

            // open file
            infile.open(argv[4]);


            if(!infile){
                cout << "Input file was not found" << endl;
                return 1;
            }

            // input cipher text
            string ciphertext;
            infile >> ciphertext;
            // ciphertext
            ciphertext = toLowercaseString(ciphertext);
            outfile.open(argv[5]);
            // decrypt message and output it
            cout << "Decrypting..." << endl;
            string plaintext = static_cast<Railfence*>(cipher)->decrypt(ciphertext);
            cout << "Done" << endl;
            outfile << plaintext;

            infile.close();
            outfile.close();
        }

    }

    // Vigenere selection
    else if(string(argv[1]) == "VIG"){
        cipher = new Vigenere();
        // check if key is valid
        if(!static_cast<Vigenere*>(cipher)->setKey(key)){
            cout << "Key was not valid" << endl;

            return 1;
        };

        // encryption choice
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
            cout << "Viginere Encrypting... " << endl;
            string ciphertext = static_cast<Vigenere*>(cipher)->encrypt(plaintext);
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
            string plaintext = static_cast<Vigenere*>(cipher)->decrypt(ciphertext);
            cout << "Done..." << endl;
            outfile << plaintext;
            infile.close();;
            outfile.close();
        }
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
            cout << "Ceasar Encrypting... " << endl;
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
            cout << "Done..." << endl;
            outfile << plaintext;
            infile.close();;
            outfile.close();
        }
    }
    else if(string(argv[1]) == "HIL"){
      cipher = new Hill();

      if(!static_cast<Hill*>(cipher)->setKey(key)){
          cout << "Key was not valid(Key of size 4 only)" << endl;
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
          cout << "Hill Encrypting... " << endl;
          string ciphertext = static_cast<Hill*>(cipher)->encrypt(plaintext);
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
          string plaintext = static_cast<Hill*>(cipher)->decrypt(ciphertext);
          cout << "Done..." << endl;
          outfile << plaintext;
          infile.close();;
          outfile.close();
      }

    }
    else {
        cout << "Invalid Cipher name: " << endl;
        cout << "PLF: PlayFair" << endl;
        cout << "RTS: Row Transposition" << endl;
        cout << "VIG: Vigenere" << endl;
        cout << "CES: Caesar" << endl;
        cout << "HIL: Hill" << endl;
        return 1;
    }


	return 0;
}
