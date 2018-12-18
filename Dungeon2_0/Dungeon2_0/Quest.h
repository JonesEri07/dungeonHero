#ifndef QUEST_H
#define QUEST_H
#include "MAP.h"
#include "Hero.h"
#define DEFAULT_MAP_SIZE 5
class Quest
{
private:
	MAP dungeons[DEFAULT_MAP_SIZE];			//Array of available dungeons
	std::map<std::string, MAP> myDungeons;	//Map/quest finder map by name
	int numDungeons;
	

public:
	Quest();

	~Quest();

	//add new filled map
	void addDungeon(MAP dungeon);

	//return Map
	MAP getDungeon(std::string name);

	//return num of dungeons created
	int totalQuests();

	std::string listDungeons();

	std::string listDunAndRooms();

	std::string toString();

	void setHeroName(std::string name);
	
};


#endif
