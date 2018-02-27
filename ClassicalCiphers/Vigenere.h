#ifndef VIGENERE_H
#define VIGENERE_H

#include <vector>   /* For vectors */
#include <string>   /* For C++ strings */
#include <stdio.h>  /* For standard I/O */
#include <stdlib.h> /* For miscellenous C functions */
#include "CipherInterface.h"

using namespace std;

/**
* This class implements the playfair cipher.
* The class extends the abstract class
* CipherInterface.
*/

class Vigenere : public CipherInterface
{
	/** The private members **/
private:
	int table[26][26];
	string vKey;

	/** The public members **/
public:
	/**
	* Default constructor that initializes the Vigenere table
	*/
	Vigenere();

	/**
	* Sets the key to use
	* @param key - the key to use
	* @return - True if the key is valid and False otherwise
	*/
	virtual bool setKey(const string& key);

	/**
	* Encrypts a plaintext string
	* @param plaintext - the plaintext string
	* @return - the encrypted ciphertext string
	*/
	virtual string encrypt(const string& plaintext);

	/**
	* Decrypts a string of ciphertext
	* @param ciphertext - the ciphertext
	* @return - the plaintext
	*/
	virtual string decrypt(const string& ciphertext);


protected:


};

#endif
