#include "Quest.h"
#include "Hero.h"
#include<iostream>
#include<string>
#include<sstream>

using namespace std;


Quest::Quest()
{
	numDungeons = 0;
}



Quest::~Quest()
{
}

void Quest::addDungeon(MAP dungeon)
{
	int next = numDungeons;
	numDungeons++;
	dungeons[next] = dungeon;
	myDungeons[dungeon.getName()] = dungeon;
	return;
}

MAP Quest::getDungeon(string name)
{
	return myDungeons[name];
}


int Quest::totalQuests()
{
	return numDungeons;
}

string Quest::listDungeons()
{
	string line;
	string post = " , ";
	int n = 0;
	while (n < numDungeons)
	{
		if (n == numDungeons - 1)
			post = "";
		line += dungeons[n].getName() + post;
		n++;
	}
	return line;
}

string Quest::listDunAndRooms()
{
	string line;
	int n = 0;
	while (n < numDungeons)
	{
		line += "Dungeon: ";
		line += dungeons[n].getName() + "\n(Rooms)\n";
		line += dungeons[n].listRoomNames() + "\n";
		n++;
	}
	return line;
}

string Quest::toString()
{
	string line;
	for (int i = 0; i < DEFAULT_MAP_SIZE; i++)
		line += dungeons[i].getName() + " ";
	return line;
}

void Quest::setHeroName(string name)
{

}