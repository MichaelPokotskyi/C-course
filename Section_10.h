#pragma once
using namespace std;
#include <string>

int Crypto()
{
	string alphabet{ "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" };
	string key{ "XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr" };
	string orig_phrase, crypted_phrase, decrypted_phrase;
	
	cout << "Enter phrase to crypt: \n";
	getline (cin, orig_phrase);

	for (size_t i{0}; i < orig_phrase.length(); ++i)
	{
		for (size_t j{ 0 }; alphabet.length(); ++j)
		{
			if (orig_phrase.at(i) == alphabet.at(j)) 
			{
				crypted_phrase += key[j];
			}
		}
	}
	// a;; 
	cout << "Crypted phrase: \n", crypted_phrase;
	return 0;
}