#ifndef CINE_H
#define CINE_H
#include <iostream>
#include <string>
#include <cctype>

void welcomeLair(MAP dungeon, Room entrance)
{
	std::string dungeon_ = dungeon.getName();
	int i = 0;
	while (dungeon_[i])
	{
		dungeon_[i] = std::toupper(dungeon_[i]);
		i++;
	}
	std::cout << "********************************************************************************";

	std::cout << "\n\n\n\n\n\n";
	std::cout << "\t\t\t WELCOME TO THE " << dungeon_ << " DUNGEON! \n\n\n\n";

	std::cout << "********************************************************************************";

	std::cout << "\n\n\n\n";
	std::cout << "As you reach the top of the hill you see it... the " << dungeon.getName() << ".\n";
	std::cout << "You have traveled far to reach this place. Where others have failed you will \nsucceed.\n";
	std::cout << "With absolute resolution you plunge yourself into the dungeon's entrance.\n";
	system("pause");
	std::cout << "\n\n\n\n\n\n\n\n";
	std::cout << "********************************************************************************";

	std::cout << "\n\n\n\n\n\n";
	std::cout << "\t\t\t\t" << entrance.getName() << " Room \n\n\n\n";

	std::cout << "********************************************************************************";

	std::cout << "You bravely walk into the dimly lit dungeon, an open room lays ahead of\n";
	std::cout << "you. You might have to feel around a bit to find where to go next.\n";
	std::cout << "Just then you hear a loud thud as the entrance behind you closes.\n";
	std::cout << "You try opening it but it wont budge. You have no choice now but\n to continue onward.\n";
	if (dungeon_ == "LAIR")
		std::cout << "Beware the MONSTER that dwells within. Defeat it and claim your treasure.\n\n";
	else if (dungeon_ == "TOWER")
		std::cout << "Beware any traps that may be waiting for you. Find the treasure and\nfind a way through this maze.\n\n";
	else
		std::cout << "\n\n\n\nDidn't work\n\n\n\n\n";
	return;
}


void roomDisplay(std::string roomName)
{
	std::cout << "********************************************************************************";

	std::cout << "\n\n\n";
	std::cout << "\t\t\t\t" << roomName << " Room \n\n\n";

	std::cout << "********************************************************************************";
	std::cout << "\n\n";


}


void cineBattleScene(std::string hero, std::string monster)
{
	std::cout << "\n\n\n";
	std::cout << "You slowly push the splintery door open.\n";
	std::cout << "Then you smell it. The over powering stench of rotting corpses.\n";
	std::cout << "Trying hard not to gag you slowly pick your way through the bone riddled \npassage.";
	std::cout << "Just then you hear a sickening crunch and slowly turn around...\n\n\n";
	system("pause");
	std::cout << "\n\n\n";
	std::cout << "There at the door you just came through you see two big yellow eyes about\n";
	std::cout << "8 feet in the air.\n";
	std::cout << "It belows a deafening roar and charges!\n";
	std::cout << "You dive out of the way just barely escaping the swing of the " << monster << "'s club.\n";
	std::cout << "Spinning around you prepare yourself to do battle!\n\n";
	system("pause");
}




#endif