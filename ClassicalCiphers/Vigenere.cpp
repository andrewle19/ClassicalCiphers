#include "Vigenere.h"

/**
* Default constructor that initializes the Vigenere table
*/
Vigenere::Vigenere()
{
	// Holds the starting char position for each row in the Vigenere table
	int num = 0; 

	for (int i = 0; i < 26; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			// This formula gets a char's ascii value to store into table from 'a' to 'z'
			// (num + j) % 26 gets position of character in alphabet
			// +97 converts to ascii value
			table[i][j] = ((num + j) % 26) + 97;
		}
		// Increments the starting char position for the next row in the Vigenere table
		num++;
	}
}

/**
* Sets the key to use
* @param key - the key to use
* @return - True if the key is valid and False otherwise
*/
bool Vigenere::setKey(const string& key)
{
	if (key.empty()) 
	{
		return false;
	}
	else 
	{
		vKey = key;
		return true;
	}
}

/**
* Encrypts a plaintext string
* @param plaintext - the plaintext string
* @return - the encrypted ciphertext string
*/
string Vigenere::encrypt(const string& plaintext)
{
	string cipher = "";
	int j = 0;
	int row = 0;
	int column = 0;
	int numMessage = 0;
	char encryptedMessage;

	for (int i = 0; i < plaintext.length(); i++) 
	{
		// Converts vkey[j] to number for row in the Vigenere table
		row = vKey[j] - 'a';

		// Converts plaintext[i] to number for column in the Vigenere table
		column = plaintext[i] - 'a';
		
		// Grabs the ascii value of char from the Vigenere table
		numMessage = table[row][column];

		// Converts ascii value to char
		encryptedMessage = numMessage;

		// Appends the character to cipher text
		cipher += encryptedMessage;

		// Increments key counter and mods by length of key for wraparound
		j = (j + 1) % vKey.length();
	}

	return cipher;
}

/**
* Decrypts a string of ciphertext
* @param cipherText - the ciphertext
* @return - the plaintext
*/
string Vigenere::decrypt(const string& cipherText)
{
	string plaintext = "";
	int j = 0;
	int row = 0;
	int column = 0;
	int numMessage = 0;
	char encryptedMessage;

	for (int i = 0; i < cipherText.length(); i++) 
	{
		// Converts vkey[i] to number for row in the Vigenere table
		row = vKey[j] - 'a';

		for (int k = 0; k < 26; k++) 
		{
			if ((cipherText[i] == table[row][k])) 
			{
				// Prepares to stop loop since column number was found
				k = 26;
			}
			// Increment column count
			column++;
		}

		// Grabs the ascii value of the column of character from the Vigenere table
		// column - 1 due to very last incrementation in for loop before exiting
		numMessage = (column - 1) + 'a';

		// Converts ascii value to char
		encryptedMessage = numMessage;

		// Appends the character to cipher text
		plaintext += encryptedMessage;

		// Increments key counter and mods by length of key for wraparound
		j = (j + 1) % vKey.length();

		// Reset column to find next plaintext character
		column = 0;
	}

	return plaintext;
}

