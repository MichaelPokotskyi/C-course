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
#include "Section_14.h"
#include "Movie.h"
#include "Movies.h"
//using namespace std;

int main()
{
    //Small section assignments 
    //Second();
    //FCCServ();
    //Vector();
    //Convert(); 
    //Numbers();
    //Crypto();
    //Stars();
    //startNumbers();
    //s12();
    
     
    //Moovie assignment
    /*Movie movie1("Star Wars", "PG", 5);
    Movie movie2("Big", "PG-13", 2);
    Movie movie3("Cinderella", "PG", 7);
    Movies m;
    m.display();
    m.add_movie(movie1);
    m.add_movie(movie2);
    m.add_movie(movie3);
    m.display();
    m.increase_watch(movie1);
    m.increase_watch(movie2);
    m.increase_watch(movie3);
    m.display();*/
    

    // pointers and ref practice;
    /*int a{ 10 }, b{15}, *p{ nullptr }, * n{ nullptr };
    p = new int;
    p = &a;
    n = &b;
    cout << &a << " " << p << endl;
    cout << a << " " << *p << endl;

    cout << &b << " " << n << endl;
    cout << b << " " << *n << endl;

    //delete p;

    /**p = 20; 
    cout << &a << " " << p << endl;
    cout << a << " " << *p << endl;

    a = 30;
    cout << &a << " " << p << endl;
    cout << a << " " << *p << endl;*/

    Mystring empty; // no args constructor
    Mystring larry("Larry"); // overloaded constructor
    Mystring stooge{ larry }; // copy constructor

    empty.display();
    larry.display();
    stooge.display();

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
