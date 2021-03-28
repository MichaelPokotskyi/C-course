#pragma once
#include "Movie.h"
using namespace std;

//class metods implementation
string Movie :: get_movie_name()
{
	return name;
}

string Movie :: get_movie_rating()
{
	return rating;
}

int Movie :: get_movie_watch_q()
{
	return watch_q;
}

void Movie::increase_watch(Movie m)
{
	m.get_movie_watch_q();
}