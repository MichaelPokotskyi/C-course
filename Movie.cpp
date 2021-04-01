#pragma once
#include "Movie.h"
#include "Movies.h"
using namespace std;

//class metods implementation
string const Movie :: get_movie_name()
{
	return name;
}

string const Movie :: get_movie_rating()
{
	return rating;
}

int const Movie :: get_movie_watch_q()
{
	return watch_q;
}