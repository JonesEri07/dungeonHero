#ifndef MAPMAKER_H
#define MAPMAKER_H
#include "Quest.h"
#include "MAP.h"
#include "Room.h"
#include "Hero.h"
#include<iostream>
#include<string>
#include<sstream>


/* Here I will use my other files to create and instantiate 
   however many dungeon maps I would like to make.
   Each MAP is new dungeon.
   For each MAP you add rooms
	the first room added will be the entrance to that dungeon.
	the last room added will be the exit to that dungeon or end of game
 **/
Quest createWorld(Quest& adventures)
{
	//First map dungeon			item, key, adjacent rooms:N,S,W,E,U,D and a monster if any
	MAP lair("Lair");
	//first add monsters
	std::string troll = "Troll";
	lair.addMonster(troll, "Cave", 100, 25);
	//First room added will be the entrance to the dungeon
	lair.addRoom("Main",		"COIN", "", "Monster's Domain", "Wall", "Left", "Dark");
	lair.addRoom("Dark",		"FORK", "", "Wall", "Wall", "Main", "Darker");
	lair.addRoom("Darker",		"APPLE", "", "Cell", "Wall", "Dark", "Darkest");
	lair.addRoom("Darkest",		"LADDER", "", "Wall", "Wall", "Darker", "Wall");
	lair.addRoom("Cell",	"WEAPON SWORD 45", "KEY", "Wall", "Darker", "Wall", "Wall");
	lair.addRoom("Left",		"KEY",	"LADDER", "Wall", "Wall", "Wall", "Main");
	lair.addRoom("Monster's Domain", "", "", "Treasure", "Main", "Wall", "Wall", troll);
	lair.addRoom("Treasure", "TREASURE", "", "Wall", "Monster's Domain", "Wall", "Wall");
	
	adventures.addDungeon(lair);
	//New map dungeon
	MAP tower("Tower");
	//List of monster;
	std::string snake = "Snake";
	tower.addMonster(snake, "Poison", 10, 10);
	std::string shroom = "Shroom Bro";
	tower.addMonster(shroom, "Poison", 10, 2);
	//1st FLOOR
	tower.addRoom("A52", "", "", "A42", "Wall", "A51", "A53", "B52", "Wall");
	tower.addRoom("A42", "", "", "A32", "A52", "A41", "A43", snake);
	tower.addRoom("A32", "", "", "A22", "A42", "Wall", "Wall");
	tower.addRoom("A22", "", "", "Wall", "A32", "Wall", "Wall", "B22", "Wall");
	tower.addRoom("A51", "", "", "Wall", "Wall", "Wall", "A52");
	tower.addRoom("A53", "", "", "A43", "Wall", "A52", "Wall");
	tower.addRoom("A41", "", "", "Wall", "Wall", "Wall", "A42", snake);
	tower.addRoom("A43", "", "", "Wall", "A53", "A42", "Wall", "B43", "Wall");
	
	
	//2nd FLOOR
	tower.addRoom("B43", "", "", "Wall", "Wall", "Wall", "Wall", "Wall", "A43");
	tower.addRoom("B52", "", "", "B42", "Wall", "Wall", "Wall", "Wall", "A52");
	tower.addRoom("B42", "", "", "B32", "B42", "Wall", "Wall");
	tower.addRoom("B32", "", "", "B22", "B32", "Wall", "Wall");
	tower.addRoom("B22", "", "", "Wall", "B32", "Wall", "Wall", "Wall", "A22");


	//3rd FLOOR
	//tower.addRoom("C43", "", "", "")

	adventures.addDungeon(tower);

	MAP waterTemple("Under Water Temple");


	adventures.addDungeon(waterTemple);

	return adventures;
}

std::string checkChoice(std::string list, std::string choice)
{
	int i = 0;
	while (choice[i])
	{
		choice[i] = tolower(choice[i]);
		i++;
	}
	std::stringstream list_(list);
	std::string check;
	std::string dungeon;
	while (list_ >> check)
	{
		std::string fullName;
		while (check != ",")
		{
			fullName += check + " ";
			if (list_.eof())
				break;
			list_ >> check;
		}
		dungeon = fullName;
		dungeon.pop_back();
		check = dungeon;
		i = 0;
		while (check[i])
		{
			check[i] = tolower(check[i]);
			i++;
		}

		if (check == choice && choice != ",")
			return dungeon;
	}
	return "bad";
}



MAP selectMap(Quest& myWorld, Hero& hero)
{
	std::cout << "Loading the following Quests:\n";
	std::cout << myWorld.listDunAndRooms() << std::endl;
	std::cout << "\n\nLoading complete\n";
	system("pause");
	std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	std::cout << "What is the name of your hero? ";
	std::string name;
	getline(std::cin, name);
	hero.setHeroName(name);
	std::cout << "\n\n\n\n\n\n";
	std::cout << "Which quest would you like to play?\n  Choices: ";
	std::string list = myWorld.listDungeons();
	std::string choice;
	while (true)
	{
		std::cout << list;
		std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nI choose ";
		getline(std::cin, choice);
		choice = checkChoice(list, choice);
		if (choice == "bad")
			std::cout << "\n\nInvalid entry.\nWhich quest would you like to play?\n";
		else
			break;
	}

	std::cout << "\n\n\n\n\n\n\n\n\n\n\n";
	std::cout << "********************************************************************************";

	std::cout << "\n\n\n\n\n\n";
	std::cout << "\t\t\t Loading " << choice << "\n\n\n\n";

	std::cout << "********************************************************************************";
	std::cout << "\n\n\n\n\n\n\nLoading complete\n";
	system("pause");

	return myWorld.getDungeon(choice);
}





#endif