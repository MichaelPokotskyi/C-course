#pragma once
using namespace std;
#include <string>
#include <windows.h>

int Crypto()
{	/**/
	int const milliseconds{ 15 };
	string alphabet{ "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ " };
	string key{ "XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr%" };
	string orig_phrase{}, crypted_phrase{}, decrypted_phrase{};
	/**/
	cout << "Enter phrase to crypt: " << "\n";
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
//	cout << "\n";
	for (size_t i{0}; i < 40; ++i)
	{
		cout << '*';
		Sleep(milliseconds);
	}
	cout << "\n";
	cout <<"Crypted phrase: \n" << crypted_phrase << "\n";
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
	for (size_t i{ 0 }; i < 40; ++i)
	{
		cout << '*';
		Sleep(milliseconds);
	}
	cout << "\n";
	cout << "Derypted phrase: \n" << decrypted_phrase;
	/**/
	return 0;
}