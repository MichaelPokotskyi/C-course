#pragma once
#include <iostream>
#include <vector>
#include "Movie.h"
using namespace std;


class Movies
{
private:
	//class variable
	vector<Movie> Mov{};

public:
	// methods prototypes
	void add_movie(Movie m);
	void display();

	//constructors
	Movies()
	{
		//empty const
	}
};