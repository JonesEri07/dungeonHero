#include "Room.h"
#include <iostream>
#include <string>

using namespace std;

Room::Room() 
{
	visited = false;
	thereIsMonster = false;
}
Room::Room(string name)
{
	roomName = name;
	visited = false;
	thereIsMonster = false;
}
Room::Room(string name, string item_)
{
	roomName = name;
	item = item_;
	visited = false;
	thereIsMonster = false;
}
Room::Room(string name, string item_, string key_)
{
	roomName = name;
	item = item_;
	key = key_;
	visited = false;
	thereIsMonster = false;
}
Room::Room(string name, string item_, string key_,
	string north, string south, string west, string east)
{
	roomName = name;
	item = item_;
	key = key_;
	exitNorth = north;
	exitSouth = south;
	exitWest = west;
	exitEast = east;
	exitUp = "Wall";
	exitDown = "Wall";
	visited = false;
	thereIsMonster = false;
}

Room::Room(std::string name, std::string item_, std::string key_,
	std::string north, std::string south, std::string west, std::string east, 
	Monster mon)
{
	roomName = name;
	item = item_;
	key = key_;
	exitNorth = north;
	exitSouth = south;
	exitWest = west;
	exitEast = east;
	exitUp = "Wall";
	exitDown = "Wall";
	visited = false;

	thereIsMonster = true;
	monster = mon;
}


Room::Room(string name, string item_, string key_,
	string north, string south, string west, string east,
	string up, string down)
{
	roomName = name;
	item = item_;
	key = key_;
	exitNorth = north;
	exitSouth = south;
	exitWest = west;
	exitEast = east;
	exitUp = up;
	exitDown = down;
	visited = false;
	thereIsMonster = false;
}

Room::Room(std::string name, std::string item_, std::string key_,
	std::string north, std::string south, std::string west, std::string east,
	std::string up, std::string down, Monster mon)
{
	roomName = name;
	item = item_;
	key = key_;
	exitNorth = north;
	exitSouth = south;
	exitWest = west;
	exitEast = east;
	exitUp = up;
	exitDown = down;
	visited = false;
	thereIsMonster = true;
	monster = mon;
}



Room::~Room()
{
}

string Room::getName()
{
	return roomName;
}

string Room::getNorth()
{
	return exitNorth;
}

string Room::getSouth()
{
	return exitSouth;
}

string Room::getWest()
{
	return exitWest;
}

string Room::getEast()
{
	return exitEast;
}

string Room::getUp()
{
	return exitUp;
}

string Room::getDown()
{
	return exitDown;
}

string Room::canMove()
{
	string res;
	res = "Move: ";
	if (exitNorth != "Wall")
		res += "North ";
	if (exitSouth != "Wall")
		res += "South ";
	if (exitWest != "Wall")
		res += "West ";
	if (exitEast != "Wall")
		res += "East ";
	if (exitUp != "Wall")
		res += "Up ";
	if (exitDown != "Wall")
		res += "Down ";
	//res.pop_back();
	res.pop_back();
	res += "\n";
	return res;
}

string Room::getItem()
{
	return item;
}

void Room::removeItem()
{
	item = "";
}

string Room::getKey()
{
	return key;
}

void Room::removeKey()
{
	key = "";
}

void Room::changeKey(string newKey)
{
	key = newKey;
}

bool Room::isThereMonster()
{
	return thereIsMonster;
}

string Room::getMonsterName()
{
	return monster.getName();
}

Monster Room::getMonster()
{
	return monster;
}

void Room::noMoreMonster()
{
	thereIsMonster = false;
}

void Room::yesVisited()
{
	visited = true;
}