#include "MapMaker.h"
#include "Play.h"
#include <iostream>
#include <string>
#include <ctype.h>
#include <stdio.h>
#include <sstream>
#include <fstream>

#ifdef _MSC_VER
#define _CRTDBG_MAP_ALLOC  
#include <crtdbg.h>
#define VS_MEM_CHECK _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#else
#define VS_MEM_CHECK
#endif


using namespace std;


//string checkChoice(string list, string choice);


int main()
{
	VS_MEM_CHECK

	
		
		
		
	Hero hero;
	Quest blank;
	Quest myWorld = createWorld(blank);		//Set up the worlds I have made
	MAP choice = selectMap(myWorld, hero);
	//if (choice.getName() == "Lair")
	start(myWorld, choice, hero);
	//if (choice.getName() == "Tower")
		//startTower(myWorld, choice, hero);
	hero.clearWeapons();
	/*
		Other ideas:
		limited number of slots for inventory
			Will need drop option. (leaves in room to be picked up later)
		multiple enemies in a room
			update room set up
		create level catagory for enemies for different sequences of battle
			new cine functions

		Enigma dungeon
			teleport rooms to confuse player
			maze

	*/


	system("pause");
	return 0;
}

