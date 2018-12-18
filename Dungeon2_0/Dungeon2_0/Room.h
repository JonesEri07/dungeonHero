#ifndef ROOM_H
#define ROOM_H
#include <string>
#include "Monster.h"

class Room
{
private:
	std::string roomName;	//name of room
	std::string item;		//Item if any
	std::string key;		//Needed to enter room if any
	std::string exitNorth;			//Use key name of room. Can exit by going north
	std::string exitSouth;			//... south
	std::string exitWest;			//... west
	std::string exitEast;			//... east
	std::string exitUp;				//... up
	std::string exitDown;			//... down
	bool visited;

	bool thereIsMonster;
	Monster monster;
public:
	Room();
	Room(std::string name);
	Room(std::string name, std::string item_);
	Room(std::string name, std::string item_, std::string key_);
	Room(std::string name, std::string item_, std::string key_,
		std::string north, std::string south, std::string west, std::string east);
	Room(std::string name, std::string item_, std::string key_,
		std::string north, std::string south, std::string west, std::string east, 
		Monster mon);

	Room(std::string name, std::string item_, std::string key_,
		std::string north, std::string south, std::string west, std::string east,
		std::string up, std::string down);
	Room(std::string name, std::string item_, std::string key_,
		std::string north, std::string south, std::string west, std::string east,
		std::string up, std::string down, Monster mon);
	~Room();

	std::string getName();
	std::string getNorth();
	std::string getSouth();
	std::string getWest();
	std::string getEast();
	std::string getUp();
	std::string getDown();

	std::string canMove();

	std::string getItem();
	void removeItem();
	std::string getKey();
	void removeKey();
	void changeKey(std::string newKey);

	bool isThereMonster();

	std::string getMonsterName();
	Monster getMonster();
	void noMoreMonster();
	void yesVisited();

	bool operator!= (Room& rm)
	{
		if (roomName == rm.getName())
			return false;
		return true;
	}

	bool operator == (Room& rm)
	{
		if (roomName == rm.getName())
			return true;
		else
			return false;
	}

};

#endif

