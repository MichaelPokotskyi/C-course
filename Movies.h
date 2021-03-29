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
	void add_movie(Movie *m);
	void const display();

	//constructors
	Movies()
	{
		//empty const
	}

	/*Movies(Movie m)
	{
		//empty const
	}*/

};