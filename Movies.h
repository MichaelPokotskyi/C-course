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
	void add_movie(Movies m, string name, string rating, int watch_q);
	void display();

	//constructors
	Movies()
	{
		//empty const
	}
};