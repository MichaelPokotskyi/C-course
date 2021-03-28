#pragma once
#include<iostream>
using namespace std;

class Movie
{
private:
	// class variables
	string name{};
	string rating{};
	int watch_q{};

public:
	//metods prototypes here
	string get_movie_name();
	string get_movie_rating();
	int get_movie_watch_q();
	void increase_watch(Movie m);

	// constructors
	Movie()
	{
		//empty const
	}

	Movie(string name, string rating, int watch_q) 
	{
		this->name = name;
		this->rating = rating;
		this->watch_q = watch_q;
	}


};