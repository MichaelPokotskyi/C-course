#pragma once
#include <iostream>
#include <vector>
#include "Movie.h"
using namespace std;


class Movies
{
private:
	//class variable
	vector<Movie> Mov;

public:
	// methods prototypes
	void add_movie(Movie m);
	void const display();
	void increase_watch(Movie m);

	//constructors
	Movies()
	{
		//empty const
	}
};