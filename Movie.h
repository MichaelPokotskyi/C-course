#pragma once
#include<iostream>
using namespace std;

class Moovie
{
private:
	// class variables
	string name{};
	string rating{};
	int watch_q{};

	//metods prototypes here
	string get_movie_name();
	string get_movie_rating();
	int get_movie_watch_q();

public:
	// constructors
	Moovie() 
	{
		//empty const
	}

	Moovie(string name, string rating, int watch_q) {
		this->name = name;
		this->rating = rating;
		this->watch_q = watch_q;
	}
};