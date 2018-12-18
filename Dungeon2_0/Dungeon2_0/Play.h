#ifndef PLAY_H
#define PLAY_H
#include <iostream>
#include <string>

#include "Cine.h"		//Large text amount output functions
#include "inputHandler.h"
#include "MAP.h"
#include "Hero.h"
#include "Battles.h"

void start(Quest& myWorld, MAP& dungeon, Hero& hero)
{
	Room entrance = dungeon.getEntrance();
	if (dungeon.getName() == "Lair");
		welcomeLair(dungeon, dungeon.getEntrance());
	dungeon.getEntrance().yesVisited();

	Room current = entrance;
	Room exit = dungeon.getExit();
	hero.setLocation(current);
	while (current.getName() != dungeon.getExit().getName())
	{
		std::cout << "\n\n\n";
		std::cout << "What would you like to do?\n";
		
		bool goodInput = false;
		while (!goodInput)
		{
			std::stringstream actions;
			actions << current.canMove();
			actions << hero.canDo();
			std::cout << actions.str();
			std::cout << "\n\nCommand: ";
			std::string command;
			std::cin >> command;
			std::cin.ignore(10000, '\n');
			std::string result;
			int perform = validInput(command);
			if (perform == 1)
			{
				result = hero.move(dungeon, command);
				if (result == "Wall")
					std::cout << "\n\n\n\n\n\n\n\n\t\tThere's a Wall there, trust me.\n\n\n";
				else if (result == "Ceiling")
					std::cout << "\n\n\n\n\n\n\n\n  Nope, just some stalactites... or are those stalagmites...\n\n\n";
				else if (result == "Floor")
					std::cout << "\n\n\n\n\n\n\n\n\t\tHmm... Solid ground.\n\n\n";
				else
				{
					std::string next = result;
					std::stringstream need(result);
					need >> result;
					if (result == "Locked")
					{
						need >> result;
						std::cout << "\n\n\n\n\n\n\nUh Oh. You need a " << result << " access this room.\n\n";
					}
					else
					{
						goodInput = true;
						Room saved = current;
						current = dungeon.getRoom(next);
						if (current.isThereMonster() && current.getMonsterName() == "Troll")
						{
							std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\nYou are about to enter the monster's domain.\n";
							std::cout << "Are you sure you want to go in? (y/n) ";
							std::string pick;
							std::cin >> pick;
							std::cin.ignore(10000, '\n');
							pick[0] = tolower(pick[0]);
							if (pick == "y")
							{
								hero.setLocation(current);
								roomDisplay(current.getName());
							}
							else
							{
								current = saved;
							}
						}
						else
						{
							hero.setLocation(current);
							roomDisplay(current.getName());
						}
					}
				}
			}
			else if (perform == 2)
			{
				if (command == "search")
					std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n" << hero.search() << "\n\n";
				if (command == "take")
					std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n" << hero.take() << "\n\n";
				if (command == "use")
				{
					if (hero.getInventory() == "")
						std::cout << "\n\n\n\n\n\n\n\n\n\n\nNothing in your inventory to use.\n\n\n";
					else
					{
						std::string myStuff = hero.getInventory();
						std::cout << "\n\n\n\n\n\n\n\n\n\n\nWhat would you like to use?\nItems: ";
						std::cout << myStuff << "\n\n\n\n";
						std::string grab;
						std::cin >> grab;
						std::cin.ignore(10000, '\n');
						std::string use = hero.use(dungeon, grab);

						if (use == "Unusable")
						{
							std::cout << grab << " can't be used here.\n\n";
						}
						else if (use == "doNotHave")
						{
							std::cout << grab << " is not in your inventory.\n\n";
						}
						else
						{
							Room openRoom = dungeon.getRoom(use);
							dungeon.setRoom(openRoom);
							std::cout << "\n\n\n\n\n\n\n\n\n\n\n" << dungeon.getRoom(use).getName() << " is now accessable.\n\n";

							hero.removeItem(grab);
						}
					}
				}
				if (command == "inventory")
				{
					std::cout << "\n\n\n\n\n\n\n\n\n\nItems: " << hero.getInventory() << "\n";
					std::cout << "Weapons: " << hero.getWeapons() << "\n";
				}
				if (command == "info")
					std::cout << "\n\n\n\n\n\n\n\n\n\n\n" << hero.getHeroInfo() << "\n\n";
			}
			else
				std::cout << "\n\n\n\n\t\t****Invalid command.****\n\n\n";

			
			
			if (current.isThereMonster())
			{
				Monster mon = current.getMonster();
				std::string alive;
				alive = battleTime(hero, mon);
				if (alive == "alive")
				{
					dungeon.removeMonster(current);
					roomDisplay(current.getName());
				}
				else
				{
					std::cout << "\n\n\n\t\t\tGAME OVER\n\n\n";
					return;
				}
			}
		

			if (current.getName() == dungeon.getExit().getName())
			{
				std::cout << "\n\n\n\n\n";
				std::cout << "\t\t\t CONGRATULATIONS YOU WON!\n\n\n\n";
			}
		}
	}
}

void startTower(Quest& myWorld, MAP& dungeon, Hero& hero)
{




}


#endif