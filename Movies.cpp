#pragma once
#include <iostream>
#include <vector>
#include "Movies.h"
using namespace std;


void Movies :: add_movie(Movie *m)
{
	Mov.push_back(*m);
}

void const Movies :: display()
{
	for (size_t i = 0; i < Mov.size(); ++i) 
	{
		cout << Mov.at(i).get_movie_name() 
			<< " " << Mov.at(i).get_movie_rating() 
			<< " " << Mov.at(i).get_movie_watch_q() << endl;
	}
}