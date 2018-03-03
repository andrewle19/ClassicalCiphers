#include "Railfence.h"


/**
* Sets the key to use
* @param key - the key to use
* @return - True if the key is valid and False otherwise
*/
bool Railfence::setKey(const string& key)
{
	if (key.empty())
	{
		return false;
	}
	else
	{
		// Converts string to int value for # of levels/depth
		vKey = atoi(key.c_str());
		return true;
	}
}




/**
* Encrypts a plaintext string
* @param plaintext - the plaintext string
* @return - the encrypted ciphertext string
*/
string Railfence::encrypt(const string& plaintext)
{
	string cipher = "";
	int index = 0;

	for (int row = 0; row < vKey; row++) {
		// Sets index equal to row
		// This is for wrap-around / start of each new row
		index = row;

		// Append to the ciphertext the char a given key length away from index
		// E.g. If key = 3, loop would go 0 + 3, 3 + 3, 6 + 3, etc...
		// At the start of a new row, 1 + 3, 4 + 3, ...
		while (index < plaintext.length()) {
			cipher += plaintext[index];
			index += vKey;
		}
	}

	return cipher;
}

/**
* Decrypts a string of ciphertext
* @param cipherText - the ciphertext
* @return - the plaintext
*/
string Railfence::decrypt(const string& cipherText)
{
	string plaintext = "";
	int rowMaxChar = 0;
	int index = 0;
	int extraChars = 0; // Holds remainder of mod operation to determine how many rows have extra chars
	int row = 0;		// Row counter used to determine those with extra chars
	bool hasExtraChars = false;

	// Sets max length of rows based on depth
	// This determines whats the highest number of characters a row can have
	// E.g. If string length = 23 and key = 3, then rowMaxChar = (23 / 3 ) + 1 = 8
	if (cipherText.length() % vKey > 0) {
		rowMaxChar = (cipherText.length() / int(vKey)) + 1;
		extraChars = cipherText.length() % vKey;
		hasExtraChars = true;
	}
	else {
		rowMaxChar = cipherText.length() / int(vKey);
	}

	// Run this if all rows even length
	if (!hasExtraChars) {
		for (int column = 0; column < rowMaxChar; column++) {
			// Sets index equal to column
			// This essentially jumps to next column after the rows are read top-to-bottom
			index = column;

			// Append to the plaintext the char going down each row in the cipher from index
			// E.g. If key = 3 and rowMaxChar = 8, loop would go 0 + 8, 8 + 8, etc...
			// At the start of a new column, 1 + 8, 9 + 8, ...
			while (index < cipherText.length()) {
				plaintext += cipherText[index];
				index += rowMaxChar;

			}
		}
	}
	else {
		for (int column = 0; column < rowMaxChar; column++) {
			index = column;

			while (index < cipherText.length() && row < extraChars) {
				plaintext += cipherText[index];
				index += rowMaxChar;
				row++;
			}
			// Next rows do not have additional chars to decrease index incrementor by 1
			rowMaxChar -= 1;

			while (plaintext.length() < cipherText.length() && index < cipherText.length()) {
				plaintext += cipherText[index];
				index += rowMaxChar;
			}

			// Essentially reset our index incrementor and row count
			rowMaxChar += 1;
			row = 0;
		}
	}
	
	return plaintext;
}

