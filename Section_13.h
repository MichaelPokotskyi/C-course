#pragma once
#include <iostream>
using namespace std;

class Player {
	string name;
	int health;
	int xp;

	void talk(string);
	bool is_dead();
};

void s13() 
{
	Player frank;
	Player hero;

	Player* enemy{ nullptr };
	enemy = new Player;
	delete enemy;
}
