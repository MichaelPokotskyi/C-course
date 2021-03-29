#pragma once
#include "Movie.h"
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

void Movie::increase_watch(Movie *m)
{
	m->watch_q = m->get_movie_watch_q() + 1;
	cout << "Watch was increased for movie: " << m->get_movie_name() << ", "
		<< "now " << m->get_movie_watch_q() << endl;
}