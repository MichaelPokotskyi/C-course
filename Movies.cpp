#pragma once
#include <iostream>
#include <vector>
#include "Movies.h"
#include "Movie.h"
using namespace std;


void Movies :: add_movie(Movie m)
{

	/*for (int i = 0; i < Mov.size(); ++i)
	{
		if (m->get_movie_name() == Mov.at(i).get_movie_name())
		{
			cout << "This movie already exist in list" << endl;
		}
		if (Mov.size() == 0)
		{
			Mov.push_back(*m);
		}
	}*/
	Mov.push_back(m);
}

void const Movies::display()
{
	if (Mov.size() == 0)
	{
		cout << "List empty" << endl;
	}
	else 
	{
		for (size_t i = 0; i < Mov.size(); ++i)
		{
			cout << Mov.at(i).get_movie_name()
				<< " " << Mov.at(i).get_movie_rating()
				<< " " << Mov.at(i).get_movie_watch_q() << endl;
		}
	}
}

void Movies::increase_watch(Movie m)
{
	for (int i = 0; i < Mov.size(); ++i) 
	{
		if (m.get_movie_name() == Mov.at(i).get_movie_name()) 
		{
			Mov.at(i).inc_movie_watch_q();
			cout << "+" << endl;
		}
	}
}