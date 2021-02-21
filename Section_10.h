#pragma once
using namespace std;
#include <string>

int Crypto()
{
	string alphabet{ "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ " };
	string key{ "XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr%" };
	string orig_phrase{}, crypted_phrase{}, decrypted_phrase{};
	/**/
	cout << "Enter phrase to crypt: \n";
	getline(cin, orig_phrase);
	/**/
	for (size_t i{ 0 }; i < orig_phrase.length(); ++i)
	{
		for (size_t j{ 0 }; j < alphabet.length(); ++j)
		{
			if (orig_phrase.at(i) == alphabet.at(j))
			{
				crypted_phrase += key[j];
			}
		}
	}
	cout << "Crypted phrase: \n" << crypted_phrase;
	/**/
	for (size_t i{ 0 }; i < crypted_phrase.length(); ++i)
	{
		for (size_t j{ 0 }; j < key.length(); ++j)
		{
			if (crypted_phrase.at(i) == key.at(j))
			{
				decrypted_phrase += alphabet[j];
			}
		}
	}
	cout << "\nDerypted phrase: \n" << decrypted_phrase;
	/**/
	return 0;
}