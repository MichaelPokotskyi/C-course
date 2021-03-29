// C course.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Section_4.h"
#include "Section_6.h"
#include "Section_7.h"
#include "Section_8.h"
#include "Section_9.h"
#include "Section_10.h"
#include "1st_assignment.h"
#include "Section_11.h"
#include "Section_12.h"
#include "Section_13.h"
#include "Movie.h"
#include "Movies.h"
using namespace std;

int main()
{
    //Second();
    //FCCServ();
    //Vector();
    //Convert();
    //Numbers();
    //Crypto();
    //Stars();
    //startNumbers();
    //s12();
    

    Movie movie1{ "Big", "PG-13", 2 },
        movie2{ "Star Wars", "PG", 5 },
        movie3{ "Cinderella", "PG", 7 };
        //movie4{"Cinderella", "PG", 7};

    Movie* m3{nullptr};
    m3 = &movie3;

    Movies m;


    //movie1("Big", "PG-13", 2);

    //movie2 = new Movie("Star Wars", "PG", 5);
    //movie3 = new Movie("Cinderella", "PG", 7);
    //movie4 = new Movie("Cinderella", "PG", 7);


    m.display();

    m.add_movie(&movie1);
    m.add_movie(&movie2);
    m.add_movie(&movie3);

    m.display();

    movie3.increase_watch(m3);

    m.display();

    //m.display();

    //m.add_movie(*movie4);

    ///m.display();

    //!!!
    /*delete movie1;
    delete movie2;
    delete movie3;
    delete movie4;*/

    //display();
    
    
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
